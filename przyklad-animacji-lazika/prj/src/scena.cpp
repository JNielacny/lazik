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
        Inicjalizuj_Lacze();
        Inicjalizuj_PowierzchnieMarsa(Lacze);

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

        Lacze.Rysuj();
    }

    void scena::Jedz(double kat)
    {
        for(int i=0; i<kat; i++)
        {
            ten->Przelicz_i_Zapisz_Wierzcholki();
        }
        
    }

    void scena::Rysuj()
    {
        Wek3D wektor;
            wektor[0]=20;
            wektor[1]=20;
            wektor[2]=10;
        
        for(list<shared_ptr<Lazik>>::iterator i=ListaObiektow.begin(); i!=ListaObiektow.end(); i++)
        {
            (*i)->set_skala() = wektor;
            (*i)->Przelicz_i_Zapisz_Wierzcholki();
            usleep(10000);
            Lacze.Rysuj();
        }


        Lacze.Rysuj();
        cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
        cin.ignore(100,'\n');
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
    
    shared_ptr<Lazik> scena::get_Lazik(int p)
    {
    int k=0;
        list<shared_ptr<Lazik>>::iterator i=ListaObiektow.begin(); 
            for(;k<p; p++, i++)
            {
                cout<<(*i)->WezNazweObiektu() << endl;
            }
            return *i;
    }
