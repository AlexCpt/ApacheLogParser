/*************************************************************************
                           Page  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Page> (fichier Page.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <string>

//------------------------------------------------------ Include personnel
#include "Page.h"


//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Page::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//~ Page & Page::operator = ( const Page & unPage )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <Page>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ Page::Page ( const Page & unPage )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <Page>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de Page (constructeur de copie)


Page::Page (vector <string> ligneHach)
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Page>" << endl;
#endif

  


} //----- Fin de Page






Page::~Page ( )
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <Page>" << endl;
#endif
} //----- Fin de ~Page


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
