#include <stdio.h>
#include <string.h>

#include "global_val.h"

void poker_percent_debug(int RunTimes, int PeopleNum)
{
    double percent = 0;
#ifdef CARD_PERCENT_DEBUG  
    printf("豹子次数%5d次\r\n", _g_bao_zi_times);
    printf("顺金次数%5d次\r\n", _g_shun_jin_times);
    printf("金花次数%5d次\r\n", _g_jin_hua_times);
    printf("顺子次数%5d次\r\n", _g_shun_zi_times);
    printf("对子次数%5d次\r\n", _g_dui_zi_times);
    printf("\r\n");

//   printf(" %d\r\n", (RunTimes * PeopleNum));
    percent = (double)_g_bao_zi_times / (double)(RunTimes * PeopleNum);
    printf("豹子概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_shun_jin_times / (double)(RunTimes * PeopleNum);
    printf("顺金概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_jin_hua_times / (double)(RunTimes * PeopleNum);
    printf("金花概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_shun_zi_times / (double)(RunTimes * PeopleNum);
    printf("顺子概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_dui_zi_times / (double)(RunTimes * PeopleNum);
    printf("对子概率 %.3f%%\r\n", (percent * 100));

    printf("\r\n");

    printf("总共%d轮 \r\n", (RunTimes));
    percent = (double)_g_bao_zi_times / (double)(RunTimes);
    printf("毎轮豹子概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_shun_jin_times / (double)(RunTimes);
    printf("毎轮顺金概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_jin_hua_times / (double)(RunTimes);
    printf("毎轮金花概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_shun_zi_times / (double)(RunTimes);
    printf("毎轮顺子概率 %.3f%%\r\n", (percent * 100));

    percent = (double)_g_dui_zi_times / (double)(RunTimes);
    printf("毎轮对子概率 %.3f%%\r\n", (percent * 100));
#endif
}

void Poker_Output(int Poker_Status)
{
    int temp;

    temp = Poker_Status;

    if (temp & BAOZI) {

#ifdef PEOPLE_CARD_DEBUG    
        printf("$$$ 豹子 $$$");
#endif
        _g_bao_zi_times++;

    } else if ((temp & JINHUA) && (temp & SHUNZI)){

        _g_shun_jin_times++;
#ifdef PEOPLE_CARD_DEBUG    
        printf("!!! 顺金 !!!");
#endif
    } else if (temp & JINHUA) {

        _g_jin_hua_times++;
#ifdef PEOPLE_CARD_DEBUG    
        printf("@@@ 金花 @@@");
#endif

    } else if (temp & SHUNZI) {

        _g_shun_zi_times++;
#ifdef PEOPLE_CARD_DEBUG    
        printf("*** 顺子 ***");
#endif
    } else if (temp & DUIZI) {

        _g_dui_zi_times++;
#ifdef PEOPLE_CARD_DEBUG    
        printf("    对子    ");
#endif
    }

}

void Poker_Num_Print(int Poker_Num)
{
    if ( Poker_Num > 14 || Poker_Num < 1)
    {
        printf("Poker Num Output Error!\r\n");
    }

    switch (Poker_Num)
    {
        case 11:
            printf("J  ");
            break;

        case 12:
            printf("Q  ");
            break;

        case 13:
            printf("K  ");
            break;
        case 10:
            printf("10 ");
            break;
        case 14:
            printf("A  ");
            break;
        default :
            printf("%d  ", Poker_Num);
    }


}

void Poker_Suit_Print(int Poker_Suit_Num)
{
    if ((Poker_Suit_Num < 1) ||(Poker_Suit_Num > 4) )
    {
        printf(" Poker Suit Output Error!\r\n");

    }
    switch (Poker_Suit_Num)
    {
        case 1:
            printf("♥ ");
            break;
        case 2:
            printf("♤ ");
            break;
        case 3:
            printf("♣ ");
            break;
        case 4:
            printf("♢ ");
            break;
    }
}
