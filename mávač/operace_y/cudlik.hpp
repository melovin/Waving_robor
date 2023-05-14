class Cudlik
{

private:
    byte Pin;
    bool PrevButtonState;
public:
    Cudlik(byte pin)
    {
        Pin = pin;
        pinMode(Pin, INPUT);

        PrevButtonState = false;
    }

    bool JsemZmacknuty()
    {
        bool currentState = (bool)digitalRead(Pin);
        if (currentState && !PrevButtonState)
        {
            PrevButtonState = currentState;
            return true;
        }
        else if(!currentState)
        {
            PrevButtonState = false;
        }
        return false;
        
    }
};