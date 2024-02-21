/**
 * @file plateau.h
 * @brief Déclaration de la classe Plateau.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#ifndef PLATEAU_H
#define PLATEAU_H

#include "jeu2048.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

/**
 * @class Plateau
 * @brief Représente le plateau de jeu 2048 et gère les interactions avec le joueur.
 * 
 * La classe Plateau encapsule un objet de la classe Jeu2048 et fournit des méthodes pour afficher le plateau,
 * jouer des coups et obtenir le score actuel.
 */

class Plateau
{
public:
    
    /**
     * @brief Constructeur par défaut de la classe Plateau.
     *
     * Initialise un nouvel objet Plateau avec un jeu 2048 et un compteur de coups.
     */
    
    Plateau();
    
    /**
     * @brief Affiche le plateau de jeu dans la console.
     */
    
    void Afficher();
    
    /**
     * @brief Permet au joueur de jouer un coup sur le plateau.
     *
     * @return true si le coup a été joué avec succès, false sinon.
     */
    
    bool JouerCoup();
    
    /**
     * @brief Obtient le score actuel du jeu sur le plateau.
     *
     * @return Le score actuel du jeu.
     */
    
    int getScore() const;
    
private:
    int nbCoups;    ///< Compteur de coups joués.
    int score;      ///< Score actuel du jeu sur le plateau.
    Jeu2048 leJeu;  ///< Objet Jeu2048 représentant l'état du jeu sur le plateau.
};

#endif /* PLATEAU_H */

