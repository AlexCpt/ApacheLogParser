/*************************************************************************
                           Graph  -  description
                             -------------------
    début       : 11/01/2017
    copyright   : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ------
#if ! defined ( Graph_H )
#define Graph_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct infosPage
{
	int hits;
	map<int, int> connexions; //<code page visée, nombre hits sortants>

	infosPage(int h=0):
	hits(h){}
};
//------------------------------------------------------------------------
// Role de la classe <Graph>
// Graph cr
//
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void add (const string ligne);
	// Mode d'emploi :
	// ligne est la string contenant les informations de la requette
	// pour mettre  à jour mapPages.
	// Met à jour l'index,l'index inv si les pages n'existent pas encore
	// dans mapPage.
	// Met à jour le nombre de hit et les connexions.
	// Fait le tri sur les extensions si excluDoc est levé.
	// Fait le tri sur les heures si heure est different de -1.

	void split (const string ligne, vector<string> & ligneHach);
	// Mode d'emploi :
	//

	void createHighHit();
	// Mode d'emploi :
	//

	void affichageTopHits ();
	// Mode d'emploi :
	//
	// Contrat :
	//
	void createDot();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Graph (string nl, string nD, bool eDoc, int h);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
map <int, infosPage> mapPages; // Contient toutes les pages
map <int, string> index;
map <string, int> indexInv;

vector<int>  tabIndiceMaxHits; // Par ordre croissant (IDEE stocker nombre de hits aussi ?)

int indicePage;
bool excluDoc;
int heure;

string nomLog;
string nomDot;
};

//--------------------------- Autres définitions dépendantes de <Graph>

#endif
