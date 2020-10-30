// But: Créer structure pour stocker les informations d'un ou plusieurs contacts.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "Contact.h"

Contact::Contact()
{
   // Constucteur par défaut. 
   // Initialiser les variables de la structure. 
   iNumeroIdentifiant = 0;
   ptrNom = nullptr;
   ptrPrenom = nullptr;
}

Contact::~Contact()
{
   cout << "Déstructeur de Contact." << endl;
   if (ptrNom)
      delete[] ptrNom;
   if (ptrPrenom)
      delete[] ptrPrenom;
}

void Contact::demander(int iIndentifiant)
{
   // Quand il y a un numéro d'identifiant fourni par le programme principale. 
   iNumeroIdentifiant = iIndentifiant;
   // Demander les informations à l'utilisateur, un champ à la fois. 
   cout << "Pour ajouter un nouveau contact, veuillez indiquer les informations suivantes:" << endl;
  

   ptrNom = demanderChaine(iMAX_NOM, "Nom du contact: ");
   ptrPrenom = demanderChaine(iMAX_NOM, "Prénom du contact: ");
   TelephoneContact.demander();
   cout << "Veuillez entrer la date de naissance: " << endl;
   DateDeNaissance.demanderEtValider("-/.,:;<>!@#\\");

   return;
}

void Contact::demander()
{
   // Demander les informations à l'utilisateur, un champ à la fois. 
   cout << "Pour ajouter un nouveau contact, veuillez indiquer les informations suivantes:" << endl;
   ptrNom = demanderChaine(iMAX_NOM, "Nom du contact: ");
   ptrPrenom = demanderChaine(iMAX_NOM, "Prénom du contact: ");
   TelephoneContact.demander();
   cout << "Veuillez entrer la date de naissance: " << endl;
   DateDeNaissance.demanderEtValider("-/.,:;<>!@#\\");

   return;
}

void Contact::afficher(const int iCOL1, const int iCOL2, const int iCOL3, const int iCOL4, const int iCOL5)
{
   // Afficher les informations du contact.
   // Les colonnes passées en paramétre permet d'ajuster l'éspacement selon les critères d'utilisation.
   cout << left;
   cout << setw(iCOL1) << iNumeroIdentifiant;
   cout << setw(iCOL2) << ptrNom;
   cout << setw(iCOL3) << ptrPrenom;
   TelephoneContact.afficher();

   cout << setw((iCOL4 - TelephoneContact.iLongeurTypeEtNumero)) << setfill(' ') << " ";
   DateDeNaissance.afficher(false);

   return;
}
