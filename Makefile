SHELL=/usr/bin/env bash

all: 
	$(MAKE) basic_pythia

basic_pythia:
	$(MAKE) -C basic/pythia

# Clean.
clean:
	$(MAKE) clean -C basic/pythia