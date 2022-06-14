#include <iostream>
#include <fstream>
#include <vector>
#include "ObiektGeom.hh"


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

bool ObiektGeom::zczytaj(obrys przeszkoda)
{
  Wek2D l_lewa = Obrys.get_W_dolny_lewy();
  Wek2D p_lewa = Obrys.get_W_dolny_lewy();
  Wek2D l_prawa = przeszkoda.get_W_dolny_lewy();
  Wek2D p_prawa = przeszkoda.get_W_dolny_lewy();

  if((l_lewa[0]>p_lewa[0] && l_lewa[0]<p_prawa[0] && l_lewa[1]>p_lewa[1] && l_lewa[1]<p_prawa[1]) || (l_prawa[0]>p_lewa[0] && l_prawa[0]<p_prawa[0] && l_prawa[1]>p_lewa[1] && l_prawa[1]<p_prawa[1]) || (l_lewa[0]>p_lewa[0] && l_lewa[0]<p_prawa[0] && l_prawa[1]>p_lewa[1] && l_prawa[1]<p_prawa[1]) || (l_prawa[0]>p_lewa[0] && l_prawa[0]<p_prawa[0] && l_lewa[1]>p_lewa[1] && l_lewa[1]<p_prawa[1]))
  {
    return true;
  }
  else
  return false;
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
    Obrys.set_W_dolny_lewy()[0]=*min(wspx.begin(), wspx.end());
    Obrys.set_W_dolny_lewy()[1]=*min(wspy.begin(), wspy.end());
    Obrys.set_W_gorny_prawy()[0]=*max(wspx.begin(), wspx.end());
    Obrys.set_W_gorny_prawy()[1]=*max(wspy.begin(), wspy.end());

  if (!StrmWe.eof()) return false;
  zadany =0;  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
