#ifndef JEU2048_H
#define JEU2048_H

#include <math.h>
#include <time.h>

class Jeu2048 {
public:
    Jeu2048();
    void PlacerNouvelleTuile();
    bool Calculer(const char _direction);
    void Deplacer(const char _direction);
    int CalculerScore();
    void ObtenirGrille(int _grille[][4]);
    
    enum ETATS_DU_JEU
    {
        EN_COURS = 1,
        PERDU,
        GAGNE
    };
    
    ETATS_DU_JEU RechercherFinDePartie();
    
private:
    int grille[4][4];
};

#endif /* JEU2048_H */

