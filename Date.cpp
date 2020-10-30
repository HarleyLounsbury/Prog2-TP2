// But: Structure de date, incluant méthodes pour la manipuler.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "Date.h"

Date::Date()
{
   // Constructeur par défaut. 
   // Initialiser les variables de la structure.
   iJour = 0;
   iMois = 0;
   iAnnee = 0;
}

Date::~Date()
{
   cout << "Déstructeur de Date." << endl;
   system("pause");
   // Si de la mémoire a été allouée dynamiquement, on doit la libérer.
   if(ptrJour)
      delete[] ptrJour;
   if(ptrMois)
      delete[] ptrMois;
}

void Date::demander(const char* ptrDELIMITEUR)
{
   // Variables locaux.
   // Constante pour le maximum nombre de caractères que l'utilisateur peut entrer.
   const int iMAX_CLAVIER = 8190;
   // Chaîne de caractères pour la saisi.
   char cClavier[iMAX_CLAVIER + 1];
   // Deux pointeurs pour découper la chaîne de caractères.
   char* ptrParcours;
   char* ptrSuivant;

   // Demander à l'utilisateur la date.
   cout << "La saisie de la date doit être sous la forme jj/mm/aaaa :";
   cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

   // On doit vérifier que la chaîne n'est pas vide avant de découper.
   if (strlen(cClavier))
   {
      // On découpe pour stocké le jour dans la variable iJour.
      ptrParcours = strtok_s(cClavier, ptrDELIMITEUR, &ptrSuivant);
      iJour = atoi(ptrParcours);

      // On passe au mois, on découpe et on stock le mois dans la variable iMois.
      if (strlen(ptrSuivant))
      {
         ptrParcours = strtok_s(NULL, ptrDELIMITEUR, &ptrSuivant);
         iMois = atoi(ptrParcours);
      }
      // Il reste les années.
      iAnnee = atoi(ptrSuivant);
   }
   return;
}

void Date::demanderEtValider(const char * ptrDELIMITEUR)
{
   // Demander à l'utilisateur.
   demander(ptrDELIMITEUR);

   // Tant que la saisi n'est pas valide, on redemande.
   while (!estValide())
   {
      cerr << "Erreur: la date n'est pas valide.";
      system("pause");
      demander(ptrDELIMITEUR);
   }

   // La date a été validé, on va assigner un jour de la semaine 0-6.
   determinerJourDeLaSemaineINT();

   return;
}

void Date::determinerJourDeLaSemaineINT()
{
   // Algorithme pour trouver le jour de la semaine, 0-6.
   // Source: https://fr.wikibooks.org/wiki/Curiosit%C3%A9s_math%C3%A9matiques/Trouver_le_jour_de_la_semaine_avec_une_date_donn%C3%A9e
   int iCalcul1 = (14 - iMois) / 12;
   int iCalcul2 = iAnnee - iCalcul1;
   int iCalcul3 = iMois + 12 * iCalcul1 - 2;

   iJourDeLaSemaine = (iJour + iCalcul2 + iCalcul2 / 4 - iCalcul2 / 100 + iCalcul2 / 400 + (31 * iCalcul3) / 12) % 7;

   return;
}

bool Date::estValide()
{
   // Les jours
  // Aucun mois n'a plus que 31 jours.
   if (iJour > 31)
      return false;
   // Les mois qui n'ont pas plus que 30 jours.
   if ((iJour > 30) && (iMois == 2 || iMois == 4 || iMois == 6 || iMois == 9 || iMois == 11))
      return false;
   // Février, jamais 30 jours.
   if (iMois == 2 && iJour == 30)
      return false;
   // Les mois, pas plus que 12.
   if (iMois > 12)
      return false;
   // Années bisextile
   if (iMois == 2 && iJour > 28)
   {
      if (!((iAnnee % 4 == 0) && (iAnnee % 100 != 0)) || (iAnnee % 400 == 0))
         return false;
   }
   // Si on est rendu ici, ça veut dire que contraintes de date n'ont pas retourné false, alors c'est valide.
   return true;
}

void Date::obtenirDateSysteme()
{
   // Struct de type tm pour stocké les données du temps système.
   tm TempsSysteme;
   // Pour chercher le temps système, en secondes.
   time_t TempsMaintenant;

   time(&TempsMaintenant);
   // Convertir le temps en type tm.
   localtime_s(&TempsSysteme, &TempsMaintenant);

   // Stocké les données du temps système dans structure Date.
   iJour = TempsSysteme.tm_mday;
   iMois = TempsSysteme.tm_mon + 1;
   iAnnee = TempsSysteme.tm_year + 1900;
   iJourDeLaSemaine = TempsSysteme.tm_wday;
   // Nous pourrions aussi utiliser notre fonction determinerJourDeLaSemaineINT(). 

   return;
}

void Date::afficher(bool bAvecEndl)
{
   // Afficher la date en format jj/mm/aaaa.
   cout << left;
   if (iJour < 10)
      cout << "0";
   cout << iJour << "/";
   if (iMois < 10)
      cout << "0";
   cout << iMois << "/" << iAnnee;
   cout << (bAvecEndl ? "\n" : "");

   return;
}

void Date::determinerJourDeLaSemaine()
{
   // Tableau pour stocker les nom des jours.
   char LesJours[7][9] = { "dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi" };

   // Reservé seulement de le mémoire qu'on a besoin.
   ptrJour = new char[strlen((*(LesJours + iJourDeLaSemaine))) + 1];

   // Copier le nom du jour dans la variable de l'objet.
   for (int i = 0; i < strlen(*(LesJours + iJourDeLaSemaine)) + 1; i++)
   {
      *(ptrJour + i) = LesJours[iJourDeLaSemaine][i];
   }   

   return;
}

void Date::determinerMois()
{
   // Tableau pour stocker les noms des mois.
   char LesMois[12][10] = { "janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre" };

   // Reserver seulement de le mémoire qu'on a besoin.
   ptrMois = new char[strlen(*(LesMois + (iMois - 1))) + 1];

   // Copier le nom du mois dans la variable de l'objet.
   for (int i = 0; i < strlen(*(LesMois + (iMois - 1))) + 1; i++)
   {
      *(ptrMois + i) = LesMois[iMois - 1][i];
   }

   return;
}

void Date::afficherFormatLong()
{
   // Appel des fonctions.
   determinerJourDeLaSemaine();
   determinerMois();

   // Afficher.
   cout << ptrJour << ", " << iJour << " " << ptrMois << " " << iAnnee;

   return;
}
