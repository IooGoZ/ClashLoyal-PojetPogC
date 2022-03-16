#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "unite.h"

char uniteToChar(t_uniteDuJeu typeUnite);

void affichePile(t_listeUnite P);

void afficheEstVide(t_listeUnite P);

#endif
