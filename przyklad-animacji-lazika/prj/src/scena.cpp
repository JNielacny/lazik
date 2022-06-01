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
        
        string regol[]={"Coulettes","Salette","Dourbes","Robine","Quartier","Bellegarde","Montdenier","Montagnac","Guillaumes","Roubion"};
        string nazwa[]={"FSR","Perseverance","Curiosity","Pelra","Kustosz","Lech"};
        
        int kolor[]={Kolor_Czerwony,Kolor_Zielony,Kolor_JasnoNiebieski,Kolor_Czarny,Kolor_Zolty,Kolor_Fioletowy};

    /*
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
    */


        shared_ptr<Lazik> Ob;
        for(int iter=0; iter<6; iter++)
        {
        przesun[0]=-120 + (40*iter);
            Ob = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat",nazwa[iter].c_str(),kolor[iter]);
                Ob->set_przesuniecia()=przesun;
                    Ob->set_skala()=skala;
                        ListaObiektow.push_back(Ob);       
                            ListaLazikow.push_back(Ob);     
        }

        uzywany = Ob;

        for(int iter=0; iter<10; iter++)
        {
            przesun[0]=rand()%180-90;
                przesun[1]=rand()%180-90;
            
            skala[0]=4;
                skala[1]=4;
                    skala[2]=4;

            shared_ptr<PrbRegol> Prb;
                Prb = make_shared<PrbRegol>("bryly_wzorcowe/szescian3.dat",regol[iter].c_str(),Kolor_JasnoNiebieski);
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
        for(list<shared_ptr<ObiektGeom>>::iterator iter=ListaObiektow.begin(); iter!=ListaObiektow.end(); iter++)
        {
            wInfoPliku = &Lacze.DodajNazwePliku((*iter)->WezNazwePliku_BrylaRysowana());
            wInfoPliku->ZmienKolor((*iter)->WezKolorID());
        }
    }

    void scena::wyborlazika(int wyb)
    {
        list<shared_ptr<ObiektGeom>>::iterator iter = ListaLazikow.begin();

        for(int laziory=0;laziory<wyb;laziory++,iter++)
        {   
            uzywany=dynamic_pointer_cast<Lazik> (*iter);
        }
    }

    void scena::wypisz()
    {
        int wyb=0;
        for (list<shared_ptr<ObiektGeom>>::iterator iter = ListaObiektow.begin();iter!=ListaObiektow.end()    ; iter++)
        {
            wyb++;
            cout <<wyb<<":"<< (*iter)->WezNazweObiektu() << endl;
        }
    }

    void scena::wypiszlaziki()
    {
        int ten=0;
        for (list<shared_ptr<ObiektGeom>>::iterator iter = ListaLazikow.begin();iter!=ListaLazikow.end()    ; iter++)
        {
            ten++;
            cout <<ten<<":"<< (*iter)->WezNazweObiektu() << endl;
        }
    }