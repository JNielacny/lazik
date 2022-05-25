#ifndef SCENA_HH
#define SCENA_HH
#include <memory>
#include <list>
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "lazik.hh"
#include "Kolory.hh"
#include "unistd.h"

using namespace std;

class scena
{
    private:
        PzG::LaczeDoGNUPlota Lacze;
        shared_ptr<Lazik> ten;
        list<shared_ptr<Lazik>> ListaObiektow;

        void Inicjalizuj_Lacze();

    public:
        scena();
        void Rysuj();
        void Jedz(double kat);
        void DodajDoListyRysowania();
        shared_ptr<Lazik> get_Lazik(int p);
};

#endif