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

all: hist basic-decays

hist: hist.cc $(PREFIX_LIB)/libpythia8.a
	$(CXX) $< -o hist $(CXX_COMMON) 

basic-decays: basic-decays.cc $(PREFIX_LIB)/libpythia8.a
	$(CXX) $< -o basic-decays $(CXX_COMMON) 

# Clean.
clean:
	rm -f *.o basic-pythia hist *.out
