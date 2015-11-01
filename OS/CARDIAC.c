#include <stdio.h>


int main() {
	int memory[100];
	memory[0] = 001;
	memory[99] = 800;
	memory[4] = 123;
	int pcount = 0, acc = 0; // pcount: Current "byte", acc: Current data?
//	printf("%d, %d\n", pcount, acc); //Test print
	int stop = 0;
	int inst = 0;	
	while(stop==0) {
		inst = memory[pcount];
		++pcount;
		int adress = inst % 100;
		int op = inst / 100;
//		printf("Instruction Used: %d\n", inst);
//		printf("Option used: %d\n", op);
		switch (op) {
			int data;
			case 0: {
				scanf("%d", &data);
				memory[adress] = data;
				break;
			}
			case  1: {
				acc = memory[adress];
				break;
			}
			case 2: {
				acc = acc + memory[adress];
				break;
			}
			case 3: {
				if (acc<0) pcount+= adress;
				break;
			}
			case 5: {
				printf("%d\n", memory[adress]);
				break;
			}
			case 6: {
				memory[adress] = acc;
				break;
			}
			case 8: {
				memory[99]+= pcount; // check dat bastard
				pcount = adress;
				break;
			}
			case 9: {
				stop = 1;
				break;
			}
		}
//		printf("End of loop check\n");
	}

	return 0;
}
