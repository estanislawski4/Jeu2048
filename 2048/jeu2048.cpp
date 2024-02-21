/**
 * @file jeu2048.cpp
 * @brief Implémentation de la classe Jeu2048.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#include "jeu2048.h"

/**
 * @brief Constructeur de la classe Jeu2048.
 *
 * Ce constructeur initialise une nouvelle instance du jeu 2048 en mettant tous les éléments
 * de la grille à zéro, puis place une nouvelle tuile aléatoire sur la grille.
 * 
 * @details La grille est représentée par un tableau 2D de dimensions 4x4.
 * 
 * @post La grille est initialisée avec toutes les tuiles à zéro et une nouvelle tuile est placée.
 * 
 * @see PlacerNouvelleTuile()
 */

Jeu2048::Jeu2048()
{
    // Initialiser la grille avec des tuiles à zéro
    int i;
    int j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            grille[i][j] = 0;
        }
    }
    
    // Initialiser le générateur de nombres aléatoires
    srand(time(nullptr));
    
    // Placer une nouvelle tuile aléatoire sur la grille
    PlacerNouvelleTuile();
}

/**
 * @brief Obtient la copie de la grille du jeu 2048.
 *
 * Cette fonction copie la grille actuelle du jeu dans le tableau 2D fourni en argument.
 * 
 * @param _grille Tableau 2D de dimensions 4x4 dans lequel la grille du jeu sera copiée.
 * 
 * @pre Le tableau _grille doit avoir une taille de 4x4.
 * 
 * @post Le contenu de la grille du jeu est copié dans le tableau _grille.
 * 
 * @see Jeu2048
 */

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

/**
 * @brief Place une nouvelle tuile aléatoire sur la grille du jeu 2048.
 *
 * Cette fonction génère aléatoirement des coordonnées (x, y) sur la grille du jeu
 * et place une nouvelle tuile (2 ou 4) sur la case correspondante si elle est vide.
 * 
 * @details La génération des coordonnées et la valeur de la tuile sont déterminées de manière aléatoire.
 * 
 * @pre La fonction ToutesLesCasesOccupees() doit renvoyer false pour qu'une nouvelle tuile soit placée.
 * 
 * @post Une nouvelle tuile est placée sur la grille du jeu à une position aléatoire.
 * 
 * @see ToutesLesCasesOccupees()
 * @see Jeu2048
 */

void Jeu2048::PlacerNouvelleTuile()
{
    // Générer des coordonnées aléatoires
    int x = rand() % 4;
    int y = rand() % 4;
    
    // Générer une nouvelle tuile aléatoire (2 ou 4)
    int nb = (((rand() % 2) + 1) * 2);

    // Vérifier si toutes les cases sont occupées
    if (Jeu2048::ToutesLesCasesOccupees() != true)
    {
        // Chercher une case vide
        while (grille[y][x] != 0)
        {
            x = rand() % 4;
            y = rand() % 4;
        }
        
        // Placer la nouvelle tuile sur la case vide
        grille[y][x] = nb;
    }
}

/**
 * @brief Déplace les tuiles de la grille dans la direction spécifiée.
 *
 * Cette fonction déplace les tuiles de la grille dans la direction spécifiée (G, D, B, H).
 * Les tuiles vides sont déplacées vers la direction indiquée, et les tuiles adjacentes sont fusionnées
 * si elles ont la même valeur.
 * 
 * @param _direction La direction dans laquelle déplacer les tuiles (G pour gauche, D pour droite, B pour bas, H pour haut).
 * 
 * @post Les tuiles de la grille sont déplacées dans la direction spécifiée.
 * 
 * @see Jeu2048
 */

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
                    // Déplacer les tuiles vides vers la gauche
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
                    // Déplacer les tuiles vides vers la droite
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
                    // Déplacer les tuiles vides vers le bas
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
                    // Déplacer les tuiles vides vers le haut
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

/**
 * @brief Calcule les fusions des tuiles dans la grille en fonction de la direction spécifiée.
 *
 * Cette fonction parcourt la grille et fusionne les tuiles adjacentes ayant la même valeur
 * dans la direction spécifiée (G pour gauche, D pour droite, B pour bas, H pour haut).
 * 
 * @param _direction La direction dans laquelle effectuer les calculs de fusion.
 * 
 * @return true si des fusions ont été effectuées, false sinon.
 * 
 * @post Les tuiles de la grille sont fusionnées en fonction de la direction spécifiée.
 * 
 * @see Jeu2048
 */

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
                    // Fusionner les tuiles adjacentes ayant la même valeur (non nulle)
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
                    // Fusionner les tuiles adjacentes ayant la même valeur (non nulle)
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
                    // Fusionner les tuiles adjacentes ayant la même valeur (non nulle)
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
                    // Fusionner les tuiles adjacentes ayant la même valeur (non nulle)
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

/**
 * @brief Calcule le score actuel du jeu 2048.
 *
 * Cette fonction parcourt la grille du jeu et calcule la somme des valeurs présentes sur toutes les tuiles.
 * 
 * @return La somme des valeurs des tuiles présentes dans la grille.
 * 
 * @post Le score du jeu est calculé en additionnant les valeurs de toutes les tuiles de la grille.
 * 
 * @see Jeu2048
 */

int Jeu2048::CalculerScore()
{
    int somme = 0;
    int ligne;
    int colonne;
    for (ligne = 0; ligne < 4; ligne++)
    {
        for (colonne = 0; colonne < 4; colonne++)
        {
            // Ajouter la valeur de la tuile à la somme
            somme += grille[ligne][colonne];
        }
    }
    return somme;
}

/**
 * @brief Recherche l'état actuel de la partie dans le jeu 2048.
 *
 * Cette fonction analyse la grille du jeu pour déterminer si le joueur a gagné, perdu ou si le jeu est toujours en cours.
 * 
 * @return L'état actuel de la partie (GAGNE si le joueur a atteint une tuile 2048, PERDU si toutes les cases sont occupées, EN_COURS sinon).
 * 
 * @post L'état de la partie est déterminé en fonction des conditions spécifiées.
 * 
 * @see Jeu2048
 */

Jeu2048::ETATS_DU_JEU Jeu2048::RechercherFinDePartie()
{
    int ligne;
    int colonne;
    
    if (Jeu2048::ToutesLesCasesOccupees())
    {
        return PERDU;
    }

    // Vérifier si une tuile 2048 est présente sur la grille
    for (ligne = 0; ligne < 4; ligne++)
    {
        for (colonne = 0; colonne < 4; colonne++)
        {
            if (grille[ligne][colonne] == 2048)
            {
                return GAGNE;
            }
        }
    }

    // Si aucune des conditions précédentes n'est remplie, le jeu est en cours
    return EN_COURS;
}

/**
 * @brief Vérifie si toutes les cases de la grille sont occupées.
 *
 * Cette fonction parcourt la grille pour déterminer si toutes les cases sont occupées par des tuiles.
 * 
 * @return true si toutes les cases de la grille sont occupées, false sinon.
 * 
 * @post L'état d'occupation de toutes les cases de la grille est vérifié.
 * 
 * @see Jeu2048
 */

bool Jeu2048::ToutesLesCasesOccupees() const
{
    for (int ligne = 0; ligne < 4; ligne++)
    {
        for (int colonne = 0; colonne < 4; colonne++)
        {
            // Vérifier s'il y a une case vide
            if (grille[ligne][colonne] == 0)
            {
                return false; // Il y a au moins une case vide
            }
        }
    }
    return true; // Toutes les cases sont occupées
}