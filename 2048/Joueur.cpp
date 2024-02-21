/**
 * @file Joueur.cpp
 * @brief Implémentation de la classe Joueur.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#include "Joueur.h"

/**
 * @brief Constructeur de la classe Joueur avec des paramètres.
 *
 * Initialise un nouvel objet Joueur avec les informations fournies : pseudo, score initial et durée de jeu cumulée.
 *
 * @param _pseudo Le pseudo du joueur.
 * @param _nouveauScore Le score initial du joueur.
 * @param _duree La durée totale de jeu cumulée du joueur.
 *
 * @post Un nouvel objet Joueur est créé avec les informations spécifiées.
 *
 * @see Joueur
 */

Joueur::Joueur(const string _pseudo,const int _nouveauScore,const int _duree):
pseudo(_pseudo),
score(_nouveauScore),
cumulTemps(_duree)
{
}

/**
 * @brief Constructeur par défaut de la classe Joueur.
 *
 * Initialise un nouvel objet Joueur avec des valeurs par défaut : pseudo vide, score nul et durée de jeu cumulée nulle.
 *
 * @post Un nouvel objet Joueur est créé avec des valeurs par défaut.
 *
 * @see Joueur
 */

Joueur::Joueur()
{
    pseudo.clear();
    score = 0;
    cumulTemps = 0;
}

/**
 * @brief Actualise les informations du joueur avec un nouveau score et une nouvelle durée de jeu.
 *
 * Cette fonction met à jour les informations du joueur en comparant le nouveau score fourni avec le score actuel.
 * Si le nouveau score est supérieur, le score du joueur est mis à jour. La durée de jeu cumulée du joueur est également augmentée.
 *
 * @param _nouveauScore Le nouveau score du joueur à prendre en compte.
 * @param _duree La nouvelle durée de jeu à ajouter à la durée cumulée du joueur.
 *
 * @post Les informations du joueur sont actualisées en fonction des paramètres spécifiés.
 *
 * @see Joueur
 */

void Joueur::Actualiser(const int _nouveauScore, const int _duree)
{
    if(_nouveauScore > score)
        score = _nouveauScore;
    cumulTemps += _duree;
}

/**
 * @brief Obtient les informations du joueur (pseudo, score, durée cumulée).
 *
 * Cette fonction permet d'obtenir les informations du joueur en passant par référence les variables
 * qui seront remplies avec le pseudo, le score et la durée cumulée du joueur.
 *
 * @param _pseudo Référence vers une chaîne pour stocker le pseudo du joueur.
 * @param _score Référence vers un entier pour stocker le score du joueur.
 * @param _cumulTemps Référence vers un entier pour stocker la durée cumulée de jeu du joueur.
 *
 * @post Les variables de sortie sont mises à jour avec les informations du joueur.
 *
 * @see Joueur
 */

void Joueur::ObtenirInfo(string & _pseudo, int & _score, int & _cumulTemps)
{
    _pseudo = pseudo;
    _score = score;
    _cumulTemps = cumulTemps;   
}

/**
 * @brief Surcharge de l'opérateur de comparaison '>'.
 *
 * Compare deux joueurs en se basant sur leur score. Renvoie true si le score du joueur actuel est strictement supérieur
 * à celui de l'autre joueur, et false sinon.
 *
 * @param _autre L'autre joueur à comparer.
 * @return true si le score du joueur actuel est strictement supérieur à celui de l'autre joueur, false sinon.
 *
 * @see Joueur
 */

bool Joueur::operator > (const Joueur& _autre) const
{
    return score < _autre.score ;
}

/**
 * @brief Surcharge de l'opérateur de comparaison '!='.
 *
 * Compare le pseudo du joueur avec une chaîne. Renvoie true si le pseudo du joueur actuel est différent
 * de la chaîne spécifiée, et false sinon.
 *
 * @param _pseudo La chaîne avec laquelle comparer le pseudo du joueur.
 * @return true si le pseudo du joueur actuel est différent de la chaîne spécifiée, false sinon.
 *
 * @see Joueur
 */

bool Joueur::operator != (const string& _pseudo) const
{
    return pseudo != _pseudo ;
}

/**
 * @brief Surcharge de l'opérateur de sortie '<<'.
 *
 * Permet d'afficher les informations du joueur dans un flux de sortie, incluant le pseudo, le score et la durée cumulée de jeu.
 *
 * @param flux Le flux de sortie où afficher les informations.
 * @param unJoueur Le joueur dont les informations seront affichées.
 * @return Le flux de sortie mis à jour.
 *
 * @see Joueur
 */

ostream& operator << (ostream &flux, const Joueur &unJoueur) {
    flux << unJoueur.pseudo << " " << unJoueur.score << " " << unJoueur.cumulTemps << endl;
    return flux;
}

/**
 * @brief Surcharge de l'opérateur d'entrée '>>'.
 *
 * Permet de lire les informations du joueur à partir d'un flux d'entrée, y compris le pseudo, le score et la durée cumulée de jeu.
 *
 * @param flux Le flux d'entrée à partir duquel lire les informations.
 * @param unJoueur Le joueur à mettre à jour avec les informations lues.
 * @return Le flux d'entrée mis à jour.
 *
 * @see Joueur
 */

istream& operator >> (istream &flux, Joueur &unJoueur) {
    flux >> unJoueur.pseudo >>  unJoueur.score >> unJoueur.cumulTemps;
    return flux;
}