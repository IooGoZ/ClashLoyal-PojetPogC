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


    for(t_listeUnite temp = unites; !estVide(temp); temp = temp->suiv) {
        tab[i] = temp->pData;
        i++;
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

//  Tri la liste des unités pouvant attaquer (à vérifier), par vitesse d’attaque.
t_unite* triTableauVitesseAttaque(t_unite *tab, int taille) {
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

//  Cree et renvoi un tableau d'unite trie par vitesse d'attaque.
t_unite* triVitesseAttaque(t_listeUnite unites) {
    int taille = lenListe(unites);
    t_unite *tab = alloueUnitesTab(taille);
    tab = remplitUnitesTab(unites, tab);
    return triTableauVitesseAttaque(tab, taille);
}

//  Concatene deux listes d'unites en un tableau trié par vitesse d'attaque
t_tabUnite concatToTab(t_listeUnite unitesOne, t_listeUnite unitesTwo) {
    int len = lenListe(unitesOne) + lenListe(unitesTwo);
    t_unite *tab = alloueUnitesTab(len);
    int i = 0;
    for(t_listeUnite temp = unitesOne; !estVide(temp); temp = temp->suiv) {
        tab[i] = temp->pData;
        i++;
    }
    for(t_listeUnite temp = unitesTwo; !estVide(temp); temp = temp->suiv) {
        tab[i] = temp->pData;
        i++;
    }

    t_tabUnite tabUnite = (t_tabUnite) malloc(sizeof(struct s_tabUnite));
    tabUnite->tab = tab;
    tabUnite->taille = len;
    return tabUnite;
}

//  Concatene deux listes d'unites en un tableau trié par vitesse d'attaque
t_tabUnite concatToSortedTab(t_listeUnite unitesOne, t_listeUnite unitesTwo) {

    t_tabUnite tabUnite = concatToTab(unitesOne, unitesTwo);

    tabUnite->tab  = triTableauVitesseAttaque(tabUnite->tab , tabUnite->taille);

    return tabUnite;
}

//Random Int--------------------------------------
int getRandomInt(int min, int max) {
	return (min + rand() % (max-min));
}
