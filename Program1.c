/*
 * Program1.c
 *
 *  Created on: Feb 19, 2023
 *      Author: zakariyaahmed
 */
#include <stdio.h>
#include <stdlib.h>

void HL(float totalSales[12], char Month[11][10])
{
	char d;
	float e;
	printf("\nSales Report (H to L)\n Month \t Sales \n\n");
	for (int a = 0; a < 12; a++)
	{
		for (int b = a; b < 12; b++)
		{
			if (totalSales[a] < totalSales[b])
			{
				for (int c = 0; c < 10; c++)
				{
					d = Month[a][c];
					Month[a][c] = Month[b][c];
					Month[b][c] = d;
				}
				e = totalSales[a];
				totalSales[a] = totalSales[b];
				totalSales[b] = e;
			}
		}
		printf("%-11s$%.2f\n", Month[a], totalSales[a]);
	}
}

void sixmonthavg(float totalSales[12], char Month[11][10])
{
	float sixMonthTotal, average;
	printf("\nSix-Month Moving Avg Report:\n\n");
	for (int a = 0; a < 7; a++)
	{
		sixMonthTotal = 0.0;
		for(int b = 0; b < 6; b++)
		{
			sixMonthTotal += totalSales[a+b];
			average = sixMonthTotal / 6.0;
		}
		printf("%-11s- %-11s $%.2f\n", Month[a], Month[a+5], average);
	}
}

void sales(float totalSales[12], char Month[11][10])
{
	printf("Monthly sales report: \n\nMonth\t\t Sales\n\n");
	for (int a = 0; a < 12; a++)
	{
		printf("%s\t\t", Month[a]);
		printf("$%5.2f\n", totalSales[a]);
	}
}

void maxmin(float totalSales[12], char Month[11][10])
{
	float min = totalSales[0], max = totalSales[0], total;

	for(int a = 0; a < 12; a++)
	{
		if (totalSales[a] < min)
		{
			min = totalSales[a];
		}
		if (totalSales[a] > max)
		{
			max = totalSales[a];
		}
		total += totalSales[a];
	}
	printf("\nSales summary:\n");
	printf("Minimum sales: $ %5.2f\t", min);
	printf("(%s)\n", Month[0]);
	printf("Maximum sales: $ %5.2f\t", max);
	printf("(%s)\n", Month[11]);
	float average = total/12.0;
	printf("Average sales: $ %5.2f\n", average);
}

int main()
{
	FILE *inputP1;
	FILE *months;
	inputP1 = fopen("inputP1.txt", "r");
	months = fopen("months.txt", "r");
	char Month[11][10];
	float totalSales[12];
	if (inputP1 == NULL)
	{
		printf("error analyzing file\n");
		exit(0);
	}
	else if (months == NULL)
	{
		printf("error analyzing file\n");
		exit(0);
	}
	for (int a = 0; a < 12; a++){
		fscanf(inputP1, "%f", &totalSales[a]);
		fscanf(months, "%s", Month[a]);
	}

sales(totalSales, Month);
maxmin(totalSales, Month);
sixmonthavg(totalSales, Month);
HL(totalSales, Month);

	fclose(inputP1);
	fclose(months);
	return 0;
}
