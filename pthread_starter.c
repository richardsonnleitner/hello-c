#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* does_not(void *a)
{
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		sleep(1);
		puts("Hollari!");
	}
	return NULL;
}

void* does_too(void *a)
{
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		sleep(1);
		puts("BIGBOOTYHOE");
	}
	return NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

int main()
{
	pthread_t t0;
	pthread_t t1;

	if(pthread_create(&t0, NULL, does_not, NULL) == -1)
	{
		error("Can't create thread t0");
	}

	if(pthread_create(&t1, NULL, does_too, NULL) == -1)
	{
		error("Can't create thread t1");
	}

	void* result;
	if(pthread_join(t0, &result) == -1)
	{
		error("Can't join thread t0");
	}
	if(pthread_join(t1, &result) == -1)
	{
		error("Can't join thread t1");
	}

	printf("Funktioniert!\n");
	return 0;
}