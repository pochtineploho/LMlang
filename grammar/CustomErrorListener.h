//
// Created by admin on 24.01.2025.
//

#ifndef MYANTLRPROJECT_CUSTOMERRORLISTENER_H
#define MYANTLRPROJECT_CUSTOMERRORLISTENER_H

#endif //MYANTLRPROJECT_CUSTOMERRORLISTENER_H

#include "antlr4-runtime.h"


class CustomErrorListener: public antlr4::BaseErrorListener {
public:
    virtual void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line,
                             size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override;
};