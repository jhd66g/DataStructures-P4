#
# Mark's Magic Makefile
#
# Instructions:
#
# 1. Add .cc files (not .h files) to the line beginning with SRCS = main.cc.
#    Files should be separated with spaces, not commas.  If all of the
#    .cc files in the directory should be included in the build, then you
#    can avoid maintaining a specific list of source files by commenting
#    out the first SRCS line and uncommenting the second (as done below).
# 2. Type 'make depend' to build or update the dependency list.  Do this
#    whenever you add this Makefile or add a .cc or .h file to a project.
# 3. Type 'make' to build the project.
# 4. Type 'make clean' to start over or prepare for submission.  This does
#    not remove the dependency information.
#
# N.B. If you're using files with .cpp extensions, then you need to search
# and replace cc with cpp.
#

DRIVER_NAME = main
SUBMIT_NAME = submit

p4: main.o PriorityQueue.o Graph.o
	g++ main.o PriorityQueue.o Graph.o -o p4

main.o: main.cpp PriorityQueue.h Graph.h
	g++ -c main.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

submit:
	rm -f submit.zip
	zip submit.zip $(DRIVER_NAME).cpp PriorityQueue.cpp PriorityQueue.h Graph.cpp Graph.h Makefile