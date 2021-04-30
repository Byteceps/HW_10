CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++2a -O0 -g 
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)
all:  tsp

tsp: tsp.o chromosome.o deme.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

deme: deme.o chromosome.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

chromosome: chromosome.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^


%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o tsp
