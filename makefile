a.out: Board.o Logic.o ConsoleDisplay.o AIPlayer.o Point.o GameLevel.o ConsoleLogic.o Player.o ConsolePlayer.o main.o
	g++ Board.o Logic.o ConsoleDisplay.o AIPlayer.o Point.o GameLevel.o ConsoleLogic.o Player.o ConsolePlayer.o main.o

Logic.o: Logic.cpp Logic.h
	g++ -c Logic.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

ALPlayer.o: AIPlayer.cpp AIPlayer.h
	g++ -c AIPlayer.cpp

ConsoleDisplay.o: ConsoleDisplay.cpp ConsoleDisplay.h
	g++ -c ConsoleDisplay.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp

GameLevel.o: GameLevel.cpp GameLevel.h
	g++ -c GameLevel.cpp

ConsoleLogic.o: ConsoleLogic.cpp ConsoleLogic.h
	g++ -c ConsoleLogic.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

ConsolePlayer.o: ConsolePlayer.cpp ConsolePlayer.h
	g++ -c ConsolePlayer.cpp

main.o: main.cpp
	g++ -c main.cpp
