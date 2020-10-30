// But: Créer un structure pour stocker et manipuler un numéro de téléphone.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

// Inclure les bibliothèques nécessaires.
#include <iostream>
#include <ctime>
#include <iomanip>
#include "fonctions.h"

using namespace std;

// Constantes pour le type.
const int iCELLULAIRE = 1;
const int iMAISON = 2;
const int iBUREAU = 3;
const int iURGENCE = 4;
const int iAUTRE = 5;

const int iMIN_TYPE = 1;
const int iMAX_TYPE = 5;

const char cTYPES[iMAX_TYPE][11] = { "Cellulaire", "Maison", "Bureau", "Urgence", "Autre" };

const char cMIN_MENU = '1';
const char cMAX_MENU = '5';

struct Telephone
{
   // Variables pour le numéro de téléphone.
   char* ptrNumero;
   int iType;
   // Pour faciliter la vie d'un utilisateur à l'affichage. 
   int iLongeurTypeEtNumero;

   // Constructeur par défaut.
   // Initialiser les attributs.
   Telephone();
   // Déstructeur.
   ~Telephone();

   // Méthodes.
   void demander();
   void saisirType();
   void demanderType();
   void afficherMenuTypes();
   // Afficher le numéro de téléphone sous la forme: Type: xxx-xxx-xxxx
   void calcLongeurTypeEtNumero();
   void afficher();
};