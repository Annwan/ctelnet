CC=gcc
CCLIBS=
CCFLAGS=-Wall -Werror -pedantic
CSOURCES=src/main.c src/nvt.c
COBJ=$(CSOURCES:src/%.c=build/%.o)
EXEC=build/telnettest

.PHONY: all clean mrproper

all: $(EXEC)

clean:
	rm -f build/**.o

mrproper: clean
	rm -f $(EXEC)

$(EXEC): $(COBJ)
	$(CC) $(CCFLAGS) $^ -o $@ $(CCLIBS)

build/%.o: src/%.c
	$(CC) $(CCFLAGS) $< -c -o $@ $(CCLIBS)

build/nvt.o: src/nvt.c src/nvt.h
build/main.o: src/main.c src/nvt.h
