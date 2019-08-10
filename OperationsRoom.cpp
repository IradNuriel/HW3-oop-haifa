//Irad Nuriel 324220458
#include <string>
#include <iostream>
#include "SubstitutionCipher.h"
#include "ShiftCipher.h"
#include "OperationsRoom.h"

OperationsRoom::OperationsRoom() {
	this->numMasseges = 0;
	this->melicious = false;
	this->decryptors = new SubstitutionCipher*[NUM_METHODS_IN_CYCLE];
	//the only place I will ever use switch case!!!
	for (int i = 0; i < NUM_METHODS_IN_CYCLE; i++) {
		switch (i) {
		case 1:
			this->decryptors[i] = new ShiftCipher<FIRST_SHIFT_LENGTH>();
			break;
		case 3:
			this->decryptors[i] = new ShiftCipher<SECOND_SHIFT_LENGTH>();
			break;
		case 5:
			this->decryptors[i] = new ShiftCipher<THIRD_SHIFT_LENGTH>();
			break;
		default:
			this->decryptors[i] = new SubstitutionCipher();
		}
	}
}

void OperationsRoom::initByOther(const OperationsRoom& other) {
	//function for initialize the object by another object.
	this->melicious = other.melicious;
	this->numMasseges = other.numMasseges;
	this->decryptors = new SubstitutionCipher*[NUM_METHODS_IN_CYCLE];
	for (int i = 0; i < NUM_METHODS_IN_CYCLE; i++) {
		this->decryptors[i] = new SubstitutionCipher(*other.decryptors[i]);
	}
}

void OperationsRoom::distract() {
	//function for deleting the decryptors array.
	for (int i = 0; i < NUM_METHODS_IN_CYCLE; i++) {
		delete this->decryptors[i];
	}
	delete[] this->decryptors;
}

//the big three:

OperationsRoom::OperationsRoom(const OperationsRoom& other) {
	//copy c'tor
	this->initByOther(other);
}

const OperationsRoom& OperationsRoom::operator=(const OperationsRoom& other){
	//assignment operator
	if (this != &other) {
		this->distract();
		this->initByOther(other);
	}
	return *this;
}
OperationsRoom::~OperationsRoom() {
	//distractor
	this->distract();
}


//getMsg function
void OperationsRoom::getMsg(std::string encryptedMsg) {
	std::string decryptedMsg;
	int method = (this->numMasseges / MAX_MSGS_NUMBER) % NUM_METHODS_IN_CYCLE;//getting the method number we need to use
	decryptedMsg = this->decryptors[method]->decrypt(encryptedMsg);
	this->melicious = this->melicious || (decryptedMsg.find(MALICIOUSE_WORD)) != std::string::npos;
	this->numMasseges++;
	std::cout << "A new message has been received."<<std::endl;
	if (this->numMasseges%MAX_MSGS_NUMBER == 0 && (this->numMasseges/MAX_MSGS_NUMBER)%NUM_METHODS_IN_CYCLE == 0) {
		this->numMasseges = 0;
	}
	if (this->numMasseges%MAX_MSGS_NUMBER == 0) {
		if (this->melicious) {
			std::cout << "Maliciouse detected!" << std::endl;
		}
		else {
			std::cout << "Maliciouse wasn't detected!" << std::endl;
		}
		this->melicious = false;
	}
}