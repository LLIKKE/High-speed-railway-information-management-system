#ifndef TEST_LINK_TR_H
#define TEST_LINK_TR_H
int num; //��������
typedef struct trip_info
{
    //int total_num;
    char train_number[5]; //����
    char SHIFA[10]; //ʼ��վվ��
    char ZHONGDAO[10];//�յ�վվ��
    int distance; //�����
    char situation[8]; //����������Ƿ�ͣ�ˣ�
    char launch_time[7]; //����ʱ��
    char arr_time[7]; //����ʱ��
    int  station_num;
    int seat1; //һ����������������
    int seat2;
    int seat3;

    //;��վ��
    char TK_name[10];
    char l_time [7]; //;������ʱ��
    char r_time [7]; //;�������
    float distance_1; //;������
}trip_info;

typedef trip_info tr_ElemType;
typedef  struct  LNode
{   tr_ElemType   data;
    struct  LNode  *next;
}LNode, *LinkList;
            /*******************/
        /*****************************/
    /**************************************/
/***************ȫ�ֱ���:����Ϣ*****************/
LinkList trip_table[100];
/***************ȫ�ֱ���:����Ϣ*****************/
    /**************************************/
        /*****************************/
            /*******************/
char query1[5][20]={"���ݳ��β���",  //��ѯʱ���
                    "ʼ��վ����",
                    "�յ�վ����",
                    "����ʱ�����",
                    ";����վ����"};

char query2[11][20]={"����",        //��ӡ������ʱ�ı��
                     "ʼ��վ",
                     "�յ�վ",
                     "�����",
                     "�������",
                     "����",
                     "����",
                     ";��վ",
                     "һ����",
                     "������",
                     "������"};
/*�г���Ϣʹ�ú���*/
Status scanf_trip_info_head(tr_ElemType &p)
{
    //����ͷ�ڵ���Ϣ

    printf("�г�����:\n");
    scanf("%s",p.train_number);
    printf("�г�ʼ��վ:\n");
    scanf("%s",p.SHIFA);
    printf("�г��յ�վ:\n");
    scanf("%s",p.ZHONGDAO);
    printf("��ʻ��·��:\n");
    scanf("%d",&p.distance);
    printf("�г�����״̬:\n");
    scanf("%s",p.situation);
    printf("����ʱ��:\n");
    scanf("%s",p.launch_time);
    printf("��վʱ��:\n");
    scanf("%s",p.arr_time);
    printf(";����վ��:\n");
    scanf("%d",&p.station_num);
    printf("������ʣ������:\n");
    scanf("%d",&p.seat1);
    printf("һ�Ȳ�ʣ������:\n");
    scanf("%d",&p.seat2);
    printf("���Ȳ�ʣ������:\n");
    scanf("%d",&p.seat3);

    return OK;
}
Status scanf_trip_info_TK(tr_ElemType &p){
    printf(";��վ��:\n");
    scanf("%s",p.TK_name);
    printf("����ʱ��:\n");
    scanf("%s",p.l_time);
    printf("����ʱ��:\n");
    scanf("%s",p.r_time);
    printf("����ʻ����:\n");
    scanf("%f",&p.distance_1);
    return OK;
}
Status search_trip_4_tk(LinkList L,char start[],tr_ElemType &station)
{
    LinkList p=L->next;
    while (p)
    {
        if(strcmp(p->data.TK_name,start)==0) {
            station = p->data;
            return OK;
        }
        p=p->next;
    }
    return FALSE;
}
Status search_key_tr(LinkList L,int i, char item[], tr_ElemType &q)
{
    switch (i) {
        case 0:
        {LinkList p=L;
            if(strcmp(item, p->data.train_number)==0)
            {   q=p->data;
                return OK;
            } else return FALSE;}
        case 1:
        {LinkList p=L;
            if(strcmp(item, p->data.SHIFA)==0)
            {   q=p->data;
                return OK;
            } else return FALSE;}
        case 2:
        {LinkList p=L;
            if(strcmp(item, p->data.ZHONGDAO)==0)
            {   q=p->data;
                return OK;
            } else return FALSE;}
        case 3:
        {LinkList p=L;
            if(strcmp(item, p->data.launch_time) == 0)
            {   q=p->data;
                return OK;
            } else return FALSE;}
        case 4: {
            LinkList p = L->next;
            while (p) {
                if (strcmp(item, p->data.TK_name) == 0) {
                    q = L->data;
                    return OK;
                }
                p = p->next;
            }
            return FALSE;
        }
        default:
            return ERROR;
    }
}
Status print_trip_info_head(tr_ElemType &p)
{
    // ��ӡ������Ϣ, ��ͷ
    //printf("The trip's information is as follows:\n");
    printf("%s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s\n",query2[0],query2[1],query2[2],query2[3],query2[4],query2[5],query2[6],query2[7],query2[8],query2[9],query2[10]);
    printf("%s ",p.train_number);
    printf("%7s ",p.SHIFA);
    printf("%7s ",p.ZHONGDAO);
    printf("%7d ",p.distance);//�����
    printf("%7s ",p.situation);//�������
    printf("%7s ",p.launch_time);//����ʱ��
    printf("%7s ",p.arr_time);//����ʱ��
    printf("%7d ",p.station_num);//վ��
    printf("%7d ",p.seat1);//����������
    printf("%7d ",p.seat2);//һ��������
    printf("%7d\n",p.seat3);//����������
    //���Ρ�ʼ��վ���յ�վ������̡�����������Ƿ�ͣ�ˣ�������ʱ�䡢�ﵽʱ�䡢վ����һ������������������
    //ͣ����վ����վ���վʱ�䡢��վʱ�䡢�����
    return OK;
}
Status print_trip_info_tk(tr_ElemType &p){
    printf("*****������Ϣ*****\n");
    printf(";��վ��  ��վʱ��  ����ʱ��  ����ʻ����\n");
    printf("%s ", p.TK_name);
    printf("%10s ", p.l_time);
    printf("%10s ", p.r_time);
    printf("%10.1f\n", p.distance_1);   //��վ�ľ���
    return OK;
}
Status print_trip_info_all(LinkList L){
    LinkList p=L;
    print_trip_info_head(p->data); //�ȴ�ӡ��ͷ��Ϣ
    p=p->next;
    while(p){
        print_trip_info_tk(p->data);
        p=p->next;
    }
    return OK;
}
Status InitList_tr(LinkList &L)
{
    L = (LinkList) malloc(sizeof(LNode));
    L->next=NULL;
    return OK;
}
Status DestroyList_tr(LinkList &L)
{
    LinkList q;
    while (L)
    {
        q=L->next;
        free(L);
        L=q;
    }
    return OK;
}
Status Append_tr(LinkList &L, tr_ElemType e)
{
    LinkList p=L,s;
    while (p->next)
    {
        p=p->next;
    }

    s=(LinkList) malloc(sizeof (LNode));
    s->data=e;
    p->next = s;
    s->next = NULL;

    return OK;
}
Status search_trip(LinkList table[] ){
    //��ѯ��Ϣ
    //���س���������Ϣ
    printf("*****���ڲ�ѯ�г�*****\n");
    char item[20];
    int key;
    printf("��ѡ���ѯ����:\n��������������:\n");
    printf("%s:0\n%s:1\n%s:2\n%s:3\n"
           "%s:4\n",query1[0],query1[1],query1[2],query1[3],query1[4]);
/*char query1[5][40]={"��0 ���ݳ��β���",  //��ѯʱ���
                    "��1 ʼ��վ����",
                    "��2 �յ�վ����",
                    "��3 ����ʱ�����",
                    "��4 ;����վ����"};*/
    printf("ѡ��Ҫ��ѯ��������Ӧ���:\n");
    scanf("%d",&key);//ѡ���ѯ��ı��
    printf("������ %s:\n",query1[key]);
    scanf("%s",item);//���복�ε���Ϣ��
    //ָÿ�˳�ͷ
    int i=0;//��¼�г�������
    int flag = 0;
    while (i<num)//С�ڳ��˴���
    {
        LinkList q=table[i];
        tr_ElemType q2;
        if(search_key_tr(q,key,item, q2)) // �ҵ������Ϣ���Ӧ�ĳ���
        {
            print_trip_info_all(q);
            flag = 1;
        }
        i++;
    }
    if(!flag) //�Ҳ��������
    {
        printf("δ��ѯ�������Ϣ�г�!\n");
        return FALSE;
    }
    return OK;
}
Status add_trip(LinkList train)
{
    //�����³���ÿվ��Ϣ
    /*train��ͷ�ڵ�*/
    tr_ElemType p;
    scanf_trip_info_head(p);
    train->data = p;

    for(int i=0;i < train->data.station_num;i++){
        tr_ElemType p1;   //���澭��վ�����Ϣ
        scanf_trip_info_TK(p1);
        Append_tr(train, p1);  //���뾭��վ���
    }
    printf("������ӳɹ���\n");
    return OK;
}
Status add_trip_next(LinkList table[] ){
    printf("*****�������һ�����г�*****\n");
    LinkList train;
    InitList_tr(train);
    add_trip(train);
    table[num] = train;
    num++;
    return OK;
}
Status Init_trip(LinkList trip_tabel[] ){ //����³��Σ�Init+add
    for(int i=0;i<num;i++){     //���Ѵ����Ŀճ��α��У�����³���

        LinkList train;         //Init�³���
        InitList_tr(train);
        add_trip(train);        //���ӽ�㣬��վ��Ϣ
        trip_tabel[i]=train;    //�����μ��복�α�

    }
    return OK;

}
Status stop_trip(LinkList table[])
{
    //ͣ��һ���г�����ɾ����
    printf("������Ҫͣ�����г����Σ�");
    char train_num[5];
    scanf("%s", train_num);
    int flag=0;
    char c[]="ͣ��";
    for(int i=0;i<num;i++){
        if(strcmp(train_num, table[i]->data.train_number)==0)
        {
            flag=1;
            strcpy(table[i]->data.situation, c);
        }
    }
    if(flag==0)
    {printf("û�ҵ��ó��Σ�");
        return FALSE;}
    return OK;
}
Status modify_trip(LinkList table[])
{
    //�޸ĳ�����Ϣ
    printf("��������Ҫ�޸ĵ��г����Σ�\n");
    char number[10];
    scanf("%s", number);
    int flag=0;
    // LinkList* modify_trian;
    for(int i=0;i<num;i++){
        if(!strcmp(number, table[i]->data.train_number))
        {
            flag=1;
            printf("�������������޸ĺ�ĳ�����Ϣ��\n");
            DestroyList_tr(table[i]);
            LinkList new_train;
            InitList_tr(new_train);
            add_trip(new_train);
            table[i]=new_train;
            printf("�޸ĳɹ���\n");
        }
    }
    if(flag==0)
    {printf("û�ҵ��ó��Σ�");
        return FALSE;}
    return OK;
}
Status show_all_trip(LinkList table[] ){ //������г���

    for(int i=0;i < num ;i++){
        LinkList p;
        p=table[i];
        print_trip_info_all(p);
    }
    printf("�ܹ�%d���г����ɹ���ӡ���г��Σ�\n",num);

    return OK;
}
float price_tickter(int grade, char start[], char end[]){
    float num1=0; //������Ʊ���ܼ�

    float prince[3]={1.2,0.6,0.46};
    tr_ElemType station_o,station_e;

    for (int i = 0; i < num; ++i) {
        if(search_trip_4_tk(trip_table[i],start,station_o))
        {

            if (search_trip_4_tk(trip_table[i],end,station_e)) {

                num1= prince[grade-1]*(station_e.distance_1-station_o.distance_1);
                return num1;  //��ͬһ�˳��������վ�Ͷ��յ�վ�ǣ��ǵ���Ʊ����ʱ��������˳������
            }
        }
    }
    return 0;
}
Status read_from_text_tr(LinkList table[],char data_path[]){
    printf("*****���ڴӸ�·����ȡ����*****\n%s\n",data_path);
    //��txt�ж�ȡ���ݣ���������������
    char str[1000];
    char info[100][20];
    const char s[2] = " "; //�ָ���
    char *token;
    FILE* fpRead;
    fpRead = fopen(data_path, "r");
    //char ch= fgetc(fpRead);
    //fscanf(fpRead,"%[^\n]", str);
    int mm=1;
    while (fgets(str,sizeof(str),fpRead) != NULL&&mm++) {//ÿ��ѭ������һ���ַ���
        /* ��ȡ��һ�����ַ��� */

        token = strtok(str, s);
        /* ������ȡ���������ַ��� */
        if(mm==2) {
            num = atoi(token); // atoi() �ַ���ת��Ϊ���εĺ���
            continue;
        }

        int i = 0;
        while (token != NULL) {
            //printf( "%s\n", token );
            strcpy(info[i++], token);
            token = strtok(NULL, s);
        }
        //printf("***************");
        LinkList train;
        InitList_tr(train);
        /*ͷ��㸳ֵ*/
        tr_ElemType t_info;
        strcpy(t_info.train_number, info[0]);
        strcpy(t_info.SHIFA, info[1]);
        strcpy(t_info.ZHONGDAO, info[2]);
        t_info.distance = atoi(info[3]);
        strcpy(t_info.situation, info[4]);
        strcpy(t_info.launch_time, info[5]);
        strcpy(t_info.arr_time, info[6]);
        t_info.station_num = atoi(info[7]);
        t_info.seat1 = atoi(info[8]);
        t_info.seat2 = atoi(info[9]);
        t_info.seat3 = atoi(info[10]);
        train->data = t_info;

        /*;��վ��ֵ*/
        for (int j = 0; j < t_info.station_num; ++j) {
            tr_ElemType tk_info;
            strcpy(tk_info.TK_name, info[11 + 4 * j]);
            strcpy(tk_info.l_time, info[12 + 4 * j]);
            strcpy(tk_info.r_time, info[13 + 4 * j]);
            tk_info.distance_1 = atof(info[14 + 4 * j]);
            Append_tr(train,tk_info);
        }
        table[mm-3] = train;
    }
    printf("*****ȫ������Ϣ�ѳɹ�����!*****\n");
    return OK;
};
#endif //TEST_LINK_TR_H
