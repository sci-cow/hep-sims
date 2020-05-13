#include "Pythia8/Pythia.h"
using namespace Pythia8;

int main()
{
    // Set up the generator
    Pythia pythia;
    pythia.readString("Top:gg2ttbar = on"); // Switch on our single decay process
    pythia.readString("Beams:eCM = 8000."); // 8 TeV sqrt(s)
    pythia.init();                          // Assumes proton-proton beams

    pythia.next();                          // Generate event. Fills the event record.
    return 0;
}