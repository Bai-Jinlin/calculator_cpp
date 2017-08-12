#pragma once
class cal_number
{
public:
	enum OPER_Type { ADD = '+', SUB = '-', DIV = '/', MUL = '*', END = ')', NUL = ' ' };
	virtual	double getValue() { return _data; };
	OPER_Type getType() { return _op; };
	virtual	void setValue(double data) { _data = data; };
	cal_number(double data, OPER_Type op) :_data(data), _op(op) {};
protected:
	double _data;
	OPER_Type _op;
};
