class Kroutak
{
private:
    byte Pin;

public:
    Kroutak(byte pin)
    {
        Pin = pin;
        pinMode(Pin, INPUT);
    }

    int KolikNakrouceno()
    {
        return analogRead(Pin);
    }
};