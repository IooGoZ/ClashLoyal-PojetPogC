#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "affichage.h"
#include "unite.h"

char uniteToChar(t_uniteDuJeu typeUnite) {
	char uniteChar[] = {'T', 'R', 'A', 'C', 'D', 'G'};
	return uniteChar[typeUnite];
}
