#include <iostream>
#include <string>
using namespace std;

// Method to encrypt by Caesar shift cipher.  Takes a string to encrypt and the amount of letters to shift
string encryptCaesar(string message, int key) {
	string encryptedString = "";
	if (key < 0) {
		cout << "Invalid shift key. Enter an integer from 0 to 26";
		return "";
	}

	for (int i = 0; i < message.length(); i++) {
		if (message[i] == ' ')
			encryptedString += ' ';
		else if (islower(message[i])) { 
			/*97 is the ASCII value for a lowercase a.  This gets the number into the 0 to 26 range
			and then shifts it.  If, after the shift, the value becomes larger than 26, it will mod 26 to get back
			to the beginning of the alphabet.  Then it adds 97 back to get the lowercase letter.
			*/
			encryptedString += (((message[i] - 97 + key) % 26) + 97);
		}
		else {
			//This does the same thing except for capital letters.  The ASCII value for a capital A is 65
			encryptedString += (((message[i] - 65 + key) % 26) + 65);
		}
	}
	return encryptedString;
}

int main() {
	string message;
	int shift;

	cout << "Enter a message to encrypt:" << endl;
	getline(cin, message);
	cout << "Enter the shift index:" << endl;
	cin >> shift;

	cout << encryptCaesar(message, shift) << endl;

	return 0;
}