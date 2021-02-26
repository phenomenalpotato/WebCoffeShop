COMP = clang++-8
BIN = gamer
sfile = gamer.cpp

all:
	@echo "Compiling..."
	${COMP} -std=c++11 ${sfile} -Werror -W#warnings -Wall -lboost_thread -lboost_system -pthread -o ${BIN}

execute_and_compile:	all
	@echo "Compiling and executing..."
	@./${BIN}

execute:
	@./${BIN}