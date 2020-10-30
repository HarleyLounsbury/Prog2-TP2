// But: Cr�er un r�pertoire t�l�phonique.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "RepertoireTelephonique.h"

Repertoire::Repertoire()
{
   // Constructeur par d�faut. 
   // Initialiser les variables de la structure.
   iNbContact = 0;

   for (int i = 0; i < iMAX_CONTACTS; i++)
   {
      *(tabContact + i) = nullptr;
   }

   // Nous voudrons la date au moment de l'instanciation.
   DateDuJour.obtenirDateSysteme();
}

Repertoire::~Repertoire()
{
   cout << "D�structeur de RepertoireTelephonique." << endl;
   system("pause");
   for (int i = 0; i < iNbContact; i++)
   {
      delete * (tabContact + i);
   }
}

void Repertoire::demander()
{
   char cReponse;
   
   // On ajoute un contact tant qu'il reste de la place dans le tableau et que l'utilisateur veut en ajouter.
   do
   {
      // On affiche la liste.
      if (iNbContact > 1)
         afficherEnOrdreAlpha();
      else
      {
         afficher();
      }

      inserer();
            
      // On r�affiche la liste.
      if (iNbContact > 1)
         afficherEnOrdreAlpha();
      else
      {
         afficher();
      }

      // R�pertoire n'est pas plein, on demande � l'utilisateur pour continuer.
      if (iNbContact < iMAX_CONTACTS)
      {
         cout << "Voulez-vous continuer? (o/n) ";
         cin >> cReponse;
         cin.ignore(1, '\n');
      }
      else
      {
         cout << "Votre r�pertoire est plein." << endl;
      }

   } while (iNbContact < iMAX_CONTACTS && cReponse == 'o');

   return;
}

void Repertoire::afficher()
{
   // �ffacer l'�cran avant d'afficher.
   system("cls");

   afficherEnTete();
   // Si la liste est vide.
   if (iNbContact == 0)
   {
      cout << "Liste vide." << endl;
   }
   else
   {
      // Pour chaque contact dans le r�pertoire, on appel la m�thode de l'affichage. 
      for (int i = 0; i < iNbContact; i++)
      {
         (*(tabContact + i))->afficher(iCOL1, iCOL2, iCOL3, iCOL4, iCOL5);
         cout << endl;
      }
   }
   
   // Ligne de tirets pour faire beau. 
   cout << setw(iCOL1 + iCOL2 + iCOL3 + iCOL4 + iCOL5) << setfill('-') << "-" << setfill(' ') << endl;

   return;
}

void Repertoire::afficherEnTete()
{
   // Afficher l'en-t�te
   cout << left;
   // Ligne de tirets.
   cout << setw(iCOL1 + iCOL2 + iCOL3 + iCOL4 + iCOL5) << setfill('-') << "-" << setfill(' ') << endl;
   // Si mon nom �tait un peu plus long, il faudrait ajuster la largeur du r�pertoire.
   // En effet, m�me dans l'exemple fourni par la cliente, si on est dimanche au mois de septembre, notre en-t�te n'est plus aussi esth�tiquement agr�able.
   cout << "R�pertoire t�l�phonique de Harley Lounsbury en date du ";
   DateDuJour.afficherFormatLong();
   cout << endl;
   cout << setw(iCOL1 + iCOL2 + iCOL3 + iCOL4 + iCOL5) << setfill('-') << "-" << setfill(' ') << endl;
   cout << setw(iCOL1) << "Id" << setw(iCOL2) << "Nom" << setw(iCOL3) << "Pr�nom" << setw(iCOL4) << "Num�ro de t�l�phone" << setw(iCOL5) << "Date de naiss." << endl;
   cout << setw(iCOL1 + iCOL2 + iCOL3 + iCOL4 + iCOL5) << setfill('-') << "-" << setfill(' ') << endl;

   return;
}

void Repertoire::afficherErreurContactExistant(int iIndexContact)
{
   cout << "Vous avez d�j� un contact du nom de " << (*(tabContact + iIndexContact))->ptrPrenom << " " << (*(tabContact + iIndexContact))->ptrNom << "." << endl;
   cout << "Ce contact n'a pas �t� ajout� au carnet d'adresses." << endl;
   system("pause");

   return;
}

bool Repertoire::trouver(int &iIndexContact)
{
   // J'ai cr�� cette fonction au mieux de ma compr�hension en ce qui concerne les sp�cifications requises. 
   // Je crois qu�il existe une autre fa�on de structurer ces op�rations, mais j�ai pens� qu�il �tait plus prudent de suivre ce que je pensais avoir �t� demand�.
   for (int i = 0; i < iNbContact; i++)
   {
      // Si le nom et pr�nom sont pareils, on va devoir lib�rer de la m�moire du doublon, r�initaliser son pointeur, r�culer le nombre de contacts, et retourner l'index du contact original. 
      if (strcmp((*(tabContact + i))->ptrNom, (*(tabContact + iNbContact))->ptrNom) == 0 && strcmp((*(tabContact + i))->ptrPrenom, (*(tabContact + iNbContact))->ptrPrenom) == 0)
      {
         delete * (tabContact + iNbContact);
         *(tabContact + iNbContact) = nullptr;
         iNbContact--;
         iIndexContact = i;
         return true;
      }
   }
  
   return false;
}

void Repertoire::inserer()
{
   // Variable pour stocker la valeur d'un contact qui existe, si trouver() retourne vrai. 
   int iContactExistant = 0;
   // Avant de demander il faut allouer un nouveau contact.
   *(tabContact + iNbContact) = new Contact;

   if (*(tabContact + iNbContact) == nullptr)
   {
      cerr << "Erreur: M�moire insuffisante" << endl;
      system("pause");
      abort();
   }

   (*(tabContact + iNbContact))->demander(iNbContact + 1);

   // V�rifier pour doublon, si on a d�j� un contact enregistr�.
   if (iNbContact > 0)
      if (trouver(iContactExistant))
      {
         afficherErreurContactExistant(iContactExistant);
      }

   // Placer le num�ro d'indentifant dans le tableau pour trier en ordre croissant par nom.
   *(iTabOrdreAlpha + iNbContact) = (*(tabContact + iNbContact))->iNumeroIdentifiant;

   // On a ajouter un nouveau Contact, on doit ajuster le nombre de Contacts.
   iNbContact++;
}

void Repertoire::afficherEnOrdreAlpha()
{
   system("cls");
   // Trier en ordre croissant par nom.
   trierOrdreAlpha();

   // Afficher l'en-t�te.
   afficherEnTete();
   // Afficher les contacts.
   for (int i = 0; i < iNbContact; i++)
   {
      (*(tabContact + (*(iTabOrdreAlpha + i)) - 1))->afficher(iCOL1, iCOL2, iCOL3, iCOL4, iCOL5);
      cout << endl;
   }

   cout << setw(iCOL1 + iCOL2 + iCOL3 + iCOL4 + iCOL5) << setfill('-') << "-" << setfill(' ') << endl;

   return;
}

void Repertoire::trierOrdreAlpha()
{
   // Deux boucles FOR pour comparer les deux contacts en parall�le.
   for (int i = 0; i < iNbContact - 1; i++)
   {
      for (int j = i + 1; j < iNbContact; j++)
      {
         // Comparer les noms.
         if (strcmp((*(tabContact + *(iTabOrdreAlpha + i) - 1))->ptrNom, (*(tabContact + *(iTabOrdreAlpha + j) - 1))->ptrNom) > 0)
         {
            permuter(*(iTabOrdreAlpha + i), *(iTabOrdreAlpha + j));
         }
         else
         {
            // Si les noms sont 
            if (strcmp((*(tabContact + *(iTabOrdreAlpha + i) - 1))->ptrNom, (*(tabContact + *(iTabOrdreAlpha + j) - 1))->ptrNom) == 0 && strcmp((*(tabContact + *(iTabOrdreAlpha + i) - 1))->ptrPrenom, (*(tabContact + *(iTabOrdreAlpha + j) - 1))->ptrPrenom) > 0)
               permuter(*(iTabOrdreAlpha + i), *(iTabOrdreAlpha + j));
         }
      }
   }

   return;
}
