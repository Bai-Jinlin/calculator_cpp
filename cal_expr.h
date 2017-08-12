#pragma once
#include "cal_number.h"
#include <memory>
#include <vector>
#include <string>
class cal_expr :public cal_number
{
public:
	double getValue() override;
	//OPER_Type getType() override { return _op; };
	void setValue(double data) override { _data = data; };
	cal_expr(std::string expr, char =' ');
private:
	std::shared_ptr<cal_number> ct();
	bool cal = false;
	const char *p;
	std::string _expr;
	std::vector<std::shared_ptr<cal_number>> _tokenList;
};