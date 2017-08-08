#pragma once
#include <string>
#include <utility>
class cal_abs
{
public:
	enum OPER_Type { ADD = '+', SUB = '-', DIV = '/', MUL = '*', END = ')' ,NUL=' '};
	virtual double getValue() = 0;
	virtual void setValue(double) = 0;
	virtual OPER_Type getType() = 0;
};
