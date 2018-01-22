#ifndef INCLUDES_H
#define INCLUDES_H
#include <QString>
#include <stdio.h>
#include <stdlib.h>
/*
#include <semaphore.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

extern SHAREDATA *read_data=NULL;
extern sem_t *sem_val=NULL;
*/
#define NO_WAIT 0
#define NO_LOAD 0
#define OK_LOAD 1
#define LOAD_FAIL_MAX 3
#define WAIT_TIME 600

extern int Load_WaitTime ;
extern char Load_OkFlag ;
extern char Load_FailCnt ;
const QString load_user = "123" ;
extern QString load_psword ;

typedef struct confige_info
{
    int suoyannumber;
    int suoyanjuli;
    int qianmenji;
}CONFIG_INFO;
extern int Mode_Count ;
extern bool Save_Confige_Flg ;
extern int Click_Mode ;
extern int Mode_Count_Tmp ;
extern CONFIG_INFO confige_s[6];
#endif // INCLUDES_H

