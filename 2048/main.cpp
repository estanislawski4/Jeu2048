/**
 * @file main.cpp
 * @brief Programme principal du jeu 2048 avec gestion des joueurs.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm> // Ajout pour la fonction transform
#include <unistd.h>

#include "menu.h"
#include "Joueur.h"
#include "plateau.h"

using namespace std;

/**
 * @brief Trie un tableau de joueurs en fonction de leur score.
 * @param _tab Tableau de joueurs.
 * @param _nb Nombre de joueurs dans le tableau.
 */

void TrierTableau(Joueur* _tab, const int _nb)
{
    Joueur aux;
    for (int indice1 = 0; indice1 < _nb - 1; indice1++)
        for (int indice2 = 0; indice2 < _nb - indice1 - 1; indice2++)
        {
            if (_tab[indice2] > _tab[indice2 + 1])
            {
                aux = _tab[indice2];
                _tab[indice2] = _tab[indice2 + 1];
                _tab[indice2 + 1] = aux;
            }
        }
}

/**
 * @brief Recherche un joueur dans un tableau par son pseudo.
 * @param _tab Tableau de joueurs.
 * @param _nb Nombre de joueurs dans le tableau.
 * @param _pseudo Pseudo du joueur à rechercher.
 * @return Indice du joueur dans le tableau s'il est trouvé, sinon -1.
 */

int RechercherJoueur(Joueur* _tab, const int _nb, const string& _pseudo)
{
    int indice = 0;
    while (indice < _nb && _tab[indice] != _pseudo)
        indice++;
    if (indice == _nb)
        indice = -1;
    return indice;
}

/**
 * @brief Fonction principale du programme.
 * @return Code de retour du programme.
 */

int main()
{
    Menu Config("config.txt");
    Plateau lePlateau;

    string pseudo;
    string pseudoJ;
    int duree;
    int score;
    int nbJoueurs = 0;
    const int NB_MAX_JOUEURS = 20; // Déplacement de la déclaration NB_MAX_JOUEURS ici
    Joueur tabJoueurs[NB_MAX_JOUEURS];

    cout << "Pseudo du joueur : ";
    cin >> pseudoJ;

    lePlateau.Afficher();

    bool continuer;

    do
    {
        continuer = lePlateau.JouerCoup();
    }
    while (continuer == false);
    
    sleep(2);

    int scoreJ = lePlateau.getScore();

    ifstream fichier("config.txt");
    if (fichier)
    {
        fichier >> nbJoueurs;
        for (int i = 0; i < nbJoueurs; i++)
        {
            fichier >> tabJoueurs[i];
        }
        fichier.close();
    }
    else
    {
        //nbJoueurs = 0;
        printf("erreur");
    }
    Menu::EffacerEcran();

    int pos;

    cout << "+" << setw(13) << setfill('-') << "+" << setw(8) << "+" << setw(8) << "+" << setfill(' ') << endl;
    for (int i = 0; i < nbJoueurs; i++)
    {
        tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
        cout << "| " << left << setw(10) << pseudo << " | " << right << setw(5) << score << " | " << setw(5) << duree << " |" << endl;
    }
    score = scoreJ, duree = 5, pseudo = pseudoJ;

    if (nbJoueurs > 0)
    {
        pos = RechercherJoueur(tabJoueurs, nbJoueurs, pseudo);
        if (pos != -1) // Changement de condition pour vérifier que le joueur a été trouvé
            tabJoueurs[pos].Actualiser(score, duree);
        else
            tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);

        TrierTableau(tabJoueurs, nbJoueurs);
    }
    else
        tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);

    cout << "| " << left << setw(10) << pseudo << " | " << right << setw(5) << score << " | " << setw(5) << duree << " |" << endl;

    cout << "+" << setw(13) << setfill('-') << "+" << setw(8) << "+" << setw(8) << "+" << setfill(' ') << endl;

    ofstream fichier2("config.txt");
    if (!fichier2)
    {
        cout << "Erreur lors de l'ouverture du fichier en écriture " << endl;
    }
    else
    {
        fichier2 << nbJoueurs << endl;
        for (int i = 0; i < nbJoueurs; i++)
        {
            fichier2 << tabJoueurs[i];
        }
        fichier2.close();
    }

    return 0;
}