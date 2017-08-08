#pragma once
#include "cal_abs.h"
class cal_number : public cal_abs
{
public:
	double getValue()  override { return _data; };
	OPER_Type getType() override { return _op; };
	void setValue(double data) override { _data = data; };
	cal_number(double data, OPER_Type op) :_data(data), _op(op) {};
private:
	double _data;
	OPER_Type _op;
};
