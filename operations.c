#include <stdio.h>
#include <stdlib.h>
#define SIX 6;

typedef struct count_colors
{
	char color;
	int count;
} colors_t;

int *check_points(char hidden[4],char u_arr[4])
{
	char colors[6] = {'B', 'G', 'O', 'P', 'R', 'Y'};
	colors_t times_by[6];
	int results[4];
	int cont, idx;
	int tmp[2];

	for (cont = 0; cont < 6; cont++) {
		times_by[cont].color = colors[cont];
		times_by[cont].count = 0;
	}

	for (cont = 0; cont < sizeof(hidden); cont++)
		for (idx = 0; idx < sizeof(colors); idx++)
			if (hidden[cont] == colors[idx])
				times_by[idx].count++;

	for (cont = 0; cont < sizeof(u_arr); cont++)
	{
		if (u_arr[cont] == hidden[cont]) {
			results[cont] = 1;

			for (idx = 0; idx < sizeof(colors); idx++)
				if (u_arr[cont] == colors[idx])
					times_by[idx].count--;
		} else
			{
			results[cont] = -1;
		}
	}
	for (cont = 0; cont < sizeof(u_arr); cont++)
	{
		for (idx = 0; idx < (sizeof(times_by) / sizeof(colors_t)); idx++)
		{
			if (u_arr[cont] == times_by[idx].color)
			{
				if (times_by[idx].count > 0)
				{
					times_by[idx].count--;
					results[cont] = 0;
				}
			}
		}
	}
	for (cont = 0; cont < 4; cont++)
		printf("%d ", results[cont]);
	printf("\n");
	for (idx = 0; idx < 4; idx++)
	{
		cont = idx + rand() / (RAND_MAX / (4 - idx) + 1);
		tmp[0] = results[cont];
		results[cont] = results[idx];
		results[idx] = tmp[0];
	}
	printf("the shuffle array \n");
	for (cont = 0; cont < 4; cont++)
		printf("%d ", results[cont]);
	printf("\n");
	return results;
}