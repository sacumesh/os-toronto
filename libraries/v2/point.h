#ifndef POINT_H
#define POINT_H

struct Point {
    int y;
    int x;
};

struct Point* point_create(int x, int y);
int point_get_x(struct Point *p);
int point_get_y(struct Point *p);
void point_destroy(struct Point *p);

#endif