#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"

//  BOIREAU Tom
//  DAKKOUNE Nabil

int main()
{
	t_listeUnite p = creerPileVide();
	p = empiler(p, getNewUnite(tourRoi));
	p = empiler(p, getNewUnite(tour));
	p = empiler(p, getNewUnite(chevalier));
	p = empiler(p, getNewUnite(archer));
	affichePile(p);

	return EXIT_SUCCESS;
}
