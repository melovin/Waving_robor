#include "barvaRGB.hpp"
class Ledka
{
private:
    byte Red;
    byte Green;
    byte Blue;

public:
    Ledka(byte red, byte green, byte blue)
    {
        Red = red;
        Green = green;
        Blue = blue;

        pinMode(Red, OUTPUT);
        pinMode(Green, OUTPUT);
        pinMode(Blue, OUTPUT);
    }

    void ZobrazBarvu(BarvaRGB novaBarva)
    {
        analogWrite(Red, novaBarva.Red);
        analogWrite(Green, novaBarva.Green);
        analogWrite(Blue, novaBarva.Blue);
    }
};