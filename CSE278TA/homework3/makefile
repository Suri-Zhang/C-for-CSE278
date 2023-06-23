CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11 -I/usr/include/mysql -I/usr/local/include/mysql++
LDFLAGS := -L/usr/local/lib
LDLIBS := -lmysqlpp -lmysqlclient

EXECUTABLE := application

$(EXECUTABLE).out: $(EXECUTABLE).o filmfunctions.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(EXECUTABLE).o: $(EXECUTABLE).cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

filmfunctions.o: filmfunctions.cpp filmfunctions.h
	$(CXX) $(CXXFLAGS) -c -o $@ filmfunctions.cpp

clean:
	rm -f $(EXECUTABLE).out $(EXECUTABLE).o filmfunctions.o
