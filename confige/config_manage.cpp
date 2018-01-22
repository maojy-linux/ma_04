#include "config_manage.h"
#include <unistd.h>
config_manage::config_manage(QWidget *parent) :
    QDialog(parent)
{
    ManageInit();
   // ReadConfigData();
    main_table->resize(505,260);
    main_table->move(100,100);
    main_table->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    main_table->setWindowModality(Qt::WindowModal);

    m_add = new AddInfo ;
    m_add->resize(240,180);
    m_add->move(150,80);
    m_numpad = new numpad();

    connect(m_numpad,&numpad::value_changed,this,&config_manage::SetItemText);
    connect(main_table,&QTableWidget::itemClicked,this,&config_manage::ModifyConfigeInfo);
   // connect(main_table,&QTableWidget::itemDoubleClicked,this,&config_manage::ModifyConfigeInfo);
    connect(m_add,&AddInfo::add_success,this,&config_manage::add_succes);

    err_box =new QMessageBox ;
    yesButton1.setText("保存");
    yesButton2.setText("不保存");
    err_box->addButton(&yesButton1,QMessageBox::AcceptRole);
    err_box->addButton(&yesButton2,QMessageBox::RejectRole);
    err_box->setIcon(QMessageBox::Question);

    war_box = new QMessageBox ;
    yesbutton.setText("确定");
    war_box->addButton(&yesbutton,QMessageBox::AcceptRole);
    war_box->setIcon(QMessageBox::Warning);
}

void config_manage::add_succes(QString str1, QString str2, QString str3)
{
    lab_s[Mode_Count*4+1]->setText(str1);
    lab_s[Mode_Count*4+2]->setText(str2);
    lab_s[Mode_Count*4+3]->setText(str3);

    if(Mode_Count >= 6) return ; //防止数组越界
    Mode_Count ++;
    Save_Confige_Flg = false ;
}

void config_manage::getwidget(QTableWidgetItem *item)
{

}


void config_manage::ModifyConfigeInfo(QTableWidgetItem *item)
{
    int i =0;
    if(item->text().isEmpty())  //若当前Item无数据，则不修改跳过
    {
        return ;
    }
    /*查找双击的是哪个Item*/
    for(i=0;i<24;i++)
    {

        if(item == lab_s[i])
        {
            if(i%4==0)   //跳过模式名称选项
            {
                Click_Mode = i ;
                break;
            }
            else
            {
                Item_Cnt = i ;
                LastData = lab_s[i]->text();
                m_numpad->exec();
                if(LastData != lab_s[i]->text()) Save_Confige_Flg = false ;
                break;
            }

        }
    }

}

void config_manage::SetItemText(QString str)
{
    lab_s[Item_Cnt]->setText(str);
}
void config_manage::ManageInit(void)
{
    /*TableWidget初始化设置*/
    main_table = new QTableWidget ;
    main_table->setRowCount(6);
    main_table->setColumnCount(5);
    QStringList header;
    header<<"模式名称"<<"锁眼个数"<<"锁眼距离"<<"前门襟"<<"功能选择";
    main_table->setHorizontalHeaderLabels(header);      //插入表头

    /*循环放入Item到Table中*/
    int x = 0 , y = 0;
    for(y=0;y<6;y++)
    {
        for(x=0;x<5;x++)
        {
            if(x == 4)continue ;        //跳过功能选择项
            lab_s[y*4+x] = new QTableWidgetItem ;
            main_table->setItem(y,x,lab_s[y*4+x]);
        }
    }
    lab_s[0]->setText("模式一");
    lab_s[4]->setText("模式二");
    lab_s[8]->setText("模式三");
    lab_s[12]->setText("模式四");
    lab_s[16]->setText("模式五");
    lab_s[20]->setText("模式六");

    /*添加功能按钮*/
    add  = new QPushButton("添加") ;
    del  = new QPushButton("删除") ;
    save = new QPushButton("保存") ;
    quit = new QPushButton("退出") ;
    main_table->setCellWidget(0,4,add);
    main_table->setCellWidget(1,4,del);
    main_table->setCellWidget(2,4,save);
    main_table->setCellWidget(3,4,quit);

    connect(add,SIGNAL(clicked()),this,SLOT(add_clicked()));
    connect(del,SIGNAL(clicked()),this,SLOT(del_clicked()));
    connect(save,SIGNAL(clicked()),this,SLOT(save_clicked()));
    connect(quit,SIGNAL(clicked()),this,SLOT(quit_clicked()));

    main_table->verticalHeader()->setVisible(false);        //设置列表头不可见
    main_table->setStyleSheet("QTableView::Item{background-color:#FF3EFF}");
    main_table->horizontalHeader()->setStyleSheet("QHeaderView {background-color:lblue } QHeaderView::section {background-color:lightblue;color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");
    add->setStyleSheet("background-color:green");
    del->setStyleSheet("background-color:green");
    save->setStyleSheet("background-color:green");
    quit->setStyleSheet("background-color:green");

}


void config_manage::add_clicked()
{
    if(Mode_Count >=6)  //判断是否超过最大数
    {
        war_box->setText("当前模式数量已超出最大值\n请修改或删除现有模式");
        war_box->exec();
    }
    else
    {
        m_add->show();
    }

}

void config_manage::del_clicked()
{
    int i = 0 , j = 0;
    if(Click_Mode % 4 == 0)
    {
        if(!(lab_s[Click_Mode+1]->text().isEmpty()))   //当前模式有数据
        {
            for(i=1;i<4;i++)        //清空当前模式数据
            {
               QString str = lab_s[Click_Mode+i]->text();
               str.clear();
               lab_s[Click_Mode+i]->setText(str);

            }
            for(j=0;j<(Mode_Count-Click_Mode/4-1);j++)
            {
                lab_s[Click_Mode+1+j*4]->setText(lab_s[Click_Mode+1+4*(j+1)]->text()) ;
                lab_s[Click_Mode+2+j*4]->setText(lab_s[Click_Mode+2+4*(j+1)]->text()) ;
                lab_s[Click_Mode+3+j*4]->setText(lab_s[Click_Mode+3+4*(j+1)]->text()) ;
            }
            for(i=1;i<4;i++)        //清空当前模式数据
            {
               QString str = lab_s[Click_Mode+i+4*j]->text();
               str.clear();
               lab_s[Click_Mode+i+4*j]->setText(str);
            }
            Mode_Count -- ;
            Save_Confige_Flg = false ;
            Click_Mode = 1 ;
        }
        else
        {
            qDebug()<<"No Data" ;
        }

    }
}

void config_manage::save_clicked()
{
    SaveConfigData();
    Save_Confige_Flg = true ;
}

void config_manage::quit_clicked()
{
    if(Save_Confige_Flg)
    {
        Mode_Count_Tmp = Mode_Count ;
        Mode_Count = 0 ;
        main_table->close();
    }
    else
    {
        err_box->setText("参数已修改，但未保存至本地\n是否保存");
        int ret=err_box->exec();
        if(ret==QMessageBox::AcceptRole)
        {
            SaveConfigData();
            Mode_Count_Tmp = Mode_Count ;
            Mode_Count = 0 ;
            Save_Confige_Flg = true ;
            main_table->close();
        }
        else
        {

            Mode_Count_Tmp = Mode_Count ;
            Mode_Count = 0 ;
            main_table->close();
        }

    }
    free_config();

}

void config_manage::SaveConfigData(void)
{
    int i = 0,j = 0;
    int cnt;
    FILE*file = fopen("backup.txt","w+");
    if(file == NULL)
    {
       qDebug()<<"Open File Failed\n";
       return ;
    }
    truncate("backup.ini",sizeof(CONFIG_INFO)*6);
    qDebug()<< " SAVE---Mode_Count = "+QString::number(Mode_Count) ;
    for(j=0;j<Mode_Count;j++)
    {
        if(i<26)       //防止数组越界
        {
            confige_s[j].suoyannumber = lab_s[i+1]->text().toInt();
            confige_s[j].suoyanjuli = lab_s[i+2]->text().toInt();
            confige_s[j].qianmenji = lab_s[i+3]->text().toInt();
            i += 4 ;
        }
        cnt = fwrite(&confige_s[j],sizeof(CONFIG_INFO),1,file) ;
        if(cnt != 1)//返回值不为1表示数据写入失败
        {
            qDebug()<<"Save Failed\n";
        }
    }
    fclose(file);
}

void config_manage::free_config(void)
{

    Mode_Count = 0 ;
}

void config_manage::ReadConfigData(void)
{
    FILE *file=fopen("backup.txt","r+");
    if(file == NULL)
    {
        qDebug()<<"open file faied";
        return ;
    }
    int i = 0 ;
    int cnt = 0 ;
    while(1)
    {
        if(Mode_Count >= 6) break ;
        qDebug()<< "READ---Mode_Count = "+QString::number(Mode_Count) ;
        cnt = fread(&confige_s[Mode_Count],sizeof(CONFIG_INFO),1,file);
        if(cnt != 1)
        {
            qDebug()<<"Read Filed";
            return ;
        }
        if(confige_s[Mode_Count].suoyannumber == 0)break;
        lab_s[i*4+1]->setText(QString::number(confige_s[Mode_Count].suoyannumber));
        lab_s[i*4+2]->setText(QString::number(confige_s[Mode_Count].suoyanjuli));
        lab_s[i*4+3]->setText(QString::number(confige_s[Mode_Count].qianmenji));
        Mode_Count ++ ;
        i ++ ;
        if(i > 6) break ;

    }
    fclose(file);
}


config_manage::~config_manage()
{

}
/*添加参数界面的构造函数*/
AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent)
{
    lab1 = new QLabel("锁眼个数") ;
    lab2 = new QLabel("锁眼距离") ;
    lab3 = new QLabel("前门襟") ;

    line1 = new my_lineedit(this) ;
    line2 = new my_lineedit(this) ;
    line3 = new my_lineedit(this) ;

    ok = new QPushButton("确定") ;
    cal = new QPushButton("取消");
    main_layout = new QGridLayout ;
    hb_layout = new QHBoxLayout ;

    main_layout->addWidget(lab1,0,0,1,1);
    main_layout->addWidget(lab2,1,0,1,1);
    main_layout->addWidget(lab3,2,0,1,1);
    main_layout->addWidget(line1,0,1,1,1);
    main_layout->addWidget(line2,1,1,1,1);
    main_layout->addWidget(line3,2,1,1,1);
    hb_layout->addWidget(ok);
    hb_layout->addWidget(cal);
    main_layout->addLayout(hb_layout,3,0,1,2);
    setLayout(main_layout);

    line1->installEventFilter(this);
    line2->installEventFilter(this);
    line3->installEventFilter(this);

    connect(line1->m_numpad,&numpad::value_changed,this,&AddInfo::setlin1);
    connect(line2->m_numpad,&numpad::value_changed,this,&AddInfo::setlin2);
    connect(line3->m_numpad,&numpad::value_changed,this,&AddInfo::setlin3);
    connect(ok,SIGNAL(clicked()),this,SLOT(ok_clicked()));
    connect(cal,SIGNAL(clicked()),this,SLOT(cal_clicked()));

    war_box =new QMessageBox ;
    yesButton.setText("确定");
    war_box->addButton(&yesButton,QMessageBox::AcceptRole);
    war_box->setIcon(QMessageBox::Warning);


}

void AddInfo::ok_clicked()
{
    if(Mode_Count < 6)
    {

        if(!line1->text().isEmpty())
        {
            if(!line2->text().isEmpty())
            {
                if(!line3->text().isEmpty())
                {
                    close();
                    emit add_success(line1->text(),line2->text(),line3->text());
                }
                else
                {
                    war_box->setText("前门襟为空，请输入");
                    war_box->exec();
                }
            }
            else
            {
                war_box->setText("锁眼距离为空，请输入");
                war_box->exec();
            }
        }
        else
        {
            war_box->setText("锁眼个数为空，请输入");
            war_box->exec();
        }
    }
}
void AddInfo::cal_clicked()
{
    close();
}

void AddInfo::setlin1(QString str)
{
    line1->setText(str);
}

void AddInfo::setlin2(QString str)
{
    line2->setText(str);
}

void AddInfo::setlin3(QString str)
{
    line3->setText(str);
}

bool AddInfo::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(obj == line1)
        {
            line1->m_numpad->VALUE->clear() ;
            line1->m_numpad->exec();
        }
        else if(obj == line2)
        {
            line2->m_numpad->VALUE->clear() ;
            line2->m_numpad->exec();
        }
        else if(obj == line3)
        {
            line3->m_numpad->VALUE->clear() ;
            line3->m_numpad->exec();
        }
    }
}

AddInfo::~AddInfo()
{

}

