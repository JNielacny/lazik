#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"


using namespace std;




/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}



int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  
  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  ObiektGeom  Ob1("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski);
  ObiektGeom  Ob2("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony);
  ObiektGeom  Ob3("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony);  

  DodajDoListyRysowania(Lacze,Ob1);
  DodajDoListyRysowania(Lacze,Ob2);
  DodajDoListyRysowania(Lacze,Ob3);

  
  Ob1.Przelicz_i_Zapisz_Wierzcholki(20,20,10,0,0,0);
  Ob2.Przelicz_i_Zapisz_Wierzcholki(20,20,10,60,60,0);
  Ob3.Przelicz_i_Zapisz_Wierzcholki(20,20,10,-20,70,0);  
  
  cout << endl << "Start programu gnuplot" << endl << endl;
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  Ob1.Przelicz_i_Zapisz_Wierzcholki(20,20,10,20,0,0);
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  Ob1.Przelicz_i_Zapisz_Wierzcholki(20,20,10,40,0,0);
  Lacze.Rysuj();
  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
}
