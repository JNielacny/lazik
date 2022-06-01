#include "scena.hh"

using namespace std;


    void scena::Inicjalizuj_Lacze()
    {
        Lacze.ZmienTrybRys(PzG::TR_3D);
        Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
        Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
        Lacze.UstawZakresZ(-0, 90);  
        Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
        Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    }


    
    scena::scena()
    {
        Wek3D skala;
            skala[0]=20;
            skala[1]=20;
            skala[2]=10;
        
        Wek3D przesun;
        przesun[0]=40;
        Inicjalizuj_PowierzchnieMarsa(Lacze);
        string regol[]={"1","2","3","4","5","6","7","8","9","10"};


        shared_ptr<Lazik>  Ob1;
            Ob1 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski);
                Ob1->set_przesuniecia()=przesun;
                    Ob1->set_skala()=skala;
                        ListaObiektow.push_back(Ob1);

        shared_ptr<Lazik>  Ob2;
            Ob2 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony);
                przesun[0]=-40;
                    Ob2->set_przesuniecia()=przesun;
                        Ob2->set_skala()=skala;
                            ListaObiektow.push_back(Ob2);
     
        shared_ptr<Lazik>  Ob3;
            Ob3 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony);  
                Ob3->set_skala()=skala;
                    ListaObiektow.push_back(Ob3);
    
        uzywany = Ob1;

        for(int i=0; i<10; i++)
        {
            przesun[0]=rand()%180-90;
                przesun[1]=rand()%180-90;
            
            skala[0]=4;
                skala[1]=4;
                    skala[2]=4;

            shared_ptr<PrbRegol> Prb;
                Prb = make_shared<PrbRegol>("bryly_wzorcowe/szescian3.dat",regol[i].c_str(),Kolor_JasnoNiebieski);
                    Prb->set_przesuniecia()=przesun;
                        Prb->set_skala()=skala;
                            ListaObiektow.push_back(Prb);
                
        }

        DodajDoListyRysowania();
        Inicjalizuj_Lacze();
        Rysuj();
        Lacze.Rysuj();
    }

    void scena::porusz(double kat, double ruch, double szybkosc)
    {
        uzywany->set_szybkosc()=szybkosc;
        uzywany->set_dlugosc()=ruch;
        uzywany->set_kat()=kat;

        uzywany->jedz(Lacze);
        uzywany->obroc(Lacze);
    }



    void scena::Rysuj()
    {
        for(list<shared_ptr<ObiektGeom>>::iterator iter=ListaObiektow.begin(); iter!=ListaObiektow.end(); iter++)
        {
            (*iter)->Przelicz_i_Zapisz_Wierzcholki();
        }

        Lacze.Rysuj();
    /*    cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
        cin.ignore(100,'\n');*/
    }

    void scena::DodajDoListyRysowania()
    {
        PzG::InfoPlikuDoRysowania *wInfoPliku;        
        for(list<shared_ptr<ObiektGeom>>::iterator i=ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
        {
            wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
            wInfoPliku->ZmienKolor((*i)->WezKolorID());
        }
    }

    void scena::wybordrona(int p)
    {
        list<shared_ptr<ObiektGeom>>::iterator i = ListaObiektow.begin();
        for(int k=0;k<p;k++,i++)
        {
            /*uzywany=(*i);*/
        }
    }

    void scena::wypisz()
    {
        int k=0;
        for (list<shared_ptr<ObiektGeom>>::iterator i = ListaObiektow.begin();i!=ListaObiektow.end(); i++)
        {
            k++;
            cout <<k<<":"<< (*i)->WezNazweObiektu() << endl;
        }
    }