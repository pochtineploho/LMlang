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
        grammar/ASTNode.h
        grammar/ASTBuilder.h
        grammar/ASTBuilder.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

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
#if (antlr4-runtime_FOUND)
#    target_include_directories(${PROJECT_NAME} PRIVATE ${antlr4-runtime_INCLUDE_DIRS})
#    target_link_libraries(${PROJECT_NAME} PRIVATE ${antlr4-runtime_LIBRARIES})
#else()
#    message(FATAL_ERROR "Antlr4 runtime package not found!")
#endif()


#target_include_directories(${PROJECT_NAME} PRIVATE "D:/1_5sem/PISVJAP/antlr4/install/include/antlr4-runtime")

target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime)
#target_link_libraries(${PROJECT_NAME} PRIVATE "D:/1_5sem/PISVJAP/antlr4/install/lib/antlr4-runtime.lib")
target_link_libraries(${PROJECT_NAME} PRIVATE BDWgc::gc)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})
