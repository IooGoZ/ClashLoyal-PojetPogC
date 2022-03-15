#include "unite.h"
#include "joueur.h"
#include "mecaniques.h"
#include "liste_chainee.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

t_listeUnite creerPileVide()
{
    return NULL;
}

/*---------------------------------------------------------*/

bool estVide(t_listeUnite P)
{
    return(P == NULL)
}

/*---------------------------------------------------------*/


t_listeUnite empiler(t_listeUnite P, char v)
{
    t_listeUnite nouv;

    nouv = (t_listeUnite)malloc(sizeof(struct cellule));

    nouv->val = v;
    nouv->suiv = P;

    return nouv;
}

/*---------------------------------------------------------*/

void affichePile(t_listeUnite P)
{
    for(t_listeUnite i = P; i != NULL ; i = i->suiv)
    {
        printf("\t[%c]\n",i->val);
    }
}

/*---------------------------------------------------------*/

t_listeUnite depiler(t_listeUnite P)
{
    if(estVide(P))
    {
        return NULL;
    }

    if(estVide(P->suiv))
    {
        return NULL;
    }

    t_listeUnite temp = P->suiv;

    free(P);

    return temp;
}

/*---------------------------------------------------------*/

char tetePile(t_listeUnite P)
{
    if(estVide(P))
    {
        printf("La pile est vide, caractere retourne : ' '");
        return ' ';
    }

    return P->val;
}

/*---------------------------------------------------------*/

t_listeUnite viderTout(t_listeUnite P)
{
    while(P != NULL)
    {
        P = depiler(P);
    }

    return P;
}

/*---------------------Fonctions utilitaires---------------------------*/

void afficheEstVide(t_listeUnite P)
{
    if(estVide(P))
    {
        printf("Ma pile est vide.\n");
    }
    else
    {
        printf("Ma pile n'est pas vide.\n");
    }
}

/*---------------------------------------------------------*/

t_listeUnite retournePile(t_listeUnite P)
{
    t_listeUnite newpile;

    newpile = creerPileVide();

    while(P != NULL)
    {
      newpile = empiler(newpile, P->val);
      P = depiler(P);
    }

    return newpile;
}
