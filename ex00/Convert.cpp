#include "Convert.hpp"

ScalarConverter::ScalarConverter() : flag_("None"), num_(0), numcnt_(0) {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) {
	this->flag_ = cpy.flag_;
	this->num_ = cpy.num_;
	this->numcnt_ = cpy.numcnt_;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy) {
	if (this == &cpy)
		return *this;
	this->flag_ = cpy.flag_;
	this->num_ = cpy.num_;
	this->numcnt_ = cpy.numcnt_;
	return (*this);
}

void ScalarConverter::convert(std::string param) {
	std::stringstream	ss(param);
	double				num;
	ss >> num;

	this->setNum(num);
	printChar();
	printInt();
	printFloat(param);
	printDouble(param);
}

std::string ScalarConverter::getFlag() {
	return this->flag_;
}

double	ScalarConverter::getNum() {
	return this->num_;
}

int	ScalarConverter::getNumcnt() {
	return this->numcnt_;
}


void	ScalarConverter::setFlag(std::string flag) {
	this->flag_ = flag;
}

void	ScalarConverter::setNum(double num) {
	this->num_ = num;
}

void	ScalarConverter::setNumcnt(int num_cnt) {
	this->numcnt_ = num_cnt;
}


void	ScalarConverter::printChar() {
	std::cout << "char: ";
	if ((num_ >= 0 && num_ <= 32) && flag_ == "None")
		std::cout << "Non displayable" << std::endl;
	else if (num_ >= 32 && num_ <= 126)
		std::cout << "\'" << (char)num_ << "\'" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::printInt() {
	std::cout << "int: ";
	if ((num_ >= -2147483648 && num_ <= 2147483647) && flag_ == "None")
		std::cout << (int)num_ << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::printFloat(std::string param) {
	std::cout << "float: ";
	if (flag_ == "nan")
		std::cout << "nanf" << std::endl;
	else if (flag_ == "+inf")
		std::cout << "+inff" << std::endl;
	else if (flag_ == "-inf")
		std::cout << "-inff" << std::endl;
	else if (param.find('.') == std::string::npos && numcnt_ <= 6)
		std::cout << (float)num_ << ".0f" << std::endl;
	else if (param.back() == '0' && param[param.length() - 2] == '.' && numcnt_ <= 6)
		std::cout << (float)num_ << ".0f" << std::endl;
	else
		std::cout << (float)num_ << "f" << std::endl;
}

void	ScalarConverter::printDouble(std::string param) {
	std::cout << "Double: ";
	if (flag_ == "nan")
		std::cout << "nan" << std::endl;
	else if (flag_ == "+inf")
		std::cout << "+inf" << std::endl;
	else if (flag_ == "-inf")
		std::cout << "-inf" << std::endl;
	else if (param.find('.') == std::string::npos && numcnt_ <= 6)
		std::cout << (float)num_ << ".0" << std::endl;
	else if (param.back() == '0' && param[param.length() - 2] == '.' && numcnt_ <= 6)
		std::cout << (float)num_ << ".0" << std::endl;
	else
		std::cout << (float)num_ << std::endl;
}