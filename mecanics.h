#ifndef MECANICS_H
#define MECANICS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"


    //  Effectue l’attaque d’une unité sur une autre. (pas de vérification)
    void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee, t_player joueurAttaquee);

    //  Vérifie si une attaque entre deux unités est possible (distance/type de cible)
    bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee, bool tourClasssiqueDetruite);

    //  Calcule la distance entre deux unités.
    float distance(t_unite uniteA, t_unite uniteB);

    //  Retourne une quantité d’élixir, compris entre 1 et 3
    int getRandomElixirAmount(void);

    //  Vérifie si une case est occupée avant la génération du plateau de jeu.
    bool caseOccupee(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, int x, int y);

    //  Permet de déclencher la tentative d’achat d’un joueur d’une unité.
    t_unite acheteUnite(t_player player);

    void positionneRandomUnite(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, t_unite unite, bool playerOnTop);

    //  Retourne la liste des unit�s adverses atteignables par une unit�.
    t_listeUnite quiEstAPortee(t_unite unite, t_listeUnite unitesAdverses, bool tourClasssiqueDetruite);

#endif
