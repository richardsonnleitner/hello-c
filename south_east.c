#include <stdio.h>

void go_south_east(int* lat, int* lon)
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

void skip(char* msg)
{
	puts(msg + 6);
}

int main()
{
	int latitude = 32;
	int longitude = -64;

	go_south_east(&latitude, &longitude);
	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

	char* msg_from_amy = "Don't call me";
	skip(msg_from_amy);
	printf("%c\n", 2[msg_from_amy]);
}