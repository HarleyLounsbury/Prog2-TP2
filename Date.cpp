// But: Structure de date, incluant m�thodes pour la manipuler.
// Auteur: Harley Lounsbury
// Date: 01/04/2019

#include "Date.h"

Date::Date()
{
   // Constructeur par d�faut. 
   // Initialiser les variables de la structure.
   iJour = 0;
   iMois = 0;
   iAnnee = 0;
}

Date::~Date()
{
   cout << "D�structeur de Date." << endl;
   system("pause");
   // Si de la m�moire a �t� allou�e dynamiquement, on doit la lib�rer.
   if(ptrJour)
      delete[] ptrJour;
   if(ptrMois)
      delete[] ptrMois;
}

void Date::demander(const char* ptrDELIMITEUR)
{
   // Variables locaux.
   // Constante pour le maximum nombre de caract�res que l'utilisateur peut entrer.
   const int iMAX_CLAVIER = 8190;
   // Cha�ne de caract�res pour la saisi.
   char cClavier[iMAX_CLAVIER + 1];
   // Deux pointeurs pour d�couper la cha�ne de caract�res.
   char* ptrParcours;
   char* ptrSuivant;

   // Demander � l'utilisateur la date.
   cout << "La saisie de la date doit �tre sous la forme jj/mm/aaaa :";
   cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

   // On doit v�rifier que la cha�ne n'est pas vide avant de d�couper.
   if (strlen(cClavier))
   {
      // On d�coupe pour stock� le jour dans la variable iJour.
      ptrParcours = strtok_s(cClavier, ptrDELIMITEUR, &ptrSuivant);
      iJour = atoi(ptrParcours);

      // On passe au mois, on d�coupe et on stock le mois dans la variable iMois.
      if (strlen(ptrSuivant))
      {
         ptrParcours = strtok_s(NULL, ptrDELIMITEUR, &ptrSuivant);
         iMois = atoi(ptrParcours);
      }
      // Il reste les ann�es.
      iAnnee = atoi(ptrSuivant);
   }
   return;
}

void Date::demanderEtValider(const char * ptrDELIMITEUR)
{
   // Demander � l'utilisateur.
   demander(ptrDELIMITEUR);

   // Tant que la saisi n'est pas valide, on redemande.
   while (!estValide())
   {
      cerr << "Erreur: la date n'est pas valide.";
      system("pause");
      demander(ptrDELIMITEUR);
   }

   // La date a �t� valid�, on va assigner un jour de la semaine 0-6.
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
   // F�vrier, jamais 30 jours.
   if (iMois == 2 && iJour == 30)
      return false;
   // Les mois, pas plus que 12.
   if (iMois > 12)
      return false;
   // Ann�es bisextile
   if (iMois == 2 && iJour > 28)
   {
      if (!((iAnnee % 4 == 0) && (iAnnee % 100 != 0)) || (iAnnee % 400 == 0))
         return false;
   }
   // Si on est rendu ici, �a veut dire que contraintes de date n'ont pas retourn� false, alors c'est valide.
   return true;
}

void Date::obtenirDateSysteme()
{
   // Struct de type tm pour stock� les donn�es du temps syst�me.
   tm TempsSysteme;
   // Pour chercher le temps syst�me, en secondes.
   time_t TempsMaintenant;

   time(&TempsMaintenant);
   // Convertir le temps en type tm.
   localtime_s(&TempsSysteme, &TempsMaintenant);

   // Stock� les donn�es du temps syst�me dans structure Date.
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

   // Reserv� seulement de le m�moire qu'on a besoin.
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
   char LesMois[12][10] = { "janvier", "f�vrier", "mars", "avril", "mai", "juin", "juillet", "ao�t", "septembre", "octobre", "novembre", "d�cembre" };

   // Reserver seulement de le m�moire qu'on a besoin.
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
