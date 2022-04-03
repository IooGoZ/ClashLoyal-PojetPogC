#ifndef UNITE_H
#define UNITE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//TYPES-------------------------

    typedef enum e_uniteDuJeu {tour, tourRoi, archer, chevalier, dragon, gargouille} t_uniteDuJeu;

    typedef enum e_cible {sol, solEtAir, air} t_cible;

    typedef struct s_unite {
        t_uniteDuJeu nom;
        t_cible cibleAttaquable;
        t_cible maPosition;
        int pointsDeVie;

        float vitesseAttaque;

        int degats;
        int portee;

        float vitesseDeplacement;

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

//FONCTIONS-USUELLES------------

    //  Positionne une unit� aux coordonn�es (x,y).
    void positionneUnite(t_unite unite, int x, int y);

    //  Cr�er une unit� du type � uniteType �, avec tous les bons param�tres.
    t_unite getNewUnite(t_uniteDuJeu uniteType);

    //  Retourne une unité de type « tour ».
    t_unite creerTourClassique(void);

    //  Retourne une unité de type « roi ».
    t_unite creerTourRoi(void);

    //  Retourne une unité de type « chevalier ».
    t_unite creerChevalier(void);

    //  Retourne une unité de type « archer ».
    t_unite creerArcher(void);

    //  Retourne une unité de type « dragon ».
    t_unite creerDragon(void);

    //  Retourne une unité de type « gargouille ».
    t_unite creerGargouille(void);


    //  Retourne le type de cible d�attaque d�une unit�.
    t_cible getCible(t_unite unite);

    //  Retourne le type de cible qu�est une unit�.
    t_cible getPosition(t_unite unite);

    //  Retourne le nombre de points de vie d�une unit�.
    int getPV(t_unite unite);

    //  Permet de d�finir le nombre de PV d�une unit�.
    void setPV(t_unite unite, int newPV);

    //  Retire une quantité de point de vie à une unité.
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

    //  Retourne le joueur (playerOnTop) auquel appartient l’unité.
    bool getPlayerUnite(t_unite unite);

    //  Définit le joueur (playerOnTop) auquel appartient l’unité.
    void setPlayerUnite(t_unite unite, bool playerOnTop);

    //  Retourne le type d’une unité.
    t_uniteDuJeu getType(t_unite unite);

    //  Créer une pile chainée vide d’unité.
    t_listeUnite creerPileVide(void);

    //  Vérifie si une pile est vide.
    bool estVide(t_listeUnite P);

    //  Ajoute une unité à une pile existante.
    t_listeUnite empiler(t_listeUnite P, t_unite unite);

    //  Retire la première unité de la pile. Libère la mémoire associée à l’unité.
    t_listeUnite depiler(t_listeUnite P);

    //  Supprime une unité spécifique de la pile. Libère la mémoire associée à l’unité.
    t_listeUnite supprimer(t_listeUnite P, t_unite unite);

    //  Retourne la première unité de la pile.
    t_unite tetePile(t_listeUnite P);




    /* Signatures fonctions utilitaires */


#endif
