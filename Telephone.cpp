// But: Cr�er un structure pour stocker et manipuler un num�ro de t�l�phone.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "Telephone.h"

Telephone::Telephone()
{
   // Initialiser les attributs de la structure.
   iType = 0;
   iLongeurTypeEtNumero = 0;
   ptrNumero = nullptr;
}

Telephone::~Telephone()
{
   cout << "D�structeur de Telephone." << endl;
   if (ptrNumero)
      delete[] ptrNumero;

}

void Telephone::demander()
{
   // Variables locaux.
   // Constante pour le maximum nombre de caract�res que l'utilisateur peut entrer.
   const int iMAX_CLAVIER = 8190;
   // Cha�ne de caract�res pour la saisi.
   char cClavier[iMAX_CLAVIER + 1];
   // Cha�ne de caract�res pour le num�ro.
   char cNumero[iMAX_CLAVIER + 1];

   bool estValide = false;
   
   do
   {
      // Demander � l'utilisateur la date.
      cout << "Veuillez entrer le num�ro de t�l�phone:";
      cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');
      // On doit v�rifier que la cha�ne n'est pas vide avant de d�couper.
      if (strlen(cClavier))
      {
         ;

         if (extraireChiffres(cNumero, cClavier) == 10)
            estValide = true;
         else
         {
            // R�initialiser cNumero.
            cout << "Erreur : Le num�ro de t�l�phone doit comporter 10 chiffres." << endl; 
            for (int i = 0; i < strlen(cClavier); i++)
               *(cNumero + i) = '\0';
         }
      }
   } while (!(estValide));

   // Allouer de la m�moire pour le num�ro. Comme �a, si on veut accepter des num�ros de t�l�phone ailleurs dans le monde, on a pas beaucoup � modifier :)
   ptrNumero = new char[strlen(cNumero)];
   
   // Copier le num�ro dans notre variable.
   for (int i = 0; i < strlen(cNumero); i++)
      *(ptrNumero + i) = *(cNumero + i);


   // Demander le type de num�ro.
   demanderType();

   return;
}

void Telephone::saisirType()
{
   // Oui, cette fonction fait la m�me chose que lireNombre(), une fonction bien connue. Si on utilise lireNombre(), on aura
   // le message d'erreur g�n�rique de lireNombre(), en plus de notre message d'erreur qui r�it�re les limites.

   // Pour lire toutes les b�tises que pourrait taper l'utilisateur, on se cr�e une variable de type cha�ne de caract�res
   // suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];


   // On lit toute ce que l'utilisateur tape au clavier dans une cha�ne de caract�res
   // qui accepte n'importe quel caract�re.
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande � l'utilisateur
   while (*(cClavier) < cMIN_MENU || *(cClavier) > cMAX_MENU || strlen(cClavier) != 1)
   {
      cout << "Erreur: Vous devez entrer un nombre entre " << cMIN_MENU << " et " << cMAX_MENU << ": ";
      cin.getline(cClavier, sizeof(cClavier), '\n');
   }

   // Convertir la cha�ne de caract�res en entier.
   iType = atoi(cClavier);

   // une fois que nous avons toutes les informations n�cessaires, nous pouvons calculer la longueur du message � afficher. 
   // En gardant le nombre et le type d�coupl�s, toute modification dans le contexte de notre affichage devient plus simple.
   calcLongeurTypeEtNumero();

   return;
}

void Telephone::demanderType()
{
   // Afficher le menu.
   afficherMenuTypes();
   // Saisir le choix de l'utilisateur.
   saisirType();

   return;
}

void Telephone::afficherMenuTypes()
{
   // Afficher les choix de type. 
   cout << "Veuillez indiquer le type de t�l�phone :" << endl;
   cout << "1. Cellulaire" << endl;
   cout << "2. Maison" << endl;
   cout << "3. Bureau" << endl;
   cout << "4. Urgence" << endl;
   cout << "5. Autre" << endl;
   cout << "Votre choix-- >";

   return;
}

void Telephone::calcLongeurTypeEtNumero()
{
   // Longeur du type.
   iLongeurTypeEtNumero += strlen(*(cTYPES + iType - 1));
   // Ajouter le longeur de ": ".
   iLongeurTypeEtNumero += 2;
   // Ajouter le num�ro de t�l�phone sour forme de xxx-xxx-xxxx.
   iLongeurTypeEtNumero += 12;

   return;
}
   
void Telephone::afficher()
{
   // Afficher le type.
   cout << *(cTYPES + iType - 1) << ": ";

   // Afficher le num�ro. 
   // Les tirets sont uniquement pour l'affichage. 
   // Le num�ro de t�l�phone en tant que cha�ne de chiffres est plus flexible pour d'autres types d'affichage (parenth�ses, espaces, etc.)
   for (int i = 0; i < 10; i++)
   {
      cout << *(ptrNumero + i);
      if (i == 2 || i == 5)
         cout << "-";
   }
   return;
}
      
