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
    double kat;
    double wypadkowa;

    public:
    Lazik(){wypadkowa=0;}
    Lazik(const char *sNazwaPliku_BrylaWzorcowa, 
          const char *sNazwaObiektu, 
          int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa, 
                                   sNazwaObiektu, 
                                   KolorID)
                                   {wypadkowa=0;}

    Tkolizji CzyKolizja(shared_ptr<Lazik> &laz)
    {
        laz;
        return TK_BrakKolizji;
    }

    void jedz(PzG::LaczeDoGNUPlota &Lacze)
    {
        
        Wek3D dane;
        dane[1]=szybkosc;
        
        for(double i=0; i<dlugosc; i = i + szybkosc)
        {
            set_zmien_polozenie()=get_przesuniecia()+(RotacjaZ(wypadkowa) * dane);
            Przelicz_i_Zapisz_Wierzcholki();
            Lacze.Rysuj();
            usleep(10000);
        }
    }

    void obroc(PzG::LaczeDoGNUPlota &Lacze)
    {        
        for(int i=0; i<kat; i+=1)
        {
            obrot();
            Przelicz_i_Zapisz_Wierzcholki();
            Lacze.Rysuj();

            usleep(5000);
        }
        for(int i=kat; i<0; i+=1)
        {
            obrot_alt();
            Przelicz_i_Zapisz_Wierzcholki();
            Lacze.Rysuj();

            usleep(5000);
        }
    }

    void obrot()
    {
        wypadkowa+=1;
            set_MacObrotu()=RotacjaZ(wypadkowa);
                if(wypadkowa==360){wypadkowa=0;}
    }

    void obrot_alt()
    {
        wypadkowa-=1;
            set_MacObrotu()=RotacjaZ(wypadkowa);
                if(wypadkowa==-360){wypadkowa=0;}
    }

    double get_szybkosc()const{return szybkosc;}
    double get_dlugosc()const{return dlugosc;}
    double get_kat()const{return kat;}

    double &set_szybkosc(){return szybkosc;}
    double &set_dlugosc(){return dlugosc;}
    double &set_kat(){return kat;}
};
#endif