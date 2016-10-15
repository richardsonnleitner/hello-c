#include <stdio.h>

typedef struct exercise
{
	const char* description;
	float duration;
} exercise;

typedef struct meal
{
	const char* ingredients;
	float weight;
} meal;

typedef struct preferences
{
	struct meal food;
	struct exercise exercise;
} preferences;

typedef struct fish
{
	const char* name;
	const char* species;
	int teeth;
	int age;
	struct preferences care;
} fish;

void label(struct fish f);

int main()
{
	fish snappy = {"Snappy", "Piranha",  69, 4, {{"meat", 2.3}, {"swim in the jacuzzi", 7.5}}};
	label(snappy);
	return 0;
}

void label(fish f)
{
	printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n", f.name, f.species, f.age, f.teeth);
	printf("Feed with %2.2f kilos of %s and allow to %s for %2.2f hours\n", f.care.food.weight, f.care.food.ingredients,
						f.care.exercise.description, f.care.exercise.duration);
}