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

//  Convertis deux joueurs en un � t_jeuStats �.
t_jeuStats convertToJeuStat(t_player playerOne, t_player playerTwo);

//  V�rifie si le jeu est termin�.
bool jeuEstTermine(t_jeuStats stats);

//  Initialise les variables n�cessaires au fonctionnement du jeu.
t_jeuStats phaseInitialisation();

//  D�cris l�ensemble des actions utiles lors de la phase de combat des unit�s.
void phaseCombat(t_jeuStats stats);

//  D�cris l�ensemble des actions utiles lors de la phase de d�placement des unit�s.
void phaseDeplacement(t_jeuStats stats);

//  D�cris l�ensemble des actions utiles lors de la phase d�achat de nouvelles unit�s.
void phaseCreation(t_jeuStats stats);

//  D�cris l�ensemble des actions utiles lors de la phase de don d��lixir aux joueurs.
void phaseElixir(t_jeuStats stats);

//  D�cris l�ensemble des actions utiles lors de la phase d�affichage du jeu.
void phaseAffichage(t_jeuStats stats, SDL_Surface** TabSprite, SDL_Surface* pWinSurf, SDL_Window* pWindow);

//  D�cris l�ensemble des actions utiles lorsque le jeu se termine.
void phaseFin(t_jeuStats stats);

#endif
