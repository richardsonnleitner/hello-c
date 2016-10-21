#include <stdio.h>

typedef enum
{
	COUNT, KILOS, PINTS
} unit_of_measure;

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
	unit_of_measure units;
} fruit_order;

void display(fruit_order order)
{
	if(order.units == PINTS)
	{
		printf("%2.2f pints of %s\n", order.amount.volume, order.name);
	}
	else if(order.units == KILOS)
	{
		printf("%2.2f kilos of %s\n", order.amount.weight, order.name);
	}
	else
	{
		printf("%i %s\n", order.amount.count, order.name);
	}
}

int main()
{
	fruit_order apples = {"apples", "England", .amount.count=144, COUNT};
	fruit_order strawberries = {"strawberries", "Spain", .amount.weight=17.6, KILOS};
	fruit_order oj = {"orange juice", "Somalia", .amount.volume=10.5, PINTS};

	display(apples);
	display(strawberries);
	display(oj);
	return 0;
}