#include <stdio.h>
#include <dlfcn.h>

typedef struct
{
	void (*print_function)(char *);
} pdata;

typedef void (*function)(pdata *, int);
void print(char *);

int main(int argc, char **argv)
{
	char filename[200];
	void *handle = NULL;
	int number = 0;

	pdata program_functions;
	program_functions.print_function = &print;

	printf("Enter object file name: ");
	fgets(filename, 200, stdin);
	strtok(filename, "\n");

	printf("Enter number to pass to init() function: ");
	scanf("%d", &number);
	printf("Number %d will be passed\n", number);

	if((handle = dlopen(filename, RTLD_LAZY)))
	{
		printf("Object file loaded\n");
		function F = dlsym(handle, "init");
		F(&program_functions, number);
	}
	else
	{
		printf("Object file not loaded: %s\n", dlerror());
	}
}

void print(char *msg)
{
	printf("message from plugin: %s\n", msg);
}
