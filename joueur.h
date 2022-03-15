#include <stdbool.h>
#include "liste_unite.h"

#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

    /* Structure de donn�es */

    typedef struct
    {
        char* nom;
        t_listeUnite listeUnite;
        int nbElixir;               //  D�finit un joueur (playerOnTop = true => il s'agit du joueur qui a la partie haute de l��cran.
        bool playerOnTop;
    } *t_player;

    /* Prototypes de fonctions */

    t_player initPlayer(char * nom, bool playerOnTop);      //  Initialise un joueur, avec un nom et sa position.

    bool tourRoiDetruite(t_listeUnite uniteListe);      //  V�rifie si la tour du roi d�un joueur est d�truite.

    int getElixir(t_player player);        //  Retourne la quantit� d��lixir d�un joueur.

    void addElixir(t_player player, int amount);        //  Ajoute une quantit� d��lixir au joueur.

    void minusElixir(t_player player, int amount);      //  Retire une quantit� d��lixir au joueur.

    bool tourClassiqueDetruite(t_listeUnite player);        // V�rifie si la tour (non-roi) d�un joueur est d�truite.

    void supprimerUnite(t_listeUnite uniteListe, t_unite *uniteDetruite);      //  Supprime une unit� � un joueur.

    void ajouterUnite(t_listeUnite uniteListe, t_unite *nouvelleUnite);        //  Ajoute une unit� � un joueur.

    bool getPlayerOnTop(t_player player);      //  Retourne true si le joueur est en haut dans l�affichage.

    t_listeUnite getListeUnite(t_player player);       //  Retourne la liste des unit�s d�un joueur.

#endif // JOUEUR_H_INCLUDED
