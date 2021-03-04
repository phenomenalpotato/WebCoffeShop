#/bin/bash

COMP=clang++-8

sfile="gamer.cpp"

BIN="gamer"

docker build --tag webfss:latest  .

# If the container is still running, will stop it
docker stop webfss
docker rm webfss

# If you want to execute the Web Server

# docker run -d --rm -p 8000:8080 --name webfss webfss:latest /bin/bash -c "make execute_and_compile"

# And if you want to execute without Dettach
docker run --rm -p 8000:8080 --name webfss webfss:latest /bin/bash -c "${COMP} -std=c++11 ${sfile} -Werror -W#warnings -Wall -lboost_thread -lboost_system -lz -pthread -o ${BIN}"

# docker run --rm -p 8000:8080 --name webfss webfss:latest /bin/bash -c "make execute_and_compile"

# If you want to execute the S3-Upload-Object/s3-upload.cpp
#docker run --name webfss webfss:latest /bin/bash -c "make execute_s3_sample"
