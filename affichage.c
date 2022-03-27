#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affichage.h"
#include "unite.h"
#include "joueur.h"


//Fonction Utilitaire------------------------------------

    //Retourne un caractere correspondant a l'initiale de l'unite.
char uniteToChar(t_uniteDuJeu typeUnite) {
	char uniteChar[] = {'T', 'R', 'A', 'C', 'D', 'G'};
	return uniteChar[typeUnite];
}


//Fonction d'affichage----------------------------------

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
            if (y==9 && x != 5) {
                printf("=====");
            } else if (unite==NULL) {
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

    //Affiche le contenu d'une pile d'unite.
void affichePile(t_listeUnite P) {
	for (t_listeUnite i = P; !estVide(i); i = i->suiv) {
        char c = uniteToChar(i->pData->nom);
		printf("[%c]\n", c);
	}
}

    //Affiche si oui ou non la pile est vide.
void afficheEstVide(t_listeUnite P) {
	if (estVide(P)) {
		printf("Ma pile d'unite est vide.\n");
	} else {
		printf("Ma pile d'unite n'est pas vide.\n");
	}
}

    //Affiche la vitesse d'attaque de chaque unite(test de la fonction de trie !).
void afficheUniteTab(t_unite *tab, int taille) {
    for(int i = 0; i < taille; i++)
    {
        printf("vitesse attaque : %f\n",getVitesseAttaque(tab[i]));
    }
}
