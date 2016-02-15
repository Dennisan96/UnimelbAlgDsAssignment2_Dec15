all: ida wida ida_improved

ida: main.o graph.o io.o ida.o heuristic.o
	gcc -Wall -O3 -o ida main.o graph.o io.o ida.o heuristic.o

wida: main.o graph.o io.o wida.o heuristic.o
	gcc -Wall -O3 -o wida main.o graph.o io.o wida.o heuristic.o

ida_improved: main.o graph.o io.o ida.o heuristic_improved.o
	gcc -Wall -O3 -o ida_improved main.o graph.o io.o ida.o heuristic_improved.o

main.o: main.c graph.h io.h
	gcc -O3 -c main.c

graph.o: graph.c graph.h io.h ida.h
	gcc -O3 -c graph.c

io.o: io.c io.h heuristic.h graph.h
	gcc -O3 -c io.c

ida.o: ida.c ida.h heuristic.h
	gcc -O3 -c ida.c

wida.o: wida.c ida.h heuristic.h
	gcc -O3 -c wida.c

heuristic.o: heuristic.c heuristic.h
	gcc -O3 -c heuristic.c

heuristic_improved.o: heuristic_improved.c heuristic.h
	gcc -O3 -c heuristic_improved.c
