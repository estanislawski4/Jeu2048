#include <cstdlib>
#include "plateau.h"

using namespace std;

int main(int argc, char** argv)
{
    Plateau lePlateau;
    
    lePlateau.Afficher();
    
    bool continuer;
    
    do {
        continuer = lePlateau.JouerCoup();
    } while (continuer == false);

    return 0;
}

