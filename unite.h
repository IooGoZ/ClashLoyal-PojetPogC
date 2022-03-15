#include "joueur.h"
#include "mecaniques.h"
#include <stdbool.h>


/* Structure de données */

typedef enum
{
	tour,
	tourRoi,
	archer,             //  Définit le type d’une unité.
	chevalier,
	dragon,
	gargouille
} t_uniteDuJeu;

typedef enum
{
	sol,
	solEtAir,               //  Définit le type d’attaque possible par une unité.
	air
} t_cible;

typedef struct
{
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

/* Prototypes de fonctions */

t_listeUnite quiEstAPortee(t_listeUnite player, t_unite *uniteAutreJoueur);     //  Retourne la liste des unités adverses atteignables par une unité.

void positionneUnite(t_listeUnite uniteDuJoueur, int x, int y, t_unite unite);      //  Positionne une unité aux coordonnées (x,y).

t_unite getNewUnite(t_uniteDuJeu uniteType);        //  Créer une unité du type « uniteType », avec tous les bons paramètres.

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

void setAttaque(t_unite unite);     //  Définit la possibilité d’attaque d’une unité.
