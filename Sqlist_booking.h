#ifndef TEST_SQLIST_BK_H
#define TEST_SQLIST_BK_H
typedef struct Node{
    char ticket_id[20];//订单号
    char psg_name[20];//乘车人姓名
    char psg_idtype[20];//订票人证件类型
    char psg_id[20];//订票人证件号
    int seat_level;//座位等级
    float fare;//票价
    int seat_number;//座位号

    struct Node *next;
}Node; // 头节点后面的结点，存储订票人和同行乘客信息（注：同行必须是起点和终点都相同）
typedef struct {
    char Booking_person[20];//订票人姓名
    char Booking_idtype[20];//订票人证件类型
    char Booking_id[20];//订票人证件号
    char Booking_data[20];//订票时间

    char train_data[10];//乘车日期
    char train_num[10];//车次
    char origin_station[10];//起点站
    char terminal_station[10];//终点站
    char departure_time[20];//发车时间
    Node* next=NULL;
}booking_info; //作为订票系统的头节点，头节点包括作为用户登录信息，后面链表包括他的订票信息

char quray_bk[][30]={"订票人姓名","订票人证件类型","订票人证件号",
    "订票时间","乘车日期","列车车次","始发站","终点站",
  "发车时间","票号","乘客姓名","乘客证件类型",
  "乘客证件号","座位等级","票价","座位号"};
typedef  booking_info bk_ElemType;
/*char* query_bk[]={"Booking person","Booking idtype","Booking id","Booking data","train data","origin station","terminal station","departure time",
                  "ticket id","passenger name","seat level","fare","seat number",NULL};*/


//定义数据类型
typedef  struct
{
    bk_ElemType*   elem;    //存储空间基址
    int        length;   //当前长度
    int        listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
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
    //构造一个空的1线性表L
    L.elem = (bk_ElemType * )malloc(LIST_INIT_SIZE * sizeof(bk_ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;//length是线性表的表长，属于这种数据类型的属性
    L.listsize = LIST_INIT_SIZE;//listsize表示线性表初始分配的内存空间大小
    return OK;
}//构造一个空的线性表，长度为0
Status print_tickter(bk_ElemType b)
{
    Node *p=b.next;
    while (p)
    {
        printf("****************************************票据信息**********************************\n");
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
    /*取车次的整数部分*/
    char num11[5];
    int pos=0;
    for (char i : t.train_number) {
        if('0'<=i&&i<='9')
            num11[pos++]=i;
    }
    char *temp;//用于储存最终生成的字符串
    temp = (char *)malloc(sizeof(char)*50);//申请内存空间，此处申请大小为50个字符(char)的大小 (2)
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
    /*假设已经查询到了：这个乘客信息和这趟列车中这个站点的信息*/
    /*
    param: booking == TRUE 订票人信息输入，用户登录
     */
    if(booking)
    {
        /*
         * 获得订票人的信息，其中包括必须输入的三个信息是：
         * 乘车日期（这个是你想买几号的票，假设每趟列车每天的发车时间，途径等都是不变的），
         * 起点站
         * 终点站
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
         * 先创建票的结点
         * 必要输入信息仅有：
         * 自己选择的座位水平，这里座位号有点缺点，就是不能按照车次和座位等级排序
         */
        Node *m = (Node*) malloc(sizeof(Node));
        if(m==NULL)
            exit(OVERFLOW);
        printf("请输入该票的座位等级:\n");
        scanf("%d",&(m->seat_level));

        strcpy(m->psg_name,p.name);
        strcpy(m->psg_idtype,p.idtype);
        strcpy(m->psg_id,p.id);
        char tcid[25];
        tricker_id(t,tcid);
        strcpy(m->ticket_id,tcid);
        /*b方案，自己输入票号*/
        m->seat_number = count_b++; // 一个小缺点，不能按每列车给他排序
        /*剩余座位减少*/
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
        m->fare = price_tickter(m->seat_level,start,end) ; //"计算票价函数返回值"

        m->next = NULL;
        //再设计插入
        if(b.next==NULL)//头结点时插入
            b.next = m;
        else//存在其他结点时插入
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
    printf("*****订票用户登录界面*****:\n");
    /*用户登录：输入证件号*/

    c = search_passenger(passengers, key_psg, TRUE);
    psg_ElemType psg;
    bk_ElemType bk; //bk是一个链表，头结点是用户信息，后面的是账户下的票
    tr_ElemType tr;

    GetElem_psg(passengers,c,psg);// 将找到的这个信息传递给变量k
    //GetElem_bk(b,b.length,bk);

    /*输入起点站和终点站，自动查询车牌（仅直达票）*/
    fl:
    printf("请输入您的乘车日期:\n");
    scanf("%s",bk.train_data);
    int y,tt,d;
    data_chaifen(bk.train_data,y,tt,d);
    if(dates_diff_more_than_two_months(y,tt)!=0)
    {
        printf("日期错误,可能输入日期超过2个月或者是输入之前的日期，重新输入！\n");
        goto fl;
    }
    printf("请输入你的出发地：\n");
    scanf("%s",bk.origin_station);
    printf("请输入您的目的地:\n");
    scanf("%s",bk.terminal_station);
    tr_ElemType station_o,station_e,train;
    int m=0;

    int train_num[20],t=0;
    for (int i = 0; i < num; ++i) {
        if(strcmp(trip_table[i]->data.situation,"停运")==0)
            continue;
        if(search_trip_4_tk(trip_table[i],bk.origin_station,station_o))
        {
            if (search_trip_4_tk(trip_table[i],bk.terminal_station,station_e)) {
                train_num[t++]=i;
                printf("*****可以运行的列车*****\n");
                print_trip_info_all(trip_table[i]);
                //当同一趟车存在起点站和恶终点站是，是直达票，这时返回这儿趟车的序号
            }
        }
    }

    /*选择高铁*/
    printf("有如下几趟车符合要求你选择第几趟？\n输入选择的列车(输入1,2,3。。。):\n");
    scanf("%d",&m);
    train = trip_table[train_num[m]]->data;
    /*用户登录，为保证订票数量,仅能定同程的票*/
    printf("请输入您的证件号登录系统:\n");
    scanf_bk_info(bk,psg,train,bk.origin_station,bk.terminal_station,TRUE);
    label:
    printf("您要预订几个人的票:\n");
    int peopel;
    scanf("%d",&peopel);
    if(peopel>3)//限定没人三张票
    {
        printf("最多预订三个人的票！\n请重新输入人数\n");
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
    printf("请选择您要查询的依据:\n");
    printf("0:乘客姓名:\n1:乘客证件号:\n2:乘车日期:\n3:车次:\n");
    int i;
    char item[20];
    printf("输入:\n");
    scanf("%d",&i);
    printf("输入信息:\n");
    scanf("%s",item);
    for (int j = 0; j < L.length; ++j) {
        int c=0;
        Node* n=L.elem[j].next;
        while (n) {
            if(search_key_bk_2(L.elem[j], n, i,item))
            {
                printf("****************************************票据信息**********************************\n");
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
    printf("请选择您要查询的依据:\n");
    printf("0:乘客姓名:\n1:乘客证件号:\n2:乘车日期:\n3:车次:\n");
    int i;
    int c=0;
    char item[20];
    scanf("%d",&i);
    printf("输入:\n");
    scanf("%s",item);
    for (int j = 0; j < L.length; ++j) {
        Node* n=L.elem[j].next;

        while (n) {
            c++;//c=1是说明是第一个节点
            if(search_key_bk(L.elem[j], n, i,item))
            {
                printf("您想要删除的票如下:\n");
                printf("****************************************票据信息**********************************\n");
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
                printf("*****改票据已删除*****");
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
    printf("*****余票查询*****\n");
    printf("您想查询的项是：\n");
    printf("\n0:车次\n1:起点\n2:终点\n");
    printf("请输入:\n");
    scanf("%d",&c);
    char item[30];
    printf("输入查询项：\n");
    scanf("%s",item);
    printf("*****%s剩余*****\n",item);
    for (int i = 0; i < num; ++i) {
        if(search_key_tr(trip_table[i],0,item,e))
        {
            printf("商务座  一等座  二等座\n");
            printf("%d%10d%10d\n",trip_table[i]->data.seat1,trip_table[i]->data.seat2,trip_table[i]->data.seat3);
        }
    }
    return OK;
}

#endif //TEST_SQLIST_BK_H
