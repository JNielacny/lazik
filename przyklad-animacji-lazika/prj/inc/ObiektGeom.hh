#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "Wektor.hh"
#include "Macierz.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

using namespace std;

class UklWsp
{
    private:
    Wek3D wsp;
    Wek3D skala;
    Wek3D przesuniecia;
    Mac3D MacObrotu; 
    public:
    Wek3D &set_wsp(){return wsp;}
    Wek3D &set_skala(){return skala;}
    Wek3D &set_przesuniecia(){return przesuniecia;}
    Mac3D &set_MacObrotu(){return MacObrotu;}
    
    Wek3D get_wsp()const{return wsp;}
    Wek3D get_skala()const{return skala;}
    Wek3D get_przesuniecia()const{return przesuniecia;}
    Mac3D get_MacObrotu()const{return MacObrotu;}
};

class ObiektGeom {
    string   _NazwaPliku_BrylaWzorcowa;
    string   _NazwaPliku_BrylaRysowana;
    string   _NazwaObiektu;
    int           _KolorID;
    UklWsp Ukl;
  public:

    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    int WezKolorID() const { return _KolorID; }
  
    const string & WezNazweObiektu() const { return _NazwaObiektu; }
  
    const string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }

    bool Przelicz_i_Zapisz_Wierzcholki(
                  ostream &StrmWyj, 
                  istream &StrmWej
                  );
    bool Przelicz_i_Zapisz_Wierzcholki();

				     
};


#endif
