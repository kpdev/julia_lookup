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

void CollideSwitch_Empty(ShapeSwitch *, ShapeSwitch *);
void CollideSwitch(ShapeSwitch *s1, ShapeSwitch *s2);


typedef struct ShapeSwitch3D ShapeSwitch3D;

ShapeSwitch3D* get_ShapeSwitch3D(int i);

void CollideSwitch3D(ShapeSwitch3D *s1, ShapeSwitch3D *s2, ShapeSwitch3D *s3);
void CollideSwitch3D_Empty(ShapeSwitch3D *, ShapeSwitch3D *, ShapeSwitch3D *);

//----------------------
struct Obj;

typedef enum {
    a_enum,
    b_enum,
    c_enum,
    d_enum,
    e_enum,
    f_enum,
    g_enum,
    h_enum,
    i_enum,
    j_enum
} ObjEnum;

void CollideSwitchX10_Empty(struct Obj *, struct Obj *);
void CollideSwitchX10(struct Obj *o1, struct Obj *o2);
struct Obj* get_obj(ObjEnum i);
