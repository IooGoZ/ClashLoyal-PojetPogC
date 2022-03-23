#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include "unite.h"
#include "joueur.h"
#include "utils.h"

//TRI-------------------------------------------------------------------------------------------------------

//  Retourne la taille de la liste.
int lenListe(t_listeUnite l) {
    if(estVide(l)){
        return 0;
    }
    else{
        return 1 + lenListe(l->suiv);
    }
}

//  Retourne un tableau alloue.
t_unite *alloueUnitesTab(int taille) {
    t_unite *res;

    res = (t_unite *)malloc(sizeof(struct s_unite) * taille);

    return res;
}

//  Retourne un tableau remplit par des unites.
t_unite *remplitUnitesTab(t_listeUnite unites, t_unite* tab) {
    int i = 0;
    t_listeUnite temp = unites;

    while(!estVide(temp)) {
        tab[i] = temp->pData;
        i++;
        temp = temp->suiv;
    }

    return tab;
}
//  Échange le contenu de deux cases du tableau.
t_unite *switchIndices(t_unite *tab, int i, int j) {
    t_unite temp = tab[i];

    tab[i] = tab[j];
    tab[j] = temp;

    return tab;
}

//  Cree et renvoi un tableau d'unite trie par vitesse d'attaque.
t_unite* triVitesseAttaque(t_listeUnite unites) {
    int taille = lenListe(unites);
    t_unite *tab = alloueUnitesTab(taille);
    tab = remplitUnitesTab(unites, tab);

    for(int i = 0; i < taille; i++) {
        int indMin = 0;
        float minVitesseAttaque = FLT_MAX;

        for(int j = i; j < taille ; j++) {
            if(getVitesseAttaque(tab[j]) < minVitesseAttaque) {
                indMin = j;
                minVitesseAttaque = getVitesseAttaque(tab[j]);
            }
        }

        tab = switchIndices(tab, i, indMin);
    }

    return tab;
}

//Random Int--------------------------------------
int getRandomInt(int min, int max) {
	return (min + rand() % (max-min));
}
