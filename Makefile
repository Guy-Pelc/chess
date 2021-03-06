CC = g++
CCFLAGS =-c
LDFLAGS = 

# User defined classes and modules. (no file suffixes)
# CLASSES =testClone
CLASSES = chess units soldier board unix point rook bishop queen king knight

# Prepare object and source file list using pattern substitution func.
OBJS = $(patsubst %, %.o,  $(CLASSES))
SRCS = $(patsubst %, %.cpp, $(CLASSES))

prog: $(OBJS)
	clear all
	$(CC) $(OBJS) $(LDFLAGS) -o chess
	./chess

test:
	g++ test6.cpp -o testt
	./testt

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) $*.cpp

run:
	./chess
clean:
	-rm *.o *.exe
depend:
	makedepend -- $(CCFLAGS) -- $(SRCS)