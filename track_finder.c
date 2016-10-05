#include <stdio.h>
#include <string.h>

char tracks[][80] = {"10 Euro Samsung",
						"Russki Kanak",
						"Mörder",
						"Palmen aus Plastik",
						"Flouz kommt Flouz geht"};

void find_track(char search[])
{
	int i;
	for(i = 0; i < 5; i++)
	{
		if (strstr(tracks[i], search))
		{
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
}

int main()
{
	char search_for[80];
	printf("Search for: ");
	scanf("%79s", search_for);
	find_track(search_for);
	return 0;
}