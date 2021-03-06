#include "Pythia8/Pythia.h"
#include "../../utils/pdg.h"
#include <iostream>
using namespace Pythia8;

// QCD decays to tops, at Run-1 LHC CoM energies
int main(int argc, char* argv[])
{
    if(argc > 1) {
        const int NUM_EVENTS = 10;

        // Set up the generator
        Pythia pythia;
        pythia.readFile(argv[1]);
        pythia.init();

        int idxTop = 0;

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

            std::cout << "The transverse momentum of the final top is " 
                << pythia.event[idxTop].pT() << " and its pseudorapidity is " 
                << pythia.event[idxTop].eta() << std::endl;
            
        }

        pythia.stat();

        return 0;
    } else {
        std::cout << "Please provide the name of a config file" << std::endl;
        return -1;
    }
}