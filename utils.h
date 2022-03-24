#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"

typedef struct s_tabUnite {
    t_unite* tab;
    int taille;
} *t_tabUnite;

//  Retourne la taille de la liste.
    int lenListe(t_listeUnite l);

    //  Retourne un tableau alloue.
    t_unite *alloueUnitesTab(int taille);

    //  Retourne un tableau remplit par des unites.
    t_unite *remplitUnitesTab(t_listeUnite unites, t_unite* tab);

    //  Échange le contenu de deux cases du tableau.
    t_unite *switchIndices(t_unite *tab, int i, int j);

    //  Tri la liste des unités pouvant attaquer (à vérifier), par vitesse d’attaque.
    t_unite *triVitesseAttaque(t_listeUnite unites);

    //Retourne un int compris entre min et max
    int getRandomInt(int min, int max);

    //  Concatene deux listes d'unites en un tableau trié par vitesse d'attaque
    t_tabUnite concatToSortedTab(t_listeUnite unitesOne, t_listeUnite unitesTwo);

#endif // UTILS_H_INCLUDED
