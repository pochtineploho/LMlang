Кратко:--------------------------------------------------------------------------------

AST - структура AST и встроенная генерация байткода 

byteCodeGener - функции для генерации bytecodeStream для работы в runtime

VM - содержит в себе несколько таблиц:

String Function и Array(в прогрессе) для хранения соотв данных

JITCompile - функция для компиляции куска кода с горячим циклом

GC - автоматический GC на базе boehmGC(прописано в gcMemoryManager.h)

Vaule - стек хранит значения этого типа и взаимодействует с ними

Туториал по установке либ:-------------------------------------------------------

Вне проекта создаёте папку(и) для них:

Example:

D:\1_5sem\PISVJAP\LMLang\LMlang - адрес проекта

D://1_5sem//PISVJAP//boehmGC// - папка для бинарей

D://1_5sem//PISVJAP//LLVM// - папка для бинарей

LLVM:--------------------------------------------------------------------------------- 

https://github.com/llvm/llvm-project/releases/tag/llvmorg-19.1.0

Качаете: clang+llvm-19.1.0-x86_64-pc-windows-msvc.tar.xz

Распаковываете в соответствующей папке, подвязываете в CmakeLists.txt локально:

find_package(LLVM REQUIRED CONFIG PATHS "D:\\1_5sem\\PISVJAP\\LLVM\\clang+llvm-19.1.0-x86_64-pc-windows-msvc\\")

LibatomicOps:----------------------------------------------------------------------------- 

git clone https://github.com/ivmai/libatomic_ops.git

cd libatomic_ops

mkdir build && cd build

cmake ..

cmake --build .

cmake -DCMAKE_INSTALL_PREFIX=D:/path/to/install/libatomic .. - это папка для бинарей

cmake --build . --target install

Bdwgc:-----------------------------------------------------------------------------------------

git clone https://github.com/ivmai/bdwgc.git

cd bdwgc

mkdir build && cd build

cmake -DCMAKE_PREFIX_PATH=D:/path/to/install/libatomic .. - это папка для бинарей libatomic

cmake --build .

cmake -DCMAKE_INSTALL_PREFIX=D:/path/to/install/bdwgc

cmake --build . --target install

Подвязываете в CmakeLists:

find_package(BDWgc 8.2.0 REQUIRED PATHS "D://1_5sem//PISVJAP//boehmGC//bdwgcInstall") - это как раз D:/path/to/install/bdwgc

P.S.---------------------------------------------------------------------------------------------

Внимательно смотрите на пути установки и генерации бинарей! Если что-то будет не получаться - зовите.

Если у вас не винда, могут быть проблемы

Удачи!!!