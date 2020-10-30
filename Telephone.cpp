// But: Créer un structure pour stocker et manipuler un numéro de téléphone.
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
   cout << "Déstructeur de Telephone." << endl;
   if (ptrNumero)
      delete[] ptrNumero;

}

void Telephone::demander()
{
   // Variables locaux.
   // Constante pour le maximum nombre de caractères que l'utilisateur peut entrer.
   const int iMAX_CLAVIER = 8190;
   // Chaîne de caractères pour la saisi.
   char cClavier[iMAX_CLAVIER + 1];
   // Chaîne de caractères pour le numéro.
   char cNumero[iMAX_CLAVIER + 1];

   bool estValide = false;
   
   do
   {
      // Demander à l'utilisateur la date.
      cout << "Veuillez entrer le numéro de téléphone:";
      cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');
      // On doit vérifier que la chaîne n'est pas vide avant de découper.
      if (strlen(cClavier))
      {
         ;

         if (extraireChiffres(cNumero, cClavier) == 10)
            estValide = true;
         else
         {
            // Réinitialiser cNumero.
            cout << "Erreur : Le numéro de téléphone doit comporter 10 chiffres." << endl; 
            for (int i = 0; i < strlen(cClavier); i++)
               *(cNumero + i) = '\0';
         }
      }
   } while (!(estValide));

   // Allouer de la mémoire pour le numéro. Comme ça, si on veut accepter des numéros de téléphone ailleurs dans le monde, on a pas beaucoup à modifier :)
   ptrNumero = new char[strlen(cNumero)];
   
   // Copier le numéro dans notre variable.
   for (int i = 0; i < strlen(cNumero); i++)
      *(ptrNumero + i) = *(cNumero + i);


   // Demander le type de numéro.
   demanderType();

   return;
}

void Telephone::saisirType()
{
   // Oui, cette fonction fait la même chose que lireNombre(), une fonction bien connue. Si on utilise lireNombre(), on aura
   // le message d'erreur générique de lireNombre(), en plus de notre message d'erreur qui réitère les limites.

   // Pour lire toutes les bétises que pourrait taper l'utilisateur, on se crée une variable de type chaîne de caractères
   // suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];


   // On lit toute ce que l'utilisateur tape au clavier dans une chaîne de caractères
   // qui accepte n'importe quel caractère.
   cin.getline(cClavier, sizeof(cClavier), '\n');

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande à l'utilisateur
   while (*(cClavier) < cMIN_MENU || *(cClavier) > cMAX_MENU || strlen(cClavier) != 1)
   {
      cout << "Erreur: Vous devez entrer un nombre entre " << cMIN_MENU << " et " << cMAX_MENU << ": ";
      cin.getline(cClavier, sizeof(cClavier), '\n');
   }

   // Convertir la chaîne de caractères en entier.
   iType = atoi(cClavier);

   // une fois que nous avons toutes les informations nécessaires, nous pouvons calculer la longueur du message à afficher. 
   // En gardant le nombre et le type découplés, toute modification dans le contexte de notre affichage devient plus simple.
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
   cout << "Veuillez indiquer le type de téléphone :" << endl;
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
   // Ajouter le numéro de téléphone sour forme de xxx-xxx-xxxx.
   iLongeurTypeEtNumero += 12;

   return;
}
   
void Telephone::afficher()
{
   // Afficher le type.
   cout << *(cTYPES + iType - 1) << ": ";

   // Afficher le numéro. 
   // Les tirets sont uniquement pour l'affichage. 
   // Le numéro de téléphone en tant que chaîne de chiffres est plus flexible pour d'autres types d'affichage (parenthèses, espaces, etc.)
   for (int i = 0; i < 10; i++)
   {
      cout << *(ptrNumero + i);
      if (i == 2 || i == 5)
         cout << "-";
   }
   return;
}
      
