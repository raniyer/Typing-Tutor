#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct report{
	int timetaken;
	int accuracy;
	struct report *next;
}report;

report *head = NULL;

void calculate(int ,int ,int);
void begin();
void knowmore();
void nextwork();
void choices();
void store(report *);

void store(report *ptr)
{
	head = ptr;
	head = NULL;	
}

int homepage(void)
{
	printf("WELCOME TO THE TYPING TUTOR!!");
	sleep(2);
	printf("\n\nHere, we will work on your typing speed make you a better typist.");
	printf("\n\nLet's start our journey to rise as the best typist of all times.");
	printf("\n\nAre you ready to begin?\n");
	choices();
	
}

void freemem(){};
void progress(){};

void choices()
{
	int c;
	
	printf("\n\nPress 1 to begin.\nPress 2 to view your progress.\nPress 3 to erase all progress\nPress 4 to know more about our workspace.\n\n");
	scanf("%d", &c);
	switch(c){
        	case 1: begin();
        	        break;
		case 2: progress();
			break;
		case 3: freemem();
			break;
        	case 4: knowmore();
                	break;
        	default:printf("Please enter a valid option");
			choices();
    	}
}

void begin()
{
	int correct=0, wrong=0, i, x, timetaken;
	clock_t start, end;
	char a[100], c ;
	char b[] = "HELLO TYPING TUTOR";
	
	printf("enter the following words as it is as fast as you can:\n");
	sleep(2);
	getchar();
	printf("%s\n", b);
	start= clock();
	scanf(" %[^\n]s", a);
	end= clock();
	x = strlen(b);
	for(i = 0 ; i < x ; i++){
	        if (a[i] == b[i])
	            correct++;
	        else
	            wrong++;
	}
	timetaken = (int)(end-start) / CLOCKS_PER_SEC;
	calculate(correct, wrong, timetaken);
	nextwork();
}

void calculate(int correct,int wrong,int timetaken)
{
	int per;
	report *ptr;
	
	ptr = (report*)malloc(sizeof(report*));
	ptr->timetaken = timetaken;
	printf("Right letters: %d\n", correct);
	printf("wrong letters: %d\n", wrong);
	printf("timetaken: %d\n", timetaken);
	ptr->accuracy = (100*correct)/(correct+wrong);
	printf("accuracy: %d", ptr->accuracy);
	printf("%%");
	printf("\n\n");
	store(ptr);
}

void knowmore()
{
}

void nextwork()
{
	int c;
	
	printf("Do you want to continue?(1=Yes/0=No)");
	scanf("%d", &c);
	switch(c){
		case 1: begin();
			break;
		case 0: choices();
			break;
		default:printf("wrong input");
			nextwork();
	}
}

int main(void)
{
        homepage();
        return 0;
}
