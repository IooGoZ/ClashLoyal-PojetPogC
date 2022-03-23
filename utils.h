#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"

//  Retourne la taille de la liste.
    int lenListe(t_listeUnite l);

    //  Retourne un tableau alloue.
    t_unite *alloueUnitesTab(int taille);

    //  Retourne un tableau remplit par des unites.
    t_unite *remplitUnitesTab(t_listeUnite unites, t_unite* tab);

    //  �change le contenu de deux cases du tableau.
    t_unite *switchIndices(t_unite *tab, int i, int j);

    //  Tri la liste des unit�s pouvant attaquer (� v�rifier), par vitesse d�attaque.
    t_unite *triVitesseAttaque(t_listeUnite unites);

    int random_int(int min, int max);

#endif // UTILS_H_INCLUDED
