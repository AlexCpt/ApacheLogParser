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
#define TAILLE_TAB_HIGH_HIT 10
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
    map<int, string>::iterator itIndex;
    itIndex = index.find(it->first);

    cout << itIndex->second;

    cout << " (" <<it->second.hits << " hit(s))"<<endl;
  }
  cout << endl;
}

void Graph::affichageTopHits ()
{
  cout << "Affichage Top 10 hits" <<endl;
  for(vector<int>::iterator itTab = tabIndiceMaxHits.begin(); itTab != tabIndiceMaxHits.end(); itTab++)
  {
    map<int, string>::iterator itIndex;
    itIndex = index.find(*itTab);

    map<int, infosPage>::iterator itPage;
    itPage = mapPages.find(*itTab);

    cout << itIndex->second;
    cout << " (" <<itPage->second.hits << " hit(s))"<<endl;
  }
  cout << endl;


}

void Graph::add (string ligne)
{
  //Découpage de la ligne : (pas générique)
  vector<string> ligneHach;    // Pas forcément vector??????
  split(ligne, ligneHach);

  //URL du GET
  string urlGet = ligneHach[6];
  const string heureRequete = ligneHach[3];
  const int heureIntRequete = stoi(heureRequete.substr(13,2));

  //On enlève les variables
  urlGet = urlGet.substr(0,urlGet.find("?"));
  urlGet = urlGet.substr(0,urlGet.find(";"));

  //On check si pas doc
  if(excluDoc)
  {
    if(urlGet.find(".jpg") != -1)
    {
      return;
    }
    else if(urlGet.find(".jpeg") != -1)
    {
      return;
    }
    else if(urlGet.find(".tiff") != -1)
    {
      return;
    }
    else if(urlGet.find(".gif") != -1)
    {
      return;
    }
    else if(urlGet.find(".png") != -1)
    {
      return;
    }
    else if(urlGet.find(".bmp") != -1)
    {
      return;
    }
    else if(urlGet.find(".ico") != -1)
    {
      return;
    }
    else if(urlGet.find(".css") != -1)
    {
      return;
    }
    else if(urlGet.find(".js") != -1)
    {
      return;
    }
    else if(urlGet.find(".doc") != -1)
    {
      return;
    }
    else if(urlGet.find(".docx") != -1) //utile ?
    {
      return;
    }
    else if(urlGet.find(".pdf") != -1) //utile ?
    {
      return;
    }
  }

  // Tri horaire
  if(heure != -1)
  {
    if(heureIntRequete != heure)
    {
      return;
    }
  }

  //On check si la page existe
  map <string,int>::iterator itIndexInv;
  itIndexInv = indexInv.find(urlGet);// URL de la page GET

  //Si oui on augmente le nombre de hits
  if(itIndexInv != indexInv.end())
  {
    map <int,infosPage>::iterator itPages;

    //get le i qui correspond à l'url
    itPages = mapPages.find(itIndexInv->second);
    itPages->second.hits ++;

    majHighHit(itPages);
  }

  //Sinon on la crée
  else if(itIndexInv == indexInv.end())
  {
    infosPage monInfosPages(1);
    mapPages.insert(make_pair(indicePage, monInfosPages)); // ou insert({i, monInfosPages})
    index.insert(make_pair(indicePage, urlGet));
    indexInv.insert(make_pair(urlGet, indicePage));

    //majHighHit(itPages); //AUSSI ICI


    indicePage++;
  }
}

// On met à jour le tab par rapport au nouveau it (JE ME DEMANDE SI LA METHODE multimap inversée est pas plus simple)
// OPTI !?
void Graph::majHighHit(map<int,infosPage>::iterator & it)
{
    //on cherche le hit mini

    map<int,infosPage>::iterator itMapPage;
    itMapPage = mapPages.find(tabIndiceMaxHits[TAILLE_TAB_HIGH_HIT-1]);
    int hitMini = itMapPage->second.hits;

    //cout
    map <int,string>::iterator itIndex;
    itIndex = index.find(it->first);
    cout << "majHighHit pour " << itIndex ->second << endl;
    cout << "hitMini du tab = "  << hitMini <<endl;

    // Si nbHits < hits mini du tableau
    if(it->second.hits < hitMini)
    {
      cout << "hit de la page < hitMini" <<endl <<endl;
      return;
    }
    else
    {
      // Tableau à l'envers : tab[9] plus petit hit tab[0] plus grand hit
      // On cherche où l'insérer
        cout << "boucle for" <<endl;
        for(vector<int>::iterator itTab = tabIndiceMaxHits.begin(); itTab != tabIndiceMaxHits.end(); itTab++)
        {
          itMapPage = mapPages.find(*itTab);
          if(it->second.hits > itMapPage->second.hits)
          {
            //on vérifie si indice pas déjà dedans
            vector<int>::iterator dejaPresent = find(tabIndiceMaxHits.begin(), tabIndiceMaxHits.end(), it->first);

            if(dejaPresent != tabIndiceMaxHits.end())
            {
              //si oui on l'efface
              tabIndiceMaxHits.erase(dejaPresent); //multiple ?
              tabIndiceMaxHits.insert(itTab, it->first);
              //cout << "déjà pres" <<endl;
              cout << endl;

              return;
            }
            else if (dejaPresent == tabIndiceMaxHits.end())
            {
              //cout << "pas pres" << endl;
              //sinon on efface le dernier
              tabIndiceMaxHits.pop_back();
              tabIndiceMaxHits.insert(itTab, it->first);
              cout << endl;

              return;
            }
          }
        }
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
  excluDoc = eDoc;
  heure = h;
  tabIndiceMaxHits = vector<int>(10,0);


	//Création du lecteur
	lecteurLog monlecteurLog;


  /*for(vector<int>::iterator itTab = tabIndiceMaxHits.begin(); itTab != tabIndiceMaxHits.end(); itTab++)
  {
    cout << *itTab <<endl;
  }*/


	monlecteurLog.read(nomLog, eDoc, h, this); // PLUTOT FAIRE CLASSES AMIES ?


  //Affichage tableau top hits
  affichageTopHits();

  //Affichage de tout
  //affichageMapPages(mapPages);
  //affichage2(mapPages);






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
