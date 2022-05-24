#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "lazik.hh"
#include "scena.hh"
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


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  
  scena Scena;
  Wek3D wektor;
  wektor[0]=20;
  wektor[1]=20;
  wektor[2]=10;

  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  (*Scena.get_Lazik(0)).set_skala()=wektor;
  (*Scena.get_Lazik(0)).Przelicz_i_Zapisz_Wierzcholki();

  (*Scena.get_Lazik(1)).set_skala()=wektor;
  (*Scena.get_Lazik(1)).Przelicz_i_Zapisz_Wierzcholki();  
  
  (*Scena.get_Lazik(2)).set_skala()=wektor;
  (*Scena.get_Lazik(2)).Przelicz_i_Zapisz_Wierzcholki();  
  
  cout << endl << "Start programu gnuplot" << endl << endl;
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  (*Scena.get_Lazik(0)).Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  (*Scena.get_Lazik(0)).Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();
  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
}
