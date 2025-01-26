cmake_minimum_required(VERSION 3.15)

project(MyANTLRProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(BDWgc 8.2.0 REQUIRED PATHS "D:/1_5sem/PISVJAP/boehmGC/bdwgcInstall")

find_package(antlr4-runtime REQUIRED CONFIG PATHS "D:/1_5sem/PISVJAP/antlr4/install/")
find_package(LLVM REQUIRED CONFIG PATHS "D:/1_5sem/PISVJAP/LLVM/clang+llvm-19.1.0-x86_64-pc-windows-msvc/")

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories("D:/1_5sem/PISVJAP/antlr4/install/include/antlr4-runtime")
include_directories("D:/1_5sem/PISVJAP/antlr4/install/include/")
include_directories("D:/1_5sem/PISVJAP/antlr4/install/lib")

link_directories("D:/1_5sem/PISVJAP/antlr4/install/include/antlr4-runtime")
link_directories("D:/1_5sem/PISVJAP/antlr4/install/lib")

link_directories(${CMAKE_SOURCE_DIR}/lib)


llvm_map_components_to_libnames(
        llvm_libs
        support
        core
        mcjit
        x86codegen
        x86desc
        x86info
        x86asmparser)

set(SOURCES
        gcMemoryManager/gcMemoryManager.cpp
        vm/vm.h
        vm/vm.cpp
        main.cpp
        grammar/ASTNode.cpp
        grammar/ASTBuilder.cpp
        codeRunner/CodeRunner.h
)

add_executable(${PROJECT_NAME} ${SOURCES})



include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})




target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime)
target_link_libraries(${PROJECT_NAME} PRIVATE BDWgc::gc)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})