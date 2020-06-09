SHELL=/usr/bin/env bash

all: 
	$(MAKE) basic_pythia
	$(MAKE) higgs_analysis

basic_pythia:
	$(MAKE) -C basic/pythia

higgs_analysis:
	$(MAKE) -C combined/higgs_analysis

# Clean.
clean:
	$(MAKE) clean -C basic/pythia
	$(MAKE) clean -C combined/higgs_analysis