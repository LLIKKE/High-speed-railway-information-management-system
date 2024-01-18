#ifndef TEST_LINK_PSG_H
#define TEST_LINK_PSG_H
typedef struct {
    char idtype[10];   //['身份证',‘护照’]
    char id[20];      //证件号
    char name[10];    //乘客姓名
    char phone[15];   //乘客电话号码
    char egy_name[10];//紧急联系人姓名
    char egy_phone[15];//紧急联系人电话
}passenger_info;
// 用于键查找的全局变量
char query_psg[6][40]={"证件类型","证件号","乘客姓名","乘客电话","紧急联系人","紧急联系人电话"};
typedef  passenger_info psg_ElemType;
typedef  struct  LNode_psg
{  psg_ElemType       data;
    struct  LNode_psg  *next;
}LNode_psg, *LinkList_psg;
            /*******************/
        /*****************************/
    /**************************************/
/***************全局变量:乘客信息*****************/
LinkList_psg passengers;
/***************全局变量:乘客信息*****************/
    /**************************************/
        /*****************************/
            /*******************/
Status scanf_passenger_info(psg_ElemType &p)
{
    printf("请输入乘客信息:\n");
    printf("乘客证件号:\n");
    scanf("%s",p.id);
    printf("乘客姓名:\n");
    scanf("%s",p.name);
    printf("乘客证件类型:\n");
    scanf("%s",p.idtype);
    printf("乘客电话:\n");
    scanf("%s",p.phone);
    printf("紧急联系人:\n");
    scanf("%s",p.egy_name);
    printf("乘客紧急联系人电话:\n");
    scanf("%s",p.egy_phone);
    return 1;
}     // 输入新乘客的信息
Status search_key_psg(psg_ElemType &p,int i,char item[20])
{
    switch (i) {
        case 0:
        {
            if(strcmp(p.idtype,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 1:
        {
            if(strcmp(p.id,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 2:
        {
            if(strcmp(p.name,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 3:
        {
            if(strcmp(p.phone,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 4:
        {
            if(strcmp(p.egy_name,item)==0)
                return OK;
            else
                return FALSE;
        }
        case 5:
        {
            if(strcmp(p.egy_phone,item)==0)
                return OK;
            else
                return FALSE;
        }
        default:
            return ERROR;
    }
}  //按照键序号i来匹配对应item的乘客
Status print_passenger_info(psg_ElemType &p)
{
    printf("该乘客信息如下:\n");
    printf("%s:\n%s\n",query_psg[0],p.idtype);
    printf("%s:\n%s\n",query_psg[1],p.id);
    printf("%s:\n%s\n",query_psg[2],p.name);
    printf("%s:\n%s\n",query_psg[3],p.phone);
    printf("%s:\n%s\n",query_psg[4],p.egy_name);
    printf("%s:\n%s\n",query_psg[5],p.egy_phone);
    return OK;
}    // 打印乘客信息
Status modify_key_psg(psg_ElemType &p,int i)
{

    if(i==1)
    {
        printf("不能更改证件号!");
        return ERROR;
    }
    char item[20];
    printf("请输入您想更改的乘客信息:\n");
    scanf("%s",item);
    switch (i) {
        case 0: {
            if (strcpy(p.idtype, item))
                return OK;
            else
                return FALSE;
        }
        case 2: {
            if (strcpy(p.name, item))
                return OK;
            else
                return FALSE;
        }
        case 3: {
            if (strcpy(p.phone, item))
                return OK;
            else
                return FALSE;
        }
        case 4: {
            if (strcpy(p.egy_name, item))
                return OK;
            else
                return FALSE;
        }
        case 5: {
            if (strcpy(p.egy_phone, item))
                return OK;
            else
                return FALSE;
        }
        default:
            return ERROR;

    }
}    //按照键序号i修改乘客信息
Status InitList_psg(LinkList_psg &L)
{
    L = (LinkList_psg) malloc(sizeof(LNode_psg));
    L->next=NULL;
    return OK;
}
Status ListInsert_psg(LinkList_psg &L,int i,psg_ElemType e)
{
    LinkList_psg p=L,s;

    int j=0;
    while (p&&j<i-1)
    {
        p=p->next;
        j++;
    }//p指i-1个节点
    if(!p||j>i-1)
        return ERROR;
    s=(LinkList_psg) malloc(sizeof (LNode_psg));
    s->data=e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status ListLength_psg(LinkList_psg L)
{
    int j=0;
    LinkList_psg q=L->next;
    while (q)
    {
        q=q->next;
        j++;
    }
    return j;
}
Status GetElem_psg(LinkList_psg L,int i,psg_ElemType &e)
{

    int j=1;
    LinkList_psg p=L->next;
    while (p&&j<i)
    {
        p = p->next;
        j++;
    }
    if(!p||j>i)
        return ERROR;
    e = p->data;
    return OK;
}//get函数可以写j=1,因为获得直接获得第一个元素，不用得到第i-1个元素
Status DestroyList_psg(LinkList_psg &L)
{
    LinkList_psg q;
    while (L)
    {
        q=L->next;
        free(L);
        L=q;
    }
    return OK;
}
Status ListDelete_psg(LinkList_psg &L,int i,psg_ElemType &e)
{
    LinkList_psg p,q;
    int j=0;
    p=L;
    while (p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
        return ERROR;
    q=p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}//Delete要写成j=0,因为你要获得第i-1个元素
Status Append_psg(LinkList_psg &L, psg_ElemType e)
{
    LinkList_psg p=L,s;
    while (p->next)
    {
        p=p->next;
    }

    s=(LinkList_psg) malloc(sizeof (LNode_psg));
    s->data=e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status Traverse_psg(LinkList_psg L)
{
    int j=1;
    LinkList_psg p=L->next;
    while (p)
    {
        printf("*****第%d个乘客*****\n",j);
        print_passenger_info(p->data);
        p = p->next;
        j++;
    }
    return OK;
}
Status search_passenger(LinkList_psg L,int &key,int Booking=FALSE){//返回这个乘客的位置
    printf("*****查询乘客系统*****\n");
/*  打印如下信息：
    select query_psg information item:
    Input serial number:
    0:id type
    1:id number
    2:passenger name
    3:passenger phone
    4:passenger's emergency contact name
    5:passenger's emergency contact phone
    Enter the selected number:
*/

    char item[20];
    if(!Booking)
    {
        printf("选择你要查询(或修改的)的项:\n输入如下数字:\n");
        printf("0:%s\n1:%s\n2:%s\n3:%s\n"
               "4:%s\n5:%s\n",query_psg[0],query_psg[1],query_psg[2],query_psg[3],query_psg[4],query_psg[5]);
        printf("请选择数字:\n");
        scanf("%d",&key);//选择查询项的编号
        printf("请输入乘客%s:\n",query_psg[key]);
        scanf("%s",item);//输入乘客的信息项
    } else{
        key=1;
        printf("请输入乘客证件号:\n");
        scanf("%s",item);//输入乘客的信息项
    }



    LinkList_psg q=L;
    int j=0;

    while (q->next)
    {

        q=q->next;
        j++;
        if(search_key_psg(q->data,key,item)) // 找到这个信息项对应的乘客
        {
            print_passenger_info(q->data);
            return j;
        }
    }

    if(j == ListLength_psg(L)) //找不到的情况
    {
        printf("没有找到该乘客!\n");
        return 0;
    }
    return -1; //返回-1时出错了
}
Status add_passenger(LinkList_psg &L)
{
    printf("***** 正在添加一个新乘客 *****\n");
    passenger_info p;
    scanf_passenger_info(p);
    Append_psg(L,p);
    return OK;
}
Status delet_passenger(LinkList_psg &L)
{
    printf("***** 正在删除一个乘客 *****");
    psg_ElemType k;
    int i=-1,key=-1;
    if((i=search_passenger(L,key)))
    {   ListDelete_psg(L,i,k);
        printf("删除成功!");
        return OK;}
    else
        return FALSE;
}
Status modify_passenger(LinkList_psg &L)
{
    printf("*****正在修改乘客信息 *****\n");
    psg_ElemType k;
    int i=-1,key=-1;
    printf("*****首先查询您想要修改的乘客 *****\n");
    if((i=search_passenger(L,key,TRUE)))
    {
        GetElem_psg(L,i,k);
        printf("选择你要修改的项:\n输入如下数字:\n");
        printf("0:%s\n1:%s\n2:%s\n3:%s\n"
               "4:%s\n5:%s\n",query_psg[0],query_psg[1],query_psg[2],query_psg[3],query_psg[4],query_psg[5]);
        printf("请选择数字:\n");
        scanf("%d",&key);//选择查询项的编号
        modify_key_psg(k,key);
        print_passenger_info(k);
        int j=0;
        LinkList_psg p=L;
        while (p&&j<i)
        {
            p=p->next;
            j++;
        }   //让p指向第i个元素
        p->data=k;
        return OK;
    }
    else
        return FALSE;
}
Status read_from_text_psg(LinkList_psg &L,char data_path[]){
    printf("***** 正在从以下路径读入乘客信息:*****\n%s \n",data_path);
    //从txt中读取数据，并保存在链表中
    char str[200];
    char info[6][20];
    const char s[2] = " "; //分隔符
    char *token;
    FILE* fpRead;
    fpRead = fopen(data_path, "r");
    //char ch= fgetc(fpRead);
    //fscanf(fpRead,"%[^\n]", str);
    while (fgets(str,sizeof(str),fpRead) != NULL) {
        /* 获取第一个子字符串 */
        token = strtok(str, s);
        /* 继续获取其他的子字符串 */
        int i = 0;
        while (token != NULL) {
            //printf( "%s\n", token );
            strcpy(info[i++], token);
            token = strtok(NULL, s);

        }
        psg_ElemType pas_info;
        strcpy(pas_info.idtype, info[2]);
        strcpy(pas_info.id, info[0]);
        strcpy(pas_info.name, info[1]);
        strcpy(pas_info.phone, info[3]);
        strcpy(pas_info.egy_name, info[4]);
        strcpy(pas_info.egy_phone, info[5]);
        Append_psg(L, pas_info);
    }
    printf("全部乘客信息已经被读入!\n*****\n");
    return OK;
};
Status print_all_passenger(LinkList_psg L){
    printf("***** 正在打印全部乘客信息 *****\n");
    Traverse_psg(L);
    printf("***** 全部乘客信息已经被成功打印!*****\n");
    return OK;
}
#endif //TEST_LINK_PSG_H
