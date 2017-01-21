/*************************************************************************
                           lecteurLog  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <lecteurLog> (fichier lecteurLog.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <Algorithm> // pour affichage3
//------------------------------------------------------ Include personnel
#include "lecteurLog.h"
#include "Graph.h"
#include "ligne.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 void lecteurLog::read (string nl, bool eDoc, int h, map <int,infosPage> & mapPages, map <int,string> & index,map  <string,int> & indexInv)
// Algorithme :
{
	nomLog = nl;
	string ligneFichier;
  int i = 0;

	ifstream fichier(nomLog.c_str(), ios::in);

	 if (fichier)
	 {
		 // ON LIT ET ON COUPE EN MORCEAUX
		 while(getline(fichier, ligneFichier))
		 {
        Ligne maligne(ligneFichier, mapPages, index, indexInv, i);
        i++;

		 }





	 }

	 else
	 {
		 cerr << "Erreur à l'ouverture du fichier"<<endl;
	 }

} //----- Fin de Méthode







//~
//~ //------------------------------------------------- Surcharge d'opérateurs
//~ lecteurLog & lecteurLog::operator = ( const lecteurLog & unlecteurLog )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <lecteurLog>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ lecteurLog::lecteurLog ( const lecteurLog & unlecteurLog )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <lecteurLog>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de lecteurLog (constructeur de copie)




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
