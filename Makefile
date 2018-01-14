SRC=*.cpp
H=*.h
CXX=g++
CPPFLAGS=-g -std=c++11 -Wall -pedantic
EXE=a.out
RM=rm -f

$(EXE): $(SRC) $(H)
	$(CXX) $(CPPFLAGS) -o $@ $(SRC)

clean:
	$(RM) *.o $(EXE)
