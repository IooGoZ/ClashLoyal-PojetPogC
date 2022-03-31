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
void printLisibleConstantesTab(FILE* saveFile) {
    //Tour classique
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 1, 0, 500, 1.0, 100, 3, 0, 0);
    //Tour du roi
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 1, 0, 800, 1.2, 120, 4, 0, 0);
    //Chevalier
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 0, 0, 400, 1.5, 250, 1, 2.0, 4);
    //Archer
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 1, 0, 80, 0.7, 120, 3, 1.0, 2);
    //Dragon
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 1, 2, 200, 1.1, 70, 2, 2.0, 3);
    //Gargouille
    fprintf(saveFile, "%d %d %d %f %d %d %f %d\n", 1, 2, 80, 0.6, 90, 1, 3.0, 1);
}

void saveLisible(t_jeuStats stats, char* path) {
    t_player joueurOne = stats->playerOne;
    t_player joueurTwo = stats->playerTwo;

    FILE* saveFile = fopen(path, "w");

    printLisibleConstantesTab(saveFile);

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
