// But: Créer structure pour stocker les informations d'un ou plusieurs contacts.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

#include "Date.h"
#include "Telephone.h"
#include "fonctions.h"

// Constantes pour le nombre de carctères maximum dans un nom ou prénom. 
const int iMAX_NOM = 15;

struct Contact
{
   // Variables pour le contact.
   int iNumeroIdentifiant;
   char* ptrNom;
   char* ptrPrenom;
   Date DateDeNaissance;
   Telephone TelephoneContact;

   // Constructeur par défaut pour initialiser les pointeurs.
   Contact();
   // Déstructeur pour libérer de la mémoire qui a été allouée dynamiquement.
   ~Contact();
 
   // Méthodes.
   void demander(int iIndentifiant);
   // Surchargement de méthode demander, sans le numéro identifiant.
   void demander();
   
   void afficher(const int iCOL1, const int iCOL2, const int iCOL3, const int iCOL4, const int iCOL5);
};