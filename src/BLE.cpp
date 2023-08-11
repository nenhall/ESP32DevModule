#include "BLE.hpp"
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define UUID_Service "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void BLE::setup()
{
    // 创建 BLE 设备
    BLEDevice::init("esp32");
    Serial.println("BLE Device Initialized");

    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(UUID_Service);

    // 添加特征
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
        UUID_Characteristic, 
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

    // 添加描述符
    pCharacteristic->addDescriptor(new BLE2902());

    pService->start();
    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();

    // 更多的蓝牙代码...
}