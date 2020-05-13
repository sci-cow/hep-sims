SHELL=/usr/bin/env bash

PREFIX_LIB=../../../pythia8244/lib
PREFIX_INCLUDE=../../../pythia8244/include
CXX_COMMON:=-I$(PREFIX_INCLUDE) $(CXX_COMMON)
CXX_COMMON+= -L$(PREFIX_LIB) -Wl,-rpath,$(PREFIX_LIB) -lpythia8 -ldl 

all: basic-decays.cc $(PREFIX_LIB)/libpythia8.a
	$(CXX) $< -o basic-pythia $(CXX_COMMON) 

# Clean.
clean:
	rm -f *.o basic-pythia *.out
