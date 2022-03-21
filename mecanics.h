#ifndef MECANICS_H
#define MECANICS_H

#define LARGEURJEU 11
#define HAUTEURJEU 19

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"


    //  Effectue l’attaque d’une unité sur une autre. (pas de vérification)
    void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  Vérifie si une attaque entre deux unités est possible (distance/type de cible)
    bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  Calcule la distance entre deux unités.
    float distance(t_unite uniteA, t_unite uniteB);

    //  Retourne une quantité d’élixir, compris entre 1 et 3
    int getRandomElixirAmount(void);

    //  Vérifie si une case est occupée avant la génération du plateau de jeu.
    bool caseOccupee(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, int x, int y);

    //  Permet de déclencher la tentative d’achat d’un joueur d’une unité.
    t_unite acheteUnite(t_player player);

    //  Tri la liste des unités pouvant attaquer (à vérifier), par vitesse d’attaque.
    t_listeUnite triVitesseAttaque(t_listeUnite unites);

#endif
