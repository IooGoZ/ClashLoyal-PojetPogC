#include "mecanics.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//  Effectue l’attaque d’une unité sur une autre. (pas de vérification)
void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    setPV(uniteAttaquee, minusPV(uniteAttaquee, getDegats(uniteAttaquante)));
}

    //  Calcule la distance entre deux unités.
float distance(t_unite uniteA, t_unite uniteB) {
    return sqrt(pow(getX(uniteA) - getX(uniteB), 2) + pow(getY(uniteA) - getY(uniteB), 2));
}

//  Vérifie si une attaque entre deux unités est possible (distance/type de cible)
bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    // Cas où l'unité attaqué est hors de portée de l'attaquant à faire en premier !
    if(getPortee(uniteAttaquante) < distance(uniteAttaquante,uniteAttaquee)) {
        return false;
    }

    // Initialisation où l'attaquant peut cibler solEtAir
    bool peutAttaquer = true;

    // Cas où l'attaquant peut cibler sol
    if(getCible(uniteAttaquante) == sol) {
        switch(getPosition(uniteAttaquee)) {
            case sol : peutAttaquer = true; break;
            case air : peutAttaquer = false; break;
            //  Cas impossible : une unité est soit terrestre, soit aérienne (warning)
            case solEtAir : peutAttaquer = false;
        }
    }

    // Cas où l'attaquant peut cibler air
    if(getCible(uniteAttaquante) == air) {
        switch(getPosition(uniteAttaquee)) {
            case sol : peutAttaquer = false; break;
            case air : peutAttaquer = true; break;
            //  Cas impossible : une unité est soit terrestre, soit aérienne (warning)
            case solEtAir : peutAttaquer = false;
        }
    }

    return peutAttaquer;
}

//  Retourne une quantité d’élixir, compris entre 1 et 3
int getRandomElixirAmount(void) {
    return 1 + (rand()%3);
}

//  Vérifie si une case est occupée avant la génération du plateau de jeu.
bool caseOccupee(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, int x, int y) {
    for(t_listeUnite temp = unitePlayerOne; !estVide(temp) ; temp = temp->suiv) {
        if((getX(temp->pData) == x) && (getY(temp->pData) == y)) {
            return true;
        }
    }

    for(t_listeUnite temp = unitePlayerTwo; !estVide(temp) ; temp = temp->suiv) {
        if((getX(temp->pData) == x) && (getY(temp->pData) == y)) {
            return true;
        }
    }

    return false;
}

//  Génère une unité aléatoire
t_unite randomUnite(void) {
    t_unite newUnite = NULL;

    switch(rand()%4) {
        case 0 : return newUnite = creerArcher();break;
        case 1 : return newUnite = creerChevalier();break;
        case 2 : return newUnite = creerDragon();break;
        case 3 : return newUnite = creerGargouille();
    }

    return newUnite;
}

//  Retourne le prix (en élixir) d'une unité.
int getPrice(t_unite unite) {
    return unite->coutEnElixir;
}

//  Permet de déclencher la tentative d’achat d’un joueur d’une unité.
t_unite acheteUnite(int *elixirDuJoueur) {
    t_unite newUnite = randomUnite();

    if(*elixirDuJoueur < getPrice(newUnite)) {
        free(newUnite);
        return NULL;
    }

    *elixirDuJoueur -= getPrice(newUnite);

    return newUnite;
}

    //  Tri la liste des unités pouvant attaquer (à vérifier), par vitesse d’attaque.
t_listeUnite triVitesseAttaque(t_listeUnite unites) {

}
