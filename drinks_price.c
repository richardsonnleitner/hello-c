#include <stdio.h>
#include <stdarg.h>

enum drink{ MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE};

double total(int args, ...)
{
	double total = 0;
	va_list yoyo;
	va_start(yoyo, args);

	int i;
	for (i = 0; i < args; ++i)
	{
		switch(va_arg(yoyo, int))
	 	{
	 		case MUDSLIDE:
	 			total += 6.79;
	 			break;
	 		case FUZZY_NAVEL:
	 			total += 5.31;
	 			break;
	 		case MONKEY_GLAND:
	 			total += 4.82;
	 			break;
	 		case ZOMBIE:
	 			total += 5.89;
	 	}
	}

	va_end(yoyo);

	return total;
}

int main()
{
	printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
	printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
	printf("Price is %.2f\n", total(1, ZOMBIE));
	return 0;
}