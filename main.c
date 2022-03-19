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
	t_player nabil = initPlayer("Nabil", true);
	t_player tom = initPlayer("Tom", false);

	t_plateauJeu plateau = allocPlateau(11,19);
	plateau = initPlateau(plateau);

	plateau = playerToPlateau(nabil, plateau);
	plateau = playerToPlateau(tom, plateau);

    affichePlateau(plateau);

	affichePile(nabil->listeUnite);
	affichePile(tom->listeUnite);

	return EXIT_SUCCESS;
}
