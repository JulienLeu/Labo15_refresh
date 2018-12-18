/* Fichier : outils_saisie.h
* Auteur   : Didier Mettler
* Date     : 08.11.2016
*
* But      : Prototypes des fonctions permettant de saisir des entiers et
*			 des réels, précédées d'une phrase précisant la demande.
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
// Cette fonction vide le tampon (buffer) d'entrée (stdin) du clavier
void viderBuffer(void);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message (question) reçu en paramètre (consigne) et 
// attend la réponse (o/n) de l'utilisateur (ex.: "Voulez-vous continuer [o/n] :" ).
// Les caractères 'o' et 'O' retourneront 1, tandis que les caractères 'n' et 'N' 0
int confirmer(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message reçu en paramètre (consigne) et retourne un entier 
// signé repondant à la consigne (ex.: "Entrer votre taille en cm : ")
int saisirEntier(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message reçu en paramètre (consigne) et retourne un entier 
// signé repondant à la consigne et se trouvant dans les limites (bornes) reçues
// (ex.: "Entrer votre taille en cm [40 - 250] :")
int saisirEntierBorne(char const *consigne, int borne_inf, int borne_sup);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message reçu en paramètre (consigne) et retourne un double 
// repondant à la consigne (ex.: "Entrer votre taille en m : ")
double saisirReel(char const *consigne);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message reçu en paramètre (consigne) et retourne un double 
// repondant à la consigne et se trouvant dans les limites (bornes) reçues
// (ex.: "Entrer votre taille en m [0.4 - 2.5] :")
double saisirReelBorne(char const *consigne, double borne_inf, double borne_sup);

//-----------------------------------------------------------------------------
// Cette fonction affiche le message reçu en paramètre (consigne) et retourne dans la
// variable "string", la chaîne de caractères entrée par l'utilisateur
// (ex.: "Entrer votre prenom suivi de votre nom : ")
void saisirString(char const *consigne, int maxTaille, char *string);
#endif

