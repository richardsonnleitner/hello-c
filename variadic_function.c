#include <stdio.h>
#include <stdarg.h>

void print_ints(int args, ...)
{
	va_list ap;
	va_start(ap, args);

	int i;
	for(i = 0; i < args; i++)
	{
		printf("Argument: %i\n", va_arg(ap, int));
	}
	va_end(ap);
}

int main()
{
	print_ints(4, 23, 44, 78, 9023);
	return 0;
}