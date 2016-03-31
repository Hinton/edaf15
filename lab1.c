#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

///*
	FILE*   fp;
	fp = fopen("out.txt", "w");

	int c = 0;
	for (int i = 0; i < argc; i++) {
		fprintf(fp, "argument number %d is %s\n", i, argv[i]);		

		if (i > 0) {
			c += strtol(argv[i], NULL, 10);
		}
	}

	
	fprintf(fp, "%d\n", c);
	fclose(fp);
//*/

/*
	int c = 0;
	for (int i = 0; i < argc; i++) {
		printf("argument number %d is %s\n", i, argv[i]);		

		if (i > 0) {
			c += strtol(argv[i], NULL, 10);
		}
	}

	printf("%d\n", c);
//*/

/*
	for (int i = 0; i < argc; i++) {
		printf("argument number %d is %s\n", i, argv[i]);		
	}

	int a = strtol(argv[1], NULL, 10);
	int b = strtol(argv[2], NULL, 10);
	int c = a + b;

	printf("%d + %d = %d\n", a, b, c);
//*/
	/*
	// Old read/print code
	int	a;
	int	b;
	int	c;

	printf("Please enter two numbers: ");
	fflush(stdout);

	int n = scanf("%d %d", &a, &b);

	c = a + b;

	printf("%d + %d = %d\n", a, b, c);
	printf("Number of inputs %d\n", n);
//	*/

	return 0;
}
