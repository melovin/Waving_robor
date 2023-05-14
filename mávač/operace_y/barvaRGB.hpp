#ifndef Barva
#define Barva
class BarvaRGB
{
public:
    byte Red;
    byte Green;
    byte Blue;
    BarvaRGB(byte red, byte green, byte blue)
    {
        Red = 255 - red;
        Green = 255 - green;
        Blue = 255 - blue;
    }
};
#endif