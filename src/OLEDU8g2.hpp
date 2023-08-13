#ifndef OLEDU8G2_HPP
#define OLEDU8G2_HPP

class OLEDU8g2
{
private:
    /* data */
    void displayChinese();
    void displayTime();
    void runingTime();

public:
    inline OLEDU8g2(/* args */) {}
    inline ~OLEDU8g2() {}

    void setup();
    void loop();
    void config_time();
};

#endif