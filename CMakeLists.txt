cmake_minimum_required(VERSION 3.26)
project(ESP32DevModule)

set(CMAKE_CXX_STANDARD 11)

include_directories(other)
include_directories(src)

add_executable(ESP32DevModule
        other/DisplayRGB.cpp
        other/DisplayRGB.hpp
        other/LCD144.cpp
        other/LCD144.hpp
        other/SSD1306.cpp
        other/SSD1306.hpp
        src/BLE.cpp
        src/BLE.hpp
        src/LED.cpp
        src/LED.hpp
        src/main.cpp
        src/OLEDU8g2.cpp
        src/OLEDU8g2.hpp
        src/Request.cpp
        src/Request.hpp
        src/WifiManager.cpp
        src/WifiManager.hpp)
