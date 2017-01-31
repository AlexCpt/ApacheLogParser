/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Graph.h"
//------------------------------------------------------------- Constantes

const string SUFFIX = ".log";
const string SUFFIX_G = ".dot";
const unsigned int TAILLE_SUFFIX = SUFFIX.size();
const unsigned int TAILLE_SUFFIX_G = SUFFIX_G.size();

int main (int argc, char *argv[])
{

	// TRAITEMENT DE LA COMMANDE
	if(argc > 7)
	{
		cerr << "Vous avez saisis trop d'arguments" << endl ;
		cerr << "Utilisation minimale de la commande : analog xxx.log" <<endl;
		return 1;
	}
	if(argc < 2)
	{
		cerr << "Vous n'avez pas saisis asez d'arguments" << endl ;
		cerr << "Utilisation minimale de la commande : analog xxx.log" <<endl;
		return 1;
	}

	string nomDot = "false";
	bool excluDoc = false;
	int heure = -1;
	string nomLog = argv[argc-1];

	for(int i = 1 ; i<argc-1; i++)
	{
		// -e
		if(strcmp(argv[i],"-e") == 0)
		{
			excluDoc = true;
		}
		//-g
		else if(strcmp(argv[i],"-g") == 0)
		{
			i++;
			nomDot = argv[i];
			if(nomDot.compare(nomDot.size() - TAILLE_SUFFIX_G, TAILLE_SUFFIX_G, SUFFIX_G) != 0 && nomDot.size() >= TAILLE_SUFFIX_G)
			{
				cerr << "argument différent de .dot" << endl;
				cerr << "Utilisation minimale de la commande : analog xxx.log" <<endl;
				return 1;
			}
		}
		//-t
		else if(strcmp(argv[i],"-t") == 0)
		{
			i++;

			string stringHeure = argv[i];

			if(isdigit(stringHeure[0]))
			{
				stringstream(stringHeure) >> heure; //proteger du non int

				if(heure < 0)
				{
					cerr << "heure négative invalide" << endl;
					return 1;
				}
				if (heure > 24)
				{
					cerr << "heure supérieure à 24 invalide" << endl;
					return 1;
				}
			}
			//Heure incorrecte
			else
			{
				cerr << "heure négative non numérique" << endl;
				return 1;
			}
		}
		else
		{
			cerr << "Mauvais arguments" << endl ;
			cerr << "Utilisation minimale de la commande : analog xxx.log" <<endl;
		}
	}

	//on vérifie que .log valide
	if(nomLog.compare(nomLog.size() - TAILLE_SUFFIX, TAILLE_SUFFIX, SUFFIX) != 0 && nomLog.size() >= TAILLE_SUFFIX)
	{
		cerr << "argument différent de .log" << endl;
		cerr << "Utilisation minimale de la commande : analog xxx.log" <<endl;

		return 1;
	}

	//Création du graph
	Graph monGraph(nomLog, nomDot, excluDoc, heure);

	return 0;
}
