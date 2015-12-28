#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "simulation.h"

double wave_propagation(double p, double t, double v) {

    /* Primeira parte da formula */
    double p1 = (p - v * t);

    /*Segunda parte da formula */
    double p2 = pow(M_E, (-1 * (pow(p1, 2))));

    /* Terceira parte da formula */
    double p3 = pow(M_E, ((-1 * t) / 10));

    return p1 * p2 * p3;

}
