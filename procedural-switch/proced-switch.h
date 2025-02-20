#pragma once

// Type tags for different shapes
typedef enum {
    CIRCLE_SW,
    RECTANGLE_SW
} ShapeTypeSwitch;

// Base shape structure
struct ShapeSwitch {
    ShapeTypeSwitch type;
};

typedef struct ShapeSwitch ShapeSwitch;

ShapeSwitch* get_shape_switch(int i);

void CollideSwitch(ShapeSwitch *s1, ShapeSwitch *s2);
