#include "mecanics.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//  Effectue l’attaque d’une unité sur une autre. (pas de vérification)
void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    setPV(uniteAttaquee, minusPV(uniteAttaquee, getDegats(uniteAttaquante)));
}

    //  Calcule la distance entre deux unités.
float distance(t_unite uniteA, t_unite uniteB) {
    return sqrt(pow(getX(uniteA) - getX(uniteB), 2) + pow(getY(uniteA) - getY(uniteB), 2));
}

//  Vérifie si une attaque entre deux unités est possible (distance/type de cible)
bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee) {
    if(getPortee(uniteAttaquante) < distance(uniteAttaquante,uniteAttaquee)) {
        return false
    }


}
