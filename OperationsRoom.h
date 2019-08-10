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
	//decryptors:
	SubstitutionCipher** decryptors;
	void initByOther(const OperationsRoom& other);
	void distract();
public:
	OperationsRoom();
	OperationsRoom(const OperationsRoom& other);
	const OperationsRoom& operator=(const OperationsRoom& other);
	~OperationsRoom();
	void getMsg(std::string encryptedMsg);
};
#endif // !OPERATIONSROOM_H_