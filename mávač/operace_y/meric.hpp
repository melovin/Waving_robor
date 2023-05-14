class Meric
{
private:
    byte Echo;
    byte Trig;

public:
    Meric(byte echo, byte trig)
    {
        Echo = echo;
        Trig = trig;

        pinMode(Trig, OUTPUT);
        pinMode(Echo, INPUT);
    }
    int ZmerVzdalenost()
    {
        digitalWrite(Trig, LOW);
        delayMicroseconds(2);
        digitalWrite(Trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(Trig, LOW);

        unsigned long trvani = pulseIn(Echo, HIGH);
        int vzdalenost = (int)((trvani / 2.0) / 29.4 / 1.25);

        return vzdalenost;
    }
};