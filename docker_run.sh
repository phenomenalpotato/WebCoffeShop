#/bin/bash

COMP=clang++-8

sfile="gamer.cpp"

BIN="gamer"

docker build --tag webfss:latest  .

# If the container is still running, will stop it
docker stop webfss
docker rm webfss

# If you want to execute the Web Server
docker run -d --rm -p 8000:8080 --name webfss -e AWS_ACCESS_KEY_ID=<your_aws_access_key_id> -e AWS_SECRET_ACCESS_KEY=<your_aws_secret_access_key> webfss:latest /bin/bash -c "./gamer"

# And if you want to execute without Dettach
# docker run --rm -p 8000:8080 --name webfss -e AWS_ACCESS_KEY_ID=<aws_access_key_id> -e AWS_SECRET_ACCESS_KEY=<aws_secret_access_key> webfss:latest /bin/bash -c "./gamer"

# docker run --rm -p 8000:8080 --name webfss webfss:latest /bin/bash -c "make execute_and_compile"

# If you want to execute the S3-Upload-Object/s3-upload.cpp-- NOT WORKING
#docker run --name webfss webfss:latest /bin/bash -c "make execute_s3_sample"