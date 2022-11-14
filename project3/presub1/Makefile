useGraph: useGraph.o graph.o heap.o hash.o
	g++ -o useGraph useGraph.o graph.o heap.o hash.o 

useGraph.o: useGraph.cpp
	g++ -c useGraph.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

heap.o: heap.cpp heap.h
	g++ -c heap.cpp

hash.o: hash.cpp hash.h
	g++ -c hash.cpp

debug:
	g++ -g -o DebugGraph useGraph.cpp graph.cpp heap.cpp hash.cpp

clean:
	rm -f useGraph DebugGraph  *.o *.stackdump *~

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.h backups
	cp Makefile backups
