CC=g++ -lncurses -g -std=c++11
exe_file=prog
$(exe_file): main.cpp game.o maze.o mazeLocation.o wall.o border.o openSpace.o mazePerson.o coordinate.o intrepidStudent.o ta.o
	$(CC) main.cpp game.o maze.o mazeLocation.o wall.o border.o openSpace.o coordinate.o mazePerson.o intrepidStudent.o ta.o -o $(exe_file)
game.o: game.cpp game.h
	$(CC) -c game.cpp

maze.o: maze.cpp maze.h
	$(CC) -c maze.cpp

mazeLocation.o: mazeLocation.cpp mazeLocation.h
	$(CC) -c mazeLocation.cpp

wall.o: wall.cpp wall.h
	$(CC) -c wall.cpp

border.o: border.cpp border.h
	$(CC) -c border.cpp

openSpace.o: openSpace.h openSpace.cpp
	$(CC) -c openSpace.cpp

mazePerson.o: mazePerson.h mazePerson.cpp
	$(CC) -c mazePerson.cpp

intrepidStudent.o: intrepidStudent.h intrepidStudent.cpp
	$(CC) -c intrepidStudent.cpp

ta.o: ta.h ta.cpp
	$(CC) -c ta.cpp

coordinate.o: coordinate.cpp coordinate.h
	$(CC) -c coordinate.cpp

clean:
	rm -f *.o $(exe_file)