#include <stdio.h>
#include <assert.h>
#include <time.h>

//Struct to show hours minutes and seconds
typedef struct hms {
	unsigned int hrs;
	unsigned int mins;
	unsigned int secs;
} hms;

//Shows the h/m/s in bits
void showNBits(int, int);
//Chamges the total seconds to h/m/s
void secToHMS(time_t total_seconds, hms* theTime);

int main(void){
	//Initializing the h/m/s structure
	hms currentTime = {0};
	//Start time initializing
	time_t T0 = time(NULL), dT;
	
	while(1) {
		//Amount of time passed since the start of the program
		dT = time(NULL) - T0;
		//Changes currentTime to the current time passed
		secToHMS(dT, &currentTime);
		//Prints the current time in bits
		showNBits(currentTime.hrs, 5); printf(":");
		showNBits(currentTime.mins, 6); printf(":");
		showNBits(currentTime.secs, 6); printf("\r");
	}
}

void showNBits(int timeVal, int NBits) {
	//Bit mask used to display each bit
	unsigned int bitMask = 0x80000000;
	//Ensures the bits passed are within limits
	assert((NBits <= 32 ) && (NBits >= 0 ));
	//Shifts the bit mask depending on whether we are priting for hours minutes or seconds
	bitMask >>= (32 - NBits);

	//Loops until the bitmask is set to 0
	while(bitMask) {
		//Uses the bitmask and the currentTime value to determine whether the current bit is 1 or 0
		printf((timeVal & bitMask)?"1":"0");
		//Shifts to check the next bit
		bitMask >>= 1;
	}
}

void secToHMS(time_t total_seconds, hms* theTimer) {
	//Sets the h/m/s using the address of the passed time
	theTimer->hrs = total_seconds/3600;
	theTimer->mins = total_seconds%3600/60;
	theTimer->secs = total_seconds%60;
}
