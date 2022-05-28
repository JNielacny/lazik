#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"
#include "unistd.h"

class Lazik: public ObiektGeom
{
    private:
    double szybkosc;
    double dlugosc;
    public:
    Lazik(){}
    Lazik(const char *sNazwaPliku_BrylaWzorcowa, 
          const char *sNazwaObiektu, 
          int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa, 
                                   sNazwaObiektu, 
                                   KolorID)
                                   {}
    void jedz(PzG::LaczeDoGNUPlota &Lacze)
    {
        
        Wek3D dane;
        dane[0]=szybkosc;
        set_przesuniecia()=dane;
        for(double i=0; i<dlugosc; i+=szybkosc)
        {
            Przelicz_i_Zapisz_Wierzcholki();
            Lacze.Rysuj();
            usleep(5000);
        }
    }

    double get_szybkosc()const{return szybkosc;}
    double get_dlugosc()const{return dlugosc;}

    double &set_szybkosc(){return szybkosc;}
    double &set_dlugosc(){return dlugosc;}
};
#endif