#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"
#include "probkaregolitu.hh"
#include "lacze_do_gnuplota.hh"
#include "unistd.h"

class Lazik: public ObiektGeom
{
    private:
    double szybkosc;
    double dlugosc;
    double kat;
    double wypadkowa;

    list<shared_ptr<PrbRegol>> ListaProbek;


    public:
    Lazik(){wypadkowa=0;}
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
            if(lazik->rozpoznaj() == 2)
            return TK_Kolizja;

            if(lazik->rozpoznaj() == 3)
            return TK_PrzejazdNadProbka;
        }
        return TK_BrakKolizji;
    }

    void jedz(PzG::LaczeDoGNUPlota &Lacze, list<shared_ptr<ObiektGeom>> &ListaObiektow, shared_ptr<Lazik> uzywany)
    {
        
        Wek3D dane;
        dane[1]=szybkosc;
        int d=0;
        for(double i=0; i<dlugosc; i = i + szybkosc)
        {
            for(list<shared_ptr<ObiektGeom>>::iterator i = ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
            {
                if(uzywany!=(dynamic_pointer_cast<Lazik>(*i)))
                {
                    if(SprawdzKolizje((*i))==TK_Kolizja)
                    {
                        cout << "--------------------------------------------------------------" << endl;
                        cout <<         "!!!!! KOLIZJA - lazik zostal zatrzymany !!!!!" << endl;
                        cout << "--------------------------------------------------------------" << endl;
                        return;
                    }

                    else
                    if(SprawdzKolizje((*i))==TK_PrzejazdNadProbka)
                    {
                        for(d=d; d<1; d++)
                        {
                            cout << "--------------------------------------------------------------" << endl;
                            cout <<                  "!!!!! Wykryto próbke!!!!!" << endl;
                            cout << "--------------------------------------------------------------" << endl;
                        } 
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

    void podnies(shared_ptr<PrbRegol> lazik)
    {
        ListaProbek.push_back(lazik);
    }

    
    void wypiszprobki()
    {
        int ten=0;
        for (list<shared_ptr<PrbRegol>>::iterator iter = ListaProbek.begin();iter!=ListaProbek.end()    ; iter++)
        {
            ten++;
            cout <<ten<<":"<< (*iter)->WezNazweObiektu() << endl;
        }
    }

    double get_szybkosc()const{return szybkosc;}
    double get_dlugosc()const{return dlugosc;}
    double get_kat()const{return kat;}

    double &set_szybkosc(){return szybkosc;}
    double &set_dlugosc(){return dlugosc;}
    double &set_kat(){return kat;}
};


class LazikFSR: public Lazik
{
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
};
#endif