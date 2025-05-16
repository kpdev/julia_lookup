#pragma once


// Forward declarations
typedef struct Shape Shape;
typedef struct Circle Circle;
typedef struct Rectangle Rectangle;

// Function pointer types for collision handling
typedef void (*CollideFunc)(Shape *self, Shape *other);
typedef void (*CollideWithCircleFunc)(Shape *self, Circle *circle);
typedef void (*CollideWithRectangleFunc)(Shape *self, Rectangle *rectangle);

// Base Shape structure
struct Shape {
    enum { CIRCLE, RECTANGLE } type;
    CollideFunc collide;
    CollideWithCircleFunc collide_with_circle;
    CollideWithRectangleFunc collide_with_rectangle;
};

struct Shape* get_shape(int i);

void collide_empty(Shape*, Shape*);
