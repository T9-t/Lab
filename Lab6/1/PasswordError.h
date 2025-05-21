#pragma once
#include "string"

using namespace std;

struct PasswordError{

	string message;

	PasswordError(string message) { this->message = message; }
};

struct LengthError: PasswordError{

	LengthError() :PasswordError("LengthError: Password length is less than 9 characters") {};
};

struct RegisterError : PasswordError {

	RegisterError() :PasswordError("RegisterError: The password contains all uppercase and lowercase characters") {};
};

struct DigitError : PasswordError {

	DigitError() :PasswordError("DigitError: There are no numbers in the password") {};
};

struct ForbiddenLetterError : PasswordError {

	ForbiddenLetterError() :PasswordError("ForbiddenLetterError: The password contains symbols that are easy to confuse with each other") {};
};