#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "unite.h"


    /* Structures de donn�es */

    typedef struct s_player
    {
        char* nom;
        t_listeUnite listeUnite;
        int nbElixir;
        //  playerOnTop = true => il s'agit du joueur qui a la partie haute de l��cran.
        bool playerOnTop;
        t_unite tourDuRoi;
        t_unite tourClassique;
    } *t_player;

    /* Signatures des fonctions */

    //  Initialise un joueur, avec un nom et sa position.
    t_player initPlayer(char * nom, bool playerOnTop);

    //  V�rifie si la tour du roi d�un joueur est d�truite.
    bool tourRoiDetruite(t_player player);

    //  Retourne la quantit� d��lixir d�un joueur.
    int getElixir(t_player player);

    char* getNom(t_player player);

    //  Ajoute une quantit� d��lixir au joueur.
    void addElixir(t_player player, int amount);

    //  Retire une quantit� d��lixir au joueur.
    void minusElixir(t_player player, int amount);

    // V�rifie si la tour (non-roi) d�un joueur est d�truite.
    bool tourClassiqueDetruite(t_player player);

    //  Supprime une unit� � un joueur.
    void supprimerUnite(t_player player, t_unite uniteDetruite);

    //  Ajoute une unit� � un joueur.
    void ajouterUnite(t_player player, t_unite nouvelleUnite);

    //  Retourne true si le joueur est en haut dans l�affichage.
    bool getPlayerOnTop(t_player player);

    //  Retourne la liste des unit�s d�un joueur.
    t_listeUnite getListeUnite(t_player player);


#endif
