#include "plateau.h"

Plateau::Plateau() :
score(0),
nbCoups(0)
{

}

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

    string choix;

    cout << "Votre déplacement : H (^), B (v), G (<-), D (->) : ";
    /*cin.ignore();
    getline(cin, choix);
    cout << choix << endl;*/
}

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
    }
    if (touche == 'F')
        retour = true;
    return retour;
}