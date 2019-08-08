//Irad Nuriel 324220458
#ifndef _SUBSTITUTIONCIPHER_H_
#define _SUBSTITUTIONCIPHER_H_
#define NUM_OF_CHARS_IN_ENGLISH 26
#define DEFAULT_CODED_ABC "rovpxdncwesmbzijtauqhkfylg"
#include <string>
#include <iostream>



class SubstitutionCipher {
private:
	int findLetter(char* abc, char letter);
	std::string changeMsg(const std::string& msg, bool type);
protected:
	char* originalABC;
	char* codedABC;
	void initOrigenal();
	void initCode(const std::string& code);
	void distractAll();
public:
	SubstitutionCipher();
	SubstitutionCipher(std::string key);
	SubstitutionCipher(const SubstitutionCipher& other);
	virtual ~SubstitutionCipher();
	const SubstitutionCipher& operator=(const SubstitutionCipher& other);
	std::string encrypt(const std::string& msg);
	std::string decrypt(const std::string& encryptedMsg);
};





#endif // !_CIPHER_H_
