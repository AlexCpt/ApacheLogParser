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
#include <string>
#include <fstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "lecteurLog.h"
//------------------------------------------------------------- Constantes
const string delimiteur = " ";
const string URL_LOCALE = "http://intranet-if.insa-lyon.fr";
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
  for (typename M::const_iterator it = m.cbegin(); it!= m.cend(); it++)
  {
    map<int, string>::iterator itIndex;
    itIndex = index.find(it->first);

    cout << itIndex->second;

    cout << " (" <<it->second.hits << " hit(s))"<<endl;
  }
  cout << endl;
}

void Graph::affichageTopHits()
{
  cout << "Affichage Top 10 hits" <<endl << "-----------------------------" <<endl;
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

void Graph::add (const string ligne)
{
  vector<string> ligneHach;    // Pas forcément vector??????
  split(ligne, ligneHach);

  //URL du GET
  string urlGet = ligneHach[6];
  string urlRef = ligneHach[10];

  const string heureRequete = ligneHach[3];
  const int heureIntRequete = stoi(heureRequete.substr(13,2));

  //On enlève les guillemets
  urlRef.pop_back();

  // On enlève l'URL locale
  if(urlRef.size() > 0)
  {
    urlRef = urlRef.substr(1,urlRef.size()-1);

    if (urlRef.find(URL_LOCALE)!= std::string::npos)
    {
		    urlRef=urlRef.substr(URL_LOCALE.size(),urlRef.size());
	  }
  }

  //On enlève les headers
  urlRef = urlRef.substr(0,urlRef.find("?"));
  urlRef = urlRef.substr(0,urlRef.find(";"));

  //On enlève les variables
  urlGet = urlGet.substr(0,urlGet.find("?"));
  urlGet = urlGet.substr(0,urlGet.find(";"));

  //On enlève le "/" si il est à la fin
  if(urlGet[urlGet.size()-1] == '/')
  {
    urlGet.pop_back();
  }
  if(urlRef[urlRef.size()-1] == '/')
  {
    urlRef.pop_back();
  }

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
    else if(urlGet.find(".ics") != -1)
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

  //GET : On check si la page existe
  map <string,int>::iterator itIndexInvGet;
  itIndexInvGet = indexInv.find(urlGet); // URL de la page GET

  //Si oui on augmente le nombre de hits
  if(itIndexInvGet != indexInv.end())
  {
    map <int,infosPage>::iterator itPages;

    //get le i qui correspond à l'url
    itPages = mapPages.find(itIndexInvGet->second);
    itPages->second.hits ++;

  }

  //GET : Sinon on la crée
  else if(itIndexInvGet == indexInv.end())
  {
    infosPage monInfosPages(1);
    mapPages.insert(make_pair(indicePage, monInfosPages)); // ou insert({i, monInfosPages})
    index.insert(make_pair(indicePage, urlGet));
    indexInv.insert(make_pair(urlGet, indicePage));
    indicePage++;
  }

  //REF : si ref pas "-"
 if(urlRef != "-")
 {
   //REF : On check si la page existe
   map<string,int>::iterator itIndexInvRef= indexInv.find(urlRef);

   //Si oui on vérifie que la connexion existe dans la page REF
   if(itIndexInvRef != indexInv.end())
   {
     map<int,int>::iterator itConnexion;
     map <int,infosPage>::iterator itPages;

     itPages = mapPages.find(itIndexInvRef->second);

     itConnexion = itPages->second.connexions.find(itIndexInvGet->second);

     //Si existe on augmente les hits
     if(itConnexion != itPages->second.connexions.end())
     {
         itConnexion->second++; // on augmente le hit
     }
     //Sinon on crée
     else
     {
       itPages->second.connexions.insert(make_pair(itIndexInvGet->second, 1));
     }
   }

   //REF : Sinon on la crée la page
   else if(itIndexInvRef == indexInv.end())
   {
     infosPage monInfosPages(0); //hit = 0
     mapPages.insert(make_pair(indicePage, monInfosPages)); // ou insert({i, monInfosPages})
     index.insert(make_pair(indicePage, urlRef));
     indexInv.insert(make_pair(urlRef, indicePage));


     //REF et on crée la connexion
     map <int,infosPage>::iterator itPages;
     itPages = mapPages.find(indicePage); //i de Ref
     itPages->second.connexions.insert(make_pair(itIndexInvGet->second, 1));

      indicePage++;
   }
 }
}


void Graph::createHighHit()
{
    //On crée le vecteur
   tabIndiceMaxHits.reserve(10);

    //On rentre le premier
    map<int, infosPage>::iterator itGraph = mapPages.begin();
    map<int, infosPage>::iterator itComp;

    tabIndiceMaxHits.push_back(itGraph->first);
    itGraph++;

    //On remplit avec les 9 suivants
    int i=1;
    int maxTopHit=0;

    if(mapPages.size()>10)
    {
		    maxTopHit=10;
	  }
	  else
	  {
		    maxTopHit=mapPages.size();
	  }

    for(; i<maxTopHit; itGraph++)
    {
        vector<int>::iterator itVect;
        for(itVect = tabIndiceMaxHits.begin(); itVect!= tabIndiceMaxHits.end(); itVect++)
        {
          itComp = mapPages.find(*itVect);
          if(itGraph->second.hits > itComp->second.hits)
          {
            tabIndiceMaxHits.insert(itVect, itGraph->first);
            break;
          }

        }
        if (itVect == tabIndiceMaxHits.end())
        {
          tabIndiceMaxHits.push_back(itGraph->first);
        }

          i++;
    }

	if(mapPages.size()>10)
	{
		//On passe à la 11ème page pour la suite
		itGraph++;

		//On reparcourt toute la map
		for( ; itGraph != mapPages.end(); itGraph++)
		{
		  vector<int>::iterator itVect;
		  for(itVect = tabIndiceMaxHits.begin(); itVect!= tabIndiceMaxHits.end(); itVect++)
		  {
  			itComp = mapPages.find(*itVect);
  			if(itGraph->second.hits > itComp->second.hits)
  			{
  			  tabIndiceMaxHits.pop_back();
  			  tabIndiceMaxHits.insert(itVect, itGraph->first);
  			  break;
  			}
		  }
		}
	}
}

void Graph::split (const string ligne, vector<string> & ligneHach)
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

void Graph::createGraph()
{
    ofstream fichier(nomDot, ios::out | ios::trunc);

            if(fichier)
            {
                fichier << "digraph {" << endl;
                //On parcourt mapPages pour les noeuds
                for(map<int, infosPage>::iterator itGraph = mapPages.begin(); itGraph != mapPages.end(); itGraph++)
                {
                    map<int,string>::iterator itIndex = index.find(itGraph->first);
                    fichier <<"node" << itGraph->first << " [label=\"" << itIndex->second << "\"];" << endl;
                }

               for(map<int, infosPage>::iterator itGraph = mapPages.begin(); itGraph != mapPages.end(); itGraph++)
              {
                 for(map<int,int>::iterator itConnexion = itGraph->second.connexions.begin(); itConnexion != itGraph->second.connexions.end(); itConnexion++)
                {
                    fichier << "node" << itGraph->first <<" -> node" << itConnexion->first <<" [label=\"" << itConnexion->second <<"\"];" <<endl;
                }

              }

              fichier << "}";
              fichier.close();
            }
            else
            {
              cerr << "Impossible d'ouvrir le fichier " << nomDot << endl;
            }
}

//Pas sûr que tout mettre dans le constructeur très bonne idée (méthodes séparées ?)
Graph::Graph (string nl, string nD, bool eDoc, int h)
{
#ifdef DEBUG
    cout << "Appel au constructeur de <Graph>" << endl;
#endif

	nomLog = nl;
  nomDot = nD;
  indicePage = 0;
  excluDoc = eDoc;
  heure = h;

	//Création du lecteur
	lecteurLog monlecteurLog;

	if(monlecteurLog.read(nomLog, eDoc, h, this) == 0)
	{
	  createHighHit();

	  //Affichage tableau top hits
	  affichageTopHits();

	  //Affichage de tout
	  //affichage2(mapPages);

	  if(nomLog != "false")
	  {
		  createGraph();
	  }
	}

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
