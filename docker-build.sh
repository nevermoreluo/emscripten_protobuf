#!/bin/bash
dot_dir=$(cd $(dirname "${BASH_SOURCE[0]}"); pwd)




POSITIONAL=()
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -buildEnv|--buildEnv-docker)
    BUILD_DOCKER=YES
    shift # past value
    ;;
    -make|--make)
    MAKE=YES
    shift # past value
    ;;
    -h|--help)
    HELP=YES
    shift
    ;;
    --default)
    DEFAULT=YES
    shift # past argument
    ;;
    *)    # unknown option
    POSITIONAL+=("$1") # save it in an array for later
    shift # past argument
    ;;
esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

if [[ -n $1 ]]; then
    echo "Last line of file specified as non-opt/last argument:"
    tail -1 "$1"
fi

if [[ ! -z "$HELP" ]]; then
    echo "Usage: <-buildEnv|-make>"
    echo "Options:"

    echo "-h, --help                    show this help message and exit"
    echo "-buildEnv,                       build docker for protobuf+emcc named emcc_proto"
    echo "-make,                        use emcc_proto docker container to make wasm"
fi


if [[ ! -z "$BUILD_DOCKER" ]]; then
    docker build -f Dockerfiles/Dockerfile -t emcc_proto .
fi

if [[ ! -z "$MAKE" ]]; then
    docker run --rm -v \
        $(pwd):/src -u $(id -u):$(id -g) emcc_proto \
        bash -c "rm -rf build/; \
        mkdir build/ && cd build/ && \
        emcmake cmake .. && make && \
        emcc --bind --ts-typings --post-js ../test_post_script.js -o ../eproto.js -Wl,--whole-archive libeProto.a -Wl,--no-whole-archive"
fi

