#include <memory>
#include <list>
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "lazik.hh"
#include "Kolory.hh"

using namespace std;

class scena
{
    private:
    PzG::LaczeDoGNUPlota Lacze;
    shared_ptr<Lazik> ten;
    list<shared_ptr<Lazik>> ListaObiektow;
    
    void Inicjalizuj_Lacze()
    {
        Lacze.ZmienTrybRys(PzG::TR_3D);
        Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
        Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
        Lacze.UstawZakresZ(-0, 90);  
        Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

        Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    }


    public:
    scena()
    {
        Inicjalizuj_Lacze();

        shared_ptr<Lazik>  Ob1;
            Ob1 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski);
                ListaObiektow.push_back(Ob1);

        shared_ptr<Lazik>  Ob2;
            Ob2 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony);
                ListaObiektow.push_back(Ob2);
     
        shared_ptr<Lazik>  Ob3;
            Ob3 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony);  
                ListaObiektow.push_back(Ob3);
    
        ten = Ob1;
    }

    shared_ptr<Lazik> get_Lazik(int p)
    {
    int k=0;
        list<shared_ptr<Lazik>>::iterator i=ListaObiektow.begin(); 
            for(;k<p; p++, i++)
            return *i;
    }

    void DodajDoListyRysowania()
    {
        PzG::InfoPlikuDoRysowania *wInfoPliku;        
        for(list<shared_ptr<Lazik>>::iterator i=ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
        {
            wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
            wInfoPliku->ZmienKolor((*i)->WezKolorID());
        }
    }
};