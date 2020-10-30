// But: Cr�er structure pour stocker les informations d'un ou plusieurs contacts.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

#include "Date.h"
#include "Telephone.h"
#include "fonctions.h"

// Constantes pour le nombre de carct�res maximum dans un nom ou pr�nom. 
const int iMAX_NOM = 15;

struct Contact
{
   // Variables pour le contact.
   int iNumeroIdentifiant;
   char* ptrNom;
   char* ptrPrenom;
   Date DateDeNaissance;
   Telephone TelephoneContact;

   // Constructeur par d�faut pour initialiser les pointeurs.
   Contact();
   // D�structeur pour lib�rer de la m�moire qui a �t� allou�e dynamiquement.
   ~Contact();
 
   // M�thodes.
   void demander(int iIndentifiant);
   // Surchargement de m�thode demander, sans le num�ro identifiant.
   void demander();
   
   void afficher(const int iCOL1, const int iCOL2, const int iCOL3, const int iCOL4, const int iCOL5);
};