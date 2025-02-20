#include "proced.h"
#include <stdlib.h>


volatile int cc = 0, cr = 0, rc = 0, rr = 0;

// Circle structure
struct Circle {
    Shape shape;
    double radius;
};

// Rectangle structure
struct Rectangle {
    Shape shape;
    double width;
    double height;
};

// Collision functions for Circle
void circle_collide(Shape *self, Shape *other) {
    other->collide_with_circle(other, (Circle *)self);
}

void circle_collide_with_circle(Shape *self, Circle *other) {
    cc++;
}

void circle_collide_with_rectangle(Shape *self, Rectangle *other) {
    cr++;
}

// Collision functions for Rectangle
void rectangle_collide(Shape *self, Shape *other) {
    other->collide_with_rectangle(other, (Rectangle *)self);
}

void rectangle_collide_with_circle(Shape *self, Circle *other) {
    rc++;
}

void rectangle_collide_with_rectangle(Shape *self, Rectangle *other) {
    rr++;
}

// Initialization functions
void init_circle(Circle *circle, double radius) {
    circle->shape.type = CIRCLE;
    circle->shape.collide = circle_collide;
    circle->shape.collide_with_circle = circle_collide_with_circle;
    circle->shape.collide_with_rectangle = circle_collide_with_rectangle;
    circle->radius = radius;
}

void init_rectangle(Rectangle *rectangle, double width, double height) {
    rectangle->shape.type = RECTANGLE;
    rectangle->shape.collide = rectangle_collide;
    rectangle->shape.collide_with_circle = rectangle_collide_with_circle;
    rectangle->shape.collide_with_rectangle = rectangle_collide_with_rectangle;
    rectangle->width = width;
    rectangle->height = height;
}


Circle g_circle;
Rectangle g_rectangle;

struct Shape* get_shape(int i)
{
    if (i == 1) {
        init_circle(&g_circle, 5.0);
        return (Shape*)&g_circle;
    }
    if (i == 2) {
        init_rectangle(&g_rectangle, 4.0, 5.0);
        return (Shape*)&g_rectangle;
    }

    exit(EXIT_FAILURE);
}

