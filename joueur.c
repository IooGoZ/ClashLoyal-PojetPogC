#include "joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*---------------------------------------------------------*/

t_player initPlayer(char * nom, bool playerOnTop)
{
    t_player joueur;

    joueur = (t_player)malloc(sizeof(t_player));    //  à vérifier sizeof(t_player) car t_player est un pointeur
    joueur->nom = nom;
    joueur->listeUnite = creerPileVide();      // => NULL ,convention ?
    joueur->nbElixir = 0;
    joueur->playerOnTop = playerOnTop;

    return joueur;
}

/*---------------------------------------------------------*/
/*
bool tourRoiDetruite(t_listeUnite uniteListe)
{
                                   // CONVENTION ?
}
*/
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
/*
bool tourClassiqueDetruite(t_listeUnite player)
{
    CONVENTION ?
}
*/
/*---------------------------------------------------------*/
/*
void supprimerUnite(t_listeUnite *unites, t_unite *uniteDetruite)
{
    BESOIN DE CREER DES FONCTIONS DE MANIPULATION DE LISTE (DOIS-JE LE FAIRE ?)
}
*/
/*---------------------------------------------------------*/

bool getPlayerOnTop(t_player player)
{
    return player->playerOnTop;
}

/*---------------------------------------------------------*/

t_listeUnite getListeUnite(t_player player)
{
    return player->listeUnite;
}
