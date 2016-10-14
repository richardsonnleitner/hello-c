#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("The value of INT_MAX is %d\n", INT_MAX);
	printf("The value of INT_MIN is %d\n", INT_MIN);
	printf("An int takes %li bytes\n", sizeof(int));

	printf("The value of INT_MAX is %f\n", FLT_MAX);
	printf("The value of INT_MIN is %.50f\n", FLT_MIN);
	printf("A float takes %li bytes\n", sizeof(float));
	return 0;
}