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
	map<int, int> connexions; //code page, nombre hits sortants
	
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
map<int, infosPage> mapPages;
string nomLog;
};

//--------------------------- Autres définitions dépendantes de <Graph>

#endif // ${include_guard_symbol}
