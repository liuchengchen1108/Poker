#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#include "poker_print.h"
#include "global_val.h"

static int buf[52] = 
{ 
    21,22,23,24,
    31,32,33,34,
    41,42,43,44,
    51,52,53,54,
    61,62,63,64,
    71,72,73,74,
    81,82,83,84,
    91,92,93,94,
    101,102,103,104,
    111,112,113,114,
    121,122,123,124,
    131,132,133,134,
    141,142,143,144
};

void Bubble(int a[],int len)
{
    int i,j,buf;

    for (i = 0; i < len - 1; i++)            //比较n-1轮
    {
        for (j = 0; j < (len - 1 - i); j++)  //每轮比较n-1-i次,
        {
            if (a[j] < a[j + 1])
            {
                buf      = a[j];
                a[j]     = a[j + 1];
                a[j + 1] = buf;
            }
        }
    }
}

int get_random_number(int maxnum, int minnum)
{
    int num = 0;

    num = rand() % (maxnum - minnum) + minnum;

    return (num);
}

int Porker_Judge(int a,int b,int c,int a1,int b1, int c1)
{
    
    int temp = 0;


    if ((a == b) && (b == c))  // bao zi 
    {
        temp = (temp | BAOZI);
    }

    if ((a1 == b1) && (b1 == c1))
    {
        temp = (temp | JINHUA); //jin hua
    }

    if (((a - b) == 1) && ((b - c) == 1))
    {
        if ((temp & BAOZI)) {

        } else {
            temp = (temp | SHUNZI); //shu zi
        }
    }

    if ((a == b) || (b == c) || (a == c))
    {
        temp = (temp | DUIZI);// duizi
    }

    if ((a == 14) && (b == 3) && (c == 2)) {

        temp = (temp | SHUNZI);

        temp = temp + 1 + b + c;
    } else {

        temp = temp + a + b + c;
    }


    return (temp);
}

int main ()
{
    
    int PeopleNum;
    int RunTimes;
    int numbuf[52] = {0};
    int card[52];
    int peopcard[17][3] = {0};
    int i, j;
    int temp,temp1;
   
    printf("Please input People num and run times \r\n");

    scanf(" %d %d", &PeopleNum, &RunTimes);

    if ((PeopleNum > 17) || (PeopleNum < 0) ) {
        printf("Invalued Player Num! \r\n");

	return (0);
    }


    if ((RunTimes < 0) ) {
	    
        printf("Invalued run times! \r\n");

	return (0);
    }

    printf(" %d people play this game , Run %d times \r\n", PeopleNum, RunTimes);
    
    srand(time(NULL));

    temp1 = RunTimes;
    
    while (RunTimes--) {
    
    
	memset(numbuf, 0,sizeof(numbuf));
	
	for (i = 0; i < (PeopleNum * 3); i++)
        {
            temp = 0;

	    while (1) {
	        temp = get_random_number(MAXNUM, MINNUM);
                if (numbuf[temp] == 0) {
                    card[i] = buf[temp];
                    numbuf[temp] = 1;
		    break;
	        }
	    }
        }

        for (i = 0; i < PeopleNum; i++)
        {
            peopcard[i][0] = card[i];
            peopcard[i][1] = card[i + PeopleNum];
            peopcard[i][2] = card[i + PeopleNum * 2];

            Bubble(peopcard[i], 3);
        }

        for(i = 1; i < (PeopleNum * 3 + 1); i++)
        {
#ifdef TOTAL_CARD_DEBUG   
            Poker_Suit_Print((card[i - 1] % 10));
        
            Poker_Num_Print((card[i - 1] / 10));

	    if ((i % PeopleNum) == 0){	
	        printf("\r\n");
	    }
#endif

        }

#ifdef TOTAL_CARD_DEBUG   
        printf("\r\n");
#endif
        for(i = 0; i < PeopleNum; i++)
        {
            temp = 0;

	    for(j = 0; j < 3; j++)
	    {	
#ifdef PEOPLE_CARD_DEBUG    
                Poker_Suit_Print((peopcard[i][j] % 10));
                Poker_Num_Print((peopcard[i][j] / 10));
#endif
	    }
            
	    /*
	     * Poker Suit
 	     * peopcard[i][0] % 10;
	     * peopcard[i][1] % 10;
	     * peopcard[i][2] % 10;
	     */
	
	    /*
	     * Poker Num
 	     * peopcard[i][0] / 10;
	     * peopcard[i][1] / 10;
	     * peopcard[i][2] / 10;
             */
	
	    temp = Porker_Judge((peopcard[i][0] / 10),
	    	                (peopcard[i][1] / 10),
		                (peopcard[i][2] / 10),
		                (peopcard[i][0] % 10),
		                (peopcard[i][1] % 10),
		                (peopcard[i][2] % 10));
        
 	    Poker_Output(temp);
#ifdef PEOPLE_CARD_DEBUG    
 	    printf("\r\n");
#endif
        }
        

#ifdef PEOPLE_CARD_DEBUG    
	printf("\r\n");
#endif
    }
    
    poker_percent_debug(temp1,PeopleNum);
    
    return (0);
}
