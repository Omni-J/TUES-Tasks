#include <stdio.h>
#include <math.h>

int main() {
	int memory[100];
	memory[0] = 001;
	int pcount = 0, acc = 0; // pcount: Current "byte", acc: Current data?
	int stop = 0;
	int inst = 0;	
	int data, x, y;
	while(stop==0) {
		inst = memory[pcount];
		++pcount;
		int adress = inst % 100;
		int op = inst / 100;
//		printf("Instruction Used: %d\n", inst);
//		printf("Option used: %d\n", op);
		switch (op) {
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
			case 4: {
				x = adress / 10;
				y = adress & 10;
				acc *= pow(10, x);
               			acc /= pow(10, y);
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
         		case 7: {
                		acc -= memory[adress];
                		break;
			}
			case 8: {
				memory[99]= 800 + pcount; // check dat bastard
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
