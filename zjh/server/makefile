#.SUFFIXES:.c .o
#
#CC = gcc
#
#SRCS   = server.c
#OBJS   = $(SRCS:.c=.o)
#EXEC   = server
#
#start: $(OBJS)
#	$(CC) -o $(EXEC) $(OBJS)
#
#	@echo "----------------------MAKE OK-----------------------"
#
#.c.o:
#	$(CC) -Wall -o $@ -c $<
#clean:
#	rm -rf $(EXEC) $(OBJS)
#	@echo "----------------------MAKE CLEAN OK-----------------------"
objects = server.o

server: $(objects)
	cc -o server $(objects)

.PHONY : clean

clean :
	rm server $(objects)




