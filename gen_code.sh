#!/bin/bash
#trpc create -protofile= <-rpconly>
# protoc --cpp_out="cpp" --grpc_out="cpp" --plugin=protoc-gen-grpc=$(which grpc_cpp_plugin) "$proto_file"
trpc create  -l cpp  --protofile=./proto/paipan.proto --output="./paipan" --validate=true --alias -f


