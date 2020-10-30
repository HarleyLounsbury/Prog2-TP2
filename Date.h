// But: Structure de date, incluant m�thodes pour la manipuler.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

// Inclure les biblioth�ques n�cessaires.
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Date
{
   // Variables pour la date.
   int iJour;
   int iMois;
   int iAnnee;
   int iJourDeLaSemaine;
   char* ptrJour = nullptr;
   char* ptrMois = nullptr;

   // Constructeur par d�faut.
   // On le recode pour initialiser les variables de la date.
   Date();
   // D�structeur pour lib�rer de la m�moire allou�e dynamiquement.
   ~Date();

   // M�thodes.
   void demander(const char* ptrDELIMITEUR);
   void demanderEtValider(const char* ptrDELIMITEUR);
   void determinerJourDeLaSemaineINT();
   bool estValide();
   void obtenirDateSysteme();
   void afficher(bool bAvecEndl);
   void determinerJourDeLaSemaine();
   void determinerMois();
   void afficherFormatLong();
};
