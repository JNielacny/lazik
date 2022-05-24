#include <fstream>
#include <iostream>
#include "PowierzchniaMarsa.hh"

using namespace std;


#define NAZWA_PLIKU__POWIERZCHNIA_PLANETY "pliki_do_rysowania/powierzchnia_planety.dat"



/*!
 * Zapisuje do strumienia siatkę punktów, które tworzą model
 * powierzchni planety.
 * \param[in] rStrmWy - strumień wyjściowy, do którego
 *                          zapisana jest siatka punktów.
 * \retval true - operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool UtworzPowierzchnie_ZapiszDoPliku(ofstream  &rStrmWy)
{
  for (double WspY = -ROMIAR_POWIERZCHNI_Y/2;
       WspY <= ROMIAR_POWIERZCHNI_Y/2;
       WspY += ROZMIAR_OCZKA_KRATY) {

     for (double WspX = -ROMIAR_POWIERZCHNI_X/2;
           WspX <= ROMIAR_POWIERZCHNI_X/2;
           WspX += ROZMIAR_OCZKA_KRATY) {
       rStrmWy << WspX << "  " << WspY << " 0" << endl;
     }
     rStrmWy << endl;
  }
  return !rStrmWy.fail();
}





/*!
 * Zapisuje do pliku siatkę punktów, które tworzą model
 * powierzchni planety.
 * \param[in] sNazwaPliku - nazwa pliku, do którego ma być
 *                          zapisana siatka punktów
 * \retval true - operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool UtworzPowierzchnie_ZapiszDoPliku(const char* sNazwaPliku)
{
  ofstream  StrmWy(sNazwaPliku);
  if (!StrmWy.is_open()) {
    cerr << endl
	 << ":( Nie powiodlo sie otwarcie do zapisu pliku: \""
	 << sNazwaPliku << "\"" << endl
	 << endl;
    return false;
  }
  return UtworzPowierzchnie_ZapiszDoPliku(StrmWy);
}





/*!
 * \brief Inicjalizuje model powierzchni Marsa
 *
 * Zapisuje do pliku powierzchnię w postaci siatki
 * oraz przekazuje nazwę tego pliku do łącza do gnuplota.
 * To spowoduje, że program gnuplot będzie rysował
 * powierzchnie na podstawie danych w tym pliku.
 * \param[in]  rLacze - zainicjalizowane łącze do gnuplota.
 *
 * \retval true - operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Inicjalizuj_PowierzchnieMarsa(
				    PzG::LaczeDoGNUPlota  &rLacze
				  )
{
  if (!UtworzPowierzchnie_ZapiszDoPliku(NAZWA_PLIKU__POWIERZCHNIA_PLANETY)) return false;

  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(NAZWA_PLIKU__POWIERZCHNIA_PLANETY);
  wInfoPliku->ZmienKolor(4);
  return true;
}
