//Irad Nuriel 324220458
#include <string>
#include <iostream>
#include "SubstitutionCipher.h"


int SubstitutionCipher::findLetter(char* abc, char letter) {
	//function for finding the index of a character inside an arrray of characters
	for (int i = 0; abc[i] != 0; i++) {
		if (abc[i] == letter) {
			return i;
		}
	}
	return -1;
}


//function for both encrypting and decrypting message, if type = true encrypting and if type = false decrypting
std::string SubstitutionCipher::changeMsg(const std::string& msg, bool type) {
	std::string changedMsg = "";
	for ( unsigned int i = 0; i < msg.length(); i++) {
		if (msg[i] > 'z' || msg[i] < 'a') {
			//if not a small letter, just coping it
			changedMsg.push_back(msg[i]);
		}
		else {
			//if a small letter, encrypt her and put her in the retured message
			char changedChar;
			if (type) {
				changedChar = this->codedABC[this->findLetter(this->originalABC, msg[i])];
			}
			else {
				changedChar = this->originalABC[this->findLetter(this->codedABC, msg[i])];
			}
			changedMsg.push_back(changedChar);
		}
	}
	return changedMsg;
}


void SubstitutionCipher::initOrigenal() {
	//function for initialize the original abc
	this->originalABC = new char[NUM_OF_CHARS_IN_ENGLISH];
	for (int i = 0; i < NUM_OF_CHARS_IN_ENGLISH; i++) {
		this->originalABC[i] = i + 'a';
	}
}


void SubstitutionCipher::initCode(const std::string& code) {
	//function for initialize the encryption abc
	this->codedABC = new char[NUM_OF_CHARS_IN_ENGLISH];
	for (int i = 0; i < NUM_OF_CHARS_IN_ENGLISH; i++) {
		this->codedABC[i] = code[i];
	}
}



void SubstitutionCipher::distractAll() {
	//method for delete all the arrays in the object
	delete[] this->codedABC;
	delete[] this->originalABC;
}


//constructors:
SubstitutionCipher::SubstitutionCipher() {
	//default c'tor
	this->initOrigenal();
	this->initCode(DEFAULT_CODED_ABC);
}


SubstitutionCipher::SubstitutionCipher(std::string key) {
	//regular c'tor
	this->initOrigenal();
	this->initCode(key);
}


//big three:
SubstitutionCipher::SubstitutionCipher(const SubstitutionCipher & other) {
	//copy c'tor
	this->initOrigenal();
	this->initCode(other.codedABC);
}


SubstitutionCipher::~SubstitutionCipher() {
	//d'tor
	this->distractAll();
}


const SubstitutionCipher& SubstitutionCipher::operator=(const SubstitutionCipher & other) {
	//assignment operator:
	if (this != &other) {
		this->distractAll();
		this->initOrigenal();
		this->initCode(other.codedABC);
	}
	return *this;
}


std::string SubstitutionCipher::encrypt(const std::string & msg) {
	//encrypting function-simply call to the mutual function that both encrypt and decrypt
	return changeMsg(msg, true);
}


std::string SubstitutionCipher::decrypt(const std::string & msg) {
	//decrypting function-simply call to the mutual function that both encrypt and decrypt
	return changeMsg(msg, false);
}