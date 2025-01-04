#include <stdio.h>

int main()
{
	FILE* fptr = fopen("input", "r");
	char input[8000];
	int floor = 0;
	int basement = 0;

	if (fptr != NULL)
	{
		while(fgets(input, 8000, fptr))
		{
			for (int i = 0; i < 7000; i++)
			{					
				char floorCounter = input[i];
				floorCounter == '(' ? floor++ : floor--;
			}
			printf("floor: %d\n", floor);

			floor = 0;
			for (int i = 0; i < 7000; i++)
			{
				char floorCounter = input[i];
				floorCounter == '(' ? floor++ : floor--;
				if (floor == -1)
				{
					basement = i+1;
					break;
				}
			}
			printf("basement position: %d\n", basement);
		}
	}
	else 
	{
		printf("Not able to open the file.\n");	
	}

	fclose(fptr);

	return 0;
}
