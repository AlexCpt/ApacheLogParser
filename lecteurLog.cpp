/*************************************************************************
                           lecteurLog  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <lecteurLog> (fichier lecteurLog.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "lecteurLog.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 int lecteurLog::read (string nl, bool eDoc, int h, Graph * monGraph)
// Algorithme :
{
	nomLog = nl;
	string ligneFichier;

	ifstream fichier(nomLog.c_str(), ios::in);

	 if (fichier)
	 {
		 fichier.seekg(0, ios::end);
		 if(fichier.tellg() == 0) // On check fichier vide
		 {
			cerr<<"Erreur : Fichier vide"<<endl;
			return -1;
		 }
		 else
		 {
			 fichier.seekg(0, ios::beg);

			 // ON LIT ET ON COUPE EN MORCEAUX
			 while(getline(fichier, ligneFichier))
			 {
				monGraph->add(ligneFichier);
			 }

			 return 0;
		 }
	 }

	 else
	 {
		 cerr << "Erreur à l'ouverture du fichier"<<endl;
		 return -1;
	 }

} //----- Fin de Méthode

lecteurLog::lecteurLog ()
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au constructeur de <lecteurLog>" << endl;
#endif
} //----- Fin de lecteurLog


lecteurLog::~lecteurLog ( )
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <lecteurLog>" << endl;
#endif

} //----- Fin de ~lecteurLog


//------------------------------------------------------------------ PRIVE



//----------------------------------------------------- Méthodes protégées
