#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz<STyp,SWymiar>, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Mac3D RotacjaZ(double kat)
{
  Mac3D Obrot;
  double radian = kat*M_PI/180;

  Obrot[0][0]=cos(radian);
    Obrot[0][1]=-sin(radian);
      Obrot[0][2]=0;
  
  Obrot[1][0]=sin(radian);
    Obrot[1][1]=cos(radian);
      Obrot[1][2]=0;
  
  Obrot[2][0]=0;
    Obrot[2][1]=0;
      Obrot[2][2]=1;

  return Obrot;
}