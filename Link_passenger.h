#ifndef TEST_LINK_PSG_H
#define TEST_LINK_PSG_H
typedef struct {
    char idtype[10];   //['���֤',�����ա�]
    char id[20];      //֤����
    char name[10];    //�˿�����
    char phone[15];   //�˿͵绰����
    char egy_name[10];//������ϵ������
    char egy_phone[15];//������ϵ�˵绰
}passenger_info;
// ���ڼ����ҵ�ȫ�ֱ���
char query_psg[6][40]={"֤������","֤����","�˿�����","�˿͵绰","������ϵ��","������ϵ�˵绰"};
typedef  passenger_info psg_ElemType;
typedef  struct  LNode_psg
{  psg_ElemType       data;
    struct  LNode_psg  *next;
}LNode_psg, *LinkList_psg;
            /*******************/
        /*****************************/
    /**************************************/
/***************ȫ�ֱ���:�˿���Ϣ*****************/
LinkList_psg passengers;
/***************ȫ�ֱ���:�˿���Ϣ*****************/
    /**************************************/
        /*****************************/
            /*******************/
Status scanf_passenger_info(psg_ElemType &p)
{
    printf("������˿���Ϣ:\n");
    printf("�˿�֤����:\n");
    scanf("%s",p.id);
    printf("�˿�����:\n");
    scanf("%s",p.name);
    printf("�˿�֤������:\n");
    scanf("%s",p.idtype);
    printf("�˿͵绰:\n");
    scanf("%s",p.phone);
    printf("������ϵ��:\n");
    scanf("%s",p.egy_name);
    printf("�˿ͽ�����ϵ�˵绰:\n");
    scanf("%s",p.egy_phone);
    return 1;
}     // �����³˿͵���Ϣ
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
}  //���ռ����i��ƥ���Ӧitem�ĳ˿�
Status print_passenger_info(psg_ElemType &p)
{
    printf("�ó˿���Ϣ����:\n");
    printf("%s:\n%s\n",query_psg[0],p.idtype);
    printf("%s:\n%s\n",query_psg[1],p.id);
    printf("%s:\n%s\n",query_psg[2],p.name);
    printf("%s:\n%s\n",query_psg[3],p.phone);
    printf("%s:\n%s\n",query_psg[4],p.egy_name);
    printf("%s:\n%s\n",query_psg[5],p.egy_phone);
    return OK;
}    // ��ӡ�˿���Ϣ
Status modify_key_psg(psg_ElemType &p,int i)
{

    if(i==1)
    {
        printf("���ܸ���֤����!");
        return ERROR;
    }
    char item[20];
    printf("������������ĵĳ˿���Ϣ:\n");
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
}    //���ռ����i�޸ĳ˿���Ϣ
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
    }//pָi-1���ڵ�
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
}//get��������дj=1,��Ϊ���ֱ�ӻ�õ�һ��Ԫ�أ����õõ���i-1��Ԫ��
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
}//DeleteҪд��j=0,��Ϊ��Ҫ��õ�i-1��Ԫ��
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
        printf("*****��%d���˿�*****\n",j);
        print_passenger_info(p->data);
        p = p->next;
        j++;
    }
    return OK;
}
Status search_passenger(LinkList_psg L,int &key,int Booking=FALSE){//��������˿͵�λ��
    printf("*****��ѯ�˿�ϵͳ*****\n");
/*  ��ӡ������Ϣ��
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
        printf("ѡ����Ҫ��ѯ(���޸ĵ�)����:\n������������:\n");
        printf("0:%s\n1:%s\n2:%s\n3:%s\n"
               "4:%s\n5:%s\n",query_psg[0],query_psg[1],query_psg[2],query_psg[3],query_psg[4],query_psg[5]);
        printf("��ѡ������:\n");
        scanf("%d",&key);//ѡ���ѯ��ı��
        printf("������˿�%s:\n",query_psg[key]);
        scanf("%s",item);//����˿͵���Ϣ��
    } else{
        key=1;
        printf("������˿�֤����:\n");
        scanf("%s",item);//����˿͵���Ϣ��
    }



    LinkList_psg q=L;
    int j=0;

    while (q->next)
    {

        q=q->next;
        j++;
        if(search_key_psg(q->data,key,item)) // �ҵ������Ϣ���Ӧ�ĳ˿�
        {
            print_passenger_info(q->data);
            return j;
        }
    }

    if(j == ListLength_psg(L)) //�Ҳ��������
    {
        printf("û���ҵ��ó˿�!\n");
        return 0;
    }
    return -1; //����-1ʱ������
}
Status add_passenger(LinkList_psg &L)
{
    printf("***** �������һ���³˿� *****\n");
    passenger_info p;
    scanf_passenger_info(p);
    Append_psg(L,p);
    return OK;
}
Status delet_passenger(LinkList_psg &L)
{
    printf("***** ����ɾ��һ���˿� *****");
    psg_ElemType k;
    int i=-1,key=-1;
    if((i=search_passenger(L,key)))
    {   ListDelete_psg(L,i,k);
        printf("ɾ���ɹ�!");
        return OK;}
    else
        return FALSE;
}
Status modify_passenger(LinkList_psg &L)
{
    printf("*****�����޸ĳ˿���Ϣ *****\n");
    psg_ElemType k;
    int i=-1,key=-1;
    printf("*****���Ȳ�ѯ����Ҫ�޸ĵĳ˿� *****\n");
    if((i=search_passenger(L,key,TRUE)))
    {
        GetElem_psg(L,i,k);
        printf("ѡ����Ҫ�޸ĵ���:\n������������:\n");
        printf("0:%s\n1:%s\n2:%s\n3:%s\n"
               "4:%s\n5:%s\n",query_psg[0],query_psg[1],query_psg[2],query_psg[3],query_psg[4],query_psg[5]);
        printf("��ѡ������:\n");
        scanf("%d",&key);//ѡ���ѯ��ı��
        modify_key_psg(k,key);
        print_passenger_info(k);
        int j=0;
        LinkList_psg p=L;
        while (p&&j<i)
        {
            p=p->next;
            j++;
        }   //��pָ���i��Ԫ��
        p->data=k;
        return OK;
    }
    else
        return FALSE;
}
Status read_from_text_psg(LinkList_psg &L,char data_path[]){
    printf("***** ���ڴ�����·������˿���Ϣ:*****\n%s \n",data_path);
    //��txt�ж�ȡ���ݣ���������������
    char str[200];
    char info[6][20];
    const char s[2] = " "; //�ָ���
    char *token;
    FILE* fpRead;
    fpRead = fopen(data_path, "r");
    //char ch= fgetc(fpRead);
    //fscanf(fpRead,"%[^\n]", str);
    while (fgets(str,sizeof(str),fpRead) != NULL) {
        /* ��ȡ��һ�����ַ��� */
        token = strtok(str, s);
        /* ������ȡ���������ַ��� */
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
    printf("ȫ���˿���Ϣ�Ѿ�������!\n*****\n");
    return OK;
};
Status print_all_passenger(LinkList_psg L){
    printf("***** ���ڴ�ӡȫ���˿���Ϣ *****\n");
    Traverse_psg(L);
    printf("***** ȫ���˿���Ϣ�Ѿ����ɹ���ӡ!*****\n");
    return OK;
}
#endif //TEST_LINK_PSG_H
