#include "ExeptionHandler.h"
ExeptionHandler::ExeptionHandler(const char* ErrorMessage) {
	this->ErrorMessage = ErrorMessage;
};
const char* ExeptionHandler::what() const noexcept {
	std::cout << this->ErrorMessage << std::endl;
	return this->ErrorMessage;
};
