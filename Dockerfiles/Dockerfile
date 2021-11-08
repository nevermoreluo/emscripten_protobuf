FROM emscripten/emsdk

WORKDIR /emcc
COPY ./Dockerfiles/lib_source/protobuf-cpp-3.6.1.tar.gz /emcc/protobuf-cpp-3.6.1.tar.gz

RUN apt-get -qq -y update && \
    apt install --no-install-recommends -y autoconf automake libtool curl make g++ unzip \
    && apt-get -y clean \
    && apt-get -y autoclean \
    && apt-get -y autoremove \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /var/cache/debconf/*-old \
    && rm -rf /usr/share/doc/* \
    && rm -rf /usr/share/man/?? \
    && rm -rf /usr/share/man/??_*

RUN tar xzf protobuf-cpp-3.6.1.tar.gz &&\
    cd protobuf-3.6.1/ &&\
    ./autogen.sh && ./configure &&\
    make install &&\
    echo "usr/local/lib" > /etc/ld.so.conf.d/usr_local_lib.conf && \
    ldconfig && \
    rm -rf /emcc/protobuf-*

WORKDIR /src
