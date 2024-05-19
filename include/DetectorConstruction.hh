#ifndef DETECTORCONSTRUCTION_HH
#define DETECTORCONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{

public:

    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4VPhysicalVolume *Construct();


private:

    G4double xWorld;
    G4double yWorld;
    G4double zWorld;

    G4Box *solidWorld;
    G4LogicalVolume *logicWorld;
    G4VPhysicalVolume *physWorld;

    G4Box *solidWater;
    G4LogicalVolume *logicWater;
    G4VPhysicalVolume *physWater;

    G4Material *waterMaterial;

    void ConstructWaterMaterial();
    void ConstructWaterBox();
    
};






#endif