a.out: Board.o Point.o GameLevel.o GameLogic.o Player.o ConsolePlayer.o main.o
	g++ Board.o Point.o GameLevel.o GameLogic.o Player.o ConsolePlayer.o main.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp

GameLevel.o: GameLevel.cpp GameLevel.h
	g++ -c GameLevel.cpp

GameLogic.o: GameLogic.cpp GameLogic.h
	g++ -c GameLogic.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

ConsolePlayer.o: ConsolePlayer.cpp ConsolePlayer.h
	g++ -c ConsolePlayer.cpp

main.o: main.cpp
	g++ -c main.cpp
