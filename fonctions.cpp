// But: Fonctions d'usgae g�n�rale.
// Auteur: Harley Lounsbury
// Date: 01/04/2019


#include "fonctions.h"

// AVIS:
// Cette fonction contient une allocation de m�moire dynamique. 
// L'utilisation de cette fonction n�cessite la d�sallocation. 
// � utiliser � vos risques et p�rils.
char * demanderChaine(const int iMAX_CAR, const char * ptrINVITE)
{
   const int iMAX_CLAVIER = 8190;
   char cClavier[iMAX_CLAVIER + 1];
   char* ptrChaine = nullptr;

   cout << ptrINVITE;
   cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

   while (strlen(cClavier) > iMAX_CAR)
   {
      cerr << "Erreur: Vous avez un maximum de " << iMAX_CAR << " caract�res." << endl;
      cout << ptrINVITE;
      cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');
   }

   // Dans cClavier, on a la cha�ne de la bonne longeur.
   // On alloue la m�moire de la bonne taille -> strlen+1

   // IMPORTANT:
   // Quand on utilise cette fonction, n'oublie pas de lib�rer la m�moire (delete[])
   ptrChaine = new char[strlen(cClavier) + 1];
   if (ptrChaine == nullptr)
   {
      cerr << "M�moire insuffisant. Goodbye." << endl;
      system("pause");
      abort();
   }

   // On doit copier le contenu de cClavier dans ptrChaine.
   strcpy_s(ptrChaine, strlen(cClavier) + 1, cClavier);

   return ptrChaine;
}

int extraireChiffres(char* ptrDest, char* ptrSource)
{
   // Fonction pour extraire les chiffres d'une cha�ne de caract�res et retourner combien de chiffres ont �t� extrait.
   int iCompteur = 0;
   // Boucle pour chercher chaque chiffre.
   for (int i = 0; i < strlen(ptrSource); i++)
   {
      // On va seulement prendre la caract�re si c'est bien un chiffre.
      if (*(ptrSource + i) >= '0' && *(ptrSource + i) <= '9')
      {
         *(ptrDest + iCompteur) = *(ptrSource + i);
         iCompteur++;
      }
   }
   // En ajoutant ceci � la fin, notre nouvelle cha�ne de nombres peut �tre utilis�e dans des fonctions de biblioth�que standard telles que strlen().
   *(ptrDest + iCompteur + 1) = '\0';

   return iCompteur;
}

void permuter(int & iChiffre1, int & iChiffre2)
{
   // Variable interm�diaire.
   int iTemp;
   // On copie la valeur du premier nombre dans la variable.
   iTemp = iChiffre1;
   // On �crase le premier avec le deuxi�me.
   iChiffre1 = iChiffre2;
   // On copie le premier dans le deuxi�me.
   iChiffre2 = iTemp;
}