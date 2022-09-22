#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	// Initialize GPIO before use
	if(gpioInitialise() < 0) {
		fprintf(stderr, "GPIO initialization failed!\n");
		return EXIT_FAILURE;
	}

	gpioSetMode(17, PI_OUTPUT);
	for(int i = 0; i < 20; ++i) {
		gpioWrite(17, 1);
		sleep(1);
		gpioWrite(17, 0);
		sleep(1);
	}

	// Terminate GPIO when ending
	gpioTerminate();
}
