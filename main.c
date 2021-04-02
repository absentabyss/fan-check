#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char FAN_ON[] = "";	// Command used to turn the fan on.
const char FAN_OFF[] = "";	// Command used to turn the fan off.
const char SENSORS[] = "";	// Command used to monitor fan speed.

static volatile int childPID;

void intHandler(int i)
{
	kill(childPID, SIGKILL);
}

void monitorRPM()
{
	while (1)
	{
		system("clear");	// Command used to clear the terminal.
		puts("Press Enter twice to stop.");
		system(SENSORS);
		sleep(1);
	}
}

int main()
{
	childPID = getpid();
	signal(SIGINT, intHandler);

	if (system(FAN_ON))
		return 0;

	childPID = fork();
	if (!childPID)
	{
		monitorRPM();
	}

	getchar();
	system(FAN_OFF);

	getchar();
	kill(childPID, SIGKILL);
	return 0;
}
