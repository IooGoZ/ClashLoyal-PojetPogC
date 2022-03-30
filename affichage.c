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

//INITIALISATION DU PLATEAU DE JEU------------------------------------------------------------------------------------------------------

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
