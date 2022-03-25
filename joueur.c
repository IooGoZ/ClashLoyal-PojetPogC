#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "joueur.h"
#include "unite.h"


/*---------------------------------------------------------*/

//  Initialise un joueur, avec un nom et sa position.
t_player initPlayer(char * nom, bool playerOnTop) {
    t_player joueur;

    joueur = (t_player)malloc(sizeof(struct s_player));
    joueur->nom = nom;
    joueur->nbElixir = 0;
    joueur->playerOnTop = playerOnTop;

    //Initialisation des unités
    t_listeUnite lUnites = creerPileVide();

    t_unite roi = getNewUnite(tourRoi);
    t_unite tourClassique = getNewUnite(tour);

    setPlayerUnite(roi, playerOnTop);
    setPlayerUnite(tourClassique, playerOnTop);

    if (playerOnTop) {
        positionneUnite(roi, 5, 1);
        positionneUnite(tourClassique, 5, 3);
    } else {
        positionneUnite(roi, 5, 17);
        positionneUnite(tourClassique, 5, 15);
    }

    lUnites = empiler(lUnites, roi);
    lUnites = empiler(lUnites, tourClassique);


    joueur->listeUnite = lUnites;
    joueur->tourDuRoi = roi;
    joueur->tourClassique = tourClassique;

    return joueur;
}

/*---------------------------------------------------------*/

//  Vérifie si la tour du roi d’un joueur est détruite.
bool tourRoiDetruite(t_player player) {
    return (player->tourDuRoi == NULL);
}


/*---------------------------------------------------------*/

//  Retourne la quantité d’élixir d’un joueur.
int getElixir(t_player player) {
    return player->nbElixir;
}

char* getNom(t_player player) {
    return player->nom;
}

/*---------------------------------------------------------*/

//  Ajoute une quantité d’élixir au joueur.
void addElixir(t_player player, int amount) {
    player->nbElixir += amount;
}

/*---------------------------------------------------------*/

//  Retire une quantité d’élixir au joueur.
void minusElixir(t_player player, int amount) {
    player->nbElixir -= amount;
}

/*---------------------------------------------------------*/

// Vérifie si la tour (non-roi) d’un joueur est détruite.
bool tourClassiqueDetruite(t_player player) {
    return player->tourClassique == NULL;
}

/*---------------------------------------------------------*/

//  Supprime une unité à un joueur.
void supprimerUnite(t_player player, t_unite uniteDetruite) {
    if (getType(uniteDetruite) == tourRoi) {
        player->tourDuRoi = NULL;
    } else if (getType(uniteDetruite) == tour) {
        player->tourClassique = NULL;
    }
    player->listeUnite = supprimer(player->listeUnite, uniteDetruite);
}

/*---------------------------------------------------------*/

//  Ajoute une unité à un joueur.
void ajouterUnite(t_player player, t_unite nouvelleUnite) {
    setPlayerUnite(nouvelleUnite, getPlayerOnTop(player));
    player->listeUnite = empiler(player->listeUnite, nouvelleUnite);
}

/*---------------------------------------------------------*/

//  Retourne true si le joueur est en haut dans l’affichage.
bool getPlayerOnTop(t_player player) {
    return player->playerOnTop;
}

/*---------------------------------------------------------*/

//  Retourne la liste des unités d’un joueur.
t_listeUnite getListeUnite(t_player player) {
    return player->listeUnite;
}

/*---------------------------------------------------------*/
