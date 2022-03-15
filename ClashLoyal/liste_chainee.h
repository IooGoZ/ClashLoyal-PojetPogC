#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct t_cell
{
	struct t_cell *suiv;
	t_unite *pData;         //  Définit la liste des unités d’un joueur.
} *t_listeUnite;

/* Prototypes de fonctions */

t_listeUnite creerPileVide();

bool estVide(t_listeUnite P);

t_listeUnite empiler(t_listeUnite P, char v);

void affichePile(t_listeUnite P);

t_listeUnite depiler(t_listeUnite P);

char tetePile(t_listeUnite P);

/* Prototypes fonctions utilitaires */

void afficheEstVide(t_listeUnite P);
