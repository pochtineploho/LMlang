cmake_minimum_required(VERSION 3.15)

project(MyANTLRProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/lib)

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(SOURCES
        main.cpp
        grammar/LMlangGrammarListener.cpp
        grammar/LMlangGrammarParser.cpp
        grammar/LMlangGrammarBaseListener.cpp
        grammar/LMlangGrammarLexer.cpp
        main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} antlr4-runtime)
