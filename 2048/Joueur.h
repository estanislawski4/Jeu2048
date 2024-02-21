/**
 * @file Joueur.h
 * @brief Déclaration de la classe Joueur.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <fstream>

using namespace std;

/**
 * @class Joueur
 * @brief Représente un joueur avec son pseudo, son score et sa durée de jeu cumulée.
 * 
 * La classe Joueur est utilisée pour stocker les informations d'un joueur, y compris son pseudo,
 * son score actuel et la durée totale de jeu cumulée.
 */

class Joueur {
public:
    
    /**
     * @brief Constructeur de la classe Joueur avec des paramètres.
     *
     * @param _pseudo Le pseudo du joueur.
     * @param _nouveauScore Le score initial du joueur (par défaut 0).
     * @param _duree La durée totale de jeu cumulée du joueur (par défaut 0).
     */
    
    Joueur(const string _pseudo,const int _nouveauScore=0,const int _duree=0);
    
    /**
     * @brief Constructeur par défaut de la classe Joueur.
     */
    
    Joueur();
    
    /**
     * @brief Actualise les informations du joueur avec un nouveau score et une nouvelle durée.
     *
     * @param _nouveauScore Le nouveau score du joueur.
     * @param _duree La nouvelle durée de jeu cumulée du joueur.
     */
    
    void Actualiser(const int _nouveauScore,const int _duree);
    
    /**
     * @brief Obtient les informations du joueur (pseudo, score, durée).
     *
     * @param _pseudo Référence vers une chaîne pour stocker le pseudo du joueur.
     * @param _score Référence vers un entier pour stocker le score du joueur.
     * @param _cumulTemps Référence vers un entier pour stocker la durée de jeu cumulée du joueur.
     */
    
    void ObtenirInfo(string &_pseudo, int & _score, int &cumulTemps);
    
    /**
     * @brief Surcharge de l'opérateur de comparaison '>' pour comparer les joueurs par score.
     *
     * @param _autre L'autre joueur à comparer.
     * @return true si le joueur actuel a un score supérieur, false sinon.
     */
    
    bool operator > (const Joueur &_autre) const;
    
    /**
     * @brief Surcharge de l'opérateur de comparaison '!=' pour comparer le pseudo du joueur avec une chaîne.
     *
     * @param _pseudo La chaîne avec laquelle comparer le pseudo du joueur.
     * @return true si le pseudo du joueur est différent de la chaîne, false sinon.
     */
    
    bool operator != (const string& _pseudo) const;
    
    /**
     * @brief Surcharge de l'opérateur de sortie pour afficher les informations du joueur.
     *
     * @param flux Le flux de sortie où afficher les informations.
     * @param unJoueur Le joueur à afficher.
     * @return Le flux de sortie mis à jour.
     */
    
    friend ostream& operator << (ostream &flux, const Joueur &unJoueur);
    
    /**
     * @brief Surcharge de l'opérateur d'entrée pour lire les informations du joueur depuis un flux.
     *
     * @param flux Le flux d'entrée à partir duquel lire les informations.
     * @param unJoueur Le joueur à mettre à jour avec les informations lues.
     * @return Le flux d'entrée mis à jour.
     */
    
    friend istream& operator >> (istream &flux, Joueur &unJoueur);
    
private:
    string pseudo ;     ///< Pseudo du joueur.
    int score;          ///< Score actuel du joueur.
    int cumulTemps;     ///< Durée totale de jeu cumulée du joueur.
};

#endif /* JOUEUR_H */

