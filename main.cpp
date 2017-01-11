/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Main.h"

//------------------------------------------------------------- Constantes
#define DEBUGMain
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Main::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Main & Main::operator = ( const Main & unMain )
// Algorithme :
//
{
#ifdef DEBUGMain
    cout << "Appel a la surcharge de l operateur d affectation de <Main>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Main::Main ( const Main & unMain )
// Algorithme :
//
{
#ifdef DEBUGMain
    cout << "Appel au constructeur de copie de <Main>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
} //----- Fin de Main (constructeur de copie)


Main::Main ( )
// Algorithme :
//
{
#ifdef DEBUGMain
    cout << "Appel au constructeur de <Main>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
} //----- Fin de Main


Main::~Main ( )
// Algorithme :
//
{
#ifdef DEBUGMain
    cout << "Appel au destructeur de <Main>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
} //----- Fin de ~Main


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
