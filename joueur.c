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

    //Initialisation des unit�s
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

//  V�rifie si la tour du roi d�un joueur est d�truite.
bool tourRoiDetruite(t_player player) {
    return (player->tourDuRoi == NULL);
}


/*---------------------------------------------------------*/

//  Retourne la quantit� d��lixir d�un joueur.
int getElixir(t_player player) {
    return player->nbElixir;
}

char* getNom(t_player player) {
    return player->nom;
}

/*---------------------------------------------------------*/

//  Ajoute une quantit� d��lixir au joueur.
void addElixir(t_player player, int amount) {
    player->nbElixir += amount;
}

/*---------------------------------------------------------*/

//  Retire une quantit� d��lixir au joueur.
void minusElixir(t_player player, int amount) {
    player->nbElixir -= amount;
}

/*---------------------------------------------------------*/

// V�rifie si la tour (non-roi) d�un joueur est d�truite.
bool tourClassiqueDetruite(t_player player) {
    return player->tourClassique == NULL;
}

/*---------------------------------------------------------*/

//  Supprime une unit� � un joueur.
void supprimerUnite(t_player player, t_unite uniteDetruite) {
    if (getType(uniteDetruite) == tourRoi) {
        player->tourDuRoi = NULL;
    } else if (getType(uniteDetruite) == tour) {
        player->tourClassique = NULL;
    }
    player->listeUnite = supprimer(player->listeUnite, uniteDetruite);
}

/*---------------------------------------------------------*/

//  Ajoute une unit� � un joueur.
void ajouterUnite(t_player player, t_unite nouvelleUnite) {
    setPlayerUnite(nouvelleUnite, getPlayerOnTop(player));
    player->listeUnite = empiler(player->listeUnite, nouvelleUnite);
}

/*---------------------------------------------------------*/

//  Retourne true si le joueur est en haut dans l�affichage.
bool getPlayerOnTop(t_player player) {
    return player->playerOnTop;
}

/*---------------------------------------------------------*/

//  Retourne la liste des unit�s d�un joueur.
t_listeUnite getListeUnite(t_player player) {
    return player->listeUnite;
}

/*---------------------------------------------------------*/
