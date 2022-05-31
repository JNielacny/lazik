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
        shared_ptr<Lazik> uzywany;
        list<shared_ptr<Lazik>> ListaObiektow;

        void Inicjalizuj_Lacze();

    public:
        scena();
        void Rysuj();
        void porusz(double kat, double ruch, double szybkosc);
        void DodajDoListyRysowania();
        void wypisz();
        void wybordrona(int k);
        string nazwauzywanego(){return uzywany->WezNazweObiektu();}
        Wek3D polozenieuzywanego(){return uzywany->get_przesuniecia();}
};

#endif