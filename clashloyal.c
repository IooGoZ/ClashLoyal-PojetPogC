#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clashloyal.h"
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"
#include "utils.h"
#include "SDL.h"
#include "maSDL.h"

//  Convertis deux joueurs en un « t_jeuStats ».
t_jeuStats convertToJeuStat(t_player playerOne, t_player playerTwo) {
	t_jeuStats res = (t_jeuStats) malloc(sizeof(struct s_jeuStats));
	res->playerOne = playerOne;
	res->playerTwo = playerTwo;
	return res;
}

//  Vérifie si le jeu est terminé.
bool jeuEstTermine(t_jeuStats stats) {
	return (tourRoiDetruite(stats->playerOne) || tourRoiDetruite(stats->playerTwo));
}

//  Initialise les variables nécessaires au fonctionnement du jeu.
t_jeuStats phaseInitialisation() {
	srand(time(NULL));

	t_player nabil = initPlayer("Nabil", true);
	t_player tom = initPlayer("Tom", false);

	return convertToJeuStat(nabil, tom);

}

//  Décris l’ensemble des actions utiles lors de la phase de combat des unités.
void phaseCombat(t_jeuStats stats) {
    t_tabUnite concatTab = concatToSortedTab(stats->playerOne->listeUnite, stats->playerTwo->listeUnite);
    int tailleTab = concatTab->taille;

    for (int i = 0; i < tailleTab; i++) {
        t_unite current_unite = concatTab->tab[i];
        t_listeUnite uniteAdverse;
        t_player playerAttaquee;
        if (!getPlayerUnite(current_unite)) {
            uniteAdverse = stats->playerOne->listeUnite;
            playerAttaquee = stats->playerOne;
        } else {
            uniteAdverse = stats->playerTwo->listeUnite;
            playerAttaquee = stats->playerTwo;
        }
        t_listeUnite unitesAPortee = quiEstAPortee(current_unite,uniteAdverse, tourClassiqueDetruite(playerAttaquee));
        if (!estVide(unitesAPortee)) {
            attaque(current_unite, unitesAPortee->pData, playerAttaquee);
        }

        concatTab = concatToSortedTab(stats->playerOne->listeUnite, stats->playerTwo->listeUnite);
        tailleTab = concatTab->taille;
    }

    for (int i = 0; i < concatTab->taille; i++) {
        t_unite current_unite = concatTab->tab[i];
        setAttaque(current_unite, true);
    }
}

//  Décris l’ensemble des actions utiles lors de la phase de déplacement des unités.
void phaseDeplacement(t_jeuStats stats) {
    t_tabUnite concatTab = concatToTab(stats->playerOne->listeUnite, stats->playerTwo->listeUnite);

    for (int i = 0; i < concatTab->taille; i++) {

        t_unite current_unite = concatTab->tab[i];

        if (!(getType(current_unite) == tourRoi || getType(current_unite) == tour)) {

            for (float j = 0; j < getVitesseDeplacement(current_unite); j++) {
                int* pos = getNextPosition(current_unite);
                if (!caseOccupee(stats->playerOne->listeUnite, stats->playerTwo->listeUnite, pos[0], pos[1])) {
                    positionneUnite(current_unite, pos[0], pos[1]);
                }
                free(pos);
            }
        }
    }
}

//  Décris l’ensemble des actions utiles lors de la phase d’achat de nouvelles unités.
void phaseCreation(t_jeuStats stats) {
    t_unite uniteOne = acheteUnite(stats->playerOne);
    if (uniteOne != NULL)
        positionneRandomUnite(stats->playerOne->listeUnite, stats->playerTwo->listeUnite, uniteOne, stats->playerOne->playerOnTop);

    t_unite uniteTwo = acheteUnite(stats->playerTwo);

    if (uniteTwo != NULL)
        positionneRandomUnite(stats->playerOne->listeUnite, stats->playerTwo->listeUnite, uniteTwo, stats->playerTwo->playerOnTop);
}

//  Décris l’ensemble des actions utiles lors de la phase de don d’élixir aux joueurs.
void phaseElixir(t_jeuStats stats) {
    int amount = getRandomElixirAmount();
    if (getElixir(stats->playerOne) + amount <= 5)
        addElixir(stats->playerOne, amount);
    amount = getRandomElixirAmount();
    if (getElixir(stats->playerTwo) + amount <= 5)
        addElixir(stats->playerTwo, amount);
}

//  Décris l’ensemble des actions utiles lors de la phase d’affichage du jeu.
void phaseAffichage(t_jeuStats stats, SDL_Surface** TabSprite, SDL_Surface* pWinSurf, SDL_Window* pWindow) {
    t_plateauJeu plateau = allocPlateau(11,19);
    plateau = initPlateau(plateau);

    plateau = playerToPlateau(stats->playerTwo, plateau);
    plateau = playerToPlateau(stats->playerOne, plateau);


    efface_fenetre(pWinSurf);
    prepareAllSpriteDuJeu(plateau,TabSprite,pWinSurf);
    maj_fenetre(pWindow);

	printf("Elixir de %s : %d", getNom(stats->playerOne), getElixir(stats->playerOne));
	printf("\nElixir de %s : %d\n\n\n", getNom(stats->playerTwo), getElixir(stats->playerTwo));
}

//  Décris l’ensemble des actions utiles lorsque le jeu se termine.
void phaseFin(t_jeuStats stats) {
    char * txt = (char*) malloc(sizeof(char)*100);
    if (!tourRoiDetruite(stats->playerOne)) {
        strcpy(txt, getNom(stats->playerOne));
        printf("%s a gagné la partie !", getNom(stats->playerOne));
    } else {
        strcpy(txt, getNom(stats->playerTwo));
        printf("%s a gagné la partie !", getNom(stats->playerTwo));
    }
    strcat(txt, " a gagné la partie !");
    message("Partie terminée", txt);
}
