/*Hantow tower code - Nawaal Fatima - fatimn8 - 2xC3 FALL 2021 - submitted dec 8, 2021*/

#include <stdio.h>
#include <unistd.h> 
#include <string.h>
int peg1[9], peg2[9], peg3[9];

void display_pegs();

void move (int pegA[9], int pegB[9]) {
	
	int i = 0;
	int move_A, move_B;
	for (i = 0; i < 9; i++) {
		if (pegA[i+1] == 0){
			 move_A = i;
			break;
		}
	}
 	for (i = 0; i < 9; i++) {
        	        if (pegB[i] == 0){                
        	                 move_B = i;
        	                break;
        	        }
        	}
	
	pegB[move_B] = pegA[move_A];
	pegA[move_A] = 0;
	display_pegs();
	printf("\n");
	sleep(1);
}

void hantow (int n, int pOG[9], int pDest[9], int pHold[9]) {

	if (n > 1) hantow(n - 1, pOG, pHold, pDest);
	move(pOG, pDest);
	if (n > 1) hantow (n - 1, pHold, pDest, pOG);
}

void display_pegs() {
	
	const char* base = "XXXXXXXXXXXXXXXXXXXXX";
	char *rings[10];
	rings[0] = "          |          ";
	rings[1] = "         +|+         ";
	rings[2] = "        ++|++        ";
	rings[3] = "       +++|+++       ";
	rings[4] = "      ++++|++++      ";
	rings[5] = "     +++++|+++++     ";
	rings[6] = "    ++++++|++++++    ";
	rings[7] = "   +++++++|+++++++   ";
	rings[8] = "  ++++++++|++++++++  ";
	rings[9] = " +++++++++|+++++++++ ";

	int i;
	for ( i = 8; i >= 0; i--) {
		
		printf("%s      %s      %s\n", rings[peg1[i]], rings[peg2[i]], rings[peg3[i]]);
	}
	printf("%s      %s      %s\n", base, base, base);
}

int main (int argc, char *argv[]) {
	int i = 0;
	int diskNum = 0;
	
	for (i = 0; i < 9; i++) {
        peg1[i] = 0;
		peg2[i] = 0;
		peg3[i] = 0;

    }

	if (argc != 3) {
		printf("Incorrect number of arguments \n");
		return 0;
	} 
	else {
		if (strlen(argv[2]) != 1) {
			printf("Incorrect length of argument \n");
			return 0;
		} else {
			int argvChar = argv[2][0] - '0';
			if (argvChar < 1) {
				printf("ERROR:Input too low(should be between 1 and 9) \n");
				return 0;
			} 
			else if (argvChar > 9) {
				printf("ERROR: Input too high(should be between 1 and 9) \n"); 
				return 0;
			} 
			diskNum = argv[2][0] - '0';
		}
	}

	for (i = 0; i < diskNum; i++) {
		peg1[diskNum-i-1] = i+1;
	}
	
	display_pegs();
	hantow(diskNum, peg1, peg2, peg3);
	printf("Done\n");
	
	
	return 1;
}


