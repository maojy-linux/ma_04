/*************************************************
- Copyright (C), 2017-2018, JACK-IOT   
- File name:      ma04_interface   
- Author: maojy      Version: V4.0       Date: 2017-12-29				      
- Description:    实现和PLC进行通信，控制整机。				
- Function List:      
  1.connect(my_welcome,&welcome::display,this,&Dialog::show_chooce);   
	//绑定自定义信号槽函数，用来实现界面之间的跳转。
  2.emit display(0);
	//发射信号函数。
- History:           
  1.  
    Date:	2017-11-23        
    Author:	maojy		
    Modification: 用控件与代码调整形式搭建各个界面；用在类中定义其他类的方式实现界面跳转；
  2.  
	Date:	2017-11-28        
	Author:	maojy		
	Modification: 采用自定义信号槽连接，实现各个界面之间的跳转;
  3.  
	Date:	2017-12-07        
	Author:	maojy		
	Modification: 实现此进程与其它进程进行通信方式，方式为POSIX共享内存，使用sem信号量进行同步保护；
        共享内存名为：read_shm；
        信号量名为：share_sem；
  4.  
	Date:	2017-12-14       
	Author:	maojy		
	Modification: 添加显示LOGO和按钮图标功能；
*************************************************/