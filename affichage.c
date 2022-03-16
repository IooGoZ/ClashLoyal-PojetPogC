#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "affichage.h"
#include "unite.h"

char uniteToChar(t_uniteDuJeu typeUnite) {
	char uniteChar[] = {'T', 'R', 'A', 'C', 'D', 'G'};
	return uniteChar[typeUnite];
}

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
