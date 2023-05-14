class Motor{
private:
byte In1;
byte In2;
byte In3;
byte In4;
byte StepNumber;
bool Smer;
int RotacniPocitadlo;

public:
int MaxOblouk;
Motor(byte in1, byte in2, byte in3, byte in4)
{
    MaxOblouk = 1000;
    StepNumber = 0; 

    In1 = in1;
    In2 = in2;
    In3 = in3;
    In4 = in4;

    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
}
bool Zamavej(int rychlost){
    byte Kombinace [4][4] = {
        {1,0,0,0},
        {0,1,0,0,},
        {0,0,1,0},
        {0,0,0,1}};


    if(Smer)
    {
        digitalWrite(In1, Kombinace[StepNumber][0]);
        digitalWrite(In2, Kombinace[StepNumber][1]);
        digitalWrite(In3, Kombinace[StepNumber][2]);
        digitalWrite(In4, Kombinace[StepNumber][3]);

    }
    else
    {
        digitalWrite(In1, Kombinace[StepNumber][3]);
        digitalWrite(In2, Kombinace[StepNumber][2]);
        digitalWrite(In3, Kombinace[StepNumber][1]);
        digitalWrite(In4, Kombinace[StepNumber][0]);
    }
    StepNumber = StepNumber + 1 > 3 ? 0 : StepNumber + 1;
    byte prevedenaRychlost = map(abs(rychlost),0,1023,2,4);
    delay(prevedenaRychlost);
    RotacniPocitadlo++;

    if(RotacniPocitadlo > MaxOblouk)
    {
        Smer = !Smer;
        RotacniPocitadlo = 0;
        return !Smer;
    }
    return false;
}
};