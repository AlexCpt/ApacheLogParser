/*************************************************************************
                           lecteurLog  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <lecteurLog> (fichier lecteurLog.h) ------
#if ! defined (lecteurLog_H )
#define lecteurLog_H


//--------------------------------------------------- Interfaces utilisées
#include "Graph.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <lecteurLog>
//
//Classe assurant la lecture d'un fichier. Elle stocke le nom du fichier en
//paramètre. 
//------------------------------------------------------------------------

class lecteurLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  
	int read (const string nl, Graph * monGraph);
	// Mode d'emploi :
    // string nl est le nom du fichier à lire. 
    // monGraph est un pointeur sur le Graph appellant le lecteur. 
    // La classe tente d'ouvrir le fichier et ajoute les pages au Graph 
    // Renvoie : 0 si l'execution c'est bien déroulée. 
    //			 -1 en cas d'echec.

    lecteurLog ();
    // Mode d'emploi :
    // Surcharge du constructeur par défaut,initialise string à undefined

    virtual ~lecteurLog ( );
    // Mode d'emploi :
    // Destructeur vide


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nomLog;


};

//--------------------------- Autres définitions dépendantes de <lecteurLog>

#endif
