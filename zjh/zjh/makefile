objects = zjhtest.o poker_print.o global_val.o
zjhtest : $(objects)
	cc -o zjhtest $(objects)

$(objects):poker_print.h global_val.h

.PHONY: clean
clean :
	rm -rf zjhtest $(objects)

