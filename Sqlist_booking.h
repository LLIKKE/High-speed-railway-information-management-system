#ifndef TEST_SQLIST_BK_H
#define TEST_SQLIST_BK_H
typedef struct Node{
    char ticket_id[20];//������
    char psg_name[20];//�˳�������
    char psg_idtype[20];//��Ʊ��֤������
    char psg_id[20];//��Ʊ��֤����
    int seat_level;//��λ�ȼ�
    float fare;//Ʊ��
    int seat_number;//��λ��

    struct Node *next;
}Node; // ͷ�ڵ����Ľ�㣬�洢��Ʊ�˺�ͬ�г˿���Ϣ��ע��ͬ�б����������յ㶼��ͬ��
typedef struct {
    char Booking_person[20];//��Ʊ������
    char Booking_idtype[20];//��Ʊ��֤������
    char Booking_id[20];//��Ʊ��֤����
    char Booking_data[20];//��Ʊʱ��

    char train_data[10];//�˳�����
    char train_num[10];//����
    char origin_station[10];//���վ
    char terminal_station[10];//�յ�վ
    char departure_time[20];//����ʱ��
    Node* next=NULL;
}booking_info; //��Ϊ��Ʊϵͳ��ͷ�ڵ㣬ͷ�ڵ������Ϊ�û���¼��Ϣ����������������Ķ�Ʊ��Ϣ

char quray_bk[][30]={"��Ʊ������","��Ʊ��֤������","��Ʊ��֤����",
    "��Ʊʱ��","�˳�����","�г�����","ʼ��վ","�յ�վ",
  "����ʱ��","Ʊ��","�˿�����","�˿�֤������",
  "�˿�֤����","��λ�ȼ�","Ʊ��","��λ��"};
typedef  booking_info bk_ElemType;
/*char* query_bk[]={"Booking person","Booking idtype","Booking id","Booking data","train data","origin station","terminal station","departure time",
                  "ticket id","passenger name","seat level","fare","seat number",NULL};*/


//������������
typedef  struct
{
    bk_ElemType*   elem;    //�洢�ռ��ַ
    int        length;   //��ǰ����
    int        listsize; //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

int data_chaifen(char dat[],int &year,int &month,int &day)
{
    char y[5],m[5],d[5];
    for (int i = 0; i < 4; ++i)
    {
        y[i]=dat[i];
    }
    for (int i = 4; i < 6; ++i)
    {
        m[i-4]=dat[i];
    }
    for (int i = 6; i < 8; ++i)
    {
        d[i-6]=dat[i];
    }
    year=atoi(y);
    month= atoi(m);
    day= atoi(d);
    return OK;
}
int dates_diff_more_than_two_months(int y,int m)
{
    int t;
    if (date.year != y) {
        t = (y-date.year) * 12 + abs(m-date.month) > 2;
    }
    else
        t=m-date.month;
    if (t>=2)
        return 1;
    else if(t>=0)
        return 0;
    else
        return -1;
}
Status InitList_bk(SqList& L)
{
    //����һ���յ�1���Ա�L
    L.elem = (bk_ElemType * )malloc(LIST_INIT_SIZE * sizeof(bk_ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;//length�����Ա�ı������������������͵�����
    L.listsize = LIST_INIT_SIZE;//listsize��ʾ���Ա��ʼ������ڴ�ռ��С
    return OK;
}//����һ���յ����Ա�����Ϊ0
Status print_tickter(bk_ElemType b)
{
    Node *p=b.next;
    while (p)
    {
        printf("****************************************Ʊ����Ϣ**********************************\n");
        printf("%8s%17s%15s%15s%11s%6s\n",quray_bk[9],quray_bk[10],quray_bk[11],quray_bk[12],quray_bk[13],quray_bk[14]);
        printf("%11s",p->ticket_id);
        printf("%9s",p->psg_name);
        printf("%8s",p->psg_idtype);
        printf("%22s",p->psg_id);
        printf("%8d",p->seat_level);
        printf("%9.1f",p->fare);
        printf("\n%s%11s%11s%11s%11s%11s\n",quray_bk[15],quray_bk[4],quray_bk[5],quray_bk[6],quray_bk[7],quray_bk[8]);
        printf("%4d",p->seat_number);
        printf("%11s",b.train_data);
        printf("%11s",b.train_num);
        printf("%13s",b.origin_station);
        printf("%13s",b.terminal_station);
        printf("%9s",b.departure_time);
        printf("\n**********************************************************************************\n");
        p=p->next;
    }
    return OK;

}
Status ListTraverse_bk(SqList L,int (*f)(bk_ElemType))
{
    int i=0;
    while (i<=L.length-1)
        f(L.elem[i++]);
        //print_tickter(L.elem[i++]);
    return OK;
}
Status print_all_tickter(SqList L)
{
    ListTraverse_bk(L,print_tickter);
    return OK;
}
Status tricker_id(tr_ElemType t,char tpid[])
{
    /*ȡ���ε���������*/
    char num11[5];
    int pos=0;
    for (char i : t.train_number) {
        if('0'<=i&&i<='9')
            num11[pos++]=i;
    }
    char *temp;//���ڴ����������ɵ��ַ���
    temp = (char *)malloc(sizeof(char)*50);//�����ڴ�ռ䣬�˴������СΪ50���ַ�(char)�Ĵ�С (2)
    char aa[]="-",ab[]="-";
    char sit[4];
    int acc = sprintf(sit,"%d",count_b);
    strcpy(temp,time_s);
    strcat(temp,aa);
    strcat(temp,num11);
    strcat(temp,ab);
    strcat(temp,sit);
    strcpy(tpid,temp);
    free(temp);
    return OK;
}
Status scanf_bk_info(bk_ElemType &b,psg_ElemType p,tr_ElemType t,char start[],char end[],int booking=FALSE)
{
    /*�����Ѿ���ѯ���ˣ�����˿���Ϣ�������г������վ�����Ϣ*/
    /*
    param: booking == TRUE ��Ʊ����Ϣ���룬�û���¼
     */
    if(booking)
    {
        /*
         * ��ö�Ʊ�˵���Ϣ�����а������������������Ϣ�ǣ�
         * �˳����ڣ�����������򼸺ŵ�Ʊ������ÿ���г�ÿ��ķ���ʱ�䣬;���ȶ��ǲ���ģ���
         * ���վ
         * �յ�վ
        */
        strcpy(b.Booking_person,p.name);
        strcpy(b.Booking_id,p.id);
        strcpy(b.Booking_idtype,p.idtype);
        strcpy(b.departure_time,t.launch_time);
        strcpy(b.Booking_data,Time);
        strcpy(b.train_num,t.train_number);
    }
    else
    {
        /*
         * �ȴ���Ʊ�Ľ��
         * ��Ҫ������Ϣ���У�
         * �Լ�ѡ�����λˮƽ��������λ���е�ȱ�㣬���ǲ��ܰ��ճ��κ���λ�ȼ�����
         */
        Node *m = (Node*) malloc(sizeof(Node));
        if(m==NULL)
            exit(OVERFLOW);
        printf("�������Ʊ����λ�ȼ�:\n");
        scanf("%d",&(m->seat_level));

        strcpy(m->psg_name,p.name);
        strcpy(m->psg_idtype,p.idtype);
        strcpy(m->psg_id,p.id);
        char tcid[25];
        tricker_id(t,tcid);
        strcpy(m->ticket_id,tcid);
        /*b�������Լ�����Ʊ��*/
        m->seat_number = count_b++; // һ��Сȱ�㣬���ܰ�ÿ�г���������
        /*ʣ����λ����*/
        switch (m->seat_level) {
            case 1:
            {
                t.seat1--;
                break;
            }
            case 2:
            {
                t.seat2--;
                break;
            }
            case 3:
            {
                t.seat3--;
                break;
            }
        }
        m->fare = price_tickter(m->seat_level,start,end) ; //"����Ʊ�ۺ�������ֵ"

        m->next = NULL;
        //����Ʋ���
        if(b.next==NULL)//ͷ���ʱ����
            b.next = m;
        else//�����������ʱ����
        {
            Node* ticker=b.next;
            while (ticker->next)
            {
                ticker=ticker->next;
            }
            ticker->next = m;
        }
    }

    return OK;
}
Status add_book_ticket(SqList &b)
{
    int key_psg;
    int c;
    printf("*****��Ʊ�û���¼����*****:\n");
    /*�û���¼������֤����*/

    c = search_passenger(passengers, key_psg, TRUE);
    psg_ElemType psg;
    bk_ElemType bk; //bk��һ������ͷ������û���Ϣ����������˻��µ�Ʊ
    tr_ElemType tr;

    GetElem_psg(passengers,c,psg);// ���ҵ��������Ϣ���ݸ�����k
    //GetElem_bk(b,b.length,bk);

    /*�������վ���յ�վ���Զ���ѯ���ƣ���ֱ��Ʊ��*/
    fl:
    printf("���������ĳ˳�����:\n");
    scanf("%s",bk.train_data);
    int y,tt,d;
    data_chaifen(bk.train_data,y,tt,d);
    if(dates_diff_more_than_two_months(y,tt)!=0)
    {
        printf("���ڴ���,�����������ڳ���2���»���������֮ǰ�����ڣ��������룡\n");
        goto fl;
    }
    printf("��������ĳ����أ�\n");
    scanf("%s",bk.origin_station);
    printf("����������Ŀ�ĵ�:\n");
    scanf("%s",bk.terminal_station);
    tr_ElemType station_o,station_e,train;
    int m=0;

    int train_num[20],t=0;
    for (int i = 0; i < num; ++i) {
        if(strcmp(trip_table[i]->data.situation,"ͣ��")==0)
            continue;
        if(search_trip_4_tk(trip_table[i],bk.origin_station,station_o))
        {
            if (search_trip_4_tk(trip_table[i],bk.terminal_station,station_e)) {
                train_num[t++]=i;
                printf("*****�������е��г�*****\n");
                print_trip_info_all(trip_table[i]);
                //��ͬһ�˳��������վ�Ͷ��յ�վ�ǣ���ֱ��Ʊ����ʱ��������˳������
            }
        }
    }

    /*ѡ�����*/
    printf("�����¼��˳�����Ҫ����ѡ��ڼ��ˣ�\n����ѡ����г�(����1,2,3������):\n");
    scanf("%d",&m);
    train = trip_table[train_num[m]]->data;
    /*�û���¼��Ϊ��֤��Ʊ����,���ܶ�ͬ�̵�Ʊ*/
    printf("����������֤���ŵ�¼ϵͳ:\n");
    scanf_bk_info(bk,psg,train,bk.origin_station,bk.terminal_station,TRUE);
    label:
    printf("��ҪԤ�������˵�Ʊ:\n");
    int peopel;
    scanf("%d",&peopel);
    if(peopel>3)//�޶�û������Ʊ
    {
        printf("���Ԥ�������˵�Ʊ��\n��������������\n");
        goto label;
    }
    for (int i = 0; i < peopel; ++i) {
        c = search_passenger(passengers, key_psg, TRUE);
        GetElem_psg(passengers,c,psg);
        scanf_bk_info(bk,psg,train,bk.origin_station,bk.terminal_station);
    }
    b.elem[b.length++]=bk;
    print_tickter(bk);
    return OK;
}
Status search_key_bk(bk_ElemType p,Node *n,int i,char item[])
{
    switch (i) {
        case 0:
        {
            if(strcmp(n->psg_name,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 1:
        {
            if(strcmp(n->psg_id,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 2:
        {
            if(strcmp(p.Booking_id,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 3:
        {
            if(strcmp(p.train_num,item)==0)
                return OK;
            else
                return FALSE;
        }
        default:
            return ERROR;
    }
}
Status search_key_bk_2(bk_ElemType p,Node *n,int i,char item[])
{
    switch (i) {
        case 0:
        {
            if(strcmp(n->psg_name,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 1:
        {
            if(strcmp(n->psg_id,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 2:
        {
            if(strcmp(p.train_data,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 3:
        {
            if(strcmp(p.train_num,item)==0)
                return OK;
            else
                return FALSE;
        }
        default:
            return ERROR;
    }
}
Node* ListTraverse_bk_dim1(SqList L,int c,char item[40],int (*f)())
{
    Node *find;
    int i=0;
    while (i<=L.length-1)
    {
        find = L.elem[i++].next;
        while (find)
        {
            if(search_key_bk(L.elem[i++],find,c,item))
                find=find->next;
        }
    }
    return find;
}
Status search_tickter(SqList &L)
{
    printf("��ѡ����Ҫ��ѯ������:\n");
    printf("0:�˿�����:\n1:�˿�֤����:\n2:�˳�����:\n3:����:\n");
    int i;
    char item[20];
    printf("����:\n");
    scanf("%d",&i);
    printf("������Ϣ:\n");
    scanf("%s",item);
    for (int j = 0; j < L.length; ++j) {
        int c=0;
        Node* n=L.elem[j].next;
        while (n) {
            if(search_key_bk_2(L.elem[j], n, i,item))
            {
                printf("****************************************Ʊ����Ϣ**********************************\n");
                printf("%8s%17s%15s%15s%11s%6s\n",quray_bk[9],quray_bk[10],quray_bk[11],quray_bk[12],quray_bk[13],quray_bk[14]);
                printf("%11s",n->ticket_id);
                printf("%9s",n->psg_name);
                printf("%8s",n->psg_idtype);
                printf("%22s",n->psg_id);
                printf("%8d",n->seat_level);
                printf("%9.1f",n->fare);
                printf("\n%s%11s%11s%11s%11s%11s\n",quray_bk[15],quray_bk[4],quray_bk[5],quray_bk[6],quray_bk[7],quray_bk[8]);
                printf("%4d",n->seat_number);
                printf("%11s",L.elem[j].train_data);
                printf("%11s",L.elem[j].train_num);
                printf("%13s",L.elem[j].origin_station);
                printf("%13s",L.elem[j].terminal_station);
                printf("%9s",L.elem[j].departure_time);
                printf("\n**********************************************************************************\n");
            }
            n=n->next;
        }
    }
    return OK;
}
Status search_and_delet_tickter(SqList &L)
{
    printf("��ѡ����Ҫ��ѯ������:\n");
    printf("0:�˿�����:\n1:�˿�֤����:\n2:�˳�����:\n3:����:\n");
    int i;
    int c=0;
    char item[20];
    scanf("%d",&i);
    printf("����:\n");
    scanf("%s",item);
    for (int j = 0; j < L.length; ++j) {
        Node* n=L.elem[j].next;

        while (n) {
            c++;//c=1��˵���ǵ�һ���ڵ�
            if(search_key_bk(L.elem[j], n, i,item))
            {
                printf("����Ҫɾ����Ʊ����:\n");
                printf("****************************************Ʊ����Ϣ**********************************\n");
                printf("%8s%17s%15s%15s%11s%6s\n",quray_bk[9],quray_bk[10],quray_bk[11],quray_bk[12],quray_bk[13],quray_bk[14]);
                printf("%11s",n->ticket_id);
                printf("%9s",n->psg_name);
                printf("%8s",n->psg_idtype);
                printf("%22s",n->psg_id);
                printf("%8d",n->seat_level);
                printf("%9.1f",n->fare);
                printf("\n%s%11s%11s%11s%11s%11s\n",quray_bk[15],quray_bk[4],quray_bk[5],quray_bk[6],quray_bk[7],quray_bk[8]);
                printf("%4d",n->seat_number);
                printf("%11s",L.elem[j].train_data);
                printf("%11s",L.elem[j].train_num);
                printf("%13s",L.elem[j].origin_station);
                printf("%13s",L.elem[j].terminal_station);
                printf("%9s",L.elem[j].departure_time);
                printf("\n**********************************************************************************\n");
                printf("*****��Ʊ����ɾ��*****");
                switch (c) {
                    case 1:
                        L.elem[j].next=NULL;
                        free(n);
                        break;
                    case 2:
                        L.elem[j].next->next=n->next;
                        free(n);
                        break;
                    case 3:
                        L.elem[j].next->next->next=NULL;
                        free(n);
                        break;
                    }
                break;
            }
            n=n->next;
        }

    }

    return OK;
}
Status refund_ticket(SqList L)
{
    search_and_delet_tickter(L);
    return OK;
}
Status Residual_ticket_inquiry()
{
    int c;
    tr_ElemType e;
    printf("*****��Ʊ��ѯ*****\n");
    printf("�����ѯ�����ǣ�\n");
    printf("\n0:����\n1:���\n2:�յ�\n");
    printf("������:\n");
    scanf("%d",&c);
    char item[30];
    printf("�����ѯ�\n");
    scanf("%s",item);
    printf("*****%sʣ��*****\n",item);
    for (int i = 0; i < num; ++i) {
        if(search_key_tr(trip_table[i],0,item,e))
        {
            printf("������  һ����  ������\n");
            printf("%d%10d%10d\n",trip_table[i]->data.seat1,trip_table[i]->data.seat2,trip_table[i]->data.seat3);
        }
    }
    return OK;
}

#endif //TEST_SQLIST_BK_H
