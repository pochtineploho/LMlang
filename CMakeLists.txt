cmake_minimum_required(VERSION 3.15)

project(MyANTLRProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Найти пакет BDWgc
find_package(BDWgc 8.2.0 REQUIRED PATHS "/home/alex/Документы/bdwgcinstall")

include_directories(${CMAKE_SOURCE_DIR}/lib)

# Указать директории для поиска библиотек
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

# Указать директории включения и библиотеки для BDWgc
target_link_libraries(${PROJECT_NAME} PRIVATE BDWgc::gc)

# Найти пакет LLVM
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Указать директории включения и библиотеки для LLVM
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Найти компоненты LLVM и связать их с проектом
llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})

# Указать директории включения и библиотеки для ANTLR4
find_library(ANTLR4_LIBRARY NAMES antlr4-runtime)
target_include_directories(${PROJECT_NAME} PRIVATE /usr/include/antlr4-runtime)
target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIBRARY})
