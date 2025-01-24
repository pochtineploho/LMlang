//
// Created by admin on 18.01.2025.
//

#pragma once

#ifndef MYANTLRPROJECT_BYTECODEGENER_H
#define MYANTLRPROJECT_BYTECODEGENER_H

#endif //MYANTLRPROJECT_BYTECODEGENER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <iostream>
#include <algorithm>

#include "bytecode.h"

class byteCodeGener { ///TODO: возможно не хватает функции для генерации массивов
    // Простой поток байткода
    std::vector<uint8_t> BytecodeStream;

// Таблица строк для строковых значений
    std::unordered_map<std::string, int> StringTable;

    std::unordered_map<int, std::vector<int>> ArrayTable; // Array table for managing arrays
    int NextArrayID = 0; // Incremental array ID

public:
// Добавить байт в поток байткода
    void EmitBytecode(uint8_t opcode) {
        BytecodeStream.push_back(opcode);
    }

// Добавить целое значение в поток байткода
    void EmitInt(int value) {
        uint8_t *bytes = reinterpret_cast<uint8_t*>(&value);
        BytecodeStream.insert(BytecodeStream.end(), bytes, bytes + sizeof(int));
    }

// Добавить число с плавающей точкой в поток байткода
    void EmitDouble(double value) {
        uint8_t *bytes = reinterpret_cast<uint8_t*>(&value);
        BytecodeStream.insert(BytecodeStream.end(), bytes, bytes + sizeof(double));
    }

// Добавить строку в таблицу строк и сохранить её индекс
    void EmitString(const std::string &value) {
        if (StringTable.find(value) == StringTable.end()) {
            StringTable[value] = StringTable.size();
        }
        EmitInt(StringTable[value]); // В поток добавляется индекс строки
    }

// Добавить булевое значение
    void EmitBool(bool value) {
        BytecodeStream.push_back(value ? 1 : 0);
    }

    // Emit a character
    void EmitChar(char value) {
        BytecodeStream.push_back(static_cast<uint8_t>(value));
    }

// Emit array creation (for integers)
    int EmitArray(const std::vector<int> &arrayElements) {
        int arrayID = NextArrayID++;
        ArrayTable[arrayID] = arrayElements; // Store array in the table
        EmitBytecode(static_cast<uint8_t>(Bytecode::CreateArray));
        EmitInt(arrayID); // Push array ID to bytecode
        return arrayID; // Return ID for reference
    }

    // Emit array creation (for doubles)
    int EmitArray(const std::vector<double> &arrayElements) {
        int arrayID = NextArrayID++;
        std::vector<int> converted(arrayElements.size());
        std::transform(arrayElements.begin(), arrayElements.end(), converted.begin(),
                       [](double val) { return static_cast<int>(val); }); // Convert doubles to ints for simplicity
        ArrayTable[arrayID] = converted;
        EmitBytecode(static_cast<uint8_t>(Bytecode::CreateArray));
        EmitInt(arrayID);
        return arrayID;
    }

    // Emit array creation (for strings)
    int EmitArray(const std::vector<std::string> &arrayElements) {
        int arrayID = NextArrayID++;
        std::vector<int> stringIDs;
        for (const auto &str : arrayElements) {
            if (StringTable.find(str) == StringTable.end()) {
                StringTable[str] = StringTable.size();
            }
            stringIDs.push_back(StringTable[str]);
        }
        ArrayTable[arrayID] = stringIDs;
        EmitBytecode(static_cast<uint8_t>(Bytecode::CreateArray));
        EmitInt(arrayID);
        return arrayID;
    }

    // Retrieve the array table for VM
    const std::unordered_map<int, std::vector<int>> &GetArrayTable() const {
        return ArrayTable;
    }

    const std::unordered_map<std::string, int> &GetStringTable() const {
        return StringTable;
    }

// Резервировать место для перехода
    int ReserveJump() {
        int position = CurrentBytecodePosition();
        EmitInt(0); // Зарезервировать 4 байта для адреса
        return position;
    }

// Исправить переход на указанную позицию
    void FixJump(int position) {
        int jumpAddress = CurrentBytecodePosition();
        uint8_t *bytes = reinterpret_cast<uint8_t*>(&jumpAddress);
        for (size_t i = 0; i < sizeof(int); ++i) {
            BytecodeStream[position + i] = bytes[i];
        }
    }

    void EmitJump(int position){
        BytecodeStream.push_back(static_cast<uint8_t>(Bytecode::Jump));
        EmitInt(position);
    }

    void EmitFunctionStart(const std::string &functionName) {
        EmitBytecode(static_cast<uint8_t>(Bytecode::Call));           // Emit the `Call` opcode to indicate a function
        EmitString(functionName);         // Emit the function name
    }

    void EmitVariableDeclaration(const std::string &varName, const std::string &varType) {
        EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));       // Emit the `StoreVar` opcode for variable storage
        EmitString(varName);              // Emit the variable name
        EmitString(varType);              // Emit the variable type (useful for type-checking or optimization)
    }

    void EmitFunctionEnd() {
        EmitBytecode(static_cast<uint8_t>(Bytecode::Return)); // Emit the `Return` opcode
    }

    size_t CurrentBytecodePosition() const{
        return BytecodeStream.size();
    }

    // Retrieve the generated bytecode stream
    const std::vector<uint8_t> &GetBytecodeStream() const { // TODO: Написать оператора, который будет передавать в runtime BytecodeStream в VM
        return BytecodeStream;
    }

    // Debugging: Print bytecode for verification
    void DebugPrint() const {
        for (size_t i = 0; i < CurrentBytecodePosition(); ++i) {
            std::cout << static_cast<int>(BytecodeStream[i]) << " ";
        }
        std::cout << std::endl;
    }
};

