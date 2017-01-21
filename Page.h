/*************************************************************************
                           Page  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Interface de la classe <Page> (fichier Page.h) ------
#if ! defined ( Page_H )
#define Page_H


//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Role de la classe <Page>
// La classe page correspond à une page du serveur. Elle stocke son numéro (on utilise
// l'index pour retrouver l'URL), le nombre de hits et map de ses connexions sortantes.
//------------------------------------------------------------------------

class Page
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
    //~ Page & operator = ( const Page & unPage );
    //~ // Mode d'emploi :
    //~ //
    //~ // Contrat :
    //~ //
//~

//-------------------------------------------- Constructeurs - destructeur
    //~ Page ( const Page & unPage );
    //~ // Mode d'emploi (constructeur de copie) :
    //~ //
    //~ // Contrat :
    //~ //

    Page (vector <string> ligneHach)
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Page ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Page>

#endif // ${include_guard_symbol}
