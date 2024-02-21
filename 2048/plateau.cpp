/**
 * @file plateau.cpp
 * @brief Implémentation de la classe Plateau.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#include "plateau.h"

/**
 * @brief Constructeur par défaut de la classe Plateau.
 *
 * Initialise un nouvel objet Plateau avec un jeu 2048, un score initial nul et un compteur de coups initial nul.
 *
 * @post Un nouvel objet Plateau est créé avec un jeu 2048, un score nul et un compteur de coups nul.
 *
 * @see Plateau
 */

Plateau::Plateau() :
score(0),
nbCoups(0)
{

}

/**
 * @brief Affiche le plateau de jeu dans la console.
 * 
 * Cette méthode affiche le plateau de jeu actuel, y compris le score, le nombre de coups,
 * et la grille 4x4 avec les valeurs actuelles des tuiles.
 *
 * Le format d'affichage est une grille rectangulaire avec les tuiles alignées.
 * Les cases vides sont représentées par des espaces vides.
 *
 * @post Le plateau de jeu est affiché dans la console.
 *
 * @see Plateau
 */

void Plateau::Afficher()
{
    int laGrille[4][4];
    system("clear");
    leJeu.ObtenirGrille(laGrille);

    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;

    int i;
    int j;

    for (i = 0; i < 4; i++)
    {
        cout << "   +" << setfill('-') << setw(6) << "+" << setw(6) << "+" << setw(6) << "+" << setw(6) << "+" << endl;
        cout << "   |";
        for (j = 0; j < 4; j++)
        {
            if (laGrille[i][j] > 0)
                cout << setfill(' ') << setw(4) << right << laGrille[i][j] << " |";
            else
                cout << setfill(' ') << setw(6) << " |";
        }
        cout << endl;
    }
    cout << "   +" << setfill('-') << setw(6) << "+" << setw(6) << "+" << setw(6) << "+" << setw(6) << "+" << endl;
    cout << endl;
    cout << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H (^), B (v), G (<-), D (->) : ";
}

/**
 * @brief Permet au joueur de jouer un coup sur le plateau.
 * 
 * Cette méthode permet au joueur de jouer un coup en fournissant une entrée de déplacement
 * (H pour Haut, B pour Bas, G pour Gauche, D pour Droite). Elle met à jour le plateau, le score,
 * et affiche le résultat dans la console.
 * 
 * Si le joueur décide de sortir du jeu, la méthode termine la partie.
 * 
 * @return true si le joueur a décidé de quitter le jeu ou s'il a perdu, false sinon.
 *
 * @see Plateau
 */

bool Plateau::JouerCoup()
{
    bool retour = false;
    bool test = false;
    char touche;
    cin >> touche;
    touche = toupper(touche);
    if (strchr("BHGD", touche) != nullptr)
    {
        nbCoups++;
        leJeu.Deplacer(touche);
        test = leJeu.Calculer(touche);
        if (test == true)
        {
            leJeu.Deplacer(touche);
        }
        leJeu.PlacerNouvelleTuile();
        score = leJeu.CalculerScore();
        Afficher();
        Jeu2048::ETATS_DU_JEU etatPartie = leJeu.RechercherFinDePartie();
        if (etatPartie == Jeu2048::PERDU)
        {
            cout << "Vous avez perdu ! Fin de la partie." << endl;
            retour = true;
        }
        if (etatPartie == Jeu2048::GAGNE)
        {
            cout << "Vous avez gagné ! Fin de la partie." << endl;
            retour = true;
        }
    }

    if (touche == 'F')
        retour = true;
    return retour;
}

/**
 * @brief Obtient le score actuel du jeu sur le plateau.
 *
 * @return Le score actuel du jeu sur le plateau.
 *
 * @see Plateau
 */

int Plateau::getScore() const
{
    return score;
}