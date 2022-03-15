#include "unite.h"
#include "joueur.h"
#include "mecaniques.h"
#include "liste_chainee.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  Retourne la liste des unités adverses atteignables par une unité.
t_listeUnite quiEstAPortee(t_listeUnite player, t_unite *uniteAutreJoueur) {

}

//  Positionne une unité aux coordonnées (x,y).
void positionneUnite(t_listeUnite uniteDuJoueur, int x, int y, t_unite unite) {

}

//  Créer une unité du type « uniteType », avec tous les bons paramètres.
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
	default :
		return NULL;

	}
}

t_unite creerTourClassique() {
	t_unite res;

	res.nom = tour;
	res.cibleAttaquable = solEtAir;
	res.maPosition = sol;
	res.pointsDeVie = 500;
	res.vitesseAttaque = 1.0;
	res.degats = 100;
	res.portee = 3;
	res.vitesseDeplacement = 0;
	res.coutEnElixir = 0;

	return res;
}

t_unite creerTourRoi() {
	t_unite res;

	res.nom = tourRoi;
	res.cibleAttaquable = solEtAir;
	res.maPosition = sol;
	res.pointsDeVie = 800;
	res.vitesseAttaque = 1.2;
	res.degats = 120;
	res.portee = 4;
	res.vitesseDeplacement = 0;
	res.coutEnElixir = 0;

	return res;
}

t_unite creerChevalier() {
	t_unite res;

	res.nom = tour;
	res.cibleAttaquable = sol;
	res.maPosition = sol;
	res.pointsDeVie = 400;
	res.vitesseAttaque = 1.5;
	res.degats = 250;
	res.portee = 1;
	res.vitesseDeplacement = 2.0;
	res.coutEnElixir = 0;

	return res;
}

t_unite creerArcher() {
	t_unite res;

	res.nom = archer;
	res.cibleAttaquable = solEtAir;
	res.maPosition = sol;
	res.pointsDeVie = 80;
	res.vitesseAttaque = 0.7;
	res.degats = 120;
	res.portee = 3;
	res.vitesseDeplacement = &.0;
	res.coutEnElixir = 2;

	return res;
}

t_unite creerDragon() {
	t_unite res;

	res.nom = dragon;
	res.cibleAttaquable = solEtAir;
	res.maPosition = air;
	res.pointsDeVie = 200;
	res.vitesseAttaque = 1.1;
	res.degats = 70;
	res.portee = 2;
	res.vitesseDeplacement = 2.0;
	res.coutEnElixir = 3;

	return res;
}

t_unite creerGargouille() {
	t_unite res;

	res.nom = gargouille;
	res.cibleAttaquable = solEtAir;
	res.maPosition = air;
	res.pointsDeVie = 80;
	res.vitesseAttaque = 0.6;
	res.degats = 90;
	res.portee = 1;
	res.vitesseDeplacement = 3.0;
	res.coutEnElixir = 1;

	return res;
}

//  Retourne le type de cible d’attaque d’une unité.
t_cible getCible(t_unite unite) {
	return unite.cibleAttaquable;
}

//  Retourne le type de cible qu’est une unité.
t_cible getPosition(t_unite unite) {
	return unite.maPosition;
}

//  Retourne le nombre de points de vie d’une unité.
int getPV(t_unite unite) {
	return unite.pointsDeVie;
}

//  Permet de définir le nombre de PV d’une unité.
void setPV(t_unite unite, int newPV) {
	unite.pointsDeVie = newPV;
}

//  Retourne la vitesse d’attaque d’une unité.
float getVitesseAttaque(t_unite unite) {
	return unite.vitesseAttaque;
}

//  Retourne les dégâts que fait une unité.
int getDegats(t_unite unite) {
	return unite.degats;
}

//  Retourne la portée des attaques d’une unité.
int getPortee(t_unite unite) {
	return unite.portee;
}

//  Retourne la vitesse d’une unité.
float getVitesseDeplacement(t_unite unite) {
	return unite.vitesseDeplacement;
}

//  Retourne la position en x d’une unité.
int getX(t_unite unite) {
	return unite.posX;
}

//  Retourne la position en y d’une unité.
int getY(t_unite unite) {
	return unite.posY;
}

//  Retourne la possibilité d’attaque d’une unité.
bool getAttaque(t_unite unite) {

}

void setAttaque(t_unite unite) {

}
/*---------------------------------------------------------*/
