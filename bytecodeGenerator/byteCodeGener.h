//
// Created by admin on 18.01.2025.
//

#ifndef MYANTLRPROJECT_BYTECODEGENER_H
#define MYANTLRPROJECT_BYTECODEGENER_H

#endif //MYANTLRPROJECT_BYTECODEGENER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>

// Простой поток байткода
std::vector<uint8_t> BytecodeStream;

// Таблица строк для строковых значений
std::unordered_map<std::string, int> StringTable;

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

// Резервировать место для перехода
int ReserveJump() {
    int position = BytecodeStream.size();
    EmitInt(0); // Зарезервировать 4 байта для адреса
    return position;
}

// Исправить переход на указанную позицию
void FixJump(int position) {
    int jumpAddress = BytecodeStream.size();
    uint8_t *bytes = reinterpret_cast<uint8_t*>(&jumpAddress);
    for (size_t i = 0; i < sizeof(int); ++i) {
        BytecodeStream[position + i] = bytes[i];
    }
}