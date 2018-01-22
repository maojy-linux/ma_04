#include "includes.h"
int Load_WaitTime = NO_WAIT ;  //是否需要等待
char Load_OkFlag = NO_LOAD ;    //是否登录成功
char Load_FailCnt = 0 ;             //输错密码计数
QString load_psword = "123456" ;
int Mode_Count = 0 ;        //模式总数
bool Save_Confige_Flg = true ; //是否保存到本地
int Click_Mode = 1;             //选中模式
int Mode_Count_Tmp = 0;
CONFIG_INFO confige_s[6];

/* Mode_Count 修改位置 */
/*
 * 引用位置：
void config_manage::add_succes(QString str1, QString str2, QString str3) ;
void config_manage::add_clicked();
void config_manage::del_clicked();
void config_manage::SaveConfigData(void);
修改位置：
---增加:
void config_manage::add_succes(QString str1, QString str2, QString str3) ;
void config_manage::ReadConfigData(void);
---减:
void config_manage::del_clicked();
---清零：
void config_manage::quit_clicked();


*/
