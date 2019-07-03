#include "ExceptionHandler.h"
ExceptionHandler::ExceptionHandler(const char* ErrorMessage) {
	this->ErrorMessage_ = ErrorMessage;
};
const char* ExceptionHandler::what() const noexcept {
	std::cout << this->ErrorMessage_ << std::endl;
	return this->ErrorMessage_;
};
