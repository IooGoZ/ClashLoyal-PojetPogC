#ifndef MECANICS_H
#define MECANICS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"

//TYPE-------------------------

    typedef struct s_plateauJeu {
        int maxX;
        int maxY;
        t_unite** plateau;
    } t_plateauJeu;


//INITIALISATION DU PLATEAU------------------------------------------------------------------------------------------------------

    //Alloue un plateau de taille x*y.
    t_plateauJeu allocPlateau(int x,int y);

    //Initialise un plateau de jeu. Toutes les cases du plateau sont NULL.
    t_plateauJeu initPlateau(t_plateauJeu jeu);

    //Positionne les unités d’un joueur sur le plateau.
    t_plateauJeu playerToPlateau(t_player player,t_plateauJeu jeu);


//COMBAT------------------------------------------------------------------------------------------------------

    //  Effectue l’attaque d’une unité sur une autre(pas de vérification).
    void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee, t_player joueurAttaquee);

    //  Calcule la distance entre deux unit�s.
    float distance(t_unite uniteA, t_unite uniteB);

    //  Vérifie si une attaque entre deux unités est possible (distance/type de cible).
    bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee, bool tourClasssiqueDetruite);

    //  Retourne la liste des unit�s adverses atteignables par une unit�.
    t_listeUnite quiEstAPortee(t_unite unite, t_listeUnite unitesAdverses, bool tourClasssiqueDetruite);


//ECONOMIE------------------------------------------------------------------------------------------------------

    //  Retourne une quantité d’élixir, compris entre 1 et 3.
    int getRandomElixirAmount(void);

    //  Permet de déclencher la tentative d’achat d’un joueur d’une unité.
    t_unite acheteUnite(t_player player);

    //  Retourne le prix (en �lixir) d'une unit�.
    int getPrice(t_unite unite);


//PLACEMENT/DEPLACEMENT-----------------------------------------------------------------------------------------

    //  Vérifie si une case est occupée avant la génération du plateau de jeu.
    bool caseOccupee(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, int x, int y);

    //  Positionne une unite aleatoirement du cote de son joueur.
    void positionneRandomUnite(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, t_unite unite, bool playerOnTop);

    //  Retourne un tableau d'entier (coordonnees x et y) de la prochaine position d'une unite.
    int * getNextPosition(t_unite unite);


//GENERATION------------------------------------------------------------------------------------------------------

    //  Génère une unité aléatoire.
    t_unite randomUnite(void);

#endif
