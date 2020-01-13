####################################################################
# Makefile for building the theater application
#

#
# Definitions
#
CC = g++
CFLAGS = -g -Wall
CCLINK = $(CC)
OBJS = Cashier.o DubbedMovie.o Employee.o Mat.o Movie.o Theater.o main.o
LIBS = 
RM = rm -f
TARGET = theater

$(TARGET): $(OBJS)
	$(CCLINK) -o $(LIBS) $(TARGET) $(OBJS)

Cashier.o: Cashier.C Cashier.H Employee.H DubbedMovie.H Movie.H Theater.H Mat.H Proj.H
Movie.o: Movie.C Movie.H Mat.H Proj.H
DubbedMovie.o: DubbedMovie.C DubbedMovie.H Movie.C Movie.H Proj.H
main.o: main.C Cashier.H Employee.H DubbedMovie.H Movie.H Theater.H Mat.H Proj.H
Employee.o: Employee.C Employee.H Proj.H
Mat.o: Mat.C Mat.H Proj.H
Theater.o: Theater.C Theater.H Mat.H Proj.H

#
# Cleaninng
#
clean:
	$(RM) $(TARGET) *.o *.bak *~* *"#"* core
