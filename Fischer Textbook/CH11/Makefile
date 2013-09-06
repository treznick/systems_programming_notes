# Rule for building a .o file from a .cpp source file.
.SUFFIXES: .cpp

.cpp.o:
	c++ -c $(CXXFLAGS) $<
    
# Compile with debug option and all warnings on.
CXXFLAGS = -g -Wall -I../..

# Object modules comprising this application.
OBJ = graphM.o graph.o row.o ../../tools.o

graph: $(OBJ)
	c++ $(CXXFLAGS) -o graph $(OBJ)

clean:
	rm -f $(OBJ) graph

# Use tools source file from grandparent directory.
../../tools.o: ../../tools.cpp ../../tools.hpp
	c++ -c $(CXXFLAGS) ../../tools.cpp -o ../../tools.o

# Dependencies
graphM.o: graphM.cpp graph.hpp ../../tools.hpp
graph.o:  graph.cpp graph.hpp row.hpp
row.o: 	  row.cpp row.hpp item.hpp
