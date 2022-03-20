#ifndef MECANICS_H
#define MECANICS_H

#define LARGEURJEU 11
#define HAUTEURJEU 19

    //  Effectue l’attaque d’une unité sur une autre. (pas de vérification)
    void attaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  Vérifie si une attaque entre deux unités est possible (distance/type de cible)
    bool checkAttaque(t_unite uniteAttaquante, t_unite uniteAttaquee);

    //  Calcule la distance entre deux unités.
    float distance(t_unite uniteA, t_unite uniteB);

#endif
