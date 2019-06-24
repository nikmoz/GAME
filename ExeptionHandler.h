#pragma once
#include <string>
#include <iostream>
#include <exception>
class ExeptionHandler :public std::exception
{
private:
	const char* ErrorMessage;
public:
	const char* what() const noexcept override;
	explicit ExeptionHandler(const char* ErrorMessage);
};

