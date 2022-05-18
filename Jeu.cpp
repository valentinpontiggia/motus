/*#include <iostream>
#include "tableau.h"
using namespace std;

Tableau::Tableau()
{}

Tableau::~Tableau()
{
    for (int i = 0; i < (int)tabJeu_.size(); i++)
        delete tabJeu_[i];
}

void Tableau::ajouterMot(Keyword* m)
{
    tabJeu_.push_back(m);
}

void Tableau::afficher() const
{
    for (int i = 0; i < (int)tabJeu_.size(); i++)  tabJeu_[i]->afficher();
}


void Semestre::saisirMatieres()
{
    Matiere* m;
    char r;
    do
    {
        cout << endl << "Saisie des matieres" << endl;
        afficher();
        cout << endl << "Saisir une matiere (o/n) ? ";
        cin >> r;
        if (r == 'o')
        {
            m = new Matiere;
            m->saisirMatiere();
            ajouterMatiere(m);
        }
        cout << endl;
    } while (r != 'n');
}

void Semestre::saisirNotes()
{
    cout << "Entrer les notes :" << endl;
    for (int i = 0; i < (int)tabMatiere_.size(); i++)
    {
        cout << tabMatiere_[i]->getNom() << " : " << endl;
        tabMatiere_[i]->saisirNote();
    }
}*/
