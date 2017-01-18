/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "lecteurLog.h"


//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//~ Graph & Graph::operator = ( const Graph & unGraph )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <Graph>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ Graph::Graph ( const Graph & unGraph )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <Graph>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de Graph (constructeur de copie)


Graph::Graph (string nl, string nD, bool eDoc, int h)
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
	nomLog = nl;
	
	//Création du lecteur
	lecteurLog monlecteurLog;
	
	monlecteurLog.read(nomLog, eDoc, h, mapPages);
	
	
} //----- Fin de Graph






Graph::~Graph ( )
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
} //----- Fin de ~Graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
