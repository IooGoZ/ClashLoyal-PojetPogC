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
	int degats;                     //  D�finit une unit�
	int portee;
	float vitesseDeplacement;
	int posX, posY;
	bool peutAttaquer;
	int coutEnElixir;
} t_unite;

typedef struct s_cell {
	struct t_cell *suiv;
	t_unite *pData;
} *t_listeUnite;

/* Prototypes de fonctions */


t_listeUnite quiEstAPortee(t_listeUnite player, t_unite *uniteAutreJoueur);     //  Retourne la liste des unit�s adverses atteignables par une unit�.

void positionneUnite(t_listeUnite uniteDuJoueur, int x, int y, t_unite unite);      //  Positionne une unit� aux coordonn�es (x,y).

t_unite getNewUnite(t_uniteDuJeu uniteType);        //  Cr�er une unit� du type � uniteType �, avec tous les bons param�tres.


t_unite creerTourClassique(void);

t_unite creerTourRoi(void);

t_unite creerChevalier(void);

t_unite creerArcher(void);

t_unite creerDragon(void);

t_unite creerGargouille(void);


t_cible getCible(t_unite unite);        //  Retourne le type de cible d�attaque d�une unit�.

t_cible getPosition(t_unite unite);     //  Retourne le type de cible qu�est une unit�.

int getPV(t_unite unite);       //  Retourne le nombre de points de vie d�une unit�.

void setPV(t_unite unite, int newPV);       //  Permet de d�finir le nombre de PV d�une unit�.

float getVitesseAttaque(t_unite unite);     //  Retourne la vitesse d�attaque d�une unit�.

int getDegats(t_unite unite);       //  Retourne les d�g�ts que fait une unit�.

int getPortee(t_unite unite);       //  Retourne la port�e des attaques d�une unit�.

float getVitesseDeplacement(t_unite unite);     //  Retourne la vitesse d�une unit�.

int getX(t_unite unite);        //  Retourne la position en x d�une unit�.

int getY(t_unite unite);        //  Retourne la position en y d�une unit�.

bool getAttaque(t_unite unite);     //  Retourne la possibilit� d�attaque d�une unit�.

void setAttaque(t_unite unite, bool stat);     //  D�finit la possibilit� d�attaque d�une unit�.


t_listeUnite creerPileVide(void);

bool estVide(t_listeUnite P);

t_listeUnite empiler(t_listeUnite P, t_unite unite);

void affichePile(t_listeUnite P);

t_listeUnite depiler(t_listeUnite P);

t_unite tetePile(t_listeUnite P);

/* Prototypes fonctions utilitaires */

void afficheEstVide(t_listeUnite P);

#endif
