// But: Structure de date, incluant méthodes pour la manipuler.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

// Inclure les bibliothèques nécessaires.
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

   // Constructeur par défaut.
   // On le recode pour initialiser les variables de la date.
   Date();
   // Déstructeur pour libérer de la mémoire allouée dynamiquement.
   ~Date();

   // Méthodes.
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
