#include "DetectorConstruction.hh"


DetectorConstruction::DetectorConstruction() 
{

    xWorld = 0.5*m;
    yWorld = 0.5*m;
    zWorld = 0.5*m;

    ConstructWaterMaterial();

}



DetectorConstruction::~DetectorConstruction() 
{

}


void DetectorConstruction::ConstructWaterMaterial()
{

    G4double aH = 2.01568*g/mole;
    G4double aO = 16.00*g/mole;
    G4double waterDensity = 18.01528*g/cm3;
    G4NistManager *nist = G4NistManager::Instance();

    waterMaterial = new G4Material("water", waterDensity, 2);
    waterMaterial->AddElement(nist->FindOrBuildElement("H"), 2);
    waterMaterial->AddElement(nist->FindOrBuildElement("O"), 1);

    // optical properties
    G4double energy[2] = {1.239841939*eV/0.9,1.239841939*eV/0.2};
    G4double rIndexWater[2] = {1.34, 1.33};

    G4MaterialPropertiesTable *MPTwater = new G4MaterialPropertiesTable();
    MPTwater->AddProperty("RINDEX", energy, rIndexWater, 2);

    waterMaterial->SetMaterialPropertiesTable(MPTwater);

}


void DetectorConstruction::ConstructWaterBox()
{

    solidWater = new G4Box("solidWater", 0.4*m, 0.4*m, 0.01*m);
    logicWater = new G4LogicalVolume(solidWater, waterMaterial, "logicWater");
    physWater = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.35*m), logicWater, "physWater", logicWorld, false, 0, true);

    

}


G4VPhysicalVolume *DetectorConstruction::Construct() 
{

    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    // optical properties
    G4MaterialPropertiesTable *MPTWorld = new G4MaterialPropertiesTable();
    G4double energy[2] = {1.239841939*eV/0.9,1.239841939*eV/0.2};
    G4double rIndexWorld[2] = {1., 1.};
    MPTWorld->AddProperty("RINDEX", energy, rIndexWorld, 2);

    //worldMat->SetMaterialPropertiesTable(MPTWorld);

    solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
    logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);

    ConstructWaterBox();

    return physWorld;

}



























