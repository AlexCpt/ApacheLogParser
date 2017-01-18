/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 //~ void Ligne::read (string nl, bool eDoc, int h, map <int,infosLigne> mapLignes)
//~ // Algorithme :
//~ {
	//~ 
	//~ 
//~ } //----- Fin de Méthode

//~ 
//~ //------------------------------------------------- Surcharge d'opérateurs
//~ Ligne & Ligne::operator = ( const Ligne & unLigne )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <Ligne>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ Ligne::Ligne ( const Ligne & unLigne )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <Ligne>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne (string line)
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif

   stringstream flux(line);
   string temp;
	
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE



//----------------------------------------------------- Méthodes protégées
