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
    
    Tkolizji SprawdzKolizje(shared_ptr<ObiektGeom> lazik)
    {
        return TK_BrakKolizji;
    }
};