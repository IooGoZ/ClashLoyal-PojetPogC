#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "affichage.h"
#include "unite.h"
#include "joueur.h"


//Fonctions Utiles------------------------------------
char uniteToChar(t_uniteDuJeu typeUnite) {
	char uniteChar[] = {'T', 'R', 'A', 'C', 'D', 'G'};
	return uniteChar[typeUnite];
}

//Fonctions Usuelles----------------------------------

    //Alloue un plateau de taille x*y.
t_plateauJeu allocPlateau(int x,int y) {
    t_plateauJeu res;
    res.maxX = x;
    res.maxY = y;
    res.plateau = (t_unite**) malloc(sizeof(t_unite*)*x);
    for (int i = 0; i < x; i++)
        res.plateau[i] = (t_unite*) malloc(sizeof(t_unite)*y);
    return res;
};

    //Initialise un plateau de jeu. Toutes les cases du plateau sont NULL.
t_plateauJeu initPlateau(t_plateauJeu jeu) {
    for (int x = 0; x < jeu.maxX; x++) {
        for (int y = 0; y < jeu.maxY; y++) {
            jeu.plateau[x][y] = NULL;
        }
    }
    return jeu;
}

    //Positionne les unités d’un joueur sur le plateau.
t_plateauJeu playerToPlateau(t_player player,t_plateauJeu jeu) {
    for (t_listeUnite i = player->listeUnite; !estVide(i); i = i->suiv) {
        t_unite unite = i->pData;
        if (jeu.plateau[unite->posX][unite->posY]!=NULL) {
            fprintf(stderr, "Erreur playerToPlateau : La case n'est pas vide.\n");
            printf("Position X : %d\nPosition Y : %d\nCase contenue : %c\nCase a placer : %c\n", unite->posX, unite->posY, uniteToChar(jeu.plateau[unite->posX][unite->posY]->nom),uniteToChar(unite->nom));
        } else {
            jeu.plateau[unite->posX][unite->posY] = unite;
        }
    }
    return jeu;
}

    //Affiche un plateau de jeu.
void affichePlateau(t_plateauJeu jeu) {
    printf("|");
    for (int x = 0; x < jeu.maxX; x++) {
        printf("-----");
    }
    printf("|\n");
    for (int y = 0; y < jeu.maxY; y++) {
        printf("|");
        for (int x = 0; x < jeu.maxX; x++) {
            t_unite unite = jeu.plateau[x][y];
            if (unite==NULL) {
                printf("|   |");
            } else {
                printf("| %c |", uniteToChar(unite->nom));
            }
        }
        printf("|\n|");
        for (int x = 0; x < jeu.maxX; x++) {
            printf("-----");
        }
        printf("|\n");
    }
}



//Debug-----------------------------------------------

void affichePile(t_listeUnite P) {
	for (t_listeUnite i = P; !estVide(i); i = i->suiv) {
        char c = uniteToChar(i->pData->nom);
		printf("[%c]\n", c);
	}
}

void afficheEstVide(t_listeUnite P) {
	if (estVide(P)) {
		printf("Ma pile d'unite est vide.\n");
	} else {
		printf("Ma pile d'unite n'est pas vide.\n");
	}
}
