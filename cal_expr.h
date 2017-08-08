#pragma once
#include "cal_abs.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
class cal_expr :public cal_abs
{
public:
	double getValue() override;
	OPER_Type getType() override { return _op; };
	void setValue(double data) override { result = data; };
	cal_expr(std::string expr, char =' ');
	void print()
	{
		std::for_each(_tokenList.begin(), _tokenList.end(), [&](std::shared_ptr<cal_abs> p) {std::cout << p->getValue() << std::endl; });
	};
private:
	std::shared_ptr<cal_abs> ct();
	bool cal = false;
	OPER_Type _op; 
	double result;
	const char *p;
	std::string _expr;
	std::vector<std::shared_ptr<cal_abs>> _tokenList;
};