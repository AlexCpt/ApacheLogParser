/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <Main> (fichier Main.h) ------
#if ! defined ( MAIN_H )
#define MAIN_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Main>
//
//
//------------------------------------------------------------------------ 

class Main
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
    Main & operator = ( const Main & unMain );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Main ( const Main & unMain );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Main ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Main ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Main>

#endif // ${include_guard_symbol}
