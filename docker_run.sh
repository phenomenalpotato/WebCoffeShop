#/bin/bash

docker build --tag webfss:latest  .

# If the container is still running, will stop it
docker stop webfss
docker rm webfss

# If you want to execute the Web Server. Before running, be sure to fill the Environment Variables AWS_ACCESS_KEY_ID AND AWS_SECRET_ACCESS_KEY
docker run -d --rm -p 8000:8080 --name webfss -e AWS_ACCESS_KEY_ID=your_aws_access_key_id -e AWS_SECRET_ACCESS_KEY=your_aws_secret_access_key webfss:latest /bin/bash -c "./gamer"

# If you want to enter inside the container that is already running
# docker exec -it webfss bash

# And if you want to execute without Dettach and see what is happening
# docker run --rm -p 8000:8080 --name webfss -e AWS_ACCESS_KEY_ID=<ws_access_key_id -e AWS_SECRET_ACCESS_KEY=aws_secret_access_key webfss:latest /bin/bash -c "./gamer"

# To test without the credentials
# docker run -d --rm -p 8000:8080 --name webfss webfss:latest /bin/bash -c "./gamer"

# If you want to execute the S3-Upload-Object/s3-upload.cpp -- NOT WORKING
# docker run --name webfss webfss:latest /bin/bash -c "make execute_s3_sample" -- NOT WORKING