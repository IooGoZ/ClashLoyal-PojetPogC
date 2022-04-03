#ifndef CLASHLOYAL_H
#define CLASHLOYAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unite.h"
#include "joueur.h"
#include "mecanics.h"
#include "affichage.h"
#include "SDL.h"
#include "maSDL.h"

#define LARGEURJEU 11
#define HAUTEURJEU 19


typedef struct s_jeuStats {
	t_player playerOne;
	t_player playerTwo;

} *t_jeuStats;

//  Convertis deux joueurs en un « t_jeuStats ».
t_jeuStats convertToJeuStat(t_player playerOne, t_player playerTwo);

//  Vérifie si le jeu est terminé.
bool jeuEstTermine(t_jeuStats stats);

//  Initialise les variables nécessaires au fonctionnement du jeu.
t_jeuStats phaseInitialisation();

//  Décris l’ensemble des actions utiles lors de la phase de combat des unités.
void phaseCombat(t_jeuStats stats);

//  Décris l’ensemble des actions utiles lors de la phase de déplacement des unités.
void phaseDeplacement(t_jeuStats stats);

//  Décris l’ensemble des actions utiles lors de la phase d’achat de nouvelles unités.
void phaseCreation(t_jeuStats stats);

//  Décris l’ensemble des actions utiles lors de la phase de don d’élixir aux joueurs.
void phaseElixir(t_jeuStats stats);

//  Décris l’ensemble des actions utiles lors de la phase d’affichage du jeu.
void phaseAffichage(t_jeuStats stats, SDL_Surface** TabSprite, SDL_Surface* pWinSurf, SDL_Window* pWindow);

//  Décris l’ensemble des actions utiles lorsque le jeu se termine.
void phaseFin(t_jeuStats stats);

#endif
