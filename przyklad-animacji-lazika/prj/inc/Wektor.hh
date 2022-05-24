#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>

using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>

class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  private:
  STyp Tab[SWymiar];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  /*
  STyp &set_Tab(int x);
  STyp get_Tab(int x);
  */
 
  STyp &operator [](int x);
  STyp operator [](int x) const;

  Wektor operator ^(Wektor const Skl);
  Wektor operator +(Wektor Wart);  /*Wart w sensie wartość komórki*/
  Wektor operator -(Wektor Wart);
  Wektor operator *(STyp Wart);
  Wektor operator /(STyp Wart);
  STyp operator *(Wektor Wart);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

template <typename STyp, int SWymiar>

Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator ^(Wektor const Skl)
{
  Wektor Wynik;
  for(int i = 0; i<SWymiar; i++)
    Wynik[i] = Tab[i] * Skl[i];
}

template <typename STyp, int SWymiar>

std::istream& operator >> (std::istream &Strm, Wektor<STyp, SWymiar> &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<STyp, SWymiar>  &Wek);


    /*
  STyp &Wektor<STyp, SWymiar> ::set_Tab(int x)
  {-
      return Tab[x];
  }
  STyp Wektor<STyp, SWymiar> ::get_Tab(int x)
  {
      return Tab[x];
  } */
  template <typename STyp, int SWymiar>
  STyp &Wektor<STyp, SWymiar> ::operator [](int x)
  {
      if(x<0 || x>=SWymiar)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }
  
  template <typename STyp, int SWymiar>
  STyp Wektor<STyp, SWymiar> ::operator [](int x) const
  {
      if(x<0 || x>=SWymiar)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator +(Wektor<STyp, SWymiar>  Wart)
  {
      Wektor<STyp, SWymiar>  Roznica;
      for(int x=0; x<SWymiar; x++)
        Roznica[x] = Tab[x] + Wart[x];
      return Roznica; 
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator -(Wektor<STyp, SWymiar>  Wart)
  {
      Wektor<STyp, SWymiar>  Roznica;
      for(int x=0; x<SWymiar; x++)
        Roznica[x] = Tab[x] - Wart[x];
      return Roznica; 
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator *(STyp Wart)
  {
      Wektor<STyp, SWymiar>  Iloczyn;
      for(int x=0; x<SWymiar; x++)
        Iloczyn[x] = Tab[x] * Wart;
      return Iloczyn;
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator /(STyp Wart)
  {
      Wektor<STyp, SWymiar>  Iloraz;
      for(int x=0; x<SWymiar; x++)
        Iloraz[x] = Tab[x] / Wart;
      return Iloraz;
  }

  template <typename STyp, int SWymiar>
  STyp Wektor<STyp, SWymiar> ::operator *(Wektor<STyp, SWymiar>  Wart)
  {
      STyp Skalar;
      Skalar=0;
      for(int x=0; x<SWymiar; x++)
        Skalar += Tab[x] * Wart[x];
      return Skalar;
  }

  template <typename STyp, int SWymiar>
  std::istream &operator >> (std::istream &Strm, Wektor<STyp, SWymiar>  &Wek)
  {
      for(int x=0; x<SWymiar; x++)
        Strm>>Wek[x];
      return Strm;
  }

  template <typename STyp, int SWymiar>
  std::ostream &operator << (std::ostream &Strm, const Wektor<STyp, SWymiar>  &Wek)
  {
      cout<<"|";
      for(int x=0; x<SWymiar; x++)
        Strm<<Wek[x]<<"  ";
      cout<<"|";
      return Strm;
  }

typedef Wektor<double,3> Wek3D;


#endif
