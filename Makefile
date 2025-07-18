CC=gcc
CCFLAGS=
SOURCES=./src/*.c
USRDEST=$(HOME)/.local
OUTPUTNAME=crudeshell

all: build

build:
	$(CC) $(SOURCES) -o $(OUTPUTNAME) $(CCFLAGS)

run:
	./$(OUTPUTNAME)
	
install:
	cp ./$(OUTPUTNAME) $(USRDEST)/bin/
	
uninstall:
	rm -f $(USRDEST)/bin/$(OUTPUTNAME)

clean:
	rm -f ./$(OUTPUTNAME) ./src/*.o
