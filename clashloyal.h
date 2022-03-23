#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"


typedef struct s_jeuStats {
	t_player playerOne;
	t_player playerTwo;

} *t_jeuStats;

t_jeuStats convertToJeuStat(t_player playerOne, t_player playerTwo);

bool jeuEstTermine(t_jeuStats stats);

t_jeuStats phaseInitialisation();

void phaseCombat(t_jeuStats stats);

void phaseDeplacement(t_jeuStats stats);

void phaseCreation(t_jeuStats stats);

void phaseElixir(t_jeuStats stats);

void phaseAffichage(t_jeuStats stats);

void phaseFin(t_jeuStats stats);
