#include "proced-switch.h"
#include <stdlib.h>

typedef struct Obj {
    ObjEnum type;
} Obj;

#define OBJNAME(x) x ## Obj

#define OBJ(x) \
typedef struct OBJNAME(x) { Obj base; } OBJNAME(x);

OBJ(a)
OBJ(b)
OBJ(c)
OBJ(d)
OBJ(e)
OBJ(f)
OBJ(g)
OBJ(h)
OBJ(i)
OBJ(j)

#define VAR(A, B) A ## B ## _swx10

#define VARDEF(L1, L2) volatile int VAR(L1,L2) = 0;

VARDEF(x, y)

#define VARS(x) \
VARDEF(x, a) \
VARDEF(x, b) \
VARDEF(x, c) \
VARDEF(x, d) \
VARDEF(x, e) \
VARDEF(x, f) \
VARDEF(x, g) \
VARDEF(x, h) \
VARDEF(x, i) \
VARDEF(x, j)

#define HNAME(x,y) \
handler_ ## x ## _ ## y

#define HANDLER(x,y) \
void HNAME(x,y) (x ## Obj* o1, y ## Obj* o2){ VAR(x,y)++; };

VARS(a)
VARS(b)
VARS(c)
VARS(d)
VARS(e)
VARS(f)
VARS(g)
VARS(h)
VARS(i)
VARS(j)

// HANDLER(a,b)
#define INITIALIZERNAME(x) \
initializer_ ## x

#define INITIALIZER(x) \
void INITIALIZERNAME(x) (OBJNAME(x)* o) \
{ o->base.type = x ## _enum; }


#define HANDLERS(x) \
INITIALIZER(x) \
HANDLER(x, a) \
HANDLER(x, b) \
HANDLER(x, c) \
HANDLER(x, d) \
HANDLER(x, e) \
HANDLER(x, f) \
HANDLER(x, g) \
HANDLER(x, h) \
HANDLER(x, i) \
HANDLER(x, j)

HANDLERS(a)
HANDLERS(b)
HANDLERS(c)
HANDLERS(d)
HANDLERS(e)
HANDLERS(f)
HANDLERS(g)
HANDLERS(h)
HANDLERS(i)
HANDLERS(j)


#define CASE2(x,y) \
case x ## _enum: \
HNAME(y,x)((y ## Obj*) o1, (x ## Obj*) o2); \
break;

#define CASES2(x) \
CASE2(a,x) \
CASE2(b,x) \
CASE2(c,x) \
CASE2(d,x) \
CASE2(e,x) \
CASE2(f,x) \
CASE2(g,x) \
CASE2(h,x) \
CASE2(i,x) \
CASE2(j,x) 

#define INNER_SWITCH(x) \
case x ## _enum: \
switch (o2->type) { \
    CASES2(x) \
} \
break;

void CollideSwitchX10_Empty(struct Obj *, struct Obj *)
{}

void CollideSwitchX10(struct Obj *o1, struct Obj *o2)
{
    switch (o1->type) {
        INNER_SWITCH(a)
        INNER_SWITCH(b)
        INNER_SWITCH(c)
        INNER_SWITCH(d)
        INNER_SWITCH(e)
        INNER_SWITCH(f)
        INNER_SWITCH(g)
        INNER_SWITCH(h)
        INNER_SWITCH(i)
        INNER_SWITCH(j)
        default: exit(EXIT_FAILURE);
    }
}

#define G_VAR_NAME(x) \
g_var_ ## x

#define G_VAR(x) \
x ## Obj G_VAR_NAME(x);

G_VAR(a)
G_VAR(b)
G_VAR(c)
G_VAR(d)
G_VAR(e)
G_VAR(f)
G_VAR(g)
G_VAR(h)
G_VAR(i)
G_VAR(j)


#define INIT(x) \
INITIALIZERNAME(x)(&G_VAR_NAME(x));

#define RET(x) \
return (Obj*)(&G_VAR_NAME(x));

#define GET_CASE(x) \
case x ## _enum: INIT(x); RET(x);

struct Obj* get_obj(ObjEnum i)
{
    switch(i) {
        GET_CASE(a)
        GET_CASE(b)
        GET_CASE(c)
        GET_CASE(d)
        GET_CASE(e)
        GET_CASE(f)
        GET_CASE(g)
        GET_CASE(h)
        GET_CASE(i)
        GET_CASE(j)
    }
    exit(EXIT_FAILURE);
}
