#include <unity.h>
#include "OLEDDisplay.hpp"
#include "LED.hpp"
#include "WifiManager.hpp"
#include <Arduino.h>

void test_function(void) {
    // TEST_ASSERT_EQUAL(expected_value, function_to_test(arguments)); // 替换 expected_value，function_to_test 和 arguments
}

void setup() {
    delay(2000); // 稍等一会儿，让串行端口准备好接收数据
    Serial.begin(115200);
    
    UNITY_BEGIN();
    RUN_TEST(test_function);
    UNITY_END();
}

void loop() {
    // 不需要循环操作
}
