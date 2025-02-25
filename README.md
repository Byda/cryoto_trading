# CryptoTradingPlatform
A simple C++ cryptocurrency trading platform that fetches prices from Binance and simulates trades.

## Prerequisites
- C++17 compatible compiler (e.g., GCC, Clang)
- libcurl (`sudo apt install libcurl4-openssl-dev` on Ubuntu)
- nlohmann/json (download from https://github.com/nlohmann/json and place in `lib/`)

## Build Instructions
1. mkdir build && cd build
2. cmake ..
3. make
4. ./CryptoTradingPlatform

## Features
- Fetch real-time prices (e.g., BTCUSDT)
- Simulate buy/sell orders
- Track portfolio