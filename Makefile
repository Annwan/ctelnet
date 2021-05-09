CC=gcc
CCLIBS=
CCFLAGS=-Wall -Werror -pedantic
CSOURCES=src/main.c
COBJ=$(CSOURCES:src/%.c=build/%.o)
EXEC=build/ctelnet

.PHONY all clean mrproper

all: $(EXEC)

clean:
	rm build/*.o

mrproper: clean
	rm $(EXEC)

$(EXEC): $(COBJ)
	$(CC) $(CCLIBS) $(CCFLAGS) $^ -o $@

build/main.o: src/main.c
	$(CC) $(CCLIBS) $(CCFLAGS) $< -o $a


