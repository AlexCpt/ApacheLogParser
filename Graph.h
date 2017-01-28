/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ------
#if ! defined ( Graph_H )
#define Graph_H


//--------------------------------------------------- Interfaces utilisées
#include <map>
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
//
//
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

		void affichageMapPages (map <int, infosPage> & mapPages);

		template <typename M>
		void affichage2 (const M & m);

		void add (string ligne);

		void split (string ligne, vector<string> & ligneHach);

		void createHighHit();

		void affichageTopHits ();



//------------------------------------------------- Surcharge d'opérateurs
    //~ Graph & operator = ( const Graph & unGraph );
    //~ // Mode d'emploi :
    //~ //
    //~ // Contrat :
    //~ //
//~

//-------------------------------------------- Constructeurs - destructeur
    //~ Graph ( const Graph & unGraph );
    //~ // Mode d'emploi (constructeur de copie) :
    //~ //
    //~ // Contrat :
    //~ //

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
};

//--------------------------- Autres définitions dépendantes de <Graph>

#endif // ${include_guard_symbol}
