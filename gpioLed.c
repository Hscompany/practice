#include <stdio.h>
#include <wiringPi.h>

#define LED1 17
#define LED2 27
#define LED3 22
#define EXIT_SUCC 0
#define EXIT_FAIL 1

int main()
{
	int i;

	if(wiringPiSetupGpio() == -1)
		return EXIT_FAIL;

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);

	for(i=0; i<10; i++)
	{
		printf("LED ON\n");
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
		delay(50);

		printf("LED OFF\n");
		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		delay(50);
	}
	return EXIT_SUCC;
}
