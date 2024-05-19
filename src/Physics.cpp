#include "Physics.hh"


Physics::Physics() {

    RegisterPhysics(new G4EmStandardPhysics);
    RegisterPhysics(new G4OpticalPhysics);
 
}


Physics::~Physics() {

}