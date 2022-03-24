#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "mecanics.h"
#include "joueur.h"
#include "unite.h"
#include "utils.h"



//COMBAT------------------------------------------------------------------------------------------------------

//  Effectue l�attaque d�une unit� sur une autre. (pas de v�rification)
void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee, t_player joueurAttaquee) {
    setAttaque(uniteAttaquante, false);
    minusPV(uniteAttaquee, getDegats(uniteAttaquante));
    if (getPV(uniteAttaquee)<=0) {
        supprimerUnite(joueurAttaquee, uniteAttaquee);
    }
}

    //  Calcule la distance entre deux unit�s.
float distance(t_unite uniteA, t_unite uniteB) {
    return sqrtf((float)(pow(getX(uniteA) - getX(uniteB), 2) + pow(getY(uniteA) - getY(uniteB), 2)));
}

//  V�rifie si une attaque entre deux unit�s est possible (distance/type de cible/possibilité d'attaque)
bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee, bool tourClasssiqueDetruite) {
    if (getAttaque(uniteAttaquante) && distance(uniteAttaquante, uniteAttaquee) <= getPortee(uniteAttaquante)) {
        if (getNom(uniteAttaquee)==tourRoi) {
            return tourClasssiqueDetruite;
        }
        else if (getCible(uniteAttaquante) == solEtAir)
            return true;
        else
            return (getCible(uniteAttaquante) == getPosition(uniteAttaquee));
    } else
        return false;
}

//  Retourne la liste des unit�s adverses atteignables par une unit�.
t_listeUnite quiEstAPortee(t_unite unite, t_listeUnite unitesAdverses, bool tourClasssiqueDetruite) {
    t_listeUnite res = creerPileVide();
    for (t_listeUnite i = unitesAdverses; !estVide(i); i = i->suiv) {
        if (checkAttaque(unite, i->pData, tourClasssiqueDetruite)) {
                printf("1");
            res = empiler(res, i->pData);
        }
    }
	return res;
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


void positionneRandomUnite(t_listeUnite unitePlayerOne, t_listeUnite unitePlayerTwo, t_unite unite, bool playerOnTop) {
    int x =-1, y=-1, minX = 0, maxX = 11, minY, maxY;
    if (playerOnTop) {
        minY = 0;
        maxY = 9;
    } else {
        minY = 10;
        maxY = 19;
    }
    do {
        x = getRandomInt(minX, maxX);
        y = getRandomInt(minY, maxY);
    } while(caseOccupee(unitePlayerOne, unitePlayerTwo, x, y));
    positionneUnite(unite, x, y);
}

//TEMPS-------------------------------------------------------------------------------------------------------
