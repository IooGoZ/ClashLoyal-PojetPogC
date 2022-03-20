#include "mecanics.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//  Effectue l�attaque d�une unit� sur une autre. (pas de v�rification)
void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    setPV(uniteAttaquee, minusPV(uniteAttaquee, getDegats(uniteAttaquante)));
}

    //  Calcule la distance entre deux unit�s.
float distance(t_unite uniteA, t_unite uniteB) {
    return sqrt(pow(getX(uniteA) - getX(uniteB), 2) + pow(getY(uniteA) - getY(uniteB), 2));
}

//  V�rifie si une attaque entre deux unit�s est possible (distance/type de cible)
bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    // Cas o� l'unit� attaqu� est hors de port�e de l'attaquant � faire en premier !
    if(getPortee(uniteAttaquante) < distance(uniteAttaquante,uniteAttaquee)) {
        return false;
    }

    // Initialisation o� l'attaquant peut cibler solEtAir
    bool peutAttaquer = true;

    // Cas o� l'attaquant peut cibler sol
    if(getCible(uniteAttaquante) == sol) {
        switch(getPosition(uniteAttaquee)) {
            case sol : peutAttaquer = true; break;
            case air : peutAttaquer = false; break;
            //  Cas impossible : une unit� est soit terrestre, soit a�rienne (warning)
            case solEtAir : peutAttaquer = false;
        }
    }

    // Cas o� l'attaquant peut cibler air
    if(getCible(uniteAttaquante) == air) {
        switch(getPosition(uniteAttaquee)) {
            case sol : peutAttaquer = false; break;
            case air : peutAttaquer = true; break;
            //  Cas impossible : une unit� est soit terrestre, soit a�rienne (warning)
            case solEtAir : peutAttaquer = false;
        }
    }

    return peutAttaquer;
}

//  Retourne une quantit� d��lixir, compris entre 1 et 3
int getRandomElixirAmount(void) {
    return 1 + (rand()%3);
}

//  V�rifie si une case est occup�e avant la g�n�ration du plateau de jeu.
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

//  G�n�re une unit� al�atoire
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

//  Retourne le prix (en �lixir) d'une unit�.
int getPrice(t_unite unite) {
    return unite->coutEnElixir;
}

//  Permet de d�clencher la tentative d�achat d�un joueur d�une unit�.
t_unite acheteUnite(int *elixirDuJoueur) {
    t_unite newUnite = randomUnite();

    if(*elixirDuJoueur < getPrice(newUnite)) {
        free(newUnite);
        return NULL;
    }

    *elixirDuJoueur -= getPrice(newUnite);

    return newUnite;
}

    //  Tri la liste des unit�s pouvant attaquer (� v�rifier), par vitesse d�attaque.
t_listeUnite triVitesseAttaque(t_listeUnite unites) {

}
