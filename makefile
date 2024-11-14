main: main.o HashTables.o
	g++ $^ -o $@

test: main
	./main