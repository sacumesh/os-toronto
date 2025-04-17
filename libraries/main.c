#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(void) {

    struct Point *p = point_create(1, 2);
    
    // library
    printf("point(x, y) = %d, %d (using library)\n", point_get_x(p), point_get_y(p));

    // executalbe
    printf("point(x, y) = %d, %d (using library)\n", p -> x, p -> y);

    return 0;
}