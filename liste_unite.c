#include "liste_unite.h"

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
    return(P == NULL);
}

/*---------------------------------------------------------*/

t_listeUnite empiler(t_listeUnite P, t_unite unite)
{
    t_listeUnite nouv = creerPileVide();

    nouv = (t_listeUnite)malloc(sizeof(t_unite));

    nouv->pData = &unite;
    nouv->suiv = P;

    return nouv;
}

/*---------------------------------------------------------*/
/*
void affichePile(t_listeUnite P)
{
    for(t_listeUnite i = P; i != NULL ; i = i->suiv)                            //      DEFAILLANT
    {
        printf("\t[%c]\n",i->val);
    }
}
*/
/*---------------------------------------------------------*/

t_listeUnite depiler(t_listeUnite P)
{
    if(estVide(P))
    {
        return creerPileVide();
    }

    if(estVide(P->suiv))
    {
        free(P);
        return creerPileVide();
    }

    t_listeUnite temp = P->suiv;

    free(P);

    return temp;
}

/*---------------------------------------------------------*/

t_unite tetePile(t_listeUnite P)
{
    return *(P->pData);
}

/*---------------------Fonctions utilitaires---------------------------*/

void afficheEstVide(t_listeUnite P)
{
    if(estVide(P))
    {
        printf("Ma pile d'unite est vide.\n");
    }
    else
    {
        printf("Ma pile d'unite n'est pas vide.\n");
    }
}
