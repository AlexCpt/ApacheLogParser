/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Ligne.h"
#include "Graph.h"


//------------------------------------------------------------- Constantes
const string delimiteur = " ";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 //~ void Ligne::read (string nl, bool eDoc, int h, map <int,infosLigne> mapLignes)
//~ // Algorithme :
//~ {
	//~
	//~
//~ } //----- Fin de Méthode

//~
//~ //------------------------------------------------- Surcharge d'opérateurs
//~ Ligne & Ligne::operator = ( const Ligne & unLigne )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <Ligne>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ Ligne::Ligne ( const Ligne & unLigne )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <Ligne>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne (string ligne, map <int,infosPage> & mapPages, map <int,string> & index, map <string,int> & indexInv)
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif

  //Découpage de la ligne : (pas générique)
  vector<string> ligneHach;    // Pas forcément vector??????
  split(ligne, ligneHach);

  affichage3(ligneHach);

  //On check si la page existe
  //index.find()
  //Si oui on augment le nombre de hits

  //Sinon on la crée



} //----- Fin de Ligne


void Ligne::split (string ligne, vector<string> & ligneHach)
{
    int pos = 0;
    int pos1 = 0;

    pos1 = ligne.find(delimiteur, pos);

    while(pos1 != -1)
    {

  		ligneHach.push_back(ligne.substr(pos, pos1-pos));
  		pos = pos1+1;

      pos1 = ligne.find(delimiteur, pos);

    }
} //----- Fin de Méthode

//affichage vector
void Ligne::affichage1 (const vector<string> vect)
{
  for(int i = 0; i < vect.size(); i ++)
  {
    cout << vect[i] << endl;
  }
}

//afichage générique
template <typename M>
void Ligne::affichage2 (const M & m)
{
  for (typename M::const_iterator it = m.cbegin() ; it!= m.cend(); it++)
  {
    cout << *it <<endl;
  }
}

//affichage vetor avec outpu_itérateurs générique ?
template <typename M>
void Ligne::affichage3 (const M & m)
{
  copy(m.begin(), m.end(), ostream_iterator <string> (cout, " "));
  cout << endl;
}



Ligne::~Ligne ()
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE



//----------------------------------------------------- Méthodes protégées
