// But: Cr�er un r�pertoire t�l�phonique.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

// Inclure la structure de notre r�pertoire t�l�phonique.
#include "RepertoireTelephonique.h"

int main()
{
   // Fonction pour afficher les caract�res accentu�s.
   setlocale(LC_ALL, "");

   // Cr�er une instance du r�pertoire
   Repertoire MonRepertoire;

   // Demander � l'utilisateur. 
   // Pour le moment, cette fonction comprend le programme principal.
   // Dans un futur contexte, ce module pourrait �tre l�un des nombreux,
   // avec des options telles que la suppression ou la mise � jour d�un contact.
   MonRepertoire.demander();

   system("pause");
   return 0;
}