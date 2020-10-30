// But: Fonctions d'usgae générale.
// Auteur: Harley Lounsbury
// Date: 01/04/2019


#include "fonctions.h"

// AVIS:
// Cette fonction contient une allocation de mémoire dynamique. 
// L'utilisation de cette fonction nécessite la désallocation. 
// À utiliser à vos risques et périls.
char * demanderChaine(const int iMAX_CAR, const char * ptrINVITE)
{
   const int iMAX_CLAVIER = 8190;
   char cClavier[iMAX_CLAVIER + 1];
   char* ptrChaine = nullptr;

   cout << ptrINVITE;
   cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

   while (strlen(cClavier) > iMAX_CAR)
   {
      cerr << "Erreur: Vous avez un maximum de " << iMAX_CAR << " caractères." << endl;
      cout << ptrINVITE;
      cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');
   }

   // Dans cClavier, on a la chaîne de la bonne longeur.
   // On alloue la mémoire de la bonne taille -> strlen+1

   // IMPORTANT:
   // Quand on utilise cette fonction, n'oublie pas de libérer la mémoire (delete[])
   ptrChaine = new char[strlen(cClavier) + 1];
   if (ptrChaine == nullptr)
   {
      cerr << "Mémoire insuffisant. Goodbye." << endl;
      system("pause");
      abort();
   }

   // On doit copier le contenu de cClavier dans ptrChaine.
   strcpy_s(ptrChaine, strlen(cClavier) + 1, cClavier);

   return ptrChaine;
}

int extraireChiffres(char* ptrDest, char* ptrSource)
{
   // Fonction pour extraire les chiffres d'une chaîne de caractères et retourner combien de chiffres ont été extrait.
   int iCompteur = 0;
   // Boucle pour chercher chaque chiffre.
   for (int i = 0; i < strlen(ptrSource); i++)
   {
      // On va seulement prendre la caractère si c'est bien un chiffre.
      if (*(ptrSource + i) >= '0' && *(ptrSource + i) <= '9')
      {
         *(ptrDest + iCompteur) = *(ptrSource + i);
         iCompteur++;
      }
   }
   // En ajoutant ceci à la fin, notre nouvelle chaîne de nombres peut être utilisée dans des fonctions de bibliothèque standard telles que strlen().
   *(ptrDest + iCompteur + 1) = '\0';

   return iCompteur;
}

void permuter(int & iChiffre1, int & iChiffre2)
{
   // Variable intermèdiaire.
   int iTemp;
   // On copie la valeur du premier nombre dans la variable.
   iTemp = iChiffre1;
   // On écrase le premier avec le deuxième.
   iChiffre1 = iChiffre2;
   // On copie le premier dans le deuxième.
   iChiffre2 = iTemp;
}