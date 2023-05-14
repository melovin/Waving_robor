#include "kroutak.hpp"
#include "cudlik.hpp"
#include "meric.hpp"
#include "ledka.hpp"
#include "barvaRGB.hpp"
#include "motor.hpp"

// cudlik na zmenu barvy oci na pinu D6
Cudlik MenicBarevCud = Cudlik(6);

// cudlik na zmenu vzdalenosti mereni pinu D7
Cudlik ZmenaVzdalenostiCud = Cudlik(7);

// změna rychlosti mavani na pinu A6
Kroutak RychlostKroutak = Kroutak(A6);

// zmena sirky mavani na pinu A7
Kroutak ObvodKroutak = Kroutak(A7);

// senzor pro mereni vzdalenosti ze ktere mavat na pinech D12 a D13
Meric MericVzdalenosti = Meric(12, 13);
int HraniceMavu = 30;

// laseroveOci
Ledka OcniZare = Ledka(9, 10, 11);

// moje nejlepsi barvy ever
byte AktualniBarviska = 0;
BarvaRGB Barvisky[] = {
    BarvaRGB(0, 191, 255),
    BarvaRGB(255, 0, 0),
    BarvaRGB(0, 255, 0),
    BarvaRGB(220, 20, 60),
    BarvaRGB(128, 0, 128),
    BarvaRGB(255, 255, 255),
    BarvaRGB(255, 255, 0),
    BarvaRGB(50, 26, 24),
    BarvaRGB(60, 60, 56)};

// motor
Motor motorRuka = Motor(5, 4, 3, 2);

void setup() {}

void loop()
{
  uchopVstup();

  // nastaveni meraku
  if (MericVzdalenosti.ZmerVzdalenost() <= HraniceMavu)
  {
    while (!motorRuka.Zamavej(RychlostKroutak.KolikNakrouceno()))
    {
      uchopVstup();
    }
  }
}
void uchopVstup()
{
  // nastaveni mackacich tlacitek
  byte VelikostPole = sizeof(Barvisky) / sizeof(BarvaRGB);
  if (MenicBarevCud.JsemZmacknuty())
  {
    AktualniBarviska = AktualniBarviska + 1 >= VelikostPole ? 0 : AktualniBarviska + 1;
  }

  if (ZmenaVzdalenostiCud.JsemZmacknuty())
  {
    HraniceMavu = (HraniceMavu + 10) <= 120 ? (HraniceMavu + 10) : 30;
  }

  OcniZare.ZobrazBarvu(Barvisky[AktualniBarviska]);
  // nastaveni kroutaku
  motorRuka.MaxOblouk = map(ObvodKroutak.KolikNakrouceno(), 0, 1023, 500, 1200);
}