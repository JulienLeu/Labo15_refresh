/* Fichier : outils_saisie.c
 * Auteur  : Quentin Müller / Julien Leuenberger
 * Date    : 20.11.2018
 *
 * Description :	
 *					Quelques fonctions très utiles
 *						- vide le buffer du scanf
 *						- confirmation de la sélection
 *
 *					Fonctions qui facilite la saisie
 *						- des nombres entier bornés ou non
 *						- des nombres réels bornés ou non
 *						- des chaines de caractères (string)
 *
 *					
 *
 * Remarque(s) : (Exemples: "Problèmes rencontés", Erreurs, etc.)
 *
 * Modifications : Date / Auteur / Raison
 *
 * Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outils_saisie.h"

void viderBuffer(void)
{
	while (getchar() != '\n');
}

int confirmer(char const *invite)
{
	int Conf,saisieDone = 0, saisieOk;
	char Confirmation;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%c", &Confirmation);
		viderBuffer();
		if (saisieOk == 1)
		{
			switch (Confirmation)
			{
				case '1':
				case 'o':
				case 'O':
				{
					Conf = 1;
					saisieDone = 1;
					break;
				}
				case '0':
				case 'n':
				case 'N':
				{
					Conf = 0;
					saisieDone = 1;
					break;
				}
				default :
				{
					printf("Commande non reconnue");
					break;
				}
			}
		}
		else
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
	} while (!saisieDone);
	return Conf;
}

int saisirEntier(char const *invite)
{
	int Entier_saisit,saisieDone = 0,saisieOk;
	double val;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%lf", &val);
		viderBuffer();
		Entier_saisit = val;
		if (Entier_saisit != 0)
		{
			if (((saisieOk != 1) || ((Entier_saisit / val) != 1)))
			{
				printf("La valeur saisie n'est pas valide.\n");
			}
			else
			{
				saisieDone = 1;
			}
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
	return Entier_saisit;
}

int saisirEntierBorne(char const *invite, int borne_inf, int borne_sup)
{
	int Entier_saisit, saisieDone = 0, saisieOk;

	do
	{
		printf("%s", invite);
		saisieOk = scanf("%d", &Entier_saisit);
		viderBuffer();
		if ((saisieOk != 1) || (Entier_saisit < borne_inf) ||
			(Entier_saisit > borne_sup))
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}

	} while (!saisieDone);
	return Entier_saisit;
}

double saisirReel(char const *invite)
{
	int saisieDone = 0;
	int saisieOk;
	double entree;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%lf", &entree);
		viderBuffer();
		if (saisieOk != 1)
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
	return entree;
}

double saisirReelBorne(char const *invite, 
	double borne_inf, double borne_sup)
{
	int saisieDone = 0;
	int saisieOk;
	double entree;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%lf", &entree);
		viderBuffer();
		if ((saisieOk != 1) || (entree < borne_inf)
			|| (entree > borne_sup))
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
	return entree;
}

void saisirString(char const *invite, int maxTaille, char *string)
{
	int saisieDone = 0;
	int longueurString;

	do
	{
		printf("%s ", invite);
		if ((fgets(string, maxTaille, stdin) != NULL) && string[0] != '\n' && ( strlen(string) <= maxTaille))
		{
			longueurString = strlen(string);
			string[longueurString - 1] = '\0';
			saisieDone = 1;
		}
		else
		{
			printf("Saisie non valide");
			viderBuffer();
		}
		
	} while (!saisieDone);

}