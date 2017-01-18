/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( Ligne_H )
#define Ligne_H


//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Ligne>
//
//
//------------------------------------------------------------------------ 

class Ligne
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
    //~ Ligne & operator = ( const Ligne & unLigne );
    //~ // Mode d'emploi :
    //~ //
    //~ // Contrat :
    //~ //


//-------------------------------------------- Constructeurs - destructeur
    //~ Ligne ( const Ligne & unLigne );
    //~ // Mode d'emploi (constructeur de copie) :
    //~ //
    //~ // Contrat :
    //~ //


    Ligne(string line);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector <string> element;

};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif
