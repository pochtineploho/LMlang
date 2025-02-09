cmake_minimum_required(VERSION 3.15)

project(MyANTLRProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

find_package(BDWgc 8.2.0 REQUIRED PATHS "C:\\Users\\Home\\Documents\\bdwgc-install\\")

find_package(LLVM REQUIRED CONFIG PATHS "C:\\Users\\Home\\Documents\\clang+llvm-19.1.0-x86_64-pc-windows-msvc\\")

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/lib)

link_directories(${CMAKE_SOURCE_DIR}/lib)


llvm_map_components_to_libnames(
        llvm_libs
        support
        core
        mcjit
        x86codegen
        x86desc
        x86info
        x86asmparser
        executionengine
        orcjit
        native
        nativecodegen)


set(SOURCES
        vm/vm.cpp
        main.cpp
        codeRunner/CodeRunner.cpp
        Mapper/mapper.cpp
        bytecodeGenerator/bytecode.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES})


include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE BDWgc::gc)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})