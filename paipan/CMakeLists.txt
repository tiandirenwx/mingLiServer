cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(./cmake/common.cmake)


#---------------------------------------------------------------------------------------
# Compile project
#---------------------------------------------------------------------------------------
project(paipan_proj)

# compile proto
set(PB_SRC ${CMAKE_SOURCE_DIR}/proto/paipan.proto)

COMPILE_PROTO(OUT_PB_SRCS "${PB_SRC}" ${PB_PROTOC} ${CMAKE_SOURCE_DIR})

TRPC_COMPILE_PROTO(OUT_TRPC_PB_SRCS "${PB_SRC}" ${PB_PROTOC} ${TRPC_CPP_PLUGIN} ${CMAKE_SOURCE_DIR})


# compile server
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/server/*.cc)
add_executable(paipan_server ${SRC_FILES} ${OUT_PB_SRCS} ${OUT_TRPC_PB_SRCS})
target_include_directories(paipan_server PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(paipan_server trpc)

# compile client
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/client/fiber_client.cc)
add_executable(paipan_fiber_client ${SRC_FILES} ${OUT_PB_SRCS} ${OUT_TRPC_PB_SRCS})
target_include_directories(paipan_fiber_client PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(paipan_fiber_client trpc)


file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/client/future_client.cc)
add_executable(paipan_future_client ${SRC_FILES} ${OUT_PB_SRCS} ${OUT_TRPC_PB_SRCS})
target_include_directories(paipan_future_client PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(paipan_future_client trpc)
