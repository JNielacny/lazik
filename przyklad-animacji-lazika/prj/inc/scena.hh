#ifndef SCENA_HH
#define SCENA_HH
#include <memory>
#include <list>
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "lazik.hh"
#include "Kolory.hh"
#include <unistd.h>
#include "probkaregolitu.hh"
#include "ObiektGeom.hh"

using namespace std;

class scena
{
    private:
        PzG::LaczeDoGNUPlota Lacze;
        shared_ptr<Lazik> uzywany;

        list<shared_ptr<ObiektGeom>> ListaObiektow;
        list<shared_ptr<ObiektGeom>> ListaLazikow;


        void Inicjalizuj_Lacze();

    public:
        scena();
    
        void porusz(double kat, double ruch, double szybkosc);
        void wyborlazika(int wyb);

        void Rysuj();
        void DodajDoListyRysowania();
        
        void wypisz();
        void wypiszlaziki();

        void usun();

        string nazwauzywanego(){return uzywany->WezNazweObiektu();}
        Wek3D polozenieuzywanego(){return uzywany->get_przesuniecia();}
};

#endif