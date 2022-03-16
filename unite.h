#ifndef UNITE_H
#define UNITE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Structure de données */

typedef enum e_uniteDuJeu {tour, tourRoi, archer, chevalier, dragon, gargouille} t_uniteDuJeu;

typedef enum e_cible {sol, solEtAir, air} t_cible;

typedef struct s_unite {
	t_uniteDuJeu nom;
	t_cible cibleAttaquable;
	t_cible maPosition;
	int pointsDeVie;
	float vitesseAttaque;
	int degats;                     //  Définit une unité
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


t_listeUnite quiEstAPortee(t_listeUnite player, t_unite *uniteAutreJoueur);     //  Retourne la liste des unités adverses atteignables par une unité.

void positionneUnite(t_listeUnite uniteDuJoueur, int x, int y, t_unite unite);      //  Positionne une unité aux coordonnées (x,y).

t_unite getNewUnite(t_uniteDuJeu uniteType);        //  Créer une unité du type « uniteType », avec tous les bons paramètres.


t_unite creerTourClassique(void);

t_unite creerTourRoi(void);

t_unite creerChevalier(void);

t_unite creerArcher(void);

t_unite creerDragon(void);

t_unite creerGargouille(void);


t_cible getCible(t_unite unite);        //  Retourne le type de cible d’attaque d’une unité.

t_cible getPosition(t_unite unite);     //  Retourne le type de cible qu’est une unité.

int getPV(t_unite unite);       //  Retourne le nombre de points de vie d’une unité.

void setPV(t_unite unite, int newPV);       //  Permet de définir le nombre de PV d’une unité.

float getVitesseAttaque(t_unite unite);     //  Retourne la vitesse d’attaque d’une unité.

int getDegats(t_unite unite);       //  Retourne les dégâts que fait une unité.

int getPortee(t_unite unite);       //  Retourne la portée des attaques d’une unité.

float getVitesseDeplacement(t_unite unite);     //  Retourne la vitesse d’une unité.

int getX(t_unite unite);        //  Retourne la position en x d’une unité.

int getY(t_unite unite);        //  Retourne la position en y d’une unité.

bool getAttaque(t_unite unite);     //  Retourne la possibilité d’attaque d’une unité.

void setAttaque(t_unite unite, bool stat);     //  Définit la possibilité d’attaque d’une unité.


t_listeUnite creerPileVide(void);

bool estVide(t_listeUnite P);

t_listeUnite empiler(t_listeUnite P, t_unite unite);

void affichePile(t_listeUnite P);

t_listeUnite depiler(t_listeUnite P);

t_unite tetePile(t_listeUnite P);

/* Prototypes fonctions utilitaires */

void afficheEstVide(t_listeUnite P);

#endif
