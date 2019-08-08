//Irad Nuriel 324220458
#include <string>
#include <iostream>
#include "SubstitutionCipher.h"
#include "ShiftCipher.h"
#include "OperationsRoom.h"

OperationsRoom::OperationsRoom() {
	this->numMasseges = 0;
	this->melicious = false;
}

OperationsRoom::~OperationsRoom() {
}

void OperationsRoom::getMsg(std::string msg) {
	std::string decryptedMsg;
	int method = (this->numMasseges / MAX_MSGS_NUMBER) % NUM_METHODS_IN_CYCLE;//method=the decrypt method that you need to use to decrypt in this message
	//the only time I ever used switch case.
	switch (method) {
	case 1:
		//decrypt with decryptor2
		decryptedMsg = this->decryptor2.decrypt(msg);
		//find if malicious
		this->melicious = this->melicious || (decryptedMsg.find(MALICIOUSE_WORD) != std::string::npos);
		break;
	case 3:
		//decrypt with decryptor3
		decryptedMsg = this->decryptor3.decrypt(msg);
		//find if malicious
		this->melicious = this->melicious || (decryptedMsg.find(MALICIOUSE_WORD) != std::string::npos);
		break;
	case 5:
		//decrypt with decryptor4
		decryptedMsg = this->decryptor4.decrypt(msg);
		//find if malicious
		this->melicious = this->melicious || (decryptedMsg.find(MALICIOUSE_WORD) != std::string::npos);
		break;
	default:
		//decrypt with decryptor1
		decryptedMsg = this->decryptor1.decrypt(msg);
		//find if malicious
		this->melicious = this->melicious || (decryptedMsg.find(MALICIOUSE_WORD) != std::string::npos);
		break;
	}
	//one more message
	this->numMasseges++;
	std::cout << "A new message has been received."<<std::endl;
	//is the cycle ended?
	if (this->numMasseges%MAX_MSGS_NUMBER == 0 && this->numMasseges%NUM_METHODS_IN_CYCLE == 0) {
		this->numMasseges == 0;
	}
	//do we need to change decrypt method?
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
