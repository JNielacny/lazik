#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
#include <cmath>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template <typename STyp, int SWymiar>
class Macierz {
  private:  
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Wektor<STyp,SWymiar> Tab[SWymiar];
  STyp Wyzn;

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  STyp get_Wyzn()const{return Wyzn;};
  Wektor<STyp,SWymiar> &operator [](int x);
  Wektor<STyp,SWymiar> operator [](int x) const;
  Wektor<STyp,SWymiar> operator*(Wektor<STyp,SWymiar> Wart);    
  void Zamien(Wektor<STyp,SWymiar> wekt, int x);
  void Gauss();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>

std::istream& operator >> (std::istream &Strm, Macierz<STyp, SWymiar> &Matrix);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>

std::ostream& operator << (std::ostream &Strm, const Macierz<STyp, SWymiar> &Matrix);

  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> &Macierz<STyp,SWymiar>::operator [](int x)
  {
    return Tab[x];
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator [](int x) const
  {
    return Tab[x];
  }

  template <typename STyp, int SWymiar>
  std::istream& operator >> (std::istream &Strm, Macierz<STyp,SWymiar> &Matrix)
  {
    for(int x=0; x<SWymiar; x++)
    Strm>>Matrix[x];
    return Strm;
  }

  template <typename STyp, int SWymiar>
  std::ostream& operator << (std::ostream &Strm, const Macierz<STyp,SWymiar> &Matrix)
  {
    for(int x=0; x<SWymiar; x++)
    Strm<<Matrix[x]<<endl;
    return Strm;
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator*(Wektor<STyp,SWymiar> Wart)
  {
    int x;
    Wektor<STyp,SWymiar> Suma;
    Wektor<STyp,SWymiar> Sumka;
      for(x=0; x<SWymiar; x++)
      {
        Sumka=Sumka+Tab[x]*Wart[x];
      }
      Suma=Sumka;
      return Suma;
  }

  template <typename STyp, int SWymiar>
  void Macierz<STyp,SWymiar>::Zamien(Wektor<STyp,SWymiar> wekt, int x)
  {
    Tab[x]=wekt;
  }

typedef Macierz<double,3> Mac3D;

Mac3D RotacjaZ(double kat);

#endif
