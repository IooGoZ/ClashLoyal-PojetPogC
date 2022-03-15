#include "joueur.h"
#include "mecaniques.h"
#include <stdbool.h>


/* Structure de donn�es */

typedef enum
{
	tour,
	tourRoi,
	archer,             //  D�finit le type d�une unit�.
	chevalier,
	dragon,
	gargouille
} t_uniteDuJeu;

typedef enum
{
	sol,
	solEtAir,               //  D�finit le type d�attaque possible par une unit�.
	air
} t_cible;

typedef struct
{
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

/* Prototypes de fonctions */

t_listeUnite quiEstAPortee(t_listeUnite player, t_unite *uniteAutreJoueur);     //  Retourne la liste des unit�s adverses atteignables par une unit�.

void positionneUnite(t_listeUnite uniteDuJoueur, int x, int y, t_unite unite);      //  Positionne une unit� aux coordonn�es (x,y).

t_unite getNewUnite(t_uniteDuJeu uniteType);        //  Cr�er une unit� du type � uniteType �, avec tous les bons param�tres.

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

void setAttaque(t_unite unite);     //  D�finit la possibilit� d�attaque d�une unit�.
