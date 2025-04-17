#include <stdlib.h>
#include "point.h"


struct Point* point_create(int x, int y) {

    struct Point *p = (struct Point*) malloc(sizeof(struct Point));

    if (!p) return 0;

    p -> x = x;
    p -> y = y;

    return (struct Point*) p;
}


int point_get_x(struct Point *p) {

    return p -> x;
}

int point_get_y(struct Point *p) {
    return p -> y;
}

void point_destroy(struct Point *p) {
    free(p);
}