CXX=g++
CXXFLAGS=-Wall -g

zipf-graphical: zipf-graphical.o
	$(CXX) $(CXXFLAGS) zipf-graphical.o -o zipf-graphical \
           `pkg-config --cflags --libs plplotd-c++` -lpthread

zipf-graphical.o: zipf-graphical.cc
	$(CXX) $(CXXFLAGS) -c `pkg-config --cflags plplotd-c++` \
	  zipf-graphical.cc

clean:
	-rm -f zipf-graphical zipf-graphical.o
