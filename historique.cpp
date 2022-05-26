#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void historique(int nb_essais)
{
	ofstream historique("historique.txt");
	historique << nb_essais << endl;
	historique.close();
}

/*double calculerMoyenne()
{
	ifstream historique;
	int total = 0;
	int nb_essais;
	int compteur = 0;
	historique.open("historique.txt");
	if (!historique.is_open())
		cout << "Le fichier n existe pas " << endl;
	else
		while (getline(historique, nb_essais))
		{
			total = total + nb_essais;
			compteur++;
		}
	return (total / compteur);
}*/