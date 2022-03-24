#ifndef UNITE_H
#define UNITE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Structure de donn�es */

typedef enum e_uniteDuJeu {tour, tourRoi, archer, chevalier, dragon, gargouille} t_uniteDuJeu;

typedef enum e_cible {sol, solEtAir, air} t_cible;

typedef struct s_unite {
	t_uniteDuJeu nom;
	t_cible cibleAttaquable;
	t_cible maPosition;
	int pointsDeVie;

	float vitesseAttaque;
	float tempsAttaque;

	int degats;
	int portee;

	float vitesseDeplacement;
	float tempsDeplacement;

	int posX, posY;
	bool peutAttaquer;
	int coutEnElixir;

	//permet de determiner à quel joueur appartient une unité. (Utile pour les combats)
	bool playerOnTop;
} *t_unite;

typedef struct s_cell {
	struct s_cell *suiv;
	t_unite pData;
} *t_listeUnite;

/* Signatures de fonctions */

//  Positionne une unit� aux coordonn�es (x,y).
void positionneUnite(t_unite unite, int x, int y);

//  Cr�er une unit� du type � uniteType �, avec tous les bons param�tres.
t_unite getNewUnite(t_uniteDuJeu uniteType);


t_unite creerTourClassique(void);

t_unite creerTourRoi(void);

t_unite creerChevalier(void);

t_unite creerArcher(void);

t_unite creerDragon(void);

t_unite creerGargouille(void);


//  Retourne le type de cible d�attaque d�une unit�.
t_cible getCible(t_unite unite);

//  Retourne le type de cible qu�est une unit�.
t_cible getPosition(t_unite unite);

//  Retourne le nombre de points de vie d�une unit�.
int getPV(t_unite unite);

//  Permet de d�finir le nombre de PV d�une unit�.
void setPV(t_unite unite, int newPV);

//  Retourne le nouveau nombre de PV d�une unit�.
void minusPV(t_unite unite, int degatSubit);

//  Retourne la vitesse d�attaque d�une unit�.
float getVitesseAttaque(t_unite unite);

//  Retourne les d�g�ts que fait une unit�.
int getDegats(t_unite unite);

//  Retourne la port�e des attaques d�une unit�.
int getPortee(t_unite unite);

//  Retourne la vitesse d�une unit�.
float getVitesseDeplacement(t_unite unite);

//  Retourne la position en x d�une unit�.
int getX(t_unite unite);

//  Retourne la position en y d�une unit�.
int getY(t_unite unite);

//  Retourne la possibilit� d�attaque d�une unit�.
bool getAttaque(t_unite unite);

//  D�finit la possibilit� d�attaque d�une unit�.
void setAttaque(t_unite unite, bool stat);

//  Retourne le temps courant d'une attaque
float getTempsAttaque(t_unite unite);

void setTempsAttaque(t_unite unite, float time);

//  Retourne le temps courant d'un déplacement
float getTempsDeplacement(t_unite unite);

void setTempsDeplacement(t_unite unite, float time);

bool getPlayerUnite(t_unite unite);

void setPlayerUnite(t_unite unite, bool playerOnTop);

t_listeUnite creerPileVide(void);

bool estVide(t_listeUnite P);

t_listeUnite empiler(t_listeUnite P, t_unite unite);

t_listeUnite depiler(t_listeUnite P);

t_unite tetePile(t_listeUnite P);

//  Retourne la liste des unit�s adverses atteignables par une unit�.
t_listeUnite quiEstAPortee(t_unite unite, t_listeUnite unitesAdverses);


/* Signatures fonctions utilitaires */


#endif
