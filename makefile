all: LOP

LOP: the-library-of-pergamon.cpp
	g++ the-library-of-pergamon.cpp -o LOP -l ncurses

