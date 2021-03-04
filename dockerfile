FROM ubuntu

RUN apt-get update
RUN apt-get update --fix-missing

RUN apt-get install -y clang-8
RUN apt-get install -y make
RUN apt-get install -y build-essential

#Set Timezone to avoid configuration in tzdata:
RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && echo $CONTAINER_TIMEZONE > /etc/timezone

RUN apt-get install -y git libcurl4-openssl-dev libssl-dev uuid-dev zlib1g-dev libpulse-dev cmake
RUN apt-get install -y libboost-all-dev

WORKDIR /var/aws-sdk-build/

RUN git clone https://github.com/aws/aws-sdk-cpp.git

WORKDIR aws-sdk-cpp/

RUN cmake CMakeLists.txt -D BUILD_ONLY="s3"

RUN make

RUN make install

ADD . /var/

# To start the container in the /var directory
WORKDIR /var/

RUN mv include/awsdoc /usr/local/include/

RUN cmake CMakeLists.txt

RUN make

EXPOSE 8080
