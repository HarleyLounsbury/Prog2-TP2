// But: Créer un répertoire téléphonique.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

#include "Contact.h"


// Constante pour le nombre de contacts maximum. Veuillez changer ce nombre pour accommoder vos besoins. 
const int iMAX_CONTACTS = 100;

// Les colonnes de l'affichage.
const int iCOL1 = 4;
const int iCOL2 = 16;
const int iCOL3 = 16;
const int iCOL4 = 27;
const int iCOL5 = 15;

struct Repertoire
{
   // Variables de la structure.
   // Tableau de pointeurs vers chaque contact.
   Contact* tabContact[iMAX_CONTACTS];
   int iNbContact;
   Date DateDuJour;
   int iTabOrdreAlpha[iMAX_CONTACTS];
   
   // Constructeur par défaut pour initialiser les variables.
   Repertoire();
   // Déstructeur pour libérer de la mémoire.
   ~Repertoire();

   // Méthodes.
   void demander();
   void afficher();
   void afficherEnTete();
   void afficherErreurContactExistant(int iIndexContact);

   bool trouver(int &iIndexContact);
   void inserer();
   void afficherEnOrdreAlpha();
   void trierOrdreAlpha();
};