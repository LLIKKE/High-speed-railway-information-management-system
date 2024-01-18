#include <conio.h>
#include "defines.h"
#include "Link_passenger.h"
#include "Link_train.h"
#include "Sqlist_booking.h"

char author[][1]={"����"};
char train_path[]="train.txt";
char passenger_path[]="passenger.txt";

char main_screen()     //��ʾ���˵�
{
    char choice;
    printf("\n@@@@@@@@@@@��������ϵͳϵͳ@@@@@@@@@\n");
    printf(" 1.����������Ϣ����\n");   //��ʾ���˵�
    printf(" 2.�˿���Ϣ����\n");
    printf(" 3.������Ʊ��Ϣ����\n");
    printf(" 0.�˳�\n");
    printf(" ��ѡ��(0-3):");
    choice=getche();
    printf("\n");         //���ѡ��
    return choice;
}

char psg_mana_screen(void)     //ѧ����Ϣ�������˵�
{
    char choice;
    printf("\n-----�˿͹���-------\n");
    printf("1.���ļ��ܶ���˿���Ϣ\n");
    printf("2.����һ���˿�\n");
    printf("3.ɾ��һ���˿�\n");
    printf("4.�˿Ͳ�ѯ\n");
    printf("5.�˿���Ϣ�޸�\n");
    printf("6.������г˿���Ϣ\n");
    printf("0.�˳�\n");
    printf("��ѡ��(0-6):");
    choice=getche(); printf("\n");         //���ѡ��
    return choice;
}
char tr_mana_screen(void)     //ѧ����Ϣ�������˵�
{
    char choice;
    printf("\n-----�𳵹���-------\n");
    printf("1.���ļ��ܶ����г���Ϣ\n");
    printf("2.����һ���г�\n");
    printf("3.ͣ��һ���г�\n");
    printf("4.�г���ѯ\n");
    printf("5.�г���Ϣ�޸�\n");
    printf("6.��������г���Ϣ\n");
    printf("0.�˳�\n");
    printf("��ѡ��(0-6):");
    choice=getche(); printf("\n");         //���ѡ��
    return choice;
}
char bk_mana_screen()     //ѧ����Ϣ�������˵�
{
    char choice;
    printf("\n-----��Ʊ����-------\n");
    printf("1.��Ʊ\n");
    printf("2.��Ʊ\n");
    printf("3.��Ʊ��Ϣ��ѯ\n");
    printf("4.��Ʊ��ѯ\n");
    printf("5.������г�Ʊ��Ϣ\n");
    printf("0.�˳�\n");
    printf("��ѡ��(0-5):");
    choice=getche(); printf("\n");         //���ѡ��
    return choice;
}
void passenge_manager()
{  //�˿���Ϣ����
    char c;
    int key;
    while((c=psg_mana_screen())!='0')
        switch(c)
        {
            case '1':
                read_from_text_psg(passengers,passenger_path);    break;  //����˿���Ϣ
            case '2':
                add_passenger(passengers);break;  //���ӳ˿���Ϣ
            case '3':
                delet_passenger(passengers); break;   //ɾ���˿���Ϣ
            case '4':
                search_passenger(passengers,key);break;  //��ѯ�˿���Ϣ
            case '5':
                modify_passenger(passengers);break;     //�޸ĳ˿���Ϣ
            case '6':
                print_all_passenger(passengers);break;
            default:
                break;
        }
}
void booking_manager(SqList &b)
{  //��Ʊ��Ϣ����
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
{  //�г���Ϣ����
    char c;

    while((c=tr_mana_screen())!='0')
        switch(c)
        {
            case '1':
                read_from_text_tr(trip_table, train_path);break;  //���ļ������г���Ϣ
            case '2':
                add_trip_next(trip_table);break;  //����һ���г���Ϣ
            case '3':
                stop_trip(trip_table); break;   //ɾ��һ���г���Ϣ
            case '4':
                search_trip(trip_table);break;  //��ѯ�г���Ϣ
            case '5':
                modify_trip(trip_table);break;   //�޸��г���Ϣ
            case '6':
                show_all_trip(trip_table);break;//��ӡȫ���г���Ϣ
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

        /*����ͷ�ļ�����trip_table,passengers��Ϊȫ�ֱ���ʹ��*/
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