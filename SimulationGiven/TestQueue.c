#include <stdio.h>
#include "Queue.h"

int main(void)
{
	int i;
	Type in, out;
	Queue q;
	
	do {
		printf("epilogh 0-6:");
		if (scanf_s("%d", &i) !=1 ) 
		{
			printf("not integer input i=%d\n",i); 
			i=1;
		}
		getchar();
		
		switch (i) {
		case 0:	
			QCreate(&q);
			printf("... klhsh DhmiourgiaOura\n");
			QInitialize(&q);
			printf("... klhsh Type Initialize\n");
			break;
		case 1:
			if (QEmpty(&q))
						printf("... kenh\n"); 
					else 	
						printf("....Mh kenh\n");
					break;
		case 2:	
			if (QFull(&q))			
				printf("... gemath\n"); 
			else 	
				printf("... Mh gemath\n");
			break;
		case 3:	 
				printf("Read input:");
				int x = 0, entry = 0 , servise = 0;

				printf("entry:");
				x = fscanf_s(stdin,"%d",&entry);
				TSetEntryTime(&in,entry );

				printf("servise:");
				x += fscanf_s(stdin, "%d", &servise);
				TSetServiseTime(&in, servise);

			if (x!=2) 
				printf("no input is read\n");
			else 
			{
				TWriteValue(stdin, &in);
				if (!QInsert(&q, &in)){
					printf("... oura gemath, den eishx9ei to");
					TWriteValue(stdout, &in);
					printf("\n");
				}
				else 
				{
					printf("... eishx9ei to: "); 
					TWriteValue(stdout, &in);
					printf("\n");
				}
			}
			break;
		case 4:	
			if (!QRemove(&q, &out))
				printf("... oura kenh\n");
			else 
			{	
				TWriteValue(stdout, &out);
				printf("\n");
			}
			break;
		case 5: 
			inspectQbyOrder(&q);
			break;
		case 6: 
			inspectQbyArray(&q);
			break;
		}
	} 
	while ((0<= i) && (i<=6));
	
	return 0;
}
