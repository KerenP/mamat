# Makeflie for airport program
CC=gcc
CFLAGS= -g -Wall -std=c99
CCLiNK= $(CC)
OBJS = main.o airport.o runway.o flight.o
RM = rm -f

#Link the final executable 
airport: $(OBJS)
	$(CCLiNK) -o airport $(OBJS)

# Creating object files using default rules 

main.o: main.c airport.h ex2.h runway.h flight.h
airport.o: airport.c airport.h ex2.h runway.h flight.h
runway.o: runway.c runway.h ex2.h flight.h
flight.o: flight.c flight.h ex2.h

# Cleaning old files before new make 
clean:
	$(RM) airport  *.o 

