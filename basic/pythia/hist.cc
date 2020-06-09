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

        // Set up the generator
        Pythia pythia;
        pythia.readFile(argv[1]);
        pythia.init();

        int idxTop = 0;
        Hist pT("Top pT", 100, 0.0, 200.0);
        Hist y("Top rapidity", 100, -5.0, 5.0);
        Hist eta("Top pseudorapidity", 100, -5.0, 5.0);

        for(int i = 0; i < NUM_EVENTS; i++) {
            // Generate event and fill the event record, check that it succeeded
            if(pythia.next()) {
                for(int j = 0; j < pythia.event.size(); j++) {
                    // Store the index if it is a top quark; the last of these will, by definition,
                    // be the final decay-product top.
                    if(pythia.event[j].id() == PDG_TOP) {
                        idxTop = j;
                    }
                }
            }

            pT.fill(pythia.event[idxTop].pT());
            eta.fill(pythia.event[idxTop].eta());        
            y.fill(pythia.event[idxTop].y());        
        }

        std::cout << pT << eta << y;

        return 0;
    } else {
        std::cout << "Please provide the name of a config file" << std::endl;
        return -1;
    }
}