#include "ExceptionHandler.h"
ExceptionHandler::ExceptionHandler(const char* ErrorMessage) {
	this->ErrorMessage = ErrorMessage;
};
const char* ExceptionHandler::what() const noexcept {
	std::cout << this->ErrorMessage << std::endl;
	return this->ErrorMessage;
};
