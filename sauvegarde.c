#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarde.h"
#include "clashloyal.h"
#include "joueur.h"
#include "utils.h"
#include "unite.h"

//Fonctions communes------------------------------------

//Fonctions séquentielles-------------------------------
void saveLisible(t_jeuStats stats, char* path) {
    t_player joueurOne = stats->playerOne;
    t_player joueurTwo = stats->playerTwo;

    FILE* saveFile = fopen(path, "w");

    int nomLenJoueurOne = strlen(getNom(joueurOne));
    int nomLenJoueurTwo = strlen(getNom(joueurTwo));

    int listeLenJoueurOne = lenListe(getListeUnite(joueurOne));
    int listeLenJoueurTwo = lenListe(getListeUnite(joueurTwo));

	fprintf(saveFile, "%d %d %d\n", getElixir(joueurOne), nomLenJoueurOne, listeLenJoueurOne);
    fprintf(saveFile, "%d %d %d\n", getElixir(joueurTwo), nomLenJoueurTwo, listeLenJoueurTwo);
    fprintf(saveFile, "%s\n", getNom(joueurOne));
    fprintf(saveFile, "%s\n", getNom(joueurTwo));

	for(t_listeUnite temp = getListeUnite(joueurOne); !estVide(temp); temp = temp->suiv) {
        t_unite currentUnite = temp->pData;
        fprintf(saveFile, "%d %d %d %d %d\n", getType(currentUnite), getPV(currentUnite), getX(currentUnite), getY(currentUnite), getAttaque(currentUnite));
	}
	for(t_listeUnite temp = getListeUnite(joueurTwo); !estVide(temp); temp = temp->suiv) {
        t_unite currentUnite = temp->pData;
        fprintf(saveFile, "%d %d %d %d %d\n", getType(currentUnite), getPV(currentUnite), getX(currentUnite), getY(currentUnite), getAttaque(currentUnite));
	}

	fclose(saveFile);
}

t_unite readLisibleUnite(FILE* saveFile, t_player player) {
    int typeInt, pv, x, y, peutAttaquer;

    fscanf(saveFile, "%d %d %d %d %d\n", &typeInt, &pv, &x, &y, &peutAttaquer);

    t_uniteDuJeu type = (t_uniteDuJeu) typeInt;

    t_unite unite = getNewUnite(type);
    setPV(unite, pv);
    positionneUnite(unite, x, y);
    setAttaque(unite, (bool) peutAttaquer);

    if (type == tour)
        player->tourClassique = unite;
    else if (type == tourRoi)
        player->tourDuRoi = unite;

    return unite;
}

void readLisible(t_jeuStats stats, char* path) {
    t_player joueurOne = stats->playerOne;
    t_player joueurTwo = stats->playerTwo;

    FILE* saveFile = fopen(path, "r");

    //Déclaration des variables avant lecture
    int nbElixirJoueurOne, nbElixirJoueurTwo;
    int nomLenJoueurOne, nomLenJoueurTwo;
    int listeLenJoueurOne, listeLenJoueurTwo;

    //Lecture des deux premières lignes
	fscanf(saveFile, "%d %d %d\n", &nbElixirJoueurOne, &nomLenJoueurOne, &listeLenJoueurOne);
    fscanf(saveFile, "%d %d %d\n", &nbElixirJoueurTwo, &nomLenJoueurTwo, &listeLenJoueurTwo);

    //Préparation des noms
    char * nomJoueurOne = (char*) malloc(sizeof(char) * nomLenJoueurOne);
    char * nomJoueurTwo = (char*) malloc(sizeof(char) * nomLenJoueurTwo);

    //Lecture des noms
    fscanf(saveFile, "%s\n", nomJoueurOne);
    fscanf(saveFile, "%s\n", nomJoueurTwo);

    //Attribution des valeurs
    joueurOne->nbElixir = nbElixirJoueurOne;
    joueurTwo->nbElixir = nbElixirJoueurTwo;
    joueurOne->nom = nomJoueurOne;
    joueurTwo->nom = nomJoueurTwo;

    //Supression des listes d'unités
    t_listeUnite temp;
    for(temp = getListeUnite(joueurOne); !estVide(temp); temp = depiler(temp));
    joueurOne->listeUnite = temp;
    for(temp = getListeUnite(joueurTwo); !estVide(temp); temp = depiler(temp));
    joueurTwo->listeUnite = temp;

    //Lecture des unités
	for(int i = 0; i < listeLenJoueurOne; i++) {
        t_unite unite = readLisibleUnite(saveFile, joueurOne);
        ajouterUnite(joueurOne, unite);
	}

	for(int i = 0; i < listeLenJoueurTwo; i++) {
        t_unite unite = readLisibleUnite(saveFile, joueurTwo);
        ajouterUnite(joueurTwo, unite);
	}

	fclose(saveFile);
}
//Fonctions binaires------------------------------------

void saveBinaire(t_jeuStats stats, char* path) {
    t_player joueurOne = stats->playerOne;
    t_player joueurTwo = stats->playerTwo;

    FILE* saveFile = fopen(path, "w");

    int nomLenJoueurOne = strlen(getNom(joueurOne));
    int nomLenJoueurTwo = strlen(getNom(joueurTwo));

    int listeLenJoueurOne = lenListe(getListeUnite(joueurOne));
    int listeLenJoueurTwo = lenListe(getListeUnite(joueurTwo));

    int elixirJoueurOne = getElixir(joueurOne);
    int elixirJoueurTwo = getElixir(joueurTwo);

    char * nomJoueurOne = getNom(joueurOne);
    char * nomJoueurTwo = getNom(joueurTwo);

    fwrite(&elixirJoueurOne, sizeof(int), 1, saveFile);
    fwrite(&nomLenJoueurOne, sizeof(int), 1, saveFile);
    fwrite(&listeLenJoueurOne, sizeof(int), 1, saveFile);

    fwrite(&elixirJoueurTwo, sizeof(int), 1, saveFile);
    fwrite(&nomLenJoueurTwo, sizeof(int), 1, saveFile);
    fwrite(&listeLenJoueurTwo, sizeof(int), 1, saveFile);

    fwrite(&listeLenJoueurTwo, sizeof(int), 1, saveFile);
    fwrite(&listeLenJoueurTwo, sizeof(int), 1, saveFile);

    fwrite(&nomJoueurOne, sizeof(char), nomLenJoueurOne, saveFile);
    fwrite(&nomJoueurTwo, sizeof(char), nomLenJoueurTwo, saveFile);

	for(t_listeUnite temp = getListeUnite(joueurOne); !estVide(temp); temp = temp->suiv) {
        t_unite currentUnite = temp->pData;
        fwrite(currentUnite, sizeof(struct s_unite), 1, saveFile);
	}
	for(t_listeUnite temp = getListeUnite(joueurTwo); !estVide(temp); temp = temp->suiv) {
        t_unite currentUnite = temp->pData;
        fwrite(currentUnite, sizeof(struct s_unite), 1, saveFile);
	}

	fclose(saveFile);
}
