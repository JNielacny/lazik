#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"
#include "probkaregolitu.hh"
#include "lacze_do_gnuplota.hh"
#include "unistd.h"


class LazikFSR: public Lazik
{
    private:
    list<shared_ptr<PrbRegol>> ListaProbek;
    public:
    Tkolizji SprawdzKolizje(shared_ptr<ObiektGeom> lazik)
    {
        if(zczytaj((*lazik).get_obrys()))
        {
            if(lazik->rozpoznaj() == 2)
            return TK_Kolizja;

            if(lazik->rozpoznaj() == 3)
            return TK_PrzejazdNadProbka;
        }
        else
        return TK_BrakKolizji;
    }

    void podnies(shared_ptr<PrbRegol> lazik)
    {
        ListaProbek.push_back(lazik);
    }

};

class Lazik: public ObiektGeom
{
    private:
    double szybkosc;
    double dlugosc;
    double kat;
    double wypadkowa;

    public:
    /*Lazik(){wypadkowa=0;}*/
    Lazik(const char *sNazwaPliku_BrylaWzorcowa, 
          const char *sNazwaObiektu, 
          int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa, 
                                   sNazwaObiektu, 
                                   KolorID)
                                   {wypadkowa=0;}

    int rozpoznaj(){return 2;}


    Tkolizji SprawdzKolizje(shared_ptr<ObiektGeom> lazik)
    {
        if(zczytaj((*lazik).get_obrys()))
        {
            return TK_Kolizja;
        }
        else
        return TK_BrakKolizji;
    }

    void jedz(PzG::LaczeDoGNUPlota &Lacze, list<shared_ptr<ObiektGeom>> &ListaObiektow, shared_ptr<Lazik> uzywany)
    {
        
        Wek3D dane;
        dane[1]=szybkosc;
        
        for(double i=0; i<dlugosc; i = i + szybkosc)
        {
            for(list<shared_ptr<ObiektGeom>>::iterator i = ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
            {
                if(uzywany!=(dynamic_pointer_cast<Lazik>(*i)))
                {
                    if(SprawdzKolizje((*i))==TK_Kolizja)
                    {
                        cout << "Kolizja - zatrzymano" << endl;
                        return;
                    }
                }
            }
            set_zmien_polozenie()=get_przesuniecia()+(RotacjaZ(wypadkowa) * dane);
                Przelicz_i_Zapisz_Wierzcholki();
                    Lacze.Rysuj();

            usleep(10000);
        }
    }

    void obroc(PzG::LaczeDoGNUPlota &Lacze)
    {        
        for(int i=0; i<kat; i+=1)
        {
            obrot();
                Przelicz_i_Zapisz_Wierzcholki();
                    Lacze.Rysuj();

            usleep(5000);
        }
        for(int i=kat; i<0; i+=1)
        {
            obrot_alt();
                Przelicz_i_Zapisz_Wierzcholki();
                    Lacze.Rysuj();

            usleep(5000);
        }
    }

    void obrot()
    {
        wypadkowa+=1;
            set_MacObrotu()=RotacjaZ(wypadkowa);
                if(wypadkowa==360){wypadkowa=0;}
    }

    void obrot_alt()
    {
        wypadkowa-=1;
            set_MacObrotu()=RotacjaZ(wypadkowa);
                if(wypadkowa==-360){wypadkowa=0;}
    }

    /*
    void kolko()
    {
        for(int i=0;i==36;i++)
        {
            
        }
    }*/

    virtual void podnies(shared_ptr<PrbRegol> lazik) = 0;

    double get_szybkosc()const{return szybkosc;}
    double get_dlugosc()const{return dlugosc;}
    double get_kat()const{return kat;}

    double &set_szybkosc(){return szybkosc;}
    double &set_dlugosc(){return dlugosc;}
    double &set_kat(){return kat;}
};
#endif