#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "clashloyal.h"
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"

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

}

void phaseDeplacement(t_jeuStats stats) {

}

void phaseCreation(t_jeuStats stats) {
    t_unite uniteOne = acheteUnite(stats->playerOne);
    t_unite uniteTwo = acheteUnite(stats->playerTwo);

}

void phaseElixir(t_jeuStats stats) {
    addElixir(stats->playerOne, getRandomElixirAmount());
    addElixir(stats->playerTwo, getRandomElixirAmount());
}

void phaseAffichage(t_jeuStats stats) {
	t_plateauJeu plateau = allocPlateau(11,19);
	plateau = initPlateau(plateau);

	plateau = playerToPlateau(stats->playerOne, plateau);
	plateau = playerToPlateau(stats->playerTwo, plateau);

	affichePlateau(plateau);
	printf("\nElixir de %s : %d", getNom(stats->playerOne), getElixir(stats->playerOne));
	printf("\nElixir de %s : %d\n\n\n", getNom(stats->playerTwo), getElixir(stats->playerTwo));
}

void phaseFin(t_jeuStats stats) {

}
