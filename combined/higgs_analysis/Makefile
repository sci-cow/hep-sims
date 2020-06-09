SHELL=/usr/bin/env bash

ifdef CI
PREFIX_LIB=../../pythia8244/lib
PREFIX_INCLUDE=../../pythia8244/include
else
PREFIX_LIB=../../../pythia8244/lib
PREFIX_INCLUDE=../../../pythia8244/include
endif
CXX_COMMON:=-I$(PREFIX_INCLUDE) $(CXX_COMMON)
CXX_COMMON+= -L$(PREFIX_LIB) -Wl,-rpath,$(PREFIX_LIB) -lpythia8 -ldl 

all: pythia-event-gen

pythia-event-gen: pythia-event-gen.cc $(PREFIX_LIB)/libpythia8.a
	$(CXX) $< -o pythia-event-gen $(CXX_COMMON) 

# Clean.
clean:
	rm -f *.o pythia-event-gen *.out
