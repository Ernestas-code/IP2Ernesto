# compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# files
CLASS = Set
DEMO = demo
TEST = test

# build object file
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CXX) $(CXXFLAGS) -c $(CLASS).cpp

# build demo
demo: $(DEMO).cpp $(CLASS).o
	$(CXX) $(CXXFLAGS) $(DEMO).cpp $(CLASS).o -o demo

# run demo
run_demo: demo
	./demo

# build test
test: $(TEST).cpp $(CLASS).o
	$(CXX) $(CXXFLAGS) $(TEST).cpp $(CLASS).o -o test

# run test
run_test: test
	./test

# clean files
clean:
	rm -f *.o demo test log.txt

# rebuild everything
rebuild: clean demo test