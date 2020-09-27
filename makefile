CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/c_parser.tab.cpp src/c_parser.tab.hpp : src/c_parser.y
	bison -v -d src/c_parser.y -o src/c_parser.tab.cpp

src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

test.o : src/test.cpp src/ast.hpp
	g++ -c src/test.cpp

bin/c_compiler : src/compiler.o src/c_parser.tab.o src/c_lexer.yy.o src/c_parser.tab.o
	g++ $(CPPFLAGS) -o bin/c_compiler $^

compileT : test.o
	g++ test.o -o test

run_test1 :
	./bin/c_compiler < test1.txt

run :
	./test.exe

clean :
		rm src/*.o
		rm bin/c_compiler
		rm src/*.tab.cpp
		rm src/*.tab.hpp
		rm src/*.yy.cpp
		rm src/*.output
