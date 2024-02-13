#include "jeu2048.h"

Jeu2048::Jeu2048()
{
    int i;
    int j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            grille[i][j] = 0;
        }
    }
    srand(time(nullptr));
    PlacerNouvelleTuile();
}

void Jeu2048::ObtenirGrille(int _grille[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _grille[i][j] = grille[i][j];
        }
    }
}

void Jeu2048::PlacerNouvelleTuile()
{
    int x = rand() % 4;
    int y = rand() % 4;
    int nb = (((rand() % 2) + 1) * 2);

    while (grille[y][x] != 0)
    {
        x = rand() % 4;
        y = rand() % 4;
    }
    grille[y][x] = nb;
}

void Jeu2048::Deplacer(char _direction)
{
    int ligne;
    int colonne;
    for (int indice = 0; indice < 4; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 3; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne + 1];
                        grille[ligne][colonne + 1] = 0;
                    }
                }
            }
            break;
        case 'D':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 3; colonne > 0; colonne--)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne - 1];
                        grille[ligne][colonne - 1] = 0;
                    }
                }
            }
            break;
        case 'B':
            for (ligne = 3; ligne > 0; ligne--)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne - 1][colonne];
                        grille[ligne - 1][colonne] = 0;
                    }
                }
            }
            break;
        case 'H':
            for (ligne = 0; ligne < 3; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne + 1][colonne];
                        grille[ligne + 1][colonne] = 0;
                    }
                }
            }
            break;
        }
    }
}

bool Jeu2048::Calculer(char _direction)
{
    int ligne;
    int colonne;
    bool retour = false;
    for (int indice = 0; indice < 4; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 3; colonne++)
                {
                    if (grille[ligne][colonne] == grille[ligne][colonne + 1] && grille[ligne][colonne] != 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne + 1]*2;
                        grille[ligne][colonne + 1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'D':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 3; colonne > 0; colonne--)
                {
                    if (grille[ligne][colonne] == grille[ligne][colonne - 1] && grille[ligne][colonne] != 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne - 1]*2;
                        grille[ligne][colonne - 1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'B':
            for (ligne = 3; ligne > 0; ligne--)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == grille[ligne - 1][colonne] && grille[ligne][colonne] != 0)
                    {
                        grille[ligne][colonne] = grille[ligne - 1][colonne]*2;
                        grille[ligne - 1][colonne] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'H':
            for (ligne = 0; ligne < 3; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == grille[ligne + 1][colonne] && grille[ligne][colonne] != 0)
                    {
                        grille[ligne][colonne] = grille[ligne + 1][colonne]*2;
                        grille[ligne + 1][colonne] = 0;
                        retour = true;
                    }
                }
            }
            break;
        }
    }
    return retour;
}

int Jeu2048::CalculerScore()
{
    int somme = 0;
    int ligne;
    int colonne;
    for (ligne = 0; ligne < 4; ligne++)
    {
        for (colonne = 0; colonne < 4; colonne++)
        {
            somme += grille[ligne][colonne];
        }
    }
    return somme;
}

Jeu2048::ETATS_DU_JEU Jeu2048::RechercherFinDePartie()
{
    int ligne;
    int colonne;
    int etat_case = 0;
    ETATS_DU_JEU result = EN_COURS;
    for (ligne = 0; ligne < 4; ligne++)
    {
        for (colonne = 0; colonne < 4; colonne++)
        {
            if (grille[colonne][ligne] == 2048)
            {
                result = GAGNE;
            } else if (grille[colonne][ligne] == 0)
            {
                etat_case +=1;
            }
        }
    }
    if (etat_case > 15)
    {
        result == PERDU;
    }
    return result;
}

//-796 68 -180