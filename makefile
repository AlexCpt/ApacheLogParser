EXE=analog
COMP=g++ -std=c++11 -Wall -c -g
INT= main.h lecteurLog.h Graph.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
EFFACE=clean
DBG = debug
RM=rm


$(EXE): $(OBJ)
	echo "edition de <$(EXE)>"
	g++ -std=c++11 -o $(EXE) $(OBJ)

%.o:%.cpp
	echo "comp de $<"
	$(COMP) $<

$(EFFACE):$(OBJ)
	 $(RM) -f $(EXE) $(OBJ)


main.o : main.cpp 

lecteurLog.o : lecteurLog.cpp lecteurLog.h