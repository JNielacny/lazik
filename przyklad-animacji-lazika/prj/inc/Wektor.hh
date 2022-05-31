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
  static int wektory;
  static int aktwektory;
  STyp Tab[SWymiar];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  /*
  STyp &set_Tab(int x);
  STyp get_Tab(int x);
  */
  Wektor(const Wektor& wektor);
  STyp &operator [](int x);
  STyp operator [](int x) const;

  Wektor operator ^(Wektor const Skl);
  Wektor operator +(Wektor const Wart);  /*Wart w sensie wartość komórki*/
  Wektor operator -(Wektor const Wart);
  Wektor operator *(STyp const Wart);
  Wektor operator /(STyp const Wart);
  STyp operator *(Wektor const 
  art);
  void zwrocinfo();
  constexpr Wektor<STyp, SWymiar>& operator=(const Wektor<STyp, SWymiar>& wektor);
  Wektor();
  ~Wektor();
};


template <typename STyp, int SWymiar>

constexpr Wektor<STyp, SWymiar>& Wektor<STyp, SWymiar>::operator=(const Wektor<STyp, SWymiar>& wektor)
{
  for(int i=0; i < SWymiar; i++)
  Tab[i]=wektor.Tab[i];
  return *this;
}


template <typename STyp, int SWymiar>

void Wektor<STyp,SWymiar>::zwrocinfo()
{
    cout << "Wszystkie obiekty: " << wektory << endl;
    cout << "Aktualne obiekty: " << aktwektory << endl;
}



template <typename STyp, int SWymiar>

Wektor<STyp,SWymiar>::Wektor()
{
  for(int i = 0; i<SWymiar; i++)
  Tab[i]=0;
  wektory++;
  aktwektory++;
}



template <typename STyp, int SWymiar>

Wektor<STyp,SWymiar>::~Wektor()
{
aktwektory--;
}


template <typename STyp, int SWymiar>

Wektor<STyp,SWymiar>::Wektor(const Wektor<STyp,SWymiar> &wektor)
{
  for(int i=0; i < SWymiar; i++)
  Tab[i]=wektor.Tab[i];
  aktwektory++;
}


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakies jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

template <typename STyp, int SWymiar>

int Wektor<STyp,SWymiar>::wektory=0;

template <typename STyp, int SWymiar>

int Wektor<STyp,SWymiar>::aktwektory=0;


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

Wektor<STyp,SWymiar>  Wektor<STyp, SWymiar> ::operator ^(Wektor const Skl)
{
  Wektor Wynik;
  for(int x = 0; x<SWymiar; x++)
    Wynik[x] = Tab[x] * Skl[x];
  
  return Wynik;
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
      for(int x=0; x<SWymiar; x++)
        Strm<<Wek[x]<<"  ";
      return Strm;
  }

typedef Wektor<double,3> Wek3D;


#endif
