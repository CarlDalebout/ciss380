#------------------------------------------------------------------------------
# Makefile for object code in mygllib
# Y. Liow
#------------------------------------------------------------------------------
# Macros
#------------------------------------------------------------------------------
CXX 		= g++
CXXFLAGS 	= -g -Wall
LINK 		= g++
LINKFLAGS 	= -lGL -lGLU -lglut -lGLEW
OBJS 		= config.o View.o

#------------------------------------------------------------------------------
# Build all object code
#------------------------------------------------------------------------------
all: 	$(OBJS)
	$(NOOP)

#------------------------------------------------------------------------------
# Object codes
#------------------------------------------------------------------------------
config.o: config.h config.cpp
	$(CXX) $(CXXFLAGS) config.cpp -c -o config.o
View.o: View.h View.cpp
	$(CXX) $(CXXFLAGS) View.cpp -c -o View.o
#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------
clean:
	rm -f $(OBJS)
c:
	rm -f $(OBJS)