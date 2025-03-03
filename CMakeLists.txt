cmake_minimum_required(VERSION 3.10)
project(CryptoTradingPlatform)
set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS} include lib)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/MarketData.cpp
    src/Order.cpp
    src/Portfolio.cpp
)
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})