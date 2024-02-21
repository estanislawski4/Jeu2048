/**
 * @file jeu2048.h
 * @brief Déclaration de la classe Jeu2048.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#ifndef JEU2048_H
#define JEU2048_H

#include <math.h>
#include <time.h>

/**
 * @class Jeu2048
 * @brief Représente le jeu 2048 avec ses fonctionnalités principales.
 * 
 * La classe Jeu2048 gère la logique du jeu 2048, y compris le placement de nouvelles tuiles,
 * le déplacement des tuiles, le calcul du score, la vérification de l'état du jeu, etc.
 */

class Jeu2048 {
public:
    
    /**
     * @brief Constructeur par défaut de la classe Jeu2048.
     *
     * Initialise une nouvelle instance du jeu 2048 en mettant toutes les tuiles à zéro
     * et en plaçant une nouvelle tuile aléatoire sur la grille.
     */
    
    Jeu2048();
    
    /**
     * @brief Place une nouvelle tuile aléatoire sur la grille.
     */
    
    void PlacerNouvelleTuile();
    
    /**
     * @brief Calcule les fusions des tuiles dans la direction spécifiée.
     *
     * @param _direction La direction dans laquelle effectuer les calculs de fusion.
     * @return true si des fusions ont été effectuées, false sinon.
     */
    
    bool Calculer(const char _direction);
    
    /**
     * @brief Déplace les tuiles de la grille dans la direction spécifiée.
     *
     * @param _direction La direction dans laquelle déplacer les tuiles (G pour gauche, D pour droite, B pour bas, H pour haut).
     */
    
    void Deplacer(const char _direction);
    
    /**
     * @brief Calcule le score actuel du jeu 2048.
     *
     * @return La somme des valeurs des tuiles présentes dans la grille.
     */
    
    int CalculerScore();
    
    /**
     * @brief Obtient une copie de la grille du jeu.
     *
     * @param _grille Tableau 2D dans lequel la grille du jeu sera copiée.
     */
    
    void ObtenirGrille(int _grille[][4]);
    
    /**
     * @brief Vérifie si toutes les cases de la grille sont occupées.
     *
     * @return true si toutes les cases de la grille sont occupées, false sinon.
     */
    
    bool ToutesLesCasesOccupees() const;
    
    /**
     * @brief Enumération des états possibles du jeu.
     */
    
    enum ETATS_DU_JEU
    {
        EN_COURS = 1, ///< Le jeu est en cours.
        PERDU,      ///< Le joueur a perdu la partie.
        GAGNE       ///< Le joueur a gagné en atteignant une tuile 2048.
    };
    
    /**
     * @brief Recherche l'état actuel de la partie dans le jeu 2048.
     *
     * @return L'état actuel de la partie (GAGNE, PERDU, EN_COURS).
     */
    
    ETATS_DU_JEU RechercherFinDePartie();
    
private:
    int grille[4][4]; ///< Grille représentant l'état actuel du jeu.
};

#endif /* JEU2048_H */

