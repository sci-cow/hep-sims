SHELL=/usr/bin/env bash

PREFIX_LIB=/home/cow/Documents/sims/pythia8244/lib
PREFIX_INCLUDE=/home/cow/Documents/sims/pythia8244/include
CXX_COMMON:=-I$(PREFIX_INCLUDE) $(CXX_COMMON)
CXX_COMMON+= -L$(PREFIX_LIB) -Wl,-rpath,$(PREFIX_LIB) -lpythia8 -ldl 

all: 
	$(MAKE) basic_pythia

basic_pythia:
	$(MAKE) -C basic/pythia

# Clean.
clean:
	$(MAKE) clean -C basic/pythia