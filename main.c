#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"

//  BOIREAU Tom
//  DAKKOUNE Nabil

int main()
{
    srand (time (NULL));


	t_player nabil = initPlayer("Nabil", true);
	t_player tom = initPlayer("Tom", false);

    addElixir(nabil, 10);
    addElixir(tom, 10);

    t_unite unite_nabil = acheteUnite(nabil);

    if (unite_nabil != NULL) {
        positionneUnite(unite_nabil, 3, 5);
    } else printf("Unité null");



	generateAndPrintPlateau(nabil, tom);

	return EXIT_SUCCESS;
}


void generateAndPrintPlateau(t_player player1, t_player player2) {
    t_plateauJeu plateau = allocPlateau(11,19);
	plateau = initPlateau(plateau);

	plateau = playerToPlateau(player1, plateau);
	plateau = playerToPlateau(player2, plateau);

    affichePlateau(plateau);
}
