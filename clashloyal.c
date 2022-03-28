#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "clashloyal.h"
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"
#include "utils.h"

t_jeuStats convertToJeuStat(t_player playerOne, t_player playerTwo) {
	t_jeuStats res = (t_jeuStats) malloc(sizeof(struct s_jeuStats));
	res->playerOne = playerOne;
	res->playerTwo = playerTwo;
	return res;
}

bool jeuEstTermine(t_jeuStats stats) {
	return (tourRoiDetruite(stats->playerOne) || tourRoiDetruite(stats->playerTwo));
}

t_jeuStats phaseInitialisation() {
	srand(time(NULL));

	t_player nabil = initPlayer("Nabil", true);
	t_player tom = initPlayer("Tom", false);

	return convertToJeuStat(nabil, tom);

}

void phaseCombat(t_jeuStats stats) {
    t_tabUnite concatTab = concatToSortedTab(stats->playerOne->listeUnite, stats->playerTwo->listeUnite);

    for (int i = 0; i < concatTab->taille; i++) {
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
    }

    for (int i = 0; i < concatTab->taille; i++) {
        t_unite current_unite = concatTab->tab[i];
        setAttaque(current_unite, true);
    }
}

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

void phaseCreation(t_jeuStats stats) {
    t_unite uniteOne = acheteUnite(stats->playerOne);
    if (uniteOne != NULL)
        positionneRandomUnite(stats->playerOne->listeUnite, stats->playerTwo->listeUnite, uniteOne, stats->playerOne->playerOnTop);

    t_unite uniteTwo = acheteUnite(stats->playerTwo);

    if (uniteTwo != NULL)
        positionneRandomUnite(stats->playerOne->listeUnite, stats->playerTwo->listeUnite, uniteTwo, stats->playerTwo->playerOnTop);
}

void phaseElixir(t_jeuStats stats) {
    addElixir(stats->playerOne, getRandomElixirAmount());
    addElixir(stats->playerTwo, getRandomElixirAmount());
}

void phaseAffichage(t_jeuStats stats) {

	t_plateauJeu plateau = allocPlateau(11,19);
	plateau = initPlateau(plateau);

	plateau = playerToPlateau(stats->playerTwo, plateau);
	plateau = playerToPlateau(stats->playerOne, plateau);



	affichePlateau(plateau);

	printf("Elixir de %s : %d", getNom(stats->playerOne), getElixir(stats->playerOne));
	printf("\nElixir de %s : %d\n\n\n", getNom(stats->playerTwo), getElixir(stats->playerTwo));
}

void phaseFin(t_jeuStats stats) {
    if (!tourRoiDetruite(stats->playerOne)) {
        printf("%s a gagné la partie !", getNom(stats->playerOne));
    } else {
        printf("%s a gagné la partie !", getNom(stats->playerTwo));
    }
}
