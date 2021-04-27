#.SUFFIXES:.c .o

#CC = gcc

#SRCS   = client.c
#OBJS   = $(SRCS:.c=.o)
#EXEC   = client

#start: $(OBJS)
#	$(CC) -o $(EXEC) $(OBJS)

#	@echo "----------------------MAKE OK-----------------------"

#.c.o:
#	$(CC) -Wall -o $@ -c $<
#clean:
#	rm -rf $(EXEC) $(OBJS)
#	@echo "----------------------MAKE CLEAN OK-----------------------"
CC   = gcc
OBJS = client.o
TAGS = client
RM   = rm -rf

$(TAGS) : $(OBJS)
	$(CC) -o $(TAGS) $(OBJS)
	@echo "----------------- make client finish ---------------------"

.PHONY : clean
clean:
	$(RM) $(OBJS) $(TAGS)
	@echo "----------------------MAKE CLEAN OK-----------------------"
