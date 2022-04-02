#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED

#include "clashloyal.h"
#include "joueur.h"
#include "utils.h"
#include "unite.h"

//Fonctions communes------------------------------------

//Fonctions séquentielles-------------------------------
void saveLisible(t_jeuStats stats, char* path);

t_unite readLisibleUnite(FILE* saveFile, t_player player);

void readLisible(t_jeuStats stats, char* path);

//Fonctions binaires------------------------------------
void saveBinaire(t_jeuStats stats, char* path);

t_unite readBinaireUnite(FILE* saveFile, t_player player);

void readBinaire(t_jeuStats stats, char* path);


#endif // SAUVEGARDE_H_INCLUDED
