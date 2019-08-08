//Irad Nuriel 324220458
#ifndef _SHIFTCIPHER_H_
#define _SHIFTCIPHER_H_
#include <string>
#include <iostream>
#include <math.h>
#include "SubstitutionCipher.h"
template <int KEY>
class ShiftCipher :public SubstitutionCipher {
private:
	//function for translating the KEY template into the encrypting ABC
	std::string makeCodeByKey() {
		std::string code = "";
		for (int i = 0; i < NUM_OF_CHARS_IN_ENGLISH; i++) {
			char codeChar = ((i + KEY)%NUM_OF_CHARS_IN_ENGLISH) + 'a';
			code.push_back(codeChar);
		}
		return code;
	}
public:
	//constructors:
	ShiftCipher():SubstitutionCipher(this->makeCodeByKey()) {
	}
	//big three:
	ShiftCipher(const ShiftCipher<KEY>& other):SubstitutionCipher(other.codedABC) {
		//copy c'tor
	}
	const ShiftCipher& operator=(const ShiftCipher<KEY>& other) {
		//assignment operator
		if (this != &other) {
			this->distractAll();
			this->initOrigenal();
			this->initCode(other.codedABC);
		}
		return *this;
	}
	~ShiftCipher() {
		//d'tor
	}
};



#endif // !_SHIFTCIPHER_H_
