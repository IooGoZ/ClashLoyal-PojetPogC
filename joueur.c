#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "joueur.h"
#include "unite.h"


/*---------------------------------------------------------*/

t_player initPlayer(char * nom, bool playerOnTop)
{
    t_player joueur;

    joueur = (t_player)malloc(sizeof(struct s_player));
    joueur->nom = nom;
    joueur->listeUnite = creerPileVide();      // => NULL ,convention ?
    joueur->nbElixir = 0;
    joueur->playerOnTop = playerOnTop;
    joueur->tourDuRoi = NULL;
    joueur->tourClassique = NULL;

    return joueur;
}

/*---------------------------------------------------------*/

bool tourRoiDetruite(t_player player) {
    return player->tourDuRoi == NULL;
}


/*---------------------------------------------------------*/

int getElixir(t_player player)
{
    return player->nbElixir;
}

/*---------------------------------------------------------*/

void addElixir(t_player player, int amount)
{
    player->nbElixir += amount;
}

/*---------------------------------------------------------*/

void minusElixir(t_player player, int amount)
{
    player->nbElixir -= amount;
}

/*---------------------------------------------------------*/

bool tourClassiqueDetruite(t_player player)
{
    return player->tourClassique == NULL;
}

/*---------------------------------------------------------*/
/*
void supprimerUnite(t_listeUnite *unites, t_unite *uniteDetruite)
{
    BESOIN DE CREER DES FONCTIONS DE MANIPULATION DE LISTE (DOIS-JE LE FAIRE ?)         //      A METTRE A JOUR
}
*/
/*---------------------------------------------------------*/

bool getPlayerOnTop(t_player player)
{
    return player->playerOnTop;
}

/*---------------------------------------------------------*/

t_listeUnite getListeUnite(t_player player) {
    return player->listeUnite;
}
