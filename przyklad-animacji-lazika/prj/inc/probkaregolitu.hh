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
    
    Tkolizji CzyKolizja(shared_ptr<Lazik> &laz)
    {
        return TK_BrakKolizji;
    }
};