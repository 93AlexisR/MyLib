#ifndef PRESSBUTTON_HPP
#define PRESSBUTTON_HPP


// https://msdn.microsoft.com/en-us/library/windows/desktop/ms646293%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396
//is key pressed

//virtualKey codes
//https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx


class ButtonPress {
private:
	unsigned int myKey;
	unsigned int pulseDuration;

protected:
	ButtonPress& pressEvent(bool pressTypeFlag);
	ButtonPress& setKey(unsigned int newKey);
	unsigned int getKey(void) { return myKey; }
	unsigned int fetchKey(void);



public:
    ButtonPress ( void );
    ButtonPress ( unsigned int );

	ButtonPress& calibrateNewKey(void);

	ButtonPress& fullPress(unsigned int tempDuration); // milliseconds
	ButtonPress& fullPress(void);
};

#endif
