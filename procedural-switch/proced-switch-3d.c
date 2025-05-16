#include <stdio.h>
#include <stdlib.h>
#include "proced-switch.h"

typedef enum { CIRCLE, RECTANGLE, TRIANGLE } ShapeSwitch3DType;

typedef struct ShapeSwitch3D {
    ShapeSwitch3DType type;
} ShapeSwitch3D;

typedef struct {
    ShapeSwitch3D base;
    double radius;
} Circle;

typedef struct {
    ShapeSwitch3D base;
    double width;
    double height;
} Rectangle;

typedef struct {
    ShapeSwitch3D base;
    double a;
    double b;
    double c;
} Triangle;


volatile int
    ccc = 0,
    ccr = 0,
    cct = 0,
    crc = 0,
    crr = 0,
    crt = 0,
    ctc = 0,
    ctr = 0,
    ctt = 0,
    rcc = 0,
    rcr = 0,
    rct = 0,
    rrc = 0,
    rrr = 0,
    rrt = 0,
    rtc = 0,
    rtr = 0,
    rtt = 0,
    tcc = 0,
    tcr = 0,
    tct = 0,
    trc = 0,
    trr = 0,
    trt = 0,
    ttc = 0,
    ttr = 0,
    ttt = 0;

// Handler implementations
void handle_ccc(Circle *c1, Circle *c2, Circle *c3) {
    ccc++;
}

void handle_ccr(Circle *c1, Circle *c2, Rectangle *r3) {
    ccr++;
}

void handle_cct(Circle *c1, Circle *c2, Triangle* s3) {
    cct++;
}

void handle_crc(Circle *c1, Rectangle *r2, Circle *c3) {
    crc++;
}

void handle_crr(Circle *c1, Rectangle *r2, Rectangle *r3) {
    crr++;
}

void handle_crt(Circle *c1, Rectangle *r2, Triangle *r3) {
    crt++;
}

void handle_ctc(Circle *c1, Triangle *r2, Circle *c3) {
    ctc++;
}

void handle_ctr(Circle *c1, Triangle *r2, Rectangle *r3) {
    ctr++;
}

void handle_ctt(Circle *c1, Triangle *r2, Triangle *r3) {
    ctt++;
}

void handle_rcc(Rectangle *r1, Circle *c2, Circle *c3) {
    rcc++;
}

void handle_rcr(Rectangle *r1, Circle *c2, Rectangle *r3) {
    rcr++;
}

void handle_rct(Rectangle *r1, Circle *c2, Triangle *r3) {
    rct++;
}

void handle_rrc(Rectangle *r1, Rectangle *r2, Circle *c3) {
    rrc++;
}

void handle_rrr(Rectangle *r1, Rectangle *r2, Rectangle *r3) {
    rrr++;
}

void handle_rrt(Rectangle *r1, Rectangle *r2, Triangle *r3) {
    rrt++;
}


void handle_rtc(Rectangle *r1, Triangle *r2, Circle *c3) {
    rtc++;
}

void handle_rtr(Rectangle *r1, Triangle *r2, Rectangle *r3) {
    rtr++;
}

void handle_rtt(Rectangle *r1, Triangle *r2, Triangle *r3) {
    rtt++;
}


void handle_tcc(Triangle *r1, Circle *c2, Circle *c3) {
    tcc++;
}

void handle_tcr(Triangle *r1, Circle *c2, Rectangle *r3) {
    tcr++;
}

void handle_tct(Triangle *r1, Circle *c2, Triangle *r3) {
    tct++;
}

void handle_trc(Triangle *r1, Rectangle *r2, Circle *c3) {
    trc++;
}

void handle_trr(Triangle *r1, Rectangle *r2, Rectangle *r3) {
    trr++;
}

void handle_trt(Triangle *r1, Rectangle *r2, Triangle *r3) {
    trt++;
}

void handle_ttc(Triangle *r1, Triangle *c2, Circle *r3) {
    ttc++;
}

void handle_ttr(Triangle *r1, Triangle *r2, Rectangle *c3) {
    ttr++;
}

void handle_ttt(Triangle *r1, Triangle *r2, Triangle *r3) {
    ttt++;
}

void CollideSwitch3D_Empty(ShapeSwitch3D *, ShapeSwitch3D *, ShapeSwitch3D *)
{}

void CollideSwitch3D(ShapeSwitch3D *s1, ShapeSwitch3D *s2, ShapeSwitch3D *s3) {
    // First level switch - s1 type
    switch(s1->type) {
        case CIRCLE: {
            Circle *c1 = (Circle *)s1;
            // Second level switch - s2 type
            switch(s2->type) {
                case CIRCLE: {
                    Circle *c2 = (Circle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_ccc(c1, c2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_ccr(c1, c2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_cct(c1, c2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case RECTANGLE: {
                    Rectangle *r2 = (Rectangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_crc(c1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_crr(c1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_crt(c1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case TRIANGLE: {
                    Triangle *r2 = (Triangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_ctc(c1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_ctr(c1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_ctt(c1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
            }
            break;
        }
        case RECTANGLE: {
            Rectangle *r1 = (Rectangle *)s1;
            // Second level switch - s2 type
            switch(s2->type) {
                case CIRCLE: {
                    Circle *c2 = (Circle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_rcc(r1, c2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_rcr(r1, c2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_rct(r1, c2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case RECTANGLE: {
                    Rectangle *r2 = (Rectangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_rrc(r1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_rrr(r1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_rrt(r1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case TRIANGLE: {
                    Triangle *r2 = (Triangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_rtc(r1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_rtr(r1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_rtt(r1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
            }
            break;
        }
        //
        case TRIANGLE: {
            Triangle *r1 = (Triangle *)s1;
            // Second level switch - s2 type
            switch(s2->type) {
                case CIRCLE: {
                    Circle *c2 = (Circle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_tcc(r1, c2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_tcr(r1, c2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_tct(r1, c2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case RECTANGLE: {
                    Rectangle *r2 = (Rectangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_trc(r1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_trr(r1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_trt(r1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
                case TRIANGLE: {
                    Triangle *r2 = (Triangle *)s2;
                    // Third level switch - s3 type
                    switch(s3->type) {
                        case CIRCLE:
                            handle_ttc(r1, r2, (Circle *)s3);
                            break;
                        case RECTANGLE:
                            handle_ttr(r1, r2, (Rectangle *)s3);
                            break;
                        case TRIANGLE:
                            handle_ttt(r1, r2, (Triangle *)s3);
                            break;
                    }
                    break;
                }
            }
            break;
        }
    }
}


// Initialization functions
void init_circle_3d(Circle *c, double radius) {
    c->base.type = CIRCLE;
    c->radius = radius;
}

void init_rectangle_3d(Rectangle *r, double width, double height) {
    r->base.type = RECTANGLE;
    r->width = width;
    r->height = height;
}

void init_triangle_3d(Triangle *r, double a, double b, double c) {
    r->base.type = TRIANGLE;
    r->a = a;
    r->b = b;
    r->c = c;
}

Circle g_c3d;
Rectangle g_r3d;
Triangle g_t3d;

ShapeSwitch3D* get_ShapeSwitch3D(int i)
{
    if (i == 1) {
        init_circle_3d(&g_c3d, 1);
        return (ShapeSwitch3D*)&g_c3d;
    }
    if (i == 2) {
        init_rectangle_3d(&g_r3d, 1, 1);
        return (ShapeSwitch3D*)&g_r3d;
    }
    if (i == 3) {
        init_triangle_3d(&g_t3d, 1, 1, 1);
        return (ShapeSwitch3D*)&g_t3d;
    }
    exit(EXIT_FAILURE);

}
