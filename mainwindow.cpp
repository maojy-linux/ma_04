#include "mainwindow.h"
#include <stdio.h>

const char *read_file_name="read_shm";

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    share_data= new QSharedMemory;
    my_welcome= new welcome();
    my_chooce= new chooce();

/*
    int fd_read=shm_open(read_file_name,O_CREAT|O_RDWR,S_IRWXU|S_IRWXG);
    ftruncate(fd_read,sizeof(SHAREDATA));
    read_data=(SHAREDATA*)mmap(0,sizeof(SHAREDATA),PROT_READ|PROT_WRITE,MAP_SHARED,fd_read,0);
    ::close(fd_read);

    sem_val=sem_open("share_sem",O_CREAT,0666,1);
    if(sem_val == SEM_FAILED)
    {
        printf("sem open failed\n");
        return ;
    }
*/
    my_welcome->show();
    /*连接信号槽*/
    connect(my_welcome,&welcome::display,this,&Dialog::show_chooce);
    connect(my_chooce,&chooce::display,my_chooce,&chooce::show_window);
}

void Dialog::show_chooce(int num)
{
    if(num==0)
    {
        my_chooce->show();
    }
}

Dialog::~Dialog()
{

}
