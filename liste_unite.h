#ifndef LISTE_UNITE_H_INCLUDED
#define LISTE_UNITE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "unite.h"

    /* Structure de données */



    /* Prototypes de fonctions */

    t_listeUnite creerPileVide();

    bool estVide(t_listeUnite P);

    t_listeUnite empiler(t_listeUnite P, t_unite unite);

    void affichePile(t_listeUnite P);

    t_listeUnite depiler(t_listeUnite P);

    t_unite tetePile(t_listeUnite P);

    /* Prototypes fonctions utilitaires */

    void afficheEstVide(t_listeUnite P);

#endif // LISTE_UNITE_H_INCLUDED
