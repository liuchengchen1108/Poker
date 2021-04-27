#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLOBAL_VAL_H
#define GLOBAL_VAL_H

#define MAXNUM              (51)
#define MINNUM              (0)
#define BAOZI               (0x80000000)
#define SHUNJIN             (0x40000000)  
#define JINHUA              (0x20000000)
#define SHUNZI              (0x10000000)
#define DUIZI               (0x8000000)
#define TOTAL_CARD_DEBUG    (1)
#define PEOPLE_CARD_DEBUG   (1)
#define CARD_PERCENT_DEBUG  (1)

extern int _g_bao_zi_times;
extern int _g_shun_jin_times;
extern int _g_jin_hua_times;
extern int _g_shun_zi_times;
extern int _g_dui_zi_times;
#endif

#ifdef __cplusplus
}
#endif

