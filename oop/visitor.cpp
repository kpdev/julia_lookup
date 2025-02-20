
#include "visitor.h"

volatile int aa, ab, ba, bb;


void ElementA::visit(class Element* visitor) { visitor->visit(*this); }

void ElementA::visit(class ElementA& visitor) {
    aa++;
}

void ElementA::visit(class ElementB& visitor) { 
    ab++;
}


void ElementB::visit(class Element* visitor) { 
    visitor->visit(*this); 
}

void ElementB::visit(class ElementA& visitor) {
    ba++;
}

void ElementB::visit(class ElementB& visitor) {
    bb++;
}

