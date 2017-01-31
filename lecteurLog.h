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
//------------------------------------------------------------- Constantes
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

		int read (string nl, bool eDoc, int h, Graph * monGraph);

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
