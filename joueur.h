#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "unite.h"


    /* Structures de données */

    typedef struct s_player
    {
        char* nom;
        t_listeUnite listeUnite;
        int nbElixir;
        //  playerOnTop = true => il s'agit du joueur qui a la partie haute de l’écran.
        bool playerOnTop;
        t_unite tourDuRoi;
        t_unite tourClassique;
    } *t_player;

    /* Signatures des fonctions */

    //  Initialise un joueur, avec un nom et sa position.
    t_player initPlayer(char * nom, bool playerOnTop);

    //  Vérifie si la tour du roi d’un joueur est détruite.
    bool tourRoiDetruite(t_player player);

    //  Retourne la quantité d’élixir d’un joueur.
    int getElixir(t_player player);

    char* getNom(t_player player);

    //  Ajoute une quantité d’élixir au joueur.
    void addElixir(t_player player, int amount);

    //  Retire une quantité d’élixir au joueur.
    void minusElixir(t_player player, int amount);

    // Vérifie si la tour (non-roi) d’un joueur est détruite.
    bool tourClassiqueDetruite(t_player player);

    //  Supprime une unité à un joueur.
    void supprimerUnite(t_player player, t_unite uniteDetruite);

    //  Ajoute une unité à un joueur.
    void ajouterUnite(t_player player, t_unite nouvelleUnite);

    //  Retourne true si le joueur est en haut dans l’affichage.
    bool getPlayerOnTop(t_player player);

    //  Retourne la liste des unités d’un joueur.
    t_listeUnite getListeUnite(t_player player);


#endif
