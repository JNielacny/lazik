#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"



using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}


bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(ostream &StrmWy, istream &StrmWe)
{
  int Indeks_Wiersza = 0;
  
  StrmWe >> Ukl.set_wsp();

  if (StrmWe.fail())return false;
  
  do {
    Ukl.set_wsp() = Ukl.get_wsp()^Ukl.get_skala() + Ukl.get_przesuniecia();
    StrmWy << Ukl.get_wsp() << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> Ukl.set_wsp();
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  int Indeks_Wiersza = 0;
  
  StrmWe >> Ukl.set_wsp();

  if (StrmWe.fail())return false;
  
  do {
    Ukl.set_wsp() = Ukl.get_wsp()^Ukl.get_skala() + Ukl.get_przesuniecia();
    StrmWy << Ukl.get_wsp() << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> Ukl.set_wsp();
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
