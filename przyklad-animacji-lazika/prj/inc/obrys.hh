#include "Wektor.hh"

using namespace std;

class obrys
{
    private:
    Wek2D W_dolny_lewy;
    Wek2D W_gorny_prawy;

    public:
    Wek2D &set_W_dolny_lewy(){return W_dolny_lewy;}
    Wek2D &set_W_gorny_prawy(){return W_gorny_prawy;}    
    Wek2D get_W_dolny_lewy()const{return W_dolny_lewy;}
    Wek2D get_W_gorny_prawy()const{return W_gorny_prawy;}
};