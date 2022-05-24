#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"

class Lazik: public ObiektGeom
{
    private:
    double szybkosc;
    double kat;
    double dlugosc;
    public:
    Lazik(){}
    Lazik(const char *sNazwaPliku_BrylaWzorcowa, 
          const char *sNazwaObiektu, 
          int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa, 
                                   sNazwaObiektu, 
                                   KolorID)
                                   {}
    double get_szybkosc()const{return szybkosc;}
    double get_kat()const{return kat;}
    double get_dlugosc()const{return dlugosc;}

    double &set_szybkosc(){return szybkosc;}
    double &set_kat(){return kat;}
    double &set_dlugosc(){return dlugosc;}
};
#endif