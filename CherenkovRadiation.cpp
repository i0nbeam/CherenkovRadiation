#include "DetectorConstruction.hh"
#include "Physics.hh"
#include "ActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"



int main(int argc, char **argv) 
{

    auto runManager = new G4RunManager();
    runManager->SetUserInitialization(new DetectorConstruction);

    runManager->SetUserInitialization(new Physics);

    runManager->SetUserInitialization(new ActionInitialization);

    runManager->Initialize();

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);

    auto *visManager = new G4VisExecutive();
    visManager->Initialize();

    auto *UImanager = G4UImanager::GetUIpointer();

    ui->SessionStart();

    delete runManager;

    return 0;

}