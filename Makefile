CXX = g++
CXXFLAGS = -Wall -g

TARGETS = zipf-cc zipf-cc-graphical zipf-hs

all: $(TARGETS)

zipf-cc: zipf-cc.o
	$(CXX) $(CXXFLAGS) -o zipf-cc zipf-cc.o

zipf-cc.o: zipf.cc
	$(CXX) $(CXXFLAGS) -c -o zipf-cc.o zipf.cc

zipf-cc-graphical: zipf-cc-graphical.o
	$(CXX) $(CXXFLAGS) zipf-cc-graphical.o -o zipf-cc-graphical \
           `pkg-config --cflags --libs plplot-c++ plplot` -lpthread

zipf-cc-graphical.o: zipf-graphical.cc
	$(CXX) $(CXXFLAGS) -c -o zipf-cc-graphical.o \
	`pkg-config --cflags plplot-c++ plplot` \
	zipf-graphical.cc

zipf-hs: zipf.hs
	ghc --make -o zipf-hs zipf.hs

clean:
	-rm -f *.o *.hi $(TARGETS)
