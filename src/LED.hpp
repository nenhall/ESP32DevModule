#ifndef LED_HPP
#define LED_HPP

class LED
{
public:
    static int ledPin; 

    static void setup(const int pin);
    static void loop();
};

#endif