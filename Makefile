CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = pa09.o scanner.o expressionTree.o tree.o 
VALS = valgrind --tool=memcheck --leak-check=full

pa09: $(OBJS)
	$(GCC) $(OBJS) -o $@

pa09.o: pa09.c
	$(GCC) -c $< -o $@ 

scanner.o: scanner.c scanner.h
	$(GCC) -c $< -o $@

expressionTree.o: expressionTree.c expressionTree.h
	$(GCC) -c $< -o $@

tree.o: tree.c tree.h
	$(GCC) -c $< -o $@


memory: pa09
	
	$(VALS) ./pa09 inputs/test1 out1
	$(VALS) ./pa09 inputs/test2 out2
	$(VALS) ./pa09 inputs/test3 out3
	$(VALS) ./pa09 inputs/test4 out4
clean:
	rm -f *.o
	rm -f pa09
	rm -f *.gcda *.gcno *.gcov gmon.out

