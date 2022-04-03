#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED

#include "clashloyal.h"
#include "joueur.h"
#include "utils.h"
#include "unite.h"

//Fonctions s�quentielles-------------------------------
//Sauvegarde un fichier �ditable avec �diteur de texte.
void saveLisible(t_jeuStats stats, char* path);

//Lit une unit� sauvegard�e avec � saveLisible �.
t_unite readLisibleUnite(FILE* saveFile, t_player player);

//Lit un fichier sauvegard� avec � saveLisible �.
void readLisible(t_jeuStats stats, char* path);

//Fonctions binaires------------------------------------
//Sauvegarde un fichier binaire.
void saveBinaire(t_jeuStats stats, char* path);

//Lit une unit� sauvegard�e avec � saveBinaire �.
t_unite readBinaireUnite(FILE* saveFile, t_player player);

//Lit un fichier sauvegard� avec � saveBinaire �.
void readBinaire(t_jeuStats stats, char* path);


#endif // SAUVEGARDE_H_INCLUDED
