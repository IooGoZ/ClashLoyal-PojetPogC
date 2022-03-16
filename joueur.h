#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "unite.h"


    /* Structure de données */

    typedef struct s_player
    {
        char* nom;
        t_listeUnite listeUnite;
        int nbElixir;               //  Définit un joueur (playerOnTop = true => il s'agit du joueur qui a la partie haute de l’écran.
        bool playerOnTop;
        t_unite* tourDuRoi;
        t_unite* tourClassique;
    } *t_player;

    /* Prototypes de fonctions */

    t_player initPlayer(char * nom, bool playerOnTop);      //  Initialise un joueur, avec un nom et sa position.

    bool tourRoiDetruite(t_player player);      //  Vérifie si la tour du roi d’un joueur est détruite.

    int getElixir(t_player player);        //  Retourne la quantité d’élixir d’un joueur.

    void addElixir(t_player player, int amount);        //  Ajoute une quantité d’élixir au joueur.

    void minusElixir(t_player player, int amount);      //  Retire une quantité d’élixir au joueur.

    bool tourClassiqueDetruite(t_player player);        // Vérifie si la tour (non-roi) d’un joueur est détruite.

    void supprimerUnite(t_listeUnite uniteListe, t_unite *uniteDetruite);      //  Supprime une unité à un joueur.

    void ajouterUnite(t_listeUnite uniteListe, t_unite *nouvelleUnite);        //  Ajoute une unité à un joueur.

    bool getPlayerOnTop(t_player player);      //  Retourne true si le joueur est en haut dans l’affichage.

    t_listeUnite getListeUnite(t_player player);       //  Retourne la liste des unités d’un joueur.

#endif
