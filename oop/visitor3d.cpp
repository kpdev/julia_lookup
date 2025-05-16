#include "visitor.h"

void collide_empty(Shape3D*, Shape3D*, Shape3D*)
{}

volatile int 
    ccc_3d = 0,
    ccr_3d = 0,
    cct_3d = 0,
    crr_3d = 0,
    crt_3d = 0,
    crc_3d = 0,
    ctr_3d = 0,
    ctt_3d = 0,
    ctc_3d = 0,
    rrr_3d = 0,
    rrt_3d = 0,
    rrc_3d = 0,
    rtr_3d = 0,
    rtt_3d = 0,
    rtc_3d = 0,
    rcr_3d = 0,
    rct_3d = 0,
    rcc_3d = 0,
    tcc_3d = 0,
    tcr_3d = 0,
    tct_3d = 0,
    trc_3d = 0,
    trr_3d = 0,
    trt_3d = 0,
    ttc_3d = 0,
    ttr_3d = 0,
    ttt_3d = 0;

class Circle3D : public Shape3D {
public:
    // Invoked as s1
    virtual void collide(Shape3D* s2, Shape3D* s3) {
        s2->collide(*this, s3);
    }

    // Invoked as s2
    virtual void collide(Rectangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Triangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Circle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    // Invoked as s3. Here all types are already known
    virtual void collide(Rectangle3D& s1, Rectangle3D& s2) {
        rrc_3d++;
    }

    virtual void collide(Rectangle3D& s1, Triangle3D& s2) {
        rtc_3d++;
    }

    virtual void collide(Rectangle3D& s1, Circle3D& s2) {
        rcc_3d++;
    }

    virtual void collide(Triangle3D& s1, Rectangle3D& s2) {
        trc_3d++;
    }

    virtual void collide(Triangle3D& s1, Triangle3D& s2) {
        ttc_3d++;
    }

    virtual void collide(Triangle3D& s1, Circle3D& s2) {
        tcc_3d++;
    }

    virtual void collide(Circle3D& s1, Rectangle3D& s2) {
        crc_3d++;
    }

    virtual void collide(Circle3D& s1, Triangle3D& s2) {
        ctc_3d++;
    }

    virtual void collide(Circle3D& s1, Circle3D& s2) {
        ccc_3d++;
    }
};


class Rectangle3D : public Shape3D {
public:
    // Invoked as s1
    virtual void collide(Shape3D* s2, Shape3D* s3) {
        s2->collide(*this, s3);
    }

    // Invoked as s2
    virtual void collide(Rectangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Triangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Circle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    // Invoked as s3. Here all types are already known
    virtual void collide(Rectangle3D& s1, Rectangle3D& s2) {
        rrr_3d++;
    }

    virtual void collide(Rectangle3D& s1, Triangle3D& s2) {
        rtr_3d++;
    }

    virtual void collide(Rectangle3D& s1, Circle3D& s2) {
        rcr_3d++;
    }

    virtual void collide(Triangle3D& s1, Rectangle3D& s2) {
        trr_3d++;
    }

    virtual void collide(Triangle3D& s1, Triangle3D& s2) {
        ttr_3d++;
    }

    virtual void collide(Triangle3D& s1, Circle3D& s2) {
        tcr_3d++;
    }

    virtual void collide(Circle3D& s1, Rectangle3D& s2) {
        crr_3d++;
    }

    virtual void collide(Circle3D& s1, Triangle3D& s2) {
        ctr_3d++;
    }

    virtual void collide(Circle3D& s1, Circle3D& s2) {
        ccr_3d++;
    }
};


class Triangle3D : public Shape3D {
public:
    // Invoked as s1
    virtual void collide(Shape3D* s2, Shape3D* s3) {
        s2->collide(*this, s3);
    }

    // Invoked as s2
    virtual void collide(Rectangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Triangle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    virtual void collide(Circle3D& s1, Shape3D* s3) {
        s3->collide(s1, *this);
    }

    // Invoked as s3. Here all types are already known
    virtual void collide(Rectangle3D& s1, Rectangle3D& s2) {
        rrt_3d++;
    }

    virtual void collide(Rectangle3D& s1, Triangle3D& s2) {
        rtt_3d++;
    }

    virtual void collide(Rectangle3D& s1, Circle3D& s2) {
        rct_3d++;
    }

    virtual void collide(Triangle3D& s1, Rectangle3D& s2) {
        trt_3d++;
    }

    virtual void collide(Triangle3D& s1, Triangle3D& s2) {
        ttt_3d++;
    }

    virtual void collide(Triangle3D& s1, Circle3D& s2) {
        tct_3d++;
    }

    virtual void collide(Circle3D& s1, Rectangle3D& s2) {
        crt_3d++;
    }

    virtual void collide(Circle3D& s1, Triangle3D& s2) {
        ctt_3d++;
    }

    virtual void collide(Circle3D& s1, Circle3D& s2) {
        cct_3d++;
    }
};

Circle3D g_c;
Rectangle3D g_r;
Triangle3D g_t;

Shape3D* get_shape3d(int i) {
    if (i == 1)
        return &g_c;
    if (i == 2)
        return &g_r;
    if (i == 3)
        return &g_t;
    exit(EXIT_FAILURE);
}
