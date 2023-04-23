#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct deftab{
	char lab[10];
	char opc[10];
	char oper[10];
} d[10];
void main(){
	char label[10], opcode[10], operand[10], newlabel[10], newoperand[10];
	char macroname[10];
	int i, lines = 0;
	FILE *f1, *f2, *f3;
	f1 = fopen("macin.dat", "r");
	f2 = fopen("macout.dat", "w");
	f3 = fopen("deftab.dat", "w");
	fscanf(f1, "%s%s%s", label, opcode, operand);
	fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);
	while (strcmp(opcode, "END") != 0){
		fscanf(f1, "%s%s%s", label, opcode, operand);
		if (strcmp(opcode, "MACRO") == 0){
			strcpy(macroname, label);
			fprintf(f2, "%s %s %s\n", label, opcode, operand);
			while (strcmp(opcode, "MEND") != 0){
				if (strcmp(label, macroname) != 0){
					fprintf(f3, "%s\t%s\t%s\n", label, opcode, operand);
					fprintf(f2, "%s %s %s\n", label, opcode, operand);
					strcpy(d[lines].lab, label);
					strcpy(d[lines].opc, opcode);
					strcpy(d[lines].oper, operand);
					fscanf(f1, "%s%s%s", label, opcode, operand);
					lines++;
				}
				else{
					fscanf(f1, "%s%s%s", label, opcode, operand);
				}
			}
			fprintf(f2, "%s %s %s\n", label, opcode, operand);
		}
		else if (strcmp(opcode, macroname) == 0){
			printf("Lines=%d\n", lines);
			for (i = 0; i < 3; i++){
				fprintf(f2, "%s\t%s\t%s\n", d[i].lab, d[i].opc, d[i].oper);
				printf("DLAB=%s\nDOPC=%s\nDOPER=%s\n", d[i].lab, d[i].opc,
				d[i].oper);
			}
		}
		else{
			fprintf(f2, "%s %s %s\n", label, opcode, operand);
		}
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	printf("FINISHED");
}

/* INPUT FILE : macin.dat
MACIN.DAT
CALC START 1000
SUM MACRO **
** LDA #5
** ADD #10
** STA 2000
** MEND **
** LDA LENGTH
** COMP ZERO
** JEQ LOOP
** SUM **
LENGTH WORD 5
ZERO WORD 0
LOOP SUM **
** END **