#include "MarketData.hpp"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

MarketData::MarketData() {
    curl_global_init(CURL_GLOBAL_ALL);
}

PriceData MarketData::getPrice(const std::string& symbol) {
    CURL* curl = curl_easy_init();
    std::string response;
    PriceData data{symbol, 0.0};

    if (curl) {
        std::string url = "https://api.binance.com/api/v3/ticker/price?symbol=" + symbol;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            auto j = json::parse(response);
            data.price = std::stod(j["price"].get<std::string>());
        }
        curl_easy_cleanup(curl);
    }
    return data;
}