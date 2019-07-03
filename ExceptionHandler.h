#pragma once
#include <string>
#include <iostream>
#include <exception>
class ExceptionHandler final :public std::exception
{
private:
	const char* ErrorMessage_;
public:
	const char* what() const noexcept override;
	explicit ExceptionHandler(const char* ErrorMessage);
};

