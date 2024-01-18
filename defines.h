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
#define QMAXSIZE 100 //���г�ʼ����
#define STACK_INIT_SIZE 100 //ջ��ʼ����
#define STACK_INCREMENT 10 //ջÿ�����ӵ�����
#define LIST_INIT_SIZE    100 //���Ա�洢�ռ�ĳ�ʼ����
#define LISTINCREMENT     10  //���Ա�洢�ռ�ķ�������
typedef struct date
{
    int year,month,day;
}DATE; //�������ڽṹ��
DATE Get_Sys_Time( ) //���ص�ǰϵͳʱ��
{
    struct tm today{}; //���ʱ��Ľṹ��
    time_t one; //���ʱ�������
    DATE now;
    one=time(&one); //���ϵͳʱ��
    today=*(gmtime(&one)); //�� time_t ��ʽϵͳʱ��תΪ struct tm ��ʽ
    now.year=today.tm_year-100+2000; //2011 �귵�� 111
    now.month=today.tm_mon+1; //9 �·��� 8;
    now.day=today.tm_mday;
    return now;
}
typedef int Status;
DATE date=Get_Sys_Time();
char Time[10];
char time_s[10];
int time_char = sprintf(Time,"%d-%d-%d",date.year,date.month,date.day);// sprintf:����ʽ������д���ַ���
int addd = sprintf(time_s,"%d%d%d",date.year,date.month,date.day);
int count_b = 0;
#endif //HIGHSPEED_RAIL_MANAGEMENT_SYSTEM_DEFINES_H
