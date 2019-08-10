//Irad Nuriel 324220458
#ifndef _OPERATIONSROOM_H_
#define _OPERATIONSROOM_H
#include <string>
#include <iostream>
#include "SubstitutionCipher.h"
#include "ShiftCipher.h"
#define MAX_MSGS_NUMBER 2 
#define FIRST_SHIFT_LENGTH 5 
#define SECOND_SHIFT_LENGTH 10 
#define THIRD_SHIFT_LENGTH 15 
#define MALICIOUSE_WORD "SpongeBob"



#define NUM_METHODS_IN_CYCLE 6

class OperationsRoom {
private:
	int numMasseges;
	bool melicious;
	SubstitutionCipher decryptor1;
	ShiftCipher<FIRST_SHIFT_LENGTH> decryptor2;
	ShiftCipher<SECOND_SHIFT_LENGTH> decryptor3;
	ShiftCipher<THIRD_SHIFT_LENGTH> decryptor4;
public:
	OperationsRoom();
	void getMsg(std::string msg);
};
#endif // !OPERATIONSROOM_H_


