#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *source, *temp;
	char ch;
	char command[100] = "mv temp.dat ";
	if( argc < 2)
	{
		printf("No file specified\n");
		return 0;
	}
	source = fopen(argv[1], "r");
	temp = fopen("temp.dat", "w");
	if( source == NULL || temp == NULL)
	{
		printf("Couldn't open the file, Exiting...\n");
		return 0;
	}
	while( (ch = fgetc(source))!= EOF )
	{
		if( ch == '\t')
			fprintf(temp, "   ");
		else
			fputc(ch, temp);
	}
	fclose(source);
	fclose(temp);
	strcat(command, argv[1]);
//	strcat(command, ".c");
	system(command);
}
