#include <stdio.h>
#include <math.h>

#include "util.h"

/* Distancia euclidiana */
double distance (double x1, double x2, double y1, double y2) {
    double x = pow((x2 - x1), 2);
    double y = pow((y2 - y1), 2);
    return sqrt(x + y);
}
