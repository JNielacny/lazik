#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "Wektor.hh"
#include "Macierz.hh"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

using namespace std;

class UklWsp
{
    protected:
    Wek3D wsp;
    Wek3D skala;

    public:

    Wek3D &set_wsp(){return wsp;}
    Wek3D &set_skala(){return skala;}
        
    Wek3D get_wsp()const{return wsp;}
    Wek3D get_skala()const{return skala;}
    
};

class ObiektGeom: public UklWsp
{
    protected:
    string   _NazwaPliku_BrylaWzorcowa;
    string   _NazwaPliku_BrylaRysowana;
    string   _NazwaObiektu;
    int           _KolorID;
    Wek3D przesuniecia;
    Mac3D MacObrotu; 

    double zadany;
    
    public:
    ObiektGeom(){        
            for(int k=0; k<3; k++)
            MacObrotu[k][k]=1;
    };
    
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    int WezKolorID() const { return _KolorID; }
    double &set_zadany(){return zadany;}
    const string & WezNazweObiektu() const { return _NazwaObiektu; }
    const string & WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }

    bool Przelicz_i_Zapisz_Wierzcholki(
                  ostream &StrmWy, 
                  istream &StrmWe
                  );
    bool Przelicz_i_Zapisz_Wierzcholki();


    
    Wek3D &set_zmien_polozenie(){return przesuniecia;}
    Wek3D &set_skala(){return skala;}
    Wek3D &set_przesuniecia(){return przesuniecia;}
    Mac3D &set_MacObrotu(){return MacObrotu;}

    Wek3D get_zmien_polozenie()const{return przesuniecia;}
    Wek3D get_przesuniecia(){return przesuniecia;}
    Wek3D get_skala(){return skala;}
    Mac3D get_MacObrotu(){return MacObrotu;}
};


#endif