include ../Makefile.rule

INCLUDES += -I$(PROJECT_ROOT_PATH)/libalgorithm/

all:test
test: test.o
	gcc test.o -o test   $(PROJECT_ROOT_PATH)/libalgorithm/libalgorithm.a  -lm -luuid

test.o: test.c
	gcc -c test.c $(INCLUDES) -o test.o

.PHONY: clean

clean:
	rm -f *.o test

.PHONY: all
