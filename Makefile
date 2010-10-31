CXX=g++
CXXFLAGS=-Wall -O2

zipf-graphical: zipf-graphical.o
	$(CXX) $(CXXFLAGS) zipf-graphical.o -o zipf-graphical \
           `pkg-config --cflags --libs plplotd-c++`

zipf-graphical.o: zipf-graphical.cc
	$(CXX) $(CXXFLAGS) -c `pkg-config --cflags plplotd-c++` \
	  zipf-graphical.cc
