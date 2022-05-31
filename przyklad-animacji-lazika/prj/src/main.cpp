#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "lazik.hh"
#include "scena.hh"
#include "Kolory.hh"
#include "Wektor.hh"

using namespace std;




/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void wyswietlm()
{
    cout << "j - jazda na wprost" << endl;
    cout << "o - zmien orientacje" << endl;
    cout << "w - wybor lazika" << endl;
    cout << "m - wyswietl menu" << endl;
    cout << "q - wyjdz" << endl;
}

int main()
{
  scena Scena;

  Scena.Rysuj();
  Wek3D wektor;
  double kat;
  double szybkosc;
  double droga;
  char wybor = ' ';
  int ktory;

  wyswietlm();
  while (wybor!='q')
  {
    cout << endl;
    wektor.zwrocinfo();
    cout << endl;
    cout << "Aktywny lazik" << endl;
    cout << "Nazwa: " << Scena.nazwauzywanego() << endl;
    cout << "Polozenie (x,y,z): " << Scena.polozenieuzywanego() << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 'm':
      wyswietlm();
    break;

    case 'j':
      cout << "podaj droge" << endl;
      cin >> szybkosc;
      cin >> droga;
      Scena.porusz(0,szybkosc,droga);
    break;

    case 'o':
      cout << "podaj kat" << endl;
      cin >> kat;
      Scena.porusz(kat,0,0);
    break;
    
    case 'w':
      Scena.wypisz();
      cin >> ktory;
      Scena.wybordrona(ktory);
      break;
    
    case 'q':
      cout << "Prgoram został zamkniety" << endl;
      return 0;
      break;      
    
    default:
      break;  

    }
  }
}