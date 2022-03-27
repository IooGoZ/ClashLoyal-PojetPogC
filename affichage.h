#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "joueur.h"
#include "unite.h"
#include "mecanics.h"


//FONCTIONS-USUELLES------------

    //Affiche un plateau de jeu.
    void affichePlateau(t_plateauJeu jeu);

//DEBUG-------------------------------

    void affichePile(t_listeUnite P);

    void afficheEstVide(t_listeUnite P);

    void afficheUniteTab(t_unite *tab, int taille);

#endif
