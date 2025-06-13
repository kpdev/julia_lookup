volatile int ccc_3d = 0;
volatile int ccr_3d = 0;
volatile int cct_3d = 0;
volatile int crr_3d = 0;
volatile int crt_3d = 0;
volatile int crc_3d = 0;
volatile int ctr_3d = 0;
volatile int ctt_3d = 0;
volatile int ctc_3d = 0;
volatile int rrr_3d = 0;
volatile int rrt_3d = 0;
volatile int rrc_3d = 0;
volatile int rtr_3d = 0;
volatile int rtt_3d = 0;
volatile int rtc_3d = 0;
volatile int rcr_3d = 0;
volatile int rct_3d = 0;
volatile int rcc_3d = 0;
volatile int tcc_3d = 0;
volatile int tcr_3d = 0;
volatile int tct_3d = 0;
volatile int trc_3d = 0;
volatile int trr_3d = 0;
volatile int trt_3d = 0;
volatile int ttc_3d = 0;
volatile int ttr_3d = 0;
volatile int ttt_3d = 0;


class Rectangle3D;
class Triangle3D;
class Circle3D;

class Shape3D {
public:
    // Invoked as s1
    virtual void collide(Shape3D* s2, Shape3D* s3) = 0;

    // Invoked as s2
    virtual void collide(Rectangle3D& s1, Shape3D* s3) = 0;
    virtual void collide(Triangle3D& s1, Shape3D* s3) = 0;
    virtual void collide(Circle3D& s1, Shape3D* s3) = 0;

    // Invoked as s3
    virtual void collide(Rectangle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Rectangle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Rectangle3D& s1, Circle3D& s2) = 0;

    virtual void collide(Triangle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Triangle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Triangle3D& s1, Circle3D& s2) = 0;

    virtual void collide(Circle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Circle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Circle3D& s1, Circle3D& s2) = 0;

    virtual ~Shape3D() = default;
};


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

class Rectangle3D gr;
class Triangle3D gt;
class Circle3D gc;