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



bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(
				      double  SkalaX, double SkalaY, double SkalaZ,
				      double  PolozenieX,
				      double  PolozenieY,
				      double  PolozenieZ
				    )
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

  double  WspX, WspY, WspZ;
  int Indeks_Wiersza = 0;
  
  StrmWe >> WspX >> WspY >> WspZ;

  if (StrmWe.fail())return false;
  
  do {
    WspX = WspX*SkalaX+PolozenieX;
    WspY = WspY*SkalaY+PolozenieY;    
    WspZ = WspZ*SkalaZ+PolozenieZ;
    StrmWy << WspX << " " << WspY << " " << WspZ << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> WspX >> WspY >> WspZ;
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
