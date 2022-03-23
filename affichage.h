#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "joueur.h"
#include "unite.h"


//TYPES-------------------------
typedef struct s_plateauJeu {
	int maxX;
	int maxY;
	t_unite** plateau;
} t_plateauJeu;


//FONCTIONS-USUELLES------------

//Alloue un plateau de taille x*y.
t_plateauJeu allocPlateau(int x,int y);

//Initialise un plateau de jeu. Toutes les cases du plateau sont NULL.
t_plateauJeu initPlateau(t_plateauJeu jeu);

//Positionne les unités d’un joueur sur le plateau.
t_plateauJeu playerToPlateau(t_player player,t_plateauJeu jeu);

//Affiche un plateau de jeu.
void affichePlateau(t_plateauJeu jeu);



//DEBUG-------------------------------
void affichePile(t_listeUnite P);

void afficheEstVide(t_listeUnite P);

 void afficheUniteTab(t_unite *tab, int taille);

#endif
