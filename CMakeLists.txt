cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------拉取trpc-cpp框架------------------------------
include(FetchContent)
FetchContent_Declare(
        trpc-cpp
        GIT_REPOSITORY    git@github.com:trpc-group/trpc-cpp.git
        GIT_TAG           main
        SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/trpc-cpp
)
FetchContent_MakeAvailable(trpc-cpp)

# -----------------------------拉取libsxwnl------------------------------
FetchContent_Declare(
        libsxwnl
        GIT_REPOSITORY    git@github.com:tiandirenwx/libsxwnl.git
        GIT_TAG           main
        SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/libsxwnl
)
FetchContent_MakeAvailable(libsxwnl)

project(paipan)

# 添加子目录
add_subdirectory(paipan)