COMP = clang++-8
BIN = gamer
BIN2 = S3-Upload-Object/s3-upload
sfile = gamer.cpp

all:
	@echo "Compiling..."
	${COMP} -std=c++11 ${sfile} -Werror -W#warnings -Wall -lboost_thread -lboost_system -lz -pthread -o ${BIN}

execute_and_compile:	all
	@echo "Compiling and executing..."
	@./${BIN}

execute:
	@./${BIN}

execute_s3_sample:
		@./${BIN2}
