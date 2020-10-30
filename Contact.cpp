// But: Cr�er structure pour stocker les informations d'un ou plusieurs contacts.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "Contact.h"

Contact::Contact()
{
   // Constucteur par d�faut. 
   // Initialiser les variables de la structure. 
   iNumeroIdentifiant = 0;
   ptrNom = nullptr;
   ptrPrenom = nullptr;
}

Contact::~Contact()
{
   cout << "D�structeur de Contact." << endl;
   if (ptrNom)
      delete[] ptrNom;
   if (ptrPrenom)
      delete[] ptrPrenom;
}

void Contact::demander(int iIndentifiant)
{
   // Quand il y a un num�ro d'identifiant fourni par le programme principale. 
   iNumeroIdentifiant = iIndentifiant;
   // Demander les informations � l'utilisateur, un champ � la fois. 
   cout << "Pour ajouter un nouveau contact, veuillez indiquer les informations suivantes:" << endl;
  

   ptrNom = demanderChaine(iMAX_NOM, "Nom du contact: ");
   ptrPrenom = demanderChaine(iMAX_NOM, "Pr�nom du contact: ");
   TelephoneContact.demander();
   cout << "Veuillez entrer la date de naissance: " << endl;
   DateDeNaissance.demanderEtValider("-/.,:;<>!@#\\");

   return;
}

void Contact::demander()
{
   // Demander les informations � l'utilisateur, un champ � la fois. 
   cout << "Pour ajouter un nouveau contact, veuillez indiquer les informations suivantes:" << endl;
   ptrNom = demanderChaine(iMAX_NOM, "Nom du contact: ");
   ptrPrenom = demanderChaine(iMAX_NOM, "Pr�nom du contact: ");
   TelephoneContact.demander();
   cout << "Veuillez entrer la date de naissance: " << endl;
   DateDeNaissance.demanderEtValider("-/.,:;<>!@#\\");

   return;
}

void Contact::afficher(const int iCOL1, const int iCOL2, const int iCOL3, const int iCOL4, const int iCOL5)
{
   // Afficher les informations du contact.
   // Les colonnes pass�es en param�tre permet d'ajuster l'�spacement selon les crit�res d'utilisation.
   cout << left;
   cout << setw(iCOL1) << iNumeroIdentifiant;
   cout << setw(iCOL2) << ptrNom;
   cout << setw(iCOL3) << ptrPrenom;
   TelephoneContact.afficher();

   cout << setw((iCOL4 - TelephoneContact.iLongeurTypeEtNumero)) << setfill(' ') << " ";
   DateDeNaissance.afficher(false);

   return;
}
