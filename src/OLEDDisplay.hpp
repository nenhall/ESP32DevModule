#ifndef OLEDDISPLAY_HPP
#define OLEDDISPLAY_HPP

class OLEDDisplay
{
private:
    /* data */
public:
    inline OLEDDisplay(/* args */) {}
    inline ~OLEDDisplay() {}

    void ssd1306Setup();
    void u8g2Setup();
    void u8g2Loop();
};

#endif