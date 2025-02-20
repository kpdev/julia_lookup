#include "proced-switch.h"
#include <stdlib.h>

typedef struct CircleSwitch CircleSwitch;
typedef struct RectangleSwitch RectangleSwitch;


// Derived shapes
struct CircleSwitch {
    ShapeSwitch base;
    double radius;
};

struct RectangleSwitch {
    ShapeSwitch base;
    double width;
    double height;
};

volatile int cc_sw = 0, cr_sw = 0, rc_sw = 0, rr_sw = 0;

// Collision handlers for specific combinations
void handle_circle_circle(CircleSwitch *a, CircleSwitch *b) {
    cc_sw++;
}

void handle_circle_rectangle(CircleSwitch *c, RectangleSwitch *r) {
    cr_sw++;
}

void handle_rectangle_circle(RectangleSwitch *r, CircleSwitch *c) {
    rc_sw++;
}

void handle_rectangle_rectangle(RectangleSwitch *a, RectangleSwitch *b) {
    rr_sw++;
}

// Main dispatch function
void CollideSwitch(ShapeSwitch *s1, ShapeSwitch *s2) {
    switch(s1->type) {
        case CIRCLE_SW: {
            CircleSwitch *c1 = (CircleSwitch *)s1;
            switch(s2->type) {
                case CIRCLE_SW:
                    handle_circle_circle(c1, (CircleSwitch *)s2);
                    break;
                case RECTANGLE_SW:
                    handle_circle_rectangle(c1, (RectangleSwitch *)s2);
                    break;
            }
            break;
        }
        
        case RECTANGLE_SW: {
            RectangleSwitch *r1 = (RectangleSwitch *)s1;
            switch(s2->type) {
                case CIRCLE_SW:
                    handle_rectangle_circle(r1, (CircleSwitch *)s2);
                    break;
                case RECTANGLE_SW:
                    handle_rectangle_rectangle(r1, (RectangleSwitch *)s2);
                    break;
            }
            break;
        }
    }
}

// Initialization functions
void init_circle_switch(CircleSwitch *c, double radius) {
    c->base.type = CIRCLE_SW;
    c->radius = radius;
}

void init_rectangle_switch(RectangleSwitch *r, double width, double height) {
    r->base.type = RECTANGLE_SW;
    r->width = width;
    r->height = height;
}


CircleSwitch g_circle_sw;
RectangleSwitch g_rectangle_sw;

struct ShapeSwitch* get_shape_switch(int i)
{
    if (i == 1) {
        init_circle_switch(&g_circle_sw, 5.0);
        return (ShapeSwitch*)&g_circle_sw;
    }
    if (i == 2) {
        init_rectangle_switch(&g_rectangle_sw, 4.0, 5.0);
        return (ShapeSwitch*)&g_rectangle_sw;
    }

    exit(EXIT_FAILURE);
}
