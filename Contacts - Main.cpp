// But: Créer un répertoire téléphonique.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

// Inclure la structure de notre répertoire téléphonique.
#include "RepertoireTelephonique.h"

int main()
{
   // Fonction pour afficher les caractères accentués.
   setlocale(LC_ALL, "");

   // Créer une instance du répertoire
   Repertoire MonRepertoire;

   // Demander à l'utilisateur. 
   // Pour le moment, cette fonction comprend le programme principal.
   // Dans un futur contexte, ce module pourrait être l’un des nombreux,
   // avec des options telles que la suppression ou la mise à jour d’un contact.
   MonRepertoire.demander();

   system("pause");
   return 0;
}