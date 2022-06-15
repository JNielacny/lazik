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
    cout << "--------------------------------------------------------------" << endl;
    cout << "j - jazda na wprost" << endl;
    cout << "o - zmien orientacje" << endl;
    cout << "w - wybor lazika" << endl;
    cout << "m - wyswietl menu" << endl;
    cout << "p - wyswietl liste wszystkich obiektow" << endl;
    cout << "l - wyswietl liste wszystkich lazikow" << endl;
    cout << "q - wyjdz" << endl;
    cout << "--------------------------------------------------------------" << endl;

}

int main()
{
  int ktory;
  double kat;  
  double szybkosc;
  double droga;
  char wybor = ' ';
  Wek3D wektor;
  srand(time(0));

  scena Scena;
  Scena.Rysuj();  
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
      cin >> droga;      
      cin >> szybkosc;
      Scena.porusz(0,droga,szybkosc);
    break;

    /*
    case 'k':
    for(int i=0;i<180;i+=5)
    {
      Scena.porusz(5,0,0);
      Scena.porusz(0,5,5);
    };
    for(int i=0;i<360;i+=5)
    {
      Scena.porusz(-5,0,0);
      Scena.porusz(0,5,5);
    };
    for(int i=0;i<180;i+=5)
    {
      Scena.porusz(5,0,0);
      Scena.porusz(0,5,5);
    };
    */

    break;

    case 'o':
      cout << "podaj kat" << endl;
      cin >> kat;
      Scena.porusz(kat,0,0);
    break;
    
    case 'w':
      Scena.wypiszlaziki();
      cin >> ktory;
      Scena.wyborlazika(ktory);
      break;

    case 'p':
      cout << "--------------------------------------------------------------" << endl;
      Scena.wypisz();
      cout << "--------------------------------------------------------------" << endl;
      break;

    case 'l':
      cout << "--------------------------------------------------------------" << endl;
      Scena.wypiszlaziki();
      cout << "--------------------------------------------------------------" << endl;
      break;

    case 'z':
      Scena.usun();

    case 'q':
      cout << "Prgoram został zamkniety" << endl;
      return 0;
      break;      
    
    default:
      break;  

    }
  }
}