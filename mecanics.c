#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "mecanics.h"
#include "joueur.h"
#include "unite.h"



//COMBAT------------------------------------------------------------------------------------------------------

//  Effectue l�attaque d�une unit� sur une autre. (pas de v�rification)
void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    minusPV(uniteAttaquee, getDegats(uniteAttaquante));
}

    //  Calcule la distance entre deux unit�s.
float distance(t_unite uniteA, t_unite uniteB) {
    return sqrtf((float)(pow(getX(uniteA) - getX(uniteB), 2) + pow(getY(uniteA) - getY(uniteB), 2)));
}

//  V�rifie si une attaque entre deux unit�s est possible (distance/type de cible)
bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    // Cas o� l'unit� attaqu� est hors de port�e de l'attaquant � faire en premier !
    if(getPortee(uniteAttaquante) < distance(uniteAttaquante,uniteAttaquee)) {
        return false;
    } else if(getCible(uniteAttaquante) == sol) {
        // Cas o� l'attaquant peut cibler sol
        switch(getPosition(uniteAttaquee)) {
            case sol : return true;
            case air : return false;
            //  Cas impossible : une unit� est soit terrestre, soit a�rienne (warning)
            case solEtAir : return false;
        }
    } else if(getCible(uniteAttaquante) == air) {
        // Cas o� l'attaquant peut cibler air
        switch(getPosition(uniteAttaquee)) {
            case sol : return false;
            case air : return true;
            //  Cas impossible : une unit� est soit terrestre, soit a�rienne (warning)
            case solEtAir : return false;
        }
    } else
        return true;
}


//ECONOMIE------------------------------------------------------------------------------------------------------
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
    switch(rand()%4) {
        case 0 : return creerArcher();
        case 1 : return creerChevalier();
        case 2 : return creerDragon();
        case 3 : return creerGargouille();
        default : return NULL;
    }
}

//  Retourne le prix (en �lixir) d'une unit�.
int getPrice(t_unite unite) {
    return unite->coutEnElixir;
}

//  Permet de d�clencher la tentative d�achat d�un joueur d�une unit�.
t_unite acheteUnite(t_player player) {

    t_unite newUnite = randomUnite();
    int price = getPrice(newUnite);

    if(getElixir(player) < price) {
        free(newUnite);
        return NULL;
    } else {
        minusElixir(player, price);
        ajouterUnite(player, newUnite);
        return newUnite;
    }
}

void positionneRandomUnite(t_unite unite, bool playerOnTop) {

}

//TEMPS-------------------------------------------------------------------------------------------------------
