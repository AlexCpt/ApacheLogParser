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
struct infosPage;

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

    void split (string ligne, vector<string> & ligneHach);

    void affichage1 (vector<string> vect);

    template <typename M>
    void affichage2 (const M & m);

    template <typename M>
    void affichage3 (const M & m);



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


    Ligne (string ligne, map <int,infosPage> & mapPages, map <int,string> & index, map <string,int> & indexInv, int i);
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
