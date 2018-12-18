/* Fichier : outils_saisie.h
* Auteur   : Didier Mettler
* Date     : 08.11.2016
*
* But      : Prototypes des fonctions permettant de saisir des entiers et
*			 des r�els, pr�c�d�es d'une phrase pr�cisant la demande.
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*		  20.11.2018/DMT : Modification des prototypes et des commentaires
* Compilateur : Visual Studio 2017
*/

#ifndef __OUTIL_SAISIE_H_
#define __OUTIL_SAISIE_H_

#define EOL '\n'
//-----------------------------------------------------------------------------
// Cette fonction vide le tampon (buffer) d'entr�e (stdin) du clavier
void viderBuffer(void);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message (question) re�u en param�tre (consigne) et 
// attend la r�ponse (o/n) de l'utilisateur (ex.: "Voulez-vous continuer [o/n] :" ).
// Les caract�res 'o' et 'O' retourneront 1, tandis que les caract�res 'n' et 'N' 0
int confirmer(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message re�u en param�tre (consigne) et retourne un entier 
// sign� repondant � la consigne (ex.: "Entrer votre taille en cm : ")
int saisirEntier(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message re�u en param�tre (consigne) et retourne un entier 
// sign� repondant � la consigne et se trouvant dans les limites (bornes) re�ues
// (ex.: "Entrer votre taille en cm [40 - 250] :")
int saisirEntierBorne(char const *consigne, int borne_inf, int borne_sup);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message re�u en param�tre (consigne) et retourne un double 
// repondant � la consigne (ex.: "Entrer votre taille en m : ")
double saisirReel(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message re�u en param�tre (consigne) et retourne un double 
// repondant � la consigne et se trouvant dans les limites (bornes) re�ues
// (ex.: "Entrer votre taille en m [0.4 - 2.5] :")
double saisirReelBorne(char const *consigne, double borne_inf, double borne_sup);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message re�u en param�tre (consigne) et retourne dans la
// variable "string", la cha�ne de caract�res entr�e par l'utilisateur
// (ex.: "Entrer votre prenom suivi de votre nom : ")
void saisirString(char const *consigne, int maxTaille, char *string);
#endif

