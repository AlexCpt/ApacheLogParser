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
// Graph stock la totatité des pages, leur nombre de hit, ainsi que le nombre
// de fois ou une page atteinte depuis cette page.
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
	// Decompose la string entree en paramètre en fragment stockes dans 
	// le vector de string ligneHach. Un fragment est créé à chaque
	// fois que la string DELIMITEUR est trouvée dans line (DELIMITEUR
	// n'est pas ajouté au fragment)
	
	void createHighHit();
	// Mode d'emploi :
	// Places les 10 index faisant references au pages possedant le plus 
	// grand nombres de hits dans le vector tabIndiceMaxHits.
	
	void affichageTopHits ();
	// Mode d'emploi :
	//	Affiche le tableau tabIndiceMaxHits
	
	void createDot();
	// Mode d'emploi :
	// Genere le code source graphViz correspondant au fichier (nomLog) 
	// analysé. Le code est écrit dans le fichier nomDot.
	

	Graph (string nl, string nD, bool eDoc, int h);
    // Mode d'emploi :
    // Recquiert un nom de fichier Log
    // Entraine la creation et l'affichage des pages correspondants au
    // tabIndiceMaxHits.
    // Si nD est different de sa valeur "false", un .dot est
    // genere a ce nom
    // Si le eDoc est vrai, les extentions de type image, css ou javascript
    // sont ignorées.
    // Si h est different de -1, seules les requetes entre h et h+1 sont 
    // traitée.
    

    virtual ~Graph ( );
    // Mode d'emploi :
    // Destructeur vide.
    

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
map <int, infosPage> mapPages; // Contient toutes les pages
map <int, string> index;
map <string, int> indexInv;

vector<int>  tabIndiceMaxHits; // Par ordre croissant

int indicePage;
bool excluDoc;
int heure;

string nomLog;
string nomDot;
};

//--------------------------- Autres définitions dépendantes de <Graph>

#endif
