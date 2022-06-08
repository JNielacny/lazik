#include <iostream>
#include <fstream>
#include <vector>
#include "ObiektGeom.hh"
#include "obrys.hh"


using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
            for(int k=0; k<3; k++)
            MacObrotu[k][k]=1;
  zadany=0;
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}


bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(ostream &StrmWy, istream &StrmWe)
{
  int Indeks_Wiersza = 0;
  
  StrmWe >> set_wsp();

  if (StrmWe.fail())return false;
  
  do {
    set_wsp() = (get_wsp()^get_skala()) + get_przesuniecia();
    StrmWy << get_wsp() << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> set_wsp();
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  vector<double> wspx;
  vector<double> wspy;

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  int Indeks_Wiersza = 0;
  
  StrmWe >> set_wsp();

  if (StrmWe.fail())return false;
  do {
    wspx.push_back(get_wsp()[0]);
    wspy.push_back(get_wsp()[1]);

    set_wsp()=MacObrotu*get_wsp();
    set_wsp() = (get_wsp()^get_skala()) + przesuniecia;
    StrmWy << get_wsp() << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> set_wsp();
    
  } while (!StrmWe.fail());
  /*  set_W_dolny_lewy()[0]=*min_element(wspx.begin(), wspx.end());
      set_W_gorny_prawy()[0]=*min_element(wspy.begin(), wspy.end()); */

  if (!StrmWe.eof()) return false;
  zadany =0;  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
