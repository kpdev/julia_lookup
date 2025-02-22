#include "visitor.h"

#include <iostream>
#include <memory>
using namespace std;

// Forward declarations
class Circle3D;
class Rectangle3D;
class Triangle3D;

// Visitor interface
class Shape3DVisitor {
public:
    // Three distinct parameters
    virtual void visit(Circle3D*, Circle3D*, Circle3D*) = 0;
    virtual void visit(Circle3D*, Circle3D*, Rectangle3D*) = 0;
    virtual void visit(Circle3D*, Circle3D*, Triangle3D*) = 0;
    virtual void visit(Circle3D*, Rectangle3D*, Rectangle3D*) = 0;
    virtual void visit(Circle3D*, Rectangle3D*, Triangle3D*) = 0;
    virtual void visit(Rectangle3D*, Rectangle3D*, Rectangle3D*) = 0;
    virtual void visit(Rectangle3D*, Rectangle3D*, Triangle3D*) = 0;
    virtual void visit(Rectangle3D*, Triangle3D*, Triangle3D*) = 0;
    virtual void visit(Triangle3D*, Triangle3D*, Triangle3D*) = 0;
    virtual ~Shape3DVisitor() = default;
};

class Rectangle3D;
class Triangle3D;
// Concrete Shape3D classes
class Circle3D : public Shape3D {
public:
    // First dispatch: initiate the chain
    void collide(Shape3D* s2, Shape3D* s3, Shape3DVisitor& visitor) override {
        s2->acceptAsSecond(this, s3, visitor);
    }

    // Second dispatch: handle being the second object
    void acceptAsSecond(Shape3D* s1, Shape3D* s3, Shape3DVisitor& visitor) override {
        s3->acceptAsThird(s1, this, visitor);
    }

    // Third dispatch: final type resolution
    void acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) override;

private:
    // Helper template for type resolution
    template <typename T1>
    void handleThirdDispatch(T1* s1, Shape3D* s2, Shape3DVisitor& visitor) {
        if (auto c2 = dynamic_cast<Circle3D*>(s2)) {
            // visitor.visit(s1, c2, this);
        }
        else if (auto r2 = dynamic_cast<Rectangle3D*>(s2)) {
            // visitor.visit(s1, r2, this);
        }
        else if (auto t2 = dynamic_cast<Triangle3D*>(s2)) {
            // visitor.visit(s1, t2, this);
        }
    }
};

class Rectangle3D : public Shape3D {
public:
    // First dispatch: initiate the chain
    void collide(Shape3D* s2, Shape3D* s3, Shape3DVisitor& visitor) override {
        s2->acceptAsSecond(this, s3, visitor);
    }

    // Second dispatch: handle being the second object
    void acceptAsSecond(Shape3D* s1, Shape3D* s3, Shape3DVisitor& visitor) override {
        s3->acceptAsThird(s1, this, visitor);
    }

    // Third dispatch: final type resolution
    void acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) override;

private:
    // Helper template for type resolution
    template <typename T1>
    void handleThirdDispatch(T1* s1, Shape3D* s2, Shape3DVisitor& visitor) {
        if (auto c2 = dynamic_cast<Circle3D*>(s2)) {
            // visitor.visit(s1, c2, this);
        }
        else if (auto r2 = dynamic_cast<Rectangle3D*>(s2)) {
            // visitor.visit(s1, r2, this);
        }
        else if (auto t2 = dynamic_cast<Triangle3D*>(s2)) {
            // visitor.visit(s1, t2, this);
        }
    }
};

// Similar implementation for Triangle3D...
class Triangle3D : public Shape3D {
public:
    // First dispatch: initiate the chain
    void collide(Shape3D* s2, Shape3D* s3, Shape3DVisitor& visitor) override {
        s2->acceptAsSecond(this, s3, visitor);
    }

    // Second dispatch: handle being the second object
    void acceptAsSecond(Shape3D* s1, Shape3D* s3, Shape3DVisitor& visitor) override {
        s3->acceptAsThird(s1, this, visitor);
    }

    // Third dispatch: final type resolution
    void acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) override {
        // Resolve s1 type
        if (auto c1 = dynamic_cast<Circle3D*>(s1)) {
            this->handleThirdDispatch(c1, s2, visitor);
        }
        else if (auto r1 = dynamic_cast<Rectangle3D*>(s1)) {
            this->handleThirdDispatch(r1, s2, visitor);
        }
        else if (auto t1 = dynamic_cast<Triangle3D*>(s1)) {
            this->handleThirdDispatch(t1, s2, visitor);
        }
    }

private:
    // Helper template for type resolution
    template <typename T1>
    void handleThirdDispatch(T1* s1, Shape3D* s2, Shape3DVisitor& visitor) {
        if (auto c2 = dynamic_cast<Circle3D*>(s2)) {
            // visitor.visit(s1, c2, this);
        }
        else if (auto r2 = dynamic_cast<Rectangle3D*>(s2)) {
            // visitor.visit(s1, r2, this);
        }
        else if (auto t2 = dynamic_cast<Triangle3D*>(s2)) {
            // visitor.visit(s1, t2, this);
        }
    }
};

volatile int 
    ccc_3d = 0,
    ccr_3d = 0,
    cct_3d = 0,
    crr_3d = 0,
    crt_3d = 0,
    rrr_3d = 0,
    rrt_3d = 0,
    rtt_3d = 0,
    ttt_3d = 0;

// Concrete visitor
class CollisionHandler : public Shape3DVisitor {
public:
    virtual void visit(Circle3D*, Circle3D*, Circle3D*) override {
        ccc_3d++;
    }

    virtual void visit(Circle3D*, Circle3D*, Rectangle3D*) override {
        ccr_3d++;
    }

    virtual void visit(Circle3D*, Circle3D*, Triangle3D*) {
        cct_3d++;
    }

    virtual void visit(Circle3D*, Rectangle3D*, Rectangle3D*) {
        crr_3d++;
    }

    virtual void visit(Circle3D*, Rectangle3D*, Triangle3D*) {
        crt_3d++;
    }

    virtual void visit(Rectangle3D*, Rectangle3D*, Rectangle3D*) {
        rrr_3d++;
    }

    virtual void visit(Rectangle3D*, Rectangle3D*, Triangle3D*) {
        rrt_3d++;
    }

    virtual void visit(Rectangle3D*, Triangle3D*, Triangle3D*) {
        rtt_3d++;
    }

    virtual void visit(Triangle3D*, Triangle3D*, Triangle3D*) {
        ttt_3d++;
    }
};

// Collision entry point
void collide3D(Shape3D& s1, Shape3D& s2, Shape3D& s3) {
    CollisionHandler handler;
    s1.collide(&s2, &s3, handler);
}


Circle3D g_c;
Rectangle3D g_r;

Shape3D* get_shape3d(int i) {
    if (i == 1)
        return &g_c;
    if (i == 2)
        return &g_r;
    exit(EXIT_FAILURE);
}

int main1() {
    Circle3D c1, c2;
    Rectangle3D r1;
    
    collide3D(c1, c2, r1);  // Properly dispatches to visit(Circle3D*, Circle3D*, Rectangle3D*)
    return 0;
}



void Circle3D::acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) {
    // Resolve s1 type
    if (auto c1 = dynamic_cast<Circle3D*>(s1)) {
        this->handleThirdDispatch(c1, s2, visitor);
    }
    else if (auto r1 = dynamic_cast<Rectangle3D*>(s1)) {
        this->handleThirdDispatch(r1, s2, visitor);
    }
    else if (auto t1 = dynamic_cast<Triangle3D*>(s1)) {
        this->handleThirdDispatch(t1, s2, visitor);
    }
}

void Rectangle3D::acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) {
    // Resolve s1 type
    if (auto c1 = dynamic_cast<Circle3D*>(s1)) {
        this->handleThirdDispatch(c1, s2, visitor);
    }
    else if (auto r1 = dynamic_cast<Rectangle3D*>(s1)) {
        this->handleThirdDispatch(r1, s2, visitor);
    }
    else if (auto t1 = dynamic_cast<Triangle3D*>(s1)) {
        this->handleThirdDispatch(t1, s2, visitor);
    }
}