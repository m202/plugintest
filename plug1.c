#include <stdio.h>

typedef struct
{
	void (*print_function)(char *);
} pdata;

void init(pdata *program_data, int x)
{
	char str[10];
	void (*print)(char *);

	sprintf(str, "given number %d", x);
	print = program_data->print_function;

	print("Inside plug1.c");
	print(str);
}
