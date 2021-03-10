#/bin/bash
docker build --tag webfss:latest  .

# If the container is still running, will stop it
docker stop webfss
docker rm webfss

# If you want to execute the Web Server. Before running, be sure to replace the env variables
docker run --rm -p 8000:8080 --name webfss \
    -e AWS_ACCESS_KEY_ID=YOUR_KEY_ID \
    -e AWS_SECRET_ACCESS_KEY=YOUR_KEY \
    -e BUCKET_NAME=YOUR_BUCKET_NAME \
    -e BUCKET_REGION=YOUR_BUCKET_REGION \
    webfss:latest /bin/bash -c "./gamer"

# If you want to enter inside the container that is already running
# docker exec -it webfss bash