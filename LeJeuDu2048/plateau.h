#ifndef PLATEAU_H
#define PLATEAU_H

#include "jeu2048.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

class Plateau
{
public:
    Plateau();
    void Afficher();
    bool JouerCoup();
    
private:
    int nbCoups;
    int score;
    Jeu2048 leJeu;
};

#endif /* PLATEAU_H */

