#include "unite.h"
#include "mecaniques.h"
#include <stdbool.h>

typedef struct
{
	char* nom;
	t_listeUnite listeUnite;
	int nbElixir;               //  Définit un joueur (playerOnTop = true => il s'agit du joueur qui a la partie haute de l’écran.
	bool playerOnTop;
} *t_player;

/* Prototypes de fonctions */

T_player initPlayer(char * nom, bool playerOnTop);      //  Initialise un joueur, avec un nom et sa position.

bool tourRoiDetruite(t_listeUnite player);      //  Vérifie si la tour du roi d’un joueur est détruite.

void getElixir(t_player player);        //  Retourne la quantité d’élixir d’un joueur.

void addElixir(t_player player, int amount);        //  Ajoute une quantité d’élixir au joueur.

void minusElixir(t_player player, int amount);      //  Retire une quantité d’élixir au joueur.

bool tourClassiqueDetruite(t_listeUnite player);        // Vérifie si la tour (non-roi) d’un joueur est détruite.

void supprimerUnite(t_listeUnite *unites, t_unite *uniteDetruite);      //  Supprime une unité à un joueur.

void ajouterUnite(t_listeUnite *unites, t_unite *nouvelleUnite);        //  Ajoute une unité à un joueur.

bool getPlayerOnTop(t_player *player);      //  Retourne true si le joueur est en haut dans l’affichage.

t_listeUnite getListeUnite(t_player *player);       //  Retourne la liste des unités d’un joueur.

