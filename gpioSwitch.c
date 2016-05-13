#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define SW 23
#define EXIT_SUCC 0
#define EXIT_FAIL 1

int main()
{	
	int dr;

	if(wiringPiSetupGpio() == -1)
		return EXIT_FAIL;
	setbuf(stdout, NULL);
	pinMode(SW, INPUT);
	pullUpDnControl(SW, PUD_UP);

	while(1)
	{
		delay(10);

		if((dr = digitalRead(SW))==1)
		{	printf("%d:-------\r", dr);   }
		else
		{
			printf("%d:--   --\n", dr);
			printf("create a new process\n");
			system("./gpioLed");
		}
	}
	return EXIT_SUCC;
}
