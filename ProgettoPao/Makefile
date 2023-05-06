CC = g++
args = -O3 -Wall -Wextra -g -std=c++11
destination = target
executable = arda.exe

UNITS = \
	$(destination)/ainur.o\
	$(destination)/valar.o\
	$(destination)/entity.o\
	$(destination)/human.o\
	$(destination)/elf.o\
	$(destination)/humanoid.o\
	$(destination)/maiar.o\
	$(destination)/orc.o\
	$(destination)/dwarf.o\
	$(destination)/hobbit.o\
	$(destination)/qontainer.o\


run: $(destination)/$(executable)
	@ $(destination)/$(executable)

$(destination)/$(executable): $(destination) main.cpp $(UNITS)
	$(CC) $(args) main.cpp $(wildcard $(destination)/*.o) -o $(destination)/$(executable)

$(destination)/%.o: %.cpp %.h
	$(CC) $(args) -c $< -o $(destination)/$(basename $<).o

$(destination):
	mkdir $(destination)