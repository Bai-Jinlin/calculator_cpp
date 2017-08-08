#include "cal_expr.h"
#include "cal_number.h"

double cal_expr::getValue()
{
	if (cal == true) return _data;
	auto begin = _tokenList.begin();
	while (begin != _tokenList.end())
	{
		if ((*begin)->getType() == OPER_Type::DIV)
		{
			(*(begin + 1))->setValue((*begin)->getValue() / (*(begin + 1))->getValue());
			begin = _tokenList.erase(begin);
		}
		else if ((*begin)->getType() == OPER_Type::MUL)
		{
			(*(begin + 1))->setValue((*begin)->getValue() * (*(begin + 1))->getValue());
			begin = _tokenList.erase(begin);
		}
		else
			++begin;
	}
	begin = _tokenList.begin();
	while (begin != _tokenList.end())
	{
		if ((*begin)->getType() == OPER_Type::ADD)
		{
			(*(begin + 1))->setValue((*begin)->getValue() + (*(begin + 1))->getValue());
			begin = _tokenList.erase(begin);
		}
		else if ((*begin)->getType() == OPER_Type::SUB)
		{
			(*(begin + 1))->setValue((*begin)->getValue() - (*(begin + 1))->getValue());
			begin = _tokenList.erase(begin);
		}
		else
			++begin;
	}
	_data = _tokenList[0]->getValue();
	_tokenList.clear();
	cal = true;
	return	_data;
}

cal_expr::cal_expr(std::string expr, char OP) :cal_number(double(), ((OPER_Type)OP)), _expr('(' + expr + ')')
{
	p = _expr.c_str();
	++p;
	do
	{
		_tokenList.push_back(ct());
	} while (*p++ != ')');
}

std::shared_ptr<cal_number> cal_expr::ct()
{
	std::string number;

	if (*p >= '0' && *p <= '9')
	{
		while (*p >= '0' && *p <= '9')
		{
			number += *p++;
		}
		return std::make_shared<cal_number>(std::stod(number), (OPER_Type)*p);
	}
	if (*p == '(')
	{
		auto temp = p;
		while (*p != ')') ++p;
		return std::make_shared<cal_expr>(std::string(temp + 1, p), *(++p));
	}
}