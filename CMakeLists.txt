cmake_minimum_required(VERSION 3.15)

project(MyANTLRProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_library(GC_LIB
        NAMES gc bdwgc GC
        PATHS "D:\\1_5sem\\ПиСВЯП\\LMLang\\LMlang\\lib\\boehmGC\\bdwgc")

include_directories(${CMAKE_SOURCE_DIR}/lib)

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(SOURCES
        grammar/LMlangGrammarListener.cpp
        grammar/LMlangGrammarParser.cpp
        grammar/LMlangGrammarBaseListener.cpp
        grammar/LMlangGrammarLexer.cpp
        AST_Vlad_version/AST.cpp
        bytecodeGenerator/byteCodeGener.cpp
        gcMemoryManager/gcMemoryManager.cpp
        vm/vm.cpp
        main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE ${GC_LIB} antlr4-runtime)

find_package(LLVM REQUIRED CONFIG PATHS "")

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} ${llvm_libs})
