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
        Wek3D przesun;
        przesun[0]=50;
        Inicjalizuj_Lacze();
        Inicjalizuj_PowierzchnieMarsa(Lacze);

        shared_ptr<Lazik>  Ob1;
            Ob1 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski);
                Ob1->set_przesuniecia()=przesun;
                    ListaObiektow.push_back(Ob1);

        shared_ptr<Lazik>  Ob2;
            Ob2 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony);
                przesun[0]=-50;
                    Ob2->set_przesuniecia()=przesun;
                        ListaObiektow.push_back(Ob2);
     
        shared_ptr<Lazik>  Ob3;
            Ob3 = make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony);  
                ListaObiektow.push_back(Ob3);
    
        uzywany = Ob1;

    }

    void scena::Jedz(double kat)
    {
        for(int i=0; i<kat; i++)
        {
            uzywany->set_zadany()=kat;
            usleep(5000);
            Rysuj();
        }
        for(int i=kat; i<0; i++)
        {
            uzywany->set_zadany()=kat;  
            usleep(5000);
            Rysuj();
        }
    }



    void scena::Rysuj()
    {
        Wek3D wektor;
            wektor[0]=20;
            wektor[1]=20;
            wektor[2]=10;
        
        for(list<shared_ptr<Lazik>>::iterator iter=ListaObiektow.begin(); iter!=ListaObiektow.end(); iter++)
        {
            (*iter)->set_skala() = wektor;
            (*iter)->Przelicz_i_Zapisz_Wierzcholki();
        }

        Lacze.Rysuj();
    /*    cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
        cin.ignore(100,'\n');*/
    }

    void scena::DodajDoListyRysowania()
    {
        PzG::InfoPlikuDoRysowania *wInfoPliku;        
        for(list<shared_ptr<Lazik>>::iterator i=ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
        {
            wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
            wInfoPliku->ZmienKolor((*i)->WezKolorID());
        }
    }

    void scena::wybordrona(int p)
    {
        list<shared_ptr<Lazik>>::iterator i = ListaObiektow.begin();
        for(int k=0;k<p;k++,i++)
        {
            uzywany=(*i);
        }
    }

    void scena::wypisz()
    {
        int k=0;
        for (list<shared_ptr<Lazik>>::iterator i = ListaObiektow.begin();i!=ListaObiektow.end(); i++)
        {
            k++;
            cout <<k<<":"<< (*i)->WezNazweObiektu() << endl;
        }
    }