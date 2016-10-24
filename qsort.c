#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int width;
	int height;
} rectangle;

int compare_scores(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;

	return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;

	return b - a;
}

int compare_areas(const void* a, const void* b)
{
	rectangle* rec1 = (rectangle*)a;
	rectangle* rec2 = (rectangle*)b;

	int area_1 = rec1->width * rec1->height;
	int area_2 = rec2->width * rec2->height;

	return area_1 - area_2;
}

int compare_names(const void* a, const void* b)
{
	char** s1 = (char**)a;
	char** s2 = (char**)b;

	return strcmp(*s1, *s2);
}

int compare_areas_desc(const void* a, const void* b)
{
	return compare_areas(b, a);
}

int compare_names_desc(const void* a, const void* b)
{
	return compare_names(b, a);
}

int main()
{
	int scores[] = {543, 323, 32, 554, 11, 3, 112};
	int i;
	qsort(scores, 7, sizeof(int), compare_scores_desc);
	puts("These are the scores in order: ");
	for(i = 0; i < 7; i++)
	{
		printf("Score = %i\n", scores[i]);
	}

	char* names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort(names, 4, sizeof(char*), compare_names_desc);
	puts("These are the names in order: ");
	for(i = 0; i < 4; i++)
	{
		printf("%s\n", names[i]);
	}


	rectangle r1;
	r1.width = 10;
	r1.height = 4;
	rectangle r2;
	r2.width = 9;
	r2.height = 8;
	rectangle r3;
	r3.width = 17;
	r3.height = 34;
	rectangle r4;
	r4.width = 100;
	r4.height = 2;
	rectangle rects[] = {r1, r2, r3, r4};

	qsort(rects, 4, sizeof(rectangle), compare_areas_desc);
	puts("These are the rectangles in order: ");
	for(i = 0; i < 4; i++)
	{
		printf("%i\n", rects[i].width);
	}

	return 0;
}