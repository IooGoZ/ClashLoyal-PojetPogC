#ifndef MECANICS_H
#define MECANICS_H

#define LARGEURJEU 11
#define HAUTEURJEU 19

    //  Effectue l�attaque d�une unit� sur une autre. (pas de v�rification)
    void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  V�rifie si une attaque entre deux unit�s est possible (distance/type de cible)
    bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  Calcule la distance entre deux unit�s.
    float distance(t_unite uniteA, t_unite uniteB);

#endif
