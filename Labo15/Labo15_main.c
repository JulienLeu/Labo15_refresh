/* Fichier : Labo15_main.c
 * Auteur  : Julien Leuenberger et Quentin Müller
 * Date    : 12.12.2018
 *
 * Description :	Afficher sur des 7 segements
 *						-
 *						-
 *
 * Remarque(s) :
 *
 * Modifications : Date / Auteur / Raison
 *
 * Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "outils_saisie.h"
#include "simulateurScore.h"

#define MISE_A_0 0
#define MIN_MENU 0
#define MAX_MENU 5
#define MENU_1 1
#define MENU_2 2
#define MENU_3 3
#define MENU_4 4
#define MENU_5 5

#define CAR_0 0
#define CAR_1 1
#define CAR_2 2
#define CAR_3 3
#define GROUPE_1 0
#define GROUPE_2 1

#define REG_BOUTON 0xF010

#define ETEINDRE 'e'
#define MOINS '-'

#define ETEINT 0x00
#define CHAR_MOINS 0x40
#define CHAR_0 0x3F
#define CHAR_1 0x06
#define CHAR_2 0x5B
#define CHAR_3 0x4F
#define CHAR_4 0x66
#define CHAR_5 0x6D
#define CHAR_6 0x7D
#define CHAR_7 0x07
#define CHAR_8 0x7F
#define CHAR_9 0x6F

#define BOUTON_1_UP 1
#define BOUTON_1_RST 2
#define BOUTON_1_DOWN 4
#define BOUTON_OFF 128
#define BOUTON_2_UP 16
#define BOUTON_2_RST 32
#define BOUTON_2_DOWN 64

#define VAL_MAX 99
#define VAL_MIN -9

#define SEP_DIZAINES_UNITES 10

/* Prototypes de fonctions */
void write_on_register(void);
void afficher_chiffre(int numero_afficheur, char caractere);
void afficher_valeur(int groupe_afficheur, int valeur);
void read_on_register(void);
void gerer_tableau(int val_1, int val_2);

int main(void)
{
	/* Variable du programme */
	int choix_menu;

	printf("\n\nProgramme permettant d'utiliser le simulateur de score");

	do
	{
		/* Interface pour choisir le bon menu */
		printf("\n\n=========== MENU ===========");
		printf("\n 1 - Ecriture des registres");
		printf("\n 2 - Ecriture d'un chiffre");
		printf("\n 3 - Ecriture d'une valeur");
		printf("\n 4 - Etat des boutons");
		printf("\n 5 - Gerer le tableau de score");
		printf("\n 0 - Quitter\n");
		choix_menu = saisirEntierBorne("Choix -> ", MIN_MENU, MAX_MENU);

		switch (choix_menu)
		{
		case MENU_1:
		{
			write_on_register();
			break;
		}
		case MENU_2:
		{
			unsigned short adresse;
			unsigned char val;
			printf("caractere :");
			scanf("%c", &val);
			adresse = saisirEntierBorne("adresse :", CAR_0, CAR_3);
			afficher_chiffre(adresse, val);
			break;
		}
		case MENU_3:
		{
			unsigned short groupe;
			unsigned int val;
			printf("caractere :");
			scanf("%d", &val);
			groupe = saisirEntier("groupe :");
			afficher_valeur(groupe, val);
			break;
		}
		case MENU_4:
		{
			read_on_register();
			break;
		}
		case MENU_5:
		{
			gerer_tableau(MISE_A_0, MISE_A_0);
			break;
		}
		default: // Valeur correspondant à aucun menu
		{
			printf("\nLa valeur saisie n'est pas valide.");
			break;
		}
		}

	} while (choix_menu != 0);
	return EXIT_SUCCESS;
}

void write_on_register(void)
{
	unsigned short adresse = saisirEntier("Adresse [0xF000 -0xF003] : ");
	unsigned char valeur = saisirEntier("Valeur a afficher : ");
	write_register(adresse, valeur);
}

void afficher_chiffre(int numero_afficheur, char caractere)
{
	int adresse, chiffre;

	switch (numero_afficheur)
	{
	case CAR_0:
		adresse = 0xF000;
		break;
	case CAR_1:
		adresse = 0xF001;
		break;
	case CAR_2:
		adresse = 0xF002;
		break;
	case CAR_3:
		adresse = 0xF003;
		break;
	}

	switch (caractere)
	{
	case '-':
		chiffre = CHAR_MOINS;
		break;
	case '0':
		chiffre = CHAR_0;
		break;
	case '1':
		chiffre = CHAR_1;
		break;
	case '2':
		chiffre = CHAR_2;
		break;
	case '3':
		chiffre = CHAR_3;
		break;
	case '4':
		chiffre = CHAR_4;
		break;
	case '5':
		chiffre = CHAR_5;
		break;
	case '6':
		chiffre = CHAR_6;
		break;
	case '7':
		chiffre = CHAR_7;
		break;
	case '8':
		chiffre = CHAR_8;
		break;
	case '9':
		chiffre = CHAR_9;
		break;
	default:
		chiffre = ETEINT;
		break;
	}

	write_register(adresse, chiffre);
}

void afficher_valeur(int groupe_afficheur, int valeur)
{
	int address0, address1, dizaines, unites;
	unsigned char valeur0, valeur1;

	switch (groupe_afficheur)
	{
	case 0:
		address0 = 0;
		address1 = 1;
		break;
	case 1:
		address0 = 2;
		address1 = 3;
		break;
	}

	dizaines = valeur / SEP_DIZAINES_UNITES % SEP_DIZAINES_UNITES;
	unites = valeur % SEP_DIZAINES_UNITES;

	switch (dizaines)
	{
	case 0:
		valeur0 = '0';
		break;
	case 1:
		valeur0 = '1';
		break;
	case 2:
		valeur0 = '2';
		break;
	case 3:
		valeur0 = '3';
		break;
	case 4:
		valeur0 = '4';
		break;
	case 5:
		valeur0 = '5';
		break;
	case 6:
		valeur0 = '6';
		break;
	case 7:
		valeur0 = '7';
		break;
	case 8:
		valeur0 = '8';
		break;
	case 9:
		valeur0 = '9';
		break;
	}

	if (unites < 0)
	{
		unites = 0 - unites;
		valeur0 = MOINS;
	}

	switch (unites)
	{
	case 0:
		valeur1 = '0';
		break;
	case 1:
		valeur1 = '1';
		break;
	case 2:
		valeur1 = '2';
		break;
	case 3:
		valeur1 = '3';
		break;
	case 4:
		valeur1 = '4';
		break;
	case 5:
		valeur1 = '5';
		break;
	case 6:
		valeur1 = '6';
		break;
	case 7:
		valeur1 = '7';
		break;
	case 8:
		valeur1 = '8';
		break;
	case 9:
		valeur1 = '9';
		break;
	}

	if (valeur > VAL_MAX || valeur < VAL_MIN)
	{
		valeur0 = MOINS;
		valeur1 = MOINS;
	}

	if (valeur == ETEINDRE)
	{
		valeur0 = ETEINDRE;
		valeur1 = ETEINDRE;
	}

	afficher_chiffre(address0, valeur0);
	afficher_chiffre(address1, valeur1);
}

void read_on_register(void)
{
	int Infini = 1, val_reg = 0, val_reg_old = 0;

	printf("Cliquer sur -off- pour quitter\n");
	while (Infini)
	{
		val_reg = read_register(REG_BOUTON);
		if (val_reg > val_reg_old)
		{
			printf("%d\n", val_reg);
		}
		val_reg_old = val_reg;
		if (val_reg == BOUTON_OFF)
		{
			Infini = 0;
		}
	}
}

void gerer_tableau(int val_1, int val_2)
{
	int Infini = 1, val_reg, val_reg_old = 0;

	afficher_valeur(GROUPE_1, val_1);
	afficher_valeur(GROUPE_2, val_2);

	while (Infini)
	{
		val_reg = read_register(REG_BOUTON);

		if (val_reg > val_reg_old)
		{
			switch (val_reg)
			{
			case BOUTON_1_UP:
				val_1++;
				afficher_valeur(GROUPE_1, val_1);
				break;
			case BOUTON_1_RST:
				val_1 = 0;
				afficher_valeur(GROUPE_1, val_1);
				break;
			case BOUTON_1_DOWN:
				if (val_1 >= VAL_MIN)
				{
					val_1--;
				}
				afficher_valeur(GROUPE_1, val_1);
				break;
			case BOUTON_2_UP:
				val_2++;
				afficher_valeur(GROUPE_2, val_2);
				break;
			case BOUTON_2_RST:
				val_2 = 0;
				afficher_valeur(GROUPE_2, val_2);
				break;
			case BOUTON_2_DOWN:
				if (val_2 >= VAL_MIN)
				{
					val_2--;
				}
				afficher_valeur(GROUPE_2, val_2);
				break;
			case BOUTON_OFF:
				Infini = 0;
				val_2 = ETEINDRE;
				afficher_valeur(GROUPE_2, val_2);
				val_1 = ETEINDRE;
				afficher_valeur(GROUPE_1, val_1);
				break;
			}
		}
		val_reg_old = val_reg;
	}
}