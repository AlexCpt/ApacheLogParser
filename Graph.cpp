/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 11/01/2017
    copyright            : (C) 2017 par Mathieu POURBAIX et Alexandre CARPENTIER
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "lecteurLog.h"


//------------------------------------------------------------- Constantes
const string delimiteur = " ";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//affichage générique

template <typename M>
void Graph::affichage2 (const M & m)
{
  for (typename M::const_iterator it = m.cbegin() ; it!= m.cend(); it++)
  {
    cout << "Page indice : "<< it->first;

    cout << "   hits : " <<it->second.hits<<endl;
    }
  cout << endl;
}

void Graph::add (string ligne)
{
  //Découpage de la ligne : (pas générique)
  vector<string> ligneHach;    // Pas forcément vector??????
  split(ligne, ligneHach);

  //affichage2(ligneHach);

  //On check si la page existe
  map <string,int>::iterator itIndexInv;
  const string urlGet = ligneHach[6];
  itIndexInv = indexInv.find(urlGet) ;// URL de la page on compte les GET

  //Si oui on augmente le nombre de hits
  if(itIndexInv != indexInv.end())
  {
    map <int,infosPage>::iterator itPages;

    //get le i qui correspond à l'url
    itPages = mapPages.find(itIndexInv->second);
    itPages->second.hits ++;
  }

  //Sinon on la crée
  else if(itIndexInv == indexInv.end())
  {
    infosPage monInfosPages(1);
    mapPages.insert(make_pair(indicePage, monInfosPages)); // ou insert({i, monInfosPages})
    index.insert(make_pair(indicePage, urlGet));
    indexInv.insert(make_pair(urlGet, indicePage));

    indicePage++;
  }
}



void Graph::split (string ligne, vector<string> & ligneHach)
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


//------------------------------------------------- Surcharge d'opérateurs
//~ Graph & Graph::operator = ( const Graph & unGraph )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel a la surcharge de l operateur d affectation de <Graph>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
	//~ return *this;
//~ } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//~ Graph::Graph ( const Graph & unGraph )
//~ // Algorithme :
//~ //
//~ {
//~ #ifdef DEBUG
    //~ cout << "Appel au constructeur de copie de <Graph>" << endl;
//~ #endif
	//~ cout << "Votre code a inserer ici ..." << endl;
//~ } //----- Fin de Graph (constructeur de copie)


Graph::Graph (string nl, string nD, bool eDoc, int h)
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
	nomLog = nl;

  indicePage =0;

	//Création du lecteur
	lecteurLog monlecteurLog;

	monlecteurLog.read(nomLog, eDoc, h, this); // PLUTOT FAIRE CLASSES AMIES ?

  //affichageMapPages(mapPages);
  affichage2(mapPages);


} //----- Fin de Graph








Graph::~Graph ( )
// Algorithme :
//
{
#ifdef DEBUG
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
