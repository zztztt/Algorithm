
CC=g++
FLAG=-Wall -O2
AVLTree: AVLTree.o main.cc
	$(CC) $(FLAG) AVLTree.o main.cc -o AVLTree
AVLTree.o: AVLTree.cc AVLTree.h
	$(CC) -c $(FLAG) AVLTree.cc -o AVLTree.o

.PHONY : clean 
clean:
	rm -rf *.o
