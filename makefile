a.out: compileAll
	g++ *.o -o ../../exe/client.out
	rm -f *.o

compileAll: *.cpp *.h
	g++ -c *.cpp
