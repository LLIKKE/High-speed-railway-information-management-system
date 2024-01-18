#include <conio.h>
#include "defines.h"
#include "Link_passenger.h"
#include "Link_train.h"
#include "Sqlist_booking.h"

char author[][1]={"李珂"};
char train_path[]="train.txt";
char passenger_path[]="passenger.txt";

char main_screen()     //显示主菜单
{
    char choice;
    printf("\n@@@@@@@@@@@高铁管理系统系统@@@@@@@@@\n");
    printf(" 1.高铁车次信息管理\n");   //显示主菜单
    printf(" 2.乘客信息管理\n");
    printf(" 3.高铁订票信息管理\n");
    printf(" 0.退出\n");
    printf(" 请选择(0-3):");
    choice=getche();
    printf("\n");         //获得选择
    return choice;
}

char psg_mana_screen(void)     //学生信息管理主菜单
{
    char choice;
    printf("\n-----乘客管理-------\n");
    printf("1.从文件总读入乘客信息\n");
    printf("2.增加一个乘客\n");
    printf("3.删除一个乘客\n");
    printf("4.乘客查询\n");
    printf("5.乘客信息修改\n");
    printf("6.输出所有乘客信息\n");
    printf("0.退出\n");
    printf("请选择(0-6):");
    choice=getche(); printf("\n");         //获得选择
    return choice;
}
char tr_mana_screen(void)     //学生信息管理主菜单
{
    char choice;
    printf("\n-----火车管理-------\n");
    printf("1.从文件总读入列车信息\n");
    printf("2.增加一趟列车\n");
    printf("3.停开一趟列车\n");
    printf("4.列车查询\n");
    printf("5.列车信息修改\n");
    printf("6.输出所有列车信息\n");
    printf("0.退出\n");
    printf("请选择(0-6):");
    choice=getche(); printf("\n");         //获得选择
    return choice;
}
char bk_mana_screen()     //学生信息管理主菜单
{
    char choice;
    printf("\n-----订票管理-------\n");
    printf("1.订票\n");
    printf("2.退票\n");
    printf("3.车票信息查询\n");
    printf("4.余票查询\n");
    printf("5.输出所有车票信息\n");
    printf("0.退出\n");
    printf("请选择(0-5):");
    choice=getche(); printf("\n");         //获得选择
    return choice;
}
void passenge_manager()
{  //乘客信息管理
    char c;
    int key;
    while((c=psg_mana_screen())!='0')
        switch(c)
        {
            case '1':
                read_from_text_psg(passengers,passenger_path);    break;  //读入乘客信息
            case '2':
                add_passenger(passengers);break;  //增加乘客信息
            case '3':
                delet_passenger(passengers); break;   //删除乘客信息
            case '4':
                search_passenger(passengers,key);break;  //查询乘客信息
            case '5':
                modify_passenger(passengers);break;     //修改乘客信息
            case '6':
                print_all_passenger(passengers);break;
            default:
                break;
        }
}
void booking_manager(SqList &b)
{  //订票信息管理
    char c;
    int key;
    while((c=bk_mana_screen())!='0')
        switch(c)
        {
            case '1':
                add_book_ticket(b);break;
            case '2':
                refund_ticket(b);break;
            case '3':
                search_tickter(b); break;
            case '4':
                Residual_ticket_inquiry();break;
            case '5':
                print_all_tickter(b);break;
            default:
                break;
        }
}
void train_manager()
{  //列车信息管理
    char c;

    while((c=tr_mana_screen())!='0')
        switch(c)
        {
            case '1':
                read_from_text_tr(trip_table, train_path);break;  //从文件读入列车信息
            case '2':
                add_trip_next(trip_table);break;  //增加一趟列车信息
            case '3':
                stop_trip(trip_table); break;   //删除一趟列车信息
            case '4':
                search_trip(trip_table);break;  //查询列车信息
            case '5':
                modify_trip(trip_table);break;   //修改列车信息
            case '6':
                show_all_trip(trip_table);break;//打印全部列车信息
            default:
                break;
        }
}
void sys_manager(SqList &booking)
{
    char c;
    while((c=main_screen())!='0')
        switch(c)
        {
            case '1': train_manager();    break;
            case '2': passenge_manager();    break;
            case '3': booking_manager(booking);   break;
        }
}
int main() {

        /*已在头文件定义trip_table,passengers作为全局变量使用*/
        SqList booking;
        InitList_bk(booking);
        InitList_psg(passengers);

        sys_manager(booking);
/*        read_from_text_tr(trip_table, train_path);
        add_passenger(passengers);
        delet_passenger(passengers);
        modify_passenger(passengers);

        read_from_text_psg(passengers, passenger_path);
        print_all_passenger(passengers);
        add_trip_next(trip_table);
        show_all_trip(trip_table);
        add_book_ticket(booking);
        print_all_tickter(booking);
        refund_ticket(booking);*/

        getchar();
        return 0;
}