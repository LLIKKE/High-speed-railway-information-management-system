#ifndef TEST_LINK_TR_H
#define TEST_LINK_TR_H
int num; //火车总趟数
typedef struct trip_info
{
    //int total_num;
    char train_number[5]; //车次
    char SHIFA[10]; //始发站站名
    char ZHONGDAO[10];//终点站站名
    int distance; //总里程
    char situation[8]; //运行情况，是否停运；
    char launch_time[7]; //发车时间
    char arr_time[7]; //到达时间
    int  station_num;
    int seat1; //一、二、三等座数量
    int seat2;
    int seat3;

    //途径站点
    char TK_name[10];
    char l_time [7]; //途径出发时间
    char r_time [7]; //途径到达点
    float distance_1; //途径距离
}trip_info;

typedef trip_info tr_ElemType;
typedef  struct  LNode
{   tr_ElemType   data;
    struct  LNode  *next;
}LNode, *LinkList;
            /*******************/
        /*****************************/
    /**************************************/
/***************全局变量:火车信息*****************/
LinkList trip_table[100];
/***************全局变量:火车信息*****************/
    /**************************************/
        /*****************************/
            /*******************/
char query1[5][20]={"根据车次查找",  //查询时表格
                    "始发站查找",
                    "终点站查找",
                    "发车时间查找",
                    "途径车站查找"};

char query2[11][20]={"车次",        //打印和输入时的表格
                     "始发站",
                     "终点站",
                     "总里程",
                     "发车情况",
                     "发车",
                     "到达",
                     "途径站",
                     "一等座",
                     "二等座",
                     "三等座"};
/*列车信息使用函数*/
Status scanf_trip_info_head(tr_ElemType &p)
{
    //输入头节点信息

    printf("列车车次:\n");
    scanf("%s",p.train_number);
    printf("列车始发站:\n");
    scanf("%s",p.SHIFA);
    printf("列车终点站:\n");
    scanf("%s",p.ZHONGDAO);
    printf("行驶总路程:\n");
    scanf("%d",&p.distance);
    printf("列车运行状态:\n");
    scanf("%s",p.situation);
    printf("发车时间:\n");
    scanf("%s",p.launch_time);
    printf("到站时间:\n");
    scanf("%s",p.arr_time);
    printf("途径总站数:\n");
    scanf("%d",&p.station_num);
    printf("商务座剩余数量:\n");
    scanf("%d",&p.seat1);
    printf("一等舱剩余数量:\n");
    scanf("%d",&p.seat2);
    printf("二等舱剩余数量:\n");
    scanf("%d",&p.seat3);

    return OK;
}
Status scanf_trip_info_TK(tr_ElemType &p){
    printf("途径站点:\n");
    scanf("%s",p.TK_name);
    printf("到达时间:\n");
    scanf("%s",p.l_time);
    printf("发车时间:\n");
    scanf("%s",p.r_time);
    printf("已行驶距离:\n");
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
    // 打印车次信息, 车头
    //printf("The trip's information is as follows:\n");
    printf("%s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s\n",query2[0],query2[1],query2[2],query2[3],query2[4],query2[5],query2[6],query2[7],query2[8],query2[9],query2[10]);
    printf("%s ",p.train_number);
    printf("%7s ",p.SHIFA);
    printf("%7s ",p.ZHONGDAO);
    printf("%7d ",p.distance);//总里程
    printf("%7s ",p.situation);//运行情况
    printf("%7s ",p.launch_time);//出发时间
    printf("%7s ",p.arr_time);//到达时间
    printf("%7d ",p.station_num);//站数
    printf("%7d ",p.seat1);//商务座数量
    printf("%7d ",p.seat2);//一等座数量
    printf("%7d\n",p.seat3);//二等座数量
    //车次、始发站、终点站、总里程、运行情况（是否停运）、发车时间、达到时间、站数、一、二、三等座数量、
    //停靠车站、各站点出站时间、到站时间、里程数
    return OK;
}
Status print_trip_info_tk(tr_ElemType &p){
    printf("*****高铁信息*****\n");
    printf("途径站点  到站时间  发车时间  已行驶距离\n");
    printf("%s ", p.TK_name);
    printf("%10s ", p.l_time);
    printf("%10s ", p.r_time);
    printf("%10.1f\n", p.distance_1);   //此站的距离
    return OK;
}
Status print_trip_info_all(LinkList L){
    LinkList p=L;
    print_trip_info_head(p->data); //先打印车头信息
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
    //查询信息
    //返回车次所有信息
    printf("*****正在查询列车*****\n");
    char item[20];
    int key;
    printf("请选择查询依据:\n请输入如下数字:\n");
    printf("%s:0\n%s:1\n%s:2\n%s:3\n"
           "%s:4\n",query1[0],query1[1],query1[2],query1[3],query1[4]);
/*char query1[5][40]={"按0 根据车次查找",  //查询时表格
                    "按1 始发站查找",
                    "按2 终点站查找",
                    "按3 发车时间查找",
                    "按4 途径车站查找"};*/
    printf("选择要查询的项，输入对应编号:\n");
    scanf("%d",&key);//选择查询项的编号
    printf("请输入 %s:\n",query1[key]);
    scanf("%s",item);//输入车次的信息项
    //指每趟车头
    int i=0;//记录列车的趟数
    int flag = 0;
    while (i<num)//小于车趟次数
    {
        LinkList q=table[i];
        tr_ElemType q2;
        if(search_key_tr(q,key,item, q2)) // 找到这个信息项对应的车次
        {
            print_trip_info_all(q);
            flag = 1;
        }
        i++;
    }
    if(!flag) //找不到的情况
    {
        printf("未查询到相关信息列车!\n");
        return FALSE;
    }
    return OK;
}
Status add_trip(LinkList train)
{
    //补充新车次每站信息
    /*train：头节点*/
    tr_ElemType p;
    scanf_trip_info_head(p);
    train->data = p;

    for(int i=0;i < train->data.station_num;i++){
        tr_ElemType p1;   //后面经过站结点信息
        scanf_trip_info_TK(p1);
        Append_tr(train, p1);  //加入经过站结点
    }
    printf("车次添加成功！\n");
    return OK;
}
Status add_trip_next(LinkList table[] ){
    printf("*****正在添加一趟新列车*****\n");
    LinkList train;
    InitList_tr(train);
    add_trip(train);
    table[num] = train;
    num++;
    return OK;
}
Status Init_trip(LinkList trip_tabel[] ){ //添加新车次：Init+add
    for(int i=0;i<num;i++){     //向已创建的空车次表中，添加新车次

        LinkList train;         //Init新车次
        InitList_tr(train);
        add_trip(train);        //增加结点，车站信息
        trip_tabel[i]=train;    //将车次加入车次表

    }
    return OK;

}
Status stop_trip(LinkList table[])
{
    //停开一趟列车（不删除）
    printf("请输入要停开的列车车次：");
    char train_num[5];
    scanf("%s", train_num);
    int flag=0;
    char c[]="停开";
    for(int i=0;i<num;i++){
        if(strcmp(train_num, table[i]->data.train_number)==0)
        {
            flag=1;
            strcpy(table[i]->data.situation, c);
        }
    }
    if(flag==0)
    {printf("没找到该车次！");
        return FALSE;}
    return OK;
}
Status modify_trip(LinkList table[])
{
    //修改车次信息
    printf("请您输入要修改的列车车次：\n");
    char number[10];
    scanf("%s", number);
    int flag=0;
    // LinkList* modify_trian;
    for(int i=0;i<num;i++){
        if(!strcmp(number, table[i]->data.train_number))
        {
            flag=1;
            printf("请您重新输入修改后的车次信息：\n");
            DestroyList_tr(table[i]);
            LinkList new_train;
            InitList_tr(new_train);
            add_trip(new_train);
            table[i]=new_train;
            printf("修改成功！\n");
        }
    }
    if(flag==0)
    {printf("没找到该车次！");
        return FALSE;}
    return OK;
}
Status show_all_trip(LinkList table[] ){ //输出所有车次

    for(int i=0;i < num ;i++){
        LinkList p;
        p=table[i];
        print_trip_info_all(p);
    }
    printf("总共%d趟列车，成功打印所有车次！\n",num);

    return OK;
}
float price_tickter(int grade, char start[], char end[]){
    float num1=0; //商务座票价总价

    float prince[3]={1.2,0.6,0.46};
    tr_ElemType station_o,station_e;

    for (int i = 0; i < num; ++i) {
        if(search_trip_4_tk(trip_table[i],start,station_o))
        {

            if (search_trip_4_tk(trip_table[i],end,station_e)) {

                num1= prince[grade-1]*(station_e.distance_1-station_o.distance_1);
                return num1;  //当同一趟车存在起点站和恶终点站是，是单程票，这时返回这儿趟车的序号
            }
        }
    }
    return 0;
}
Status read_from_text_tr(LinkList table[],char data_path[]){
    printf("*****正在从该路径读取数据*****\n%s\n",data_path);
    //从txt中读取数据，并保存在链表中
    char str[1000];
    char info[100][20];
    const char s[2] = " "; //分隔符
    char *token;
    FILE* fpRead;
    fpRead = fopen(data_path, "r");
    //char ch= fgetc(fpRead);
    //fscanf(fpRead,"%[^\n]", str);
    int mm=1;
    while (fgets(str,sizeof(str),fpRead) != NULL&&mm++) {//每次循环就是一行字符串
        /* 获取第一个子字符串 */

        token = strtok(str, s);
        /* 继续获取其他的子字符串 */
        if(mm==2) {
            num = atoi(token); // atoi() 字符串转换为整形的函数
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
        /*头结点赋值*/
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

        /*途径站赋值*/
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
    printf("*****全部火车信息已成功读入!*****\n");
    return OK;
};
#endif //TEST_LINK_TR_H
