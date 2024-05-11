#pragma once
#include <memory>
#include <string>
class BaseAST {
public:
    virtual ~BaseAST() = default;
};

class CompUnitAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_def;
};

class FuncDefAST : public  BaseAST {
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;
};

class FuncTypeAST : public BaseAST {
public:
    std::string Int = "int";
};

class BlockAST : public BaseAST {
public:
    std::unique_ptr<BaseAST> stmt;
};

class StmtAST : public BaseAST {
public:
//    std::string keywords;
    std::unique_ptr<BaseAST> number;
};

class NumberAST : public BaseAST {
public:
    int int_const;
};