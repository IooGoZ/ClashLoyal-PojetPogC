#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "unite.h"

#define DEFAULT_POS_X -1
#define DEFAULT_POS_Y -1

//  Positionne une unit� aux coordonn�es (x,y).
void positionneUnite(t_unite unite, int x, int y) {
    unite->posX = x;
    unite->posY = y;
}

//  Cr�er une unit� du type � uniteType �, avec tous les bons param�tres.
t_unite getNewUnite(t_uniteDuJeu uniteType) {
	switch (uniteType) {
	case tour:
		return creerTourClassique();
	case tourRoi:
		return creerTourRoi();
	case chevalier:
		return creerChevalier();
	case archer:
		return creerArcher();
	case dragon:
		return creerDragon();
	case gargouille:
		return creerGargouille();
	}
	return NULL;
}

t_unite allocUnite() {
    return (t_unite) malloc(sizeof(struct s_unite));
}

t_unite creerTourClassique() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = tour;
	res->cibleAttaquable = solEtAir;
	res->maPosition = sol;
	res->pointsDeVie = 500;
	res->vitesseAttaque = 1.0;
	res->degats = 100;
	res->portee = 3;
	res->vitesseDeplacement = 0;
	res->coutEnElixir = 0;

	return res;
}

t_unite creerTourRoi() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = tourRoi;
	res->cibleAttaquable = solEtAir;
	res->maPosition = sol;
	res->pointsDeVie = 800;
	res->vitesseAttaque = 1.2;
	res->degats = 120;
	res->portee = 4;
	res->vitesseDeplacement = 0;
	res->coutEnElixir = 0;

	return res;
}

t_unite creerChevalier() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = chevalier;
	res->cibleAttaquable = sol;
	res->maPosition = sol;
	res->pointsDeVie = 400;
	res->vitesseAttaque = 1.5;
	res->degats = 250;
	res->portee = 1;
	res->vitesseDeplacement = 2.0;
	res->coutEnElixir = 4;

	return res;
}

t_unite creerArcher() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = archer;
	res->cibleAttaquable = solEtAir;
	res->maPosition = sol;
	res->pointsDeVie = 80;
	res->vitesseAttaque = 0.7;
	res->degats = 120;
	res->portee = 3;
	res->vitesseDeplacement = 1.0;
	res->coutEnElixir = 2;

	return res;
}

t_unite creerDragon() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = dragon;
	res->cibleAttaquable = solEtAir;
	res->maPosition = air;
	res->pointsDeVie = 200;
	res->vitesseAttaque = 1.1;
	res->degats = 70;
	res->portee = 2;
	res->vitesseDeplacement = 2.0;
	res->coutEnElixir = 3;

	return res;
}

t_unite creerGargouille() {
	t_unite res = allocUnite();

	res->posX = DEFAULT_POS_X;
	res->posY = DEFAULT_POS_Y;

	res->nom = gargouille;
	res->cibleAttaquable = solEtAir;
	res->maPosition = air;
	res->pointsDeVie = 80;
	res->vitesseAttaque = 0.6;
	res->degats = 90;
	res->portee = 1;
	res->vitesseDeplacement = 3.0;
	res->coutEnElixir = 1;

	return res;
}



//  Retourne le type de cible d�attaque d�une unit�.
t_cible getCible(t_unite unite) {
	return unite->cibleAttaquable;
}

//  Retourne le type de cible qu�est une unit�.
t_cible getPosition(t_unite unite) {
	return unite->maPosition;
}

//  Retourne le nombre de points de vie d�une unit�.
int getPV(t_unite unite) {
	return unite->pointsDeVie;
}

//  Permet de d�finir le nombre de PV d�une unit�.
void setPV(t_unite unite, int newPV) {
	unite->pointsDeVie = newPV;
}

//  Retire une quantité de point de vie à une unité.
void minusPV(t_unite unite, int degatSubit) {
	unite->pointsDeVie = getPV(unite) - degatSubit;
}

//  Retourne la vitesse d�attaque d�une unit�.
float getVitesseAttaque(t_unite unite) {
	return unite->vitesseAttaque;
}

//  Retourne les d�g�ts que fait une unit�.
int getDegats(t_unite unite) {
	return unite->degats;
}

//  Retourne la port�e des attaques d�une unit�.
int getPortee(t_unite unite) {
	return unite->portee;
}

//  Retourne la vitesse d�une unit�.
float getVitesseDeplacement(t_unite unite) {
	return unite->vitesseDeplacement;
}

//  Retourne la position en x d�une unit�.
int getX(t_unite unite) {
	return unite->posX;
}

//  Retourne la position en y d�une unit�.
int getY(t_unite unite) {
	return unite->posY;
}

//  Retourne la possibilit� d�attaque d�une unit�.
bool getAttaque(t_unite unite) {
	return unite->peutAttaquer;
}

//  D�finit la possibilit� d�attaque d�une unit�.
void setAttaque(t_unite unite, bool stat) {
	unite->peutAttaquer = stat;
}

//  Retourne le joueur (playerOnTop) auquel appartient l’unité.
bool getPlayerUnite(t_unite unite) {
    return unite->playerOnTop;
}

//  Définit le joueur (playerOnTop) auquel appartient l’unité.
void setPlayerUnite(t_unite unite, bool playerOnTop) {
    unite->playerOnTop = playerOnTop;
}

//  Retourne le type d’une unité.
t_uniteDuJeu getType(t_unite unite) {
    return unite->nom;
}

//Piles--------------------------------------------------------------
//  Créer une pile chainée vide d’unité.
t_listeUnite creerPileVide() {
	t_listeUnite res = (t_listeUnite) malloc(sizeof(struct s_cell));
	res->pData = NULL;
	res->suiv = NULL;
	return res;
}

//  Vérifie si une pile est vide.
bool estVide(t_listeUnite P) {
	return (P->pData == NULL) && (P->suiv == NULL);
}

//  Ajoute une unité à une pile existante.
t_listeUnite empiler(t_listeUnite P, t_unite unite) {
	t_listeUnite nouv = (t_listeUnite) malloc(sizeof(struct s_cell));

	nouv->pData = unite;
	nouv->suiv = P;

	return nouv;
}

//  Retire la première unité de la pile. Libère la mémoire associée à l’unité.
t_listeUnite depiler(t_listeUnite P) {
	if (estVide(P)) {
		return P;
	} else {
		t_listeUnite temp = P->suiv;
		free(P);
		return temp;
	}

}

//  Supprime une unité spécifique de la pile. Libère la mémoire associée à l’unité.
t_listeUnite supprimer(t_listeUnite P, t_unite unite) {
	if (estVide(P)) {
		return P;
	} else if (P->pData == unite) {
        return P->suiv;
	} else {
		for (t_listeUnite i = P; !estVide(i); i = i->suiv) {
            if (i->suiv->pData == unite) {
                t_listeUnite temp = i->suiv;
                i->suiv = temp->suiv;
                free(temp);
                free(unite);
                break;
            }
		}
		return P;
	}
}

//  Retourne la première unité de la pile.
t_unite tetePile(t_listeUnite P) {
	return P->pData;
}
