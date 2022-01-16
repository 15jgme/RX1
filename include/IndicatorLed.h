#ifndef INDICATORLED_H
#define INDICATORLED_H
#include <Adafruit_NeoPixel.h>

#define LED_PIN    8
#define LED_COUNT 1

class IndicatorLed
{
    std::array<int, 10> pattern = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    std::array<int, 10> colour = {0, 0, 0};
    std::array<int, 10> blue = {33, 150, 243};
    std::array<int, 10> red = {255, 0, 0};
    std::array<int, 10> cyan = {0, 188, 212};           
    std::array<int, 10> yellow = {255, 235, 59};  
    std::array<int, 10> orange = {255, 152, 0};        
    std::array<int, 10> green = {118, 255, 3};         
    bool updates = false;

public:
    IndicatorLed();
    void init();
    void update();
    void setBlue(){colour = blue; updates = true;}
    void setCyan(){colour = cyan; updates = true;}
    void setYellow(){colour = yellow; updates = true;}
    void setOrange(){colour = orange; updates = true;}
    void setGreen(){colour = green; updates = true;}
    void setRed(){colour = red; updates = true;}

    bool runState = false;
};
#endif