/**
 * @file menu.cpp
 * @brief Implémentation de la classe Menu.
 * @version 1.0
 * @author Erwän STANISLAWSKi
 * @date 20/02/2024
 */

#include "menu.h"

/**
 * @brief Constructeur de la classe Menu à partir d'un fichier.
 *
 * Initialise un nouvel objet Menu en chargeant les options à partir d'un fichier.
 * La longueur maximale des options est déterminée pour l'affichage.
 *
 * @param _nomFichier Le nom du fichier contenant les options du menu.
 *
 * @post Un nouvel objet Menu est créé avec les options chargées à partir du fichier.
 *       La longueur maximale des options est déterminée.
 *
 * @throw std::runtime_error Si une erreur survient lors de l'ouverture du fichier.
 *
 * @see Menu
 */

Menu::Menu(const string _nomFichier) :
nomFichier(_nomFichier),
longueurMax(0),
options(nullptr)
{
    ifstream fichierMenu(nomFichier);
    if (fichierMenu.fail())
    {
        cerr << "Erreur lors de l'ouverture du fichier : " << strerror(errno) << endl;
        exit errno;
    }
    else
    {
        nbOptions = static_cast<int> (count(istreambuf_iterator<char>(fichierMenu),
                                            istreambuf_iterator<char>(), '\n'));
        fichierMenu.seekg(0, ios::beg);

        size_t longueur;
        string item;

        options = new string[nbOptions];
        for (int i = 0; i < nbOptions; i++)
        {
            getline(fichierMenu, item);
            longueur = item.length();
            if (longueur > longueurMax)
                longueurMax = longueur;
            if (longueur > 0)
                options[i] = item;
            else
            {
                nbOptions--;
                i--;
            }
        }

    }
}

/**
 * @brief Constructeur de la classe Menu à partir d'un tableau d'options.
 *
 * Initialise un nouvel objet Menu en utilisant un tableau d'options spécifié.
 * La longueur maximale des options est déterminée pour l'affichage.
 *
 * @param _options Un tableau de chaînes représentant les options du menu.
 * @param _nbOptions Le nombre d'options dans le tableau.
 *
 * @post Un nouvel objet Menu est créé avec les options fournies dans le tableau.
 *       La longueur maximale des options est déterminée.
 *
 * @see Menu
 */

Menu::Menu(const string* _options, const int _nbOptions) :
nbOptions(_nbOptions),
        longueurMax(0)
{
    nomFichier.clear();
    size_t longueur;
    options = new string[nbOptions];
    for (int i = 0; i < nbOptions; i++)
    {
        options[i] = _options[i];
        longueur = options[i].length();
        if (longueur > longueurMax)
            longueurMax = longueur;
    }

}

/**
 * @brief Destructeur de la classe Menu.
 *
 * Libère la mémoire allouée dynamiquement pour le tableau d'options si nécessaire.
 *
 * @post La mémoire allouée dynamiquement est libérée si le tableau d'options existe.
 *
 * @see Menu
 */

Menu::~Menu()
{
    if (!nomFichier.empty() && options != nullptr)
        delete[] options;
}

/**
 * @brief Affiche le menu et attend le choix de l'utilisateur.
 *
 * Cette méthode affiche le menu avec les options numérotées et attend que
 * l'utilisateur fasse un choix valide. L'utilisateur doit entrer un nombre entre
 * 1 et le nombre total d'options inclus.
 *
 * @return Le choix de l'utilisateur, ou -1 si une entrée invalide a été détectée.
 *
 * @pre Le tableau d'options ne doit pas être vide et doit être non nul.
 *      Le nombre d'options doit être différent de zéro.
 *
 * @post Le menu est affiché dans la console et le choix de l'utilisateur est retourné.
 *       Si une entrée invalide est détectée, -1 est retourné.
 *
 * @see Menu
 */

int Menu::AfficherEtAttendreChoix()
{
    int choix = -1;

    if (nbOptions != 0 && options != nullptr)
    {
        cout << setfill('-');
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax + 2) << "-+" << endl;
        cout << setfill(' ');
        for (int i = 0; i < nbOptions; i++)
        {
            cout << "| " << i + 1 << " | " << left << setw(longueurMax) << options[i] << " |" << endl;
        }
        std::cout << setfill('-') << right;
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax + 2) << "-+" << endl;
        cout << setfill(' ');

        do
        {
            cout << "Votre choix : entre 1 et " << nbOptions << " : ";
            if (!(cin >> choix))
            {
                cin. clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                choix = -1;
            }
        }
        while (choix < 1 || choix > nbOptions);

    }

    return choix;
}

/**
 * @brief Attend l'appui d'une touche pour continuer.
 *
 * Cette méthode affiche un message pour demander à l'utilisateur d'appuyer sur la touche Entrée
 * pour continuer. Elle attend ensuite que l'utilisateur appuie sur Entrée avant de poursuivre.
 *
 * @post Un message est affiché et l'exécution est en pause jusqu'à ce que l'utilisateur appuie sur Entrée.
 *
 * @see Menu
 */

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour continuer ...";
    getline(cin, uneChaine);
    // Vidage du tampon d'entrée
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // efface l'écran de la console
    cout << "\033[2J\033[1;1H";
}

/**
 * @brief Efface l'écran de la console.
 *
 * Cette méthode utilise des codes d'échappement ANSI pour effacer l'écran de la console.
 *
 * @post L'écran de la console est effacé.
 *
 * @see Menu
 */

void Menu::EffacerEcran()
{
     cout << "\033[2J\033[1;1H";
}