#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "clashloyal.h"
#define TEMPS_PAR_TOUR 1000

//  BOIREAU Tom
//  DAKKOUNE Nabil

int main()
{

	t_jeuStats stats =  phaseInitialisation();

	clock_t current_time = clock();

	while (!jeuEstTermine(stats)) {
		unsigned long millis = (clock() -  current_time) * 1000 / CLOCKS_PER_SEC;
		if (millis>=TEMPS_PAR_TOUR) {

			phaseCombat(stats);
			phaseDeplacement(stats);
			phaseCreation(stats);
			phaseElixir(stats);
			phaseAffichage(stats);

			current_time = clock();
		}
	}

	phaseFin(stats);

	return EXIT_SUCCESS;
}
