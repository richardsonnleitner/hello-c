#include <stdio.h>

typedef union
{
	short count;
	float weight;
	float volume;
} quantity;

typedef struct
{
	const char* name;
	const char* country;
	quantity amount;
} fruit_order;

int main()
{
	fruit_order juicy = {"mango", "Marokko", .amount.weight=4.2};
	printf("This order contains %2.2f kilos of %s\n", juicy.amount.weight, juicy.name);
	return 0;
}