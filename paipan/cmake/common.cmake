cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 'TRPC_ROOT_PATH' is the src director of trpc-cpp. You must specify it correctly.
set(TRPC_ROOT_PATH ${CMAKE_SOURCE_DIR}/3rd_party/trpc-cpp/)

# 2. load config(hdrs/libs paths) and utils(tools for generating stub code)
include(${TRPC_ROOT_PATH}/cmake/config/trpc_config.cmake)
include(${TRPC_ROOT_PATH}/cmake/tools/trpc_utils.cmake)

# 3. add hdrs and libs paths to cmake build system
include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})

# 4. set current project dependency libs(trpc and other libs(protobuf/yaml-cpp/pthread/...etc))
set(LIBRARY trpc ${LIBS_BASIC})

# 5. Set the paths of protoc and trpc_cpp_plugin which will be generated at ${TRPC_ROOT_PATH}/build/bin
set(PB_PROTOC protoc)
set(TRPC_CPP_PLUGIN ${TRPC_TO_CPP_PLUGIN})