void connect_wifi();
#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include <string>

class WifiManager
{
private:
    std::string ssid;
    std::string password;

public:
    WifiManager(const std::string &ssid_ = "boss", const std::string &password_ = "@nenhall666")
        : ssid(ssid_), password(password_) {}

    void connectWifi();
    void setValue(int newValue);
    int getValue() const;
};

#endif