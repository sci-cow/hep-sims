// Creating histograms using the basic built-in Pythia functionality
// Using the results from `basic-decays.cc` to guide some of our boundaries here.
#include "Pythia8/Pythia.h"
#include "../../utils/pdg.h"
#include <iostream>
using namespace Pythia8;

int main(int argc, char* argv[])
{
    if(argc > 1) {
        const int NUM_EVENTS = 1000;

        Pythia pythia;
        pythia.readFile(argv[1]);
        pythia.init();

        int idxHiggs = 0;
        Hist pT("Higgs pT", 100, 0.0, 200.0);
        Hist y("Higgs rapidity", 100, -5.0, 5.0);
        Hist eta("Higgs pseudorapidity", 100, -5.0, 5.0);

        for(int i = 0; i < NUM_EVENTS; i++) {
            if(pythia.next()) {
                for(int j = 0; j < pythia.event.size(); j++) {
                    if(pythia.event[j].id() == PDG_HIGGS) {
                        idxHiggs = j;
                    }
                }
            }

            pT.fill(pythia.event[idxHiggs].pT());
            eta.fill(pythia.event[idxHiggs].eta());        
            y.fill(pythia.event[idxHiggs].y());        
        }

        std::cout << pT << eta << y;

        return 0;
    } else {
        std::cout << "Please provide the name of a config file" << std::endl;
        return -1;
    }
}