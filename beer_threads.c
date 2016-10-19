#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
int beers = 2000000;

void error(char* msg, int t)
{
	printf("%s %i\n", msg, t);
	exit(1);
}

void* drink_lots(void* a)
{
	int i;
	pthread_mutex_lock(&beers_lock);
	for(i = 0; i < 100000; i++)
	{
		beers = beers - 1;
	}
	pthread_mutex_unlock(&beers_lock);
	printf("beers = %i\n", beers);
	return NULL;
}

int main()
{
	pthread_t threads[20];
	int t;

	printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
	for(t = 0; t < 20; t++)
	{
		if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
		{
			error("Can't create thread", t);
		}
	}

	void* result;
	for(t = 0; t < 20; t++)
	{
		if(pthread_join(threads[t], &result) == -1)
		{
			error("Can't join thread", t);
		}
	}
	printf("There are now %i bottles of beer on the wall\n", beers);
	return 0;
}