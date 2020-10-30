// But: Cr�er un structure pour stocker et manipuler un num�ro de t�l�phone.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#pragma once

// Inclure les biblioth�ques n�cessaires.
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
   // Variables pour le num�ro de t�l�phone.
   char* ptrNumero;
   int iType;
   // Pour faciliter la vie d'un utilisateur � l'affichage. 
   int iLongeurTypeEtNumero;

   // Constructeur par d�faut.
   // Initialiser les attributs.
   Telephone();
   // D�structeur.
   ~Telephone();

   // M�thodes.
   void demander();
   void saisirType();
   void demanderType();
   void afficherMenuTypes();
   // Afficher le num�ro de t�l�phone sous la forme: Type: xxx-xxx-xxxx
   void calcLongeurTypeEtNumero();
   void afficher();
};