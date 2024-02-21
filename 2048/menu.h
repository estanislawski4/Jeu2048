/**
 * @file menu.h
 * @brief Déclaration de la classe Menu.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <algorithm>


using namespace std;

/**
 * @class Menu
 * @brief Gère l'affichage et la sélection d'options dans un menu.
 *
 * La classe Menu permet de créer et d'afficher des menus avec différentes options,
 * ainsi que de récupérer le choix de l'utilisateur.
 */

class Menu {
public:
    
    /**
     * @brief Constructeur de la classe Menu à partir d'un fichier.
     *
     * @param _nomFichier Le nom du fichier contenant les options du menu.
     */
    
    Menu(const string _nomFichier);
    
    /**
     * @brief Constructeur de la classe Menu à partir d'un tableau d'options.
     *
     * @param _option Un tableau de chaînes représentant les options du menu.
     * @param _nbOptions Le nombre d'options dans le tableau.
     */
    
    Menu(const string *_option, const int _nbOptions);
    
    /**
     * @brief Affiche le menu, attend le choix de l'utilisateur et le retourne.
     *
     * @return Le choix de l'utilisateur.
     */
    
    int AfficherEtAttendreChoix();
    
    /**
     * @brief Attend l'appui d'une touche pour continuer.
     */
    
    static void AttendreAppuiTouche();
    
    /**
     * @brief Efface l'écran de la console.
     */
    
    static void EffacerEcran();
    
    /**
     * @brief Destructeur de la classe Menu.
     */
    
    ~Menu();
private:
    string nomFichier;  ///< Le nom du fichier contenant les options du menu.
    string *options;    ///< Un tableau de chaînes représentant les options du menu.
    int nbOptions;      ///< Le nombre d'options dans le tableau.
    size_t longueurMax; ///< La longueur maximale parmi les options du menu.
};

#endif /* MENU_H */

