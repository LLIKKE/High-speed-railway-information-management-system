#ifndef HIGHSPEED_RAIL_MANAGEMENT_SYSTEM_DEFINES_H
#define HIGHSPEED_RAIL_MANAGEMENT_SYSTEM_DEFINES_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define QMAXSIZE 100 //队列初始容量
#define STACK_INIT_SIZE 100 //栈初始容量
#define STACK_INCREMENT 10 //栈每次增加的容量
#define LIST_INIT_SIZE    100 //线性表存储空间的初始分配
#define LISTINCREMENT     10  //线性表存储空间的分配增量
typedef struct date
{
    int year,month,day;
}DATE; //定义日期结构体
DATE Get_Sys_Time( ) //返回当前系统时间
{
    struct tm today{}; //存放时间的结构体
    time_t one; //存放时间的类型
    DATE now;
    one=time(&one); //获得系统时间
    today=*(gmtime(&one)); //将 time_t 格式系统时间转为 struct tm 格式
    now.year=today.tm_year-100+2000; //2011 年返回 111
    now.month=today.tm_mon+1; //9 月返回 8;
    now.day=today.tm_mday;
    return now;
}
typedef int Status;
DATE date=Get_Sys_Time();
char Time[10];
char time_s[10];
int time_char = sprintf(Time,"%d-%d-%d",date.year,date.month,date.day);// sprintf:将格式化数据写入字符串
int addd = sprintf(time_s,"%d%d%d",date.year,date.month,date.day);
int count_b = 0;
#endif //HIGHSPEED_RAIL_MANAGEMENT_SYSTEM_DEFINES_H
