#include "ButtonPress.hpp"
#include "pch.h"
using namespace std;


ButtonPress::ButtonPress ( void ) : myKey(VK_OEM_3), pulseDuration(200){
   //default key is tilde
}

ButtonPress::ButtonPress(unsigned int newKey){
    setKey(newKey);
}

ButtonPress& ButtonPress::setKey(unsigned int myKey){


    if (myKey >= VK_LBUTTON && myKey <= VK_OEM_CLEAR){
        this->myKey = myKey;
    }

    else{
        throw std::invalid_argument("Key specified is out of bounds");
    }

	return *this;
}


unsigned int ButtonPress::fetchKey( void ){
	for (unsigned int i = 55; i <= 255; i++) {
		if (GetAsyncKeyState(i))
		{
			return i;
		}
	}
	return 257;
}


ButtonPress& ButtonPress::pressEvent(bool pressTypeFlag){

	INPUT keyInput;
	keyInput.type = INPUT_KEYBOARD;

	KEYBDINPUT key;
	key.wVk = myKey;
	key.wScan = ::VkKeyScan(myKey);
	key.dwFlags = 0;
	keyInput.ki = key;
	SendInput(1, &keyInput, sizeof(INPUT));
	if (pressTypeFlag) { //ensures key is de-pressed
		std::this_thread::sleep_for(std::chrono::milliseconds(pulseDuration));
		SendInput(1, &keyInput, sizeof(INPUT));
	}

	return *this;
}

ButtonPress& ButtonPress::fullPress(void) {
	fullPress(pulseDuration);
	return *this;
}

ButtonPress& ButtonPress::fullPress(unsigned int tempDuration) {
	if (tempDuration == this->pulseDuration) {
		pressEvent(true);
	}
	else {
		unsigned int tempValue = this->pulseDuration;
		this->pulseDuration = tempDuration;
		pressEvent(true);
	}
	return *this;
}

ButtonPress& ButtonPress::calibrateNewKey(void)
{
	myKey = 299;
	do{
		cout << "myKey = " << myKey << endl;
		myKey = fetchKey();
	} while (myKey < VK_OEM_CLEAR);
	
	return *this;
}