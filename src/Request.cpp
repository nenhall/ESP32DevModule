#include "Request.hpp"

void Request::requestData()
{
    // 发起网络请求
    HTTPClient http;
    String url = "http://example.com/api/data"; // 替换成您的目标URL
    http.begin(url);

    int httpResponseCode = http.GET(); // 发起GET请求

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        String payload = http.getString(); // 获取响应内容
        Serial.println(payload);
    }
    else
    {
        Serial.print("Error on HTTP request: ");
        Serial.println(httpResponseCode);
    }

    http.end(); // 关闭连接
}
