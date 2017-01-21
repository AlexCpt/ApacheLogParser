/*************************************************************************
                           lecteurLog  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <lecteurLog> (fichier lecteurLog.h) ------
#if ! defined ( lecteurLog_H )
#define lecteurLog_H


//--------------------------------------------------- Interfaces utilisées
#include "Graph.h"
#include <vector>

//------------------------------------------------------------- Constantes
const string SEP = " ";
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <lecteurLog>
//
//
//------------------------------------------------------------------------

class lecteurLog
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
    //~ lecteurLog & operator = ( const lecteurLog & unlecteurLog );
    //~ // Mode d'emploi :
    //~ //
    //~ // Contrat :
    //~ //


//-------------------------------------------- Constructeurs - destructeur
    //~ lecteurLog ( const lecteurLog & unlecteurLog );
    //~ // Mode d'emploi (constructeur de copie) :
    //~ //
    //~ // Contrat :
    //~ //

		void read (string nl, bool eDoc, int h, map <int,infosPage> & mapPages, map <int,string> & index,map  <string,int> & indexInv);





    lecteurLog ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~lecteurLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nomLog;


};

//--------------------------- Autres définitions dépendantes de <lecteurLog>

#endif
