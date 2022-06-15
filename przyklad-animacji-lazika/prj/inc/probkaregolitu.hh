#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"

using namespace std;

class PrbRegol:public ObiektGeom
{
    public:
    PrbRegol(const char *sNazwaPliku_BrylaWzorcowa, 
          const char *sNazwaObiektu, 
          int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa, 
                                   sNazwaObiektu, 
                                   KolorID)
                                   {}
    int rozpoznaj(){return 3;}
    Tkolizji SprawdzKolizje(shared_ptr<ObiektGeom> lazik)
    {
        return TK_BrakKolizji;
    }
};

#endif