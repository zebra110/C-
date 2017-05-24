#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define LEN 15 
#define N 100 
struct record 
{
char code[LEN+1]; 
char name[LEN+1]; 
char sex[3]; 
char add[30]; 
char tel[LEN+1]; 
char mail[30];
char qq[LEN+1];
int  arrange;

}stu[N],st[N],temp;
struct e
{
  char a[10];
  char b[10];
  char c[10];
}z[N];
int n,k=1,m,y,d,dd;
char s[100],o[100],skk[100]; 
void read();
void bao();
void sort();
void readfile();
void seek();
void modify();
void insert();
void del();
void display();
void save();
void menu();
void help();
void login(); 
void registe();
void menu2();
void duqu();
void cunru();
void daochu();
void loginmodify();
void getpassword();
void beifen();
void delmenu() ;
void yichu();
void baocun()
{  int i;
	FILE *fp;
   fp=fopen("D://1.txt","w");
   for(i=0;i<dd;i++)
   {
       fprintf(fp,"%s %s %s %s %s %s %s\n",st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq);
   }
   fclose(fp);
   
}
void blackreadfile()
{
	int j,i=0;
   char sv[100];
	FILE *fp;
   fp=fopen("D://1.txt","r");
   while(fscanf(fp,"%s %s %s %s %s %s %s\n",st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq)==7)
   i++;
   fclose(fp);
   dd=i;
}
void yichu()
{  int flagg=0,j1,i,j,q,ff;
   readfile();
   j1=1;printf("\n");
   printf("所有黑名单成员的信息如下:\n");
   printf("编号      学号        姓名        性别           地址        电话        E-mail                 qq\n");
   printf("                                                                   \n");
   for(i=0;i<dd;i++)
   {   st[i].arrange=j1;
   printf("%d     %s   %s   %s    %s    %s    %s    %s\n",st[i].arrange,st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq);
   j1++;} 
	blackreadfile();
	printf("                                    请输入所要移除黑名单成员的编号"); 
   scanf("%d",&q);
   for(i=0;i<dd;i++)
   if(st[i].arrange==q)
   {ff=n;stu[ff]=st[i];
   	n++;bao();
	flagg=1;
   for(j=i;j<n-1;j++)
   st[j]=st[j+1];
   dd--;baocun();}
   if(flagg==0)
   printf("                                    该编号不存在！\n");
   printf("                                    成功移除该黑名单 原通讯录已恢复该联系人！\n\n");
	}

void tianjia()
{  int flagg=0,j1,i,j,q,ff;
   readfile();
   j1=1;printf("\n");
   printf("所有通讯人的信息为:\n");
   printf("编号      学号        姓名        性别           地址        电话        E-mail                 qq\n");
   printf("                                                               \n");
   for(i=0;i<n;i++)
   {   stu[i].arrange=j1;
   printf("%d      %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   j1++;} 
	blackreadfile();
	printf("                                    请输入添加至黑名单的编号"); 
   scanf("%d",&q);
   for(i=0;i<n;i++)
   if(stu[i].arrange==q)
   {ff=dd;st[ff]=stu[i];
  	dd++;
	flagg=1;
   for(j=i;j<n-1;j++)
   stu[j]=stu[j+1];
   n--;bao();}
   if(flagg==0)
   printf("                                    该编号不存在！\n");
   baocun();
	printf("                                    成功添加到黑名单 原通讯录已删除该联系人！\n\n");} 
   
void blacklist()
{ int i,ff=1;printf("\n");
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                    1.添加黑名单成员                 \n");
   printf("                                                                     \n");
	printf("                                    2.移除黑名单成员                 \n");
	printf("                                                                     \n");
	printf("                                    3.显示黑名单成员                 \n");
	printf("                                                                     \n");
	printf("                                    4.退出本菜单                     \n");
	printf("                                                                     \n");

	printf("                 ----------------------------------------------------\n");
	int pp;
	while(ff)
	{printf("                                    请选择:");
	fflush(stdin);scanf("%d",&pp);
   switch(pp)
	{
	case 1:ff=0;tianjia();break;
	case 2:ff=0;yichu();break; 
   case 3:ff=0;
   blackreadfile();
	printf("所有黑名单成员的信息如下:\n");
   printf("学号      姓名      性别         地址         电话          E-mail          qq\n");
   printf("                                                                \n");
   for(i=0;i<dd;i++)
   printf("%s   %s   %s    %s    %s    %s    %s\n",st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq);
   break;
	case 4:ff=0;menu();break;
	default:printf("                                    请在1-4之间选择！\n");ff=1;
} } }
void ab()
{FILE *fp;
  
   fp=fopen("D:\\student.txt","r");  int i=0;
   while(fscanf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c)==3)
   i++;
   d=i;
   }
void paixuduqu()
{  int i;
	printf("所有通讯人的信息为:\n");
   printf(" 学号                  姓名                 性别                    地址                         电话              E-mail                 qq\n");
   printf("                                                                    \n");
   for(i=0;i<n;i++)
   { 
   printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
}		
int main()
{  
   int num,ff=1;printf("\n");	system("color 0f");
   printf("                 -------------- 欢迎使用通讯录管理系统 --------------\n");
   printf("                                                                     \n");
	printf("                                    1.登录                           \n");
   printf("                                                                     \n");
   printf("                                    2.注册                           \n");
   printf("                                                                     \n");
   printf("                                    3.密码修改                       \n");
   printf("                                                                     \n");
   printf("                                    4.找回密码                       \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(ff)
	{printf("                                     请选择:"); 
   fflush(stdin);scanf("%d",&num);
   switch(num)
 {
 	case 1:ff=0;login();break;
 	case 2:ff=0;registe();break;
	case 3:ff=0;loginmodify();break;
	case 4:ff=0;getpassword();break; 
 	default:printf("                                     请在1-4之间选择!\n");ff=1;
 }
	 
 }
   while(k)
   menu();
   return 0;
}
void registe() 
{  ab();printf("\n");
   int i=d,j,e=0,ee=0,flag,m,u,pp,ff=1;char ch[100];
   do
   {
       flag=1;
       while(flag)
       {
           flag=0;
           printf("                                    请输入账号:");
           scanf("%s",z[i].a);
           for(j=0;j<i;j++)
           if(strcmp(z[i].a,z[j].a)==0)
           {
               printf("                                    已有该账号,请检查后重新录入!\n");
               flag=1;
               break; 
           }
       }
       printf("                                    请输入密码:");
        while((ch[e]=getch())!='\r')//scanf("%s",z[i].b); 
		 {
		 printf("*");
 			e++;
 		 }ch[e]='\0';
 		 printf("\n");
	    printf("                                    请再次输入密码:");
       while((z[i].b[ee]=getch())!='\r')//scanf("%s",z[i].b); 
		 {
		 printf("*");
		
 			ee++;
 		 }z[i].b[ee]='\0';
 		 if(strcmp(ch,z[i].b)!=0)
	  {printf("                                    两次密码输入不相同，请重新注册！");registe();}
 		 
	    printf("                 ----------------------------------------------------\n");
		 printf("                                                                 \n");
       printf("                                    请选择密保问题:              \n");
       printf("                                                                 \n");
       printf("                                    1.您父亲的姓名               \n");
       printf("                                                                 \n");
		 printf("                                    2.您母亲的姓名               \n");
	    printf("                                                                 \n");
		 printf("                                    3.你印象最深的事             \n");
       printf("                                                                 \n");
 	    printf("                                    4.你的出身地                 \n");
       printf("                                                                 \n");
       printf("                                    5.自定义密保密码                 \n");
       printf("                                                                 \n");
		 printf("                 ----------------------------------------------------\n"); 
		 while(ff)
		 {printf("                                    请选择:");
		 fflush(stdin);scanf("%d",&pp);
		 switch(pp) 
		 {case 1:ff=0;printf("                                   请输入您父亲的姓名:"); 
               scanf("%s",z[i].c);break;        
        case 2:ff=0;printf("                                   请输入您母亲的姓名:"); 
               scanf("%s",z[i].c);break;
        case 3:ff=0;printf("                                   请输入你印象最深的事:"); 
               scanf("%s",z[i].c);break;
        case 4:ff=0;printf("                                   请输入你的出身地:"); 
               scanf("%s",z[i].c);break;
        case 5:ff=0;printf("                                   请输入您自定义的密保答案:"); 
               scanf("%s",z[i].c);break;
        default:printf("                                  请在1-5之间选择！\n");ff=1;
		  }}		     
       if(flag==0)
      
           i++;
     
     
   }while(i<d++);
   
   d++;
   printf("                                   注册成功！\n");
	FILE *fp;
   fp=fopen("D:\\student.txt","w"); 
   for(i=0;i<d;i++)
   {
       fprintf(fp,"%s  %s %s ",z[i].a,z[i].b,z[i].c);
   } fclose(fp);
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
	printf("                                    1.登录                           \n");
	printf("                                                                     \n");
   printf("                                    2.退出                           \n");
   printf("                                                                     \n");
   printf("                                    3.密码修改                       \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n"); 
   ff=1;
	while(ff)
   {printf("                                    请选择：");
	fflush(stdin);scanf("%d",&u);
	switch(u)
	{
	case 1:ff=0;login();break;
 	case 2:ff=0;exit(0);break;
 	case 3:ff=0;loginmodify();break;
 	default:printf("                                请在1-3之间选择\n");ff=1;
	}}}
   
void login() 
{int i;ab();printf("\n");
   int item,num,count=0,u;
   char s2[LEN]={"\0"}; 
   for(i=0;i<n;i++)
   printf("%s %s %s",z[i].b,z[i].a,z[i].c);
   printf("                                     请输入账号:");
   scanf("%s",s);
	printf("                                     请输入密码:");
	 while(1)
    {   u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
		  s2[i]=u;
        i++;

    }
   for(i=0;i<d;i++)
   if(strcmp(z[i].a,s)==0&&strcmp(z[i].b,s2)==0) 
	{printf("\n                                     登录成功!");count=1;
	
  }
	if(count==0){printf("\n                                     密码错误，登录失败!");exit(0);}       
} 
void loginmodify()
{
	printf("\n");int i;ab();
   int item,num,count=0,pp,flag=0,bb,u,c=0,ff=0;
   char s2[LEN],ee[100]; 
  	FILE *fp;
   fp=fopen("D:\\student.txt","w");
   printf("                                请输入原账号:");
   scanf("%s",s);
   printf("                                请输入原密码:");
   scanf("%s",s2);
     for(i=0;i<d;i++)
   if(strcmp(z[i].a,s)==0&&strcmp(z[i].b,s2)==0) 
	{   count=1;
       printf("                 ----------------------------------------------------\n");
       printf("                                                                 \n");
	    printf("                                待校验的密保问题:                \n");
		 printf("                                                                 \n"); 
       printf("                                1.您父亲的姓名                   \n");
		 printf("                                                                 \n"); 
		 printf("                                2.您母亲的姓名                   \n");
		 printf("                                                                 \n"); 
		 printf("                                3.你印象最深的事                 \n"); 
 	    printf("                                                                 \n"); 
	    printf("                                4.你的出身地                     \n");
       printf("                                                                 \n"); 
		 printf("                                5.自定义密保                     \n");
		 printf("                                                                 \n");
       printf("                 ----------------------------------------------------\n"); 
	     
		 while(ff)
		 {printf("                                请选择:");
		 scanf("%d",&pp);
		 fflush(stdin);switch(pp) 
		 {case 1:ff=0;printf("                                请输入您父亲的姓名");
		         scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                请输入新的密码:");
               scanf("%s",z[i].b);}
               if(flag==0)printf("                                答案错误！\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;

        case 2:ff=0;printf("                                请输入您母亲的姓名："); 
              scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                请输入新的密码：    ");
               scanf("%s",z[i].b);}
               if(flag==0)printf("                                答案错误！\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 3:ff=0;printf("                                请输入你印象最深的事："); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                请输入新的密码：    ");
               scanf("%s",z[i].b);}
               if(flag==0)printf("                                答案错误！\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 4:ff=0;printf("                                请输入你的出身地:    "); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                请输入新的密码：    ");
               scanf("%s",z[i].b);}
               if(flag==0)printf("                                答案错误！\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 5:ff=0;printf("                                请输入您自定义的密保答案："); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)
					flag=1;
               if(flag==1)
					{printf("                                请输入新的密码：");
               scanf("%s",z[i].b); }
               if(flag==0)printf("                                答案错误！\n");
				   fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);
               break;
					
        default:printf("                                请在1-5之间选择！\n");ff=1;
		  }}		     
	
  }if(count==0){printf("                                原登录信息不正确!\n");exit(0);} 
   fclose(fp);
	if(flag==1)printf("                                密码修改成功！\n");
	printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	printf("                                         1.登录                      \n");
	printf("                                                                     \n");
   printf("                                         2.退出                      \n");
   printf("                                                                     \n");
   printf("                                         3.密码修改                  \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   ff=1;while(ff)
	{printf("                                          请选择：");
	fflush(stdin);scanf("%d",&u);
	switch(u)
	{
	case 1:ff=0;login();break;
 	case 2:ff=0;exit(0);break;
 	case 3:ff=0;loginmodify();break;
 	default:printf("                                          请在1-3之间选择\n");ff=1;
	}}
}
void getpassword()
{int i;ab();printf("\n");
   int item,num,count=0,pp,flag=0,bb,u,ff=1;
   char s2[LEN],ee[100];
   printf("                                          请输入原账号:\n");
   scanf("%s",s);
       printf("                 ------------------------------------------------\n");
       printf("                                                                 \n");
       printf("                                请选择待校验的密保问题:          \n");
		 printf("                                                                 \n"); 
       printf("                                1.您父亲的姓名                   \n");
		 printf("                                                                 \n"); 
		 printf("                                2.您母亲的姓名                   \n");
		 printf("                                                                 \n"); 
		 printf("                                3.你印象最深的事                 \n"); 
 	    printf("                                                                 \n"); 
	    printf("                                4.你的出身地                     \n");
       printf("                                                                 \n"); 
		 printf("                                5.自定义密保                     \n");
		 printf("                                                                 \n");
		 printf("                 ------------------------------------------------\n"); 
	    while(ff)
	    {
		 printf("                                请选择：                           ");
		 fflush(stdin);
		 scanf("%d",&pp);
		 switch(pp) 
		 {case 1:ff=0;printf("                               请输入您父亲的姓名:");
		         scanf("%s",ee); 
		         for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               您的原密码为:%s\n",z[i].b); count=1;
             }
					break;

        case 2:ff=0;printf("                               请输入您母亲的姓名:"); 
              scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               您的原密码为:%s\n",z[i].b); count=1;
             }
					break;
					
        case 3:ff=0;printf("                               请输入你印象最深的事:"); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               您的原密码为:%s\n",z[i].b); count=1;
             }
					break;
					
        case 4:ff=0;printf("                               请输入你的出身地:  "); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               您的原密码为:%s\n",z[i].b); count=1;
             }
					break;
					
        case 5:ff=0;printf("                               请输入您自定义的密保答案:"); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               您的原密码为:%s\n",z[i].b); count=1;
             }
					break;
					
        default:printf("                               请在1-5之间选择！\n");ff=1;
		  }}		     
		  
   if(count==0){printf("                               原登录信息不正确!\n");exit(0);} 
   printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	printf("                                         1.登录                      \n");
	printf("                                                                     \n");
   printf("                                         2.退出                      \n");
   printf("                                                                     \n");
   printf("                                         3.密码修改                  \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   ff=1;while(ff)
	{printf("                                         请选择：");
	fflush(stdin);
	scanf("%d",&u);
	switch(u)
	{
	case 1:ff=0;login();break;
 	case 2:ff=0;exit(0);break;
 	case 3:ff=0;loginmodify();break;
 	default:printf("                                    请在1-3之间选择!\n");ff=01;
	}}
}
void menu()
{  
   int num,mm=1,ff=1;
	readfile();
	//_sleep(1600);
   //system("cls");
	system("color f0");
	
	printf("                                                                     \n");
	printf("                                                                     \n");
	printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                     1.查询                     \n");
   printf("                                                                     \n");
   printf("                                     2.修改                     \n");             
   printf("                                                                     \n");
   printf("                                     3.增加                     \n");         
   printf("                                                                     \n");
   printf("                                     4.删除                     \n");
   printf("                                                                     \n");
   printf("                                     5.显示                     \n");
   printf("                                                                     \n");
   printf("                                     6.排序                     \n");                                
   printf("                                                                     \n");
	printf("                                     7.导出                     \n");  
   printf("                                                                     \n");
	printf("                                     8.备份                     \n"); 
   printf("                                                                     \n");
	printf("                                     9.黑名单                   \n");  
   printf("                                                                     \n");
	printf("                                     0.退出                     \n"); 
	printf("                                                                     \n");                                              
   printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	while(ff)
	{printf("                                     请选择:");
   fflush(stdin);scanf("%d",&num);
   switch(num)
   { 
       
      
       case 1:ff=0;seek();break;
       case 2:ff=0;modify();break;
       case 3:ff=0;insert();break;
       case 4:ff=0;del();break;
       case 5:ff=0;display();break;
       case 6:ff=0;sort();break;
       case 7:ff=0;daochu();break;
       case 8:ff=0;beifen();break;
       case 9:ff=0;blacklist();break;
		 case 0:ff=0;k=0;exit(0);break;
       default:printf("                                    请在0-9之间选择!\n");ff=1;
}}}
void dubeifen()
{   FILE *fp;
   int i=0;char sk[100];
   fp=fopen(skk,"r+");
	for(i=0;i<n;i++)
   {
       fscanf(fp,"%s %s %s %s %s %s %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   } fclose(fp); 
}	 
void beifen()
{  int pp,ff=1;
 readfile(); 
   FILE *fp;
   int i=0;char sk[100];
   sprintf(skk,"%s.备份",o);
   fp=fopen(skk,"w");
	fprintf(fp,"%s %s %s %s %s %s %s\n","学号", "姓名","性别","地址","电话","E-mail","qq");
	 printf("                 ----------------------------------------------------\n");
	printf("                                                        \n");
	printf("                                    1.添加当前信息至备份\n");
	printf("                                                        \n");
	printf("                                    2.显示所有备份      \n");
	printf("                                                        \n");
	 printf("                 ----------------------------------------------------\n");
	while(ff)
{	printf("                                    请选择:");
	fflush(stdin);scanf("%d",&pp);
	switch(pp)
	{
		case 1: ff=0;
	for(i=0;i<n;i++)
   {
       
 fprintf(fp,"%s      %s        %s        %s        %s      %s           %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }printf("                                    备份成功！\n");break;
  
   
      case 2:ff=0;
	   dubeifen();
		printf("                                   所有备份的信息如下:\n");
   printf(" 学号        姓名          性别         地址     电话    E-mail   qq\n");
   printf("                                                                 \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }break;
   
	default:printf("                                    请在1-2之间选择!\n");ff=1;
}}
	fclose(fp);  
	menu();
}
void readfile()
{
   
   FILE *fp;
   int j,i=0;
   for(j=0;j<strlen(s);j++)
   o[j]=s[j];
   fp=fopen(o,"r"); 
   while(fscanf(fp,"%s %s %s %s %s %s %s",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq)==7)
   i++;
   fclose(fp);
   n=i;
}
void sort()
{  
   FILE *fp;
   int i=0,p=1,ff=1;
   fp=fopen(o,"r"); 
   while(fscanf(fp,"%s %s %s %s %s %s %s",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq)==7)
   i++;
   fclose(fp);
   int j,k,uu;
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
	printf("                                    1.按学号排列                     \n");
	printf("                                                                     \n");
   printf("                                    2.按姓名排列                     \n");
	printf("                                                                     \n");
   printf("                                    3.按性别排列                     \n");
  	printf("                                                                     \n");
   printf("                                    4.按地址排列                     \n");
  	printf("                                                                     \n");
   printf("                                    5.按电话排列                     \n");
  	printf("                                                                     \n");
   printf("                                    6.按E-mail排列                   \n");
  	printf("                                                                     \n");
   printf("                                    7.按qq排列                       \n");
  	printf("                                                                     \n");
   printf("                                    8.退出本菜单                     \n");
  	printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(ff)
   {
	printf("                                    请选择:");
	fflush(stdin);scanf("%d",&uu);
switch(uu)
	{ case 1:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].code,stu[k].code)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}
		break;
		
		case 2:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].name,stu[k].name)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}break;
		
		case 3:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].sex,stu[k].sex)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}break;
		
		case 4:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].add,stu[k].add)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}break;
		
		
		case 5:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].tel,stu[k].tel)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}
		break;
		
		case 6:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].mail,stu[k].mail)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}break;
	
	case 7:ff=0;
	  for (i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(strcmp(stu[j].qq,stu[k].qq)<0)
		k=j;
		temp=stu[k];
		stu[k]=stu[i];
		stu[i]=temp;}break;
	
	case 8: ff=0;menu();break;
	
	default:printf("                                    请在1-8之间选择！");ff=1;
	
	} }
	printf("                                   所有通讯人的信息如下:\n");
   printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
	bao();
	
	
}  
void daochu()
{  
   int i;
   char sk[100];
  sprintf(sk,"%s.csv",o);
	FILE * fp=fopen(sk,"w");
		fprintf(fp,"%6s %7s %5s %8s %10s %14s %14s\n","学号", "姓名","性别","地址","电话","E-mail","qq");

     for(i=0;i<n;i++)
      { 
   fprintf(fp,"%6s %7s %5s %8s %10s %14s %14s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
   fclose(fp);
}  
void seek() 
{
   readfile();
   int i=0,k,item,flag=0,j,count=0,num,mm=1;
   char s1[21];
   printf("                 ----------------------------------------------------\n");	
   printf("                                                                     \n");
   printf("                                    1.按学号查询                     \n");
   printf("                                                                     \n");
   printf("                                    2.按姓名查询                     \n");
   printf("                                                                     \n");
   printf("                                    3.模糊查找                       \n");
   printf("                                                                     \n");
   printf("                                    4.退出本菜单                     \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(mm)
   {
       printf("                                    请选择:");
       fflush(stdin); scanf("%d",&item);
       flag=0;
       switch(item)
       {
           case 1:
           printf("                                    请输入要查询的人的学号:  ");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           if(strcmp(stu[i].code,s1)==0)
           {
               flag=1;
               printf("                                   所有通讯人的信息如下:\n");
   printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   } }
           if(flag==0)
           printf("                                    该编号不存在！\n"); 
           break;

           case 2:
           printf("                                    请输入要查询的人的姓名:  ");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           if(strcmp(stu[i].name,s1)==0)
           {
               flag=1;
               printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
               printf("                                                                   \n");
               printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
           }
           if(flag==0)
           printf("                                    该姓名不存在！\n"); 
           break;
        
           case 3:
			  printf("                                    输入查询关键字：");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           {
               for(k=0,j=0;stu[i].name[k]!='\0'&&s1[j]!='\0';)
               {
           if(stu[i].name[k]==s1[j]||stu[i].code[k]==s1[j]||stu[i].sex[k]==s1[j]||stu[i].add[k]==s1[j]||stu[i].tel[k]==s1[j]||stu[i].mail[k]==s1[j]||stu[i].qq[k]==s1[j]){k++;j++;}
			  else {k++;j=0;}
            }
            if(s1[j]=='\0'){
			                  printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
                           printf("                                                                       \n");
                           printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);}}
				if(s1[j]!='\0')printf("                                    该关键字不存在！\n");break; 
         					
           case 4:mm=0;break;
           default:printf("                                    请在1-4之间选择！\n");break;
          
       }
   }menu();
}
void modify() 
{  
   readfile();
   
   int i,item,num,count=0,ff=1;
   char sex1[3],s1[LEN+1],s2[LEN+1];
   printf("                                   所有通讯人的信息如下:\n");
   printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   } 
   printf("                                    请输入要修改的人的学号:");
   scanf("%s",s1);
   for(i=0;i<n;i++)
   if(strcmp(stu[i].code,s1)==0) 
   {num=i;count=1;} 
   if(count==0){printf("                                    该学号不存在！\n");modify();}
   if(count==1)
	{printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                    1.修改姓名                       \n");
	printf("                                                                     \n"); 
   printf("                                    2.修改性别                       \n");
   printf("                                                                     \n");
   printf("                                    3.修改地址                       \n");
   printf("                                                                     \n");
   printf("                                    4.修改电话号码                   \n");
   printf("                                                                     \n");
   printf("                                    5.修改E-mail地址                 \n");
   printf("                                                                     \n");
   printf("                                    6.修改qq                         \n");
   printf("                                                                     \n");
   printf("                                    7.确认修改并退出本菜单           \n");
   printf("                                                                     \n");
   printf("                                    8.直接退出           \n");
   printf("                 ----------------------------------------------------\n");
   while(ff)
   {
       printf("                                请选择:");
       fflush(stdin);scanf("%d",&item);
       switch(item)
       {
           case 1:ff=0;
           printf("                                    请输入新的姓名:");
           scanf("%s",s2);
           strcpy(stu[num].name,s2); 
           break;

       case 2:ff=0;
       printf("                                    请输入新的性别:");
       scanf("%s",sex1);
       strcpy(stu[num].sex,sex1); 
       break;

       case 3:ff=0;
       printf("                                    请输入新的地址:");
       scanf("%s",s2);
       strcpy(stu[num].add,s2); 
       break;

       case 4:ff=0;
       printf("                                    请输入新的电话号码:");
       scanf("%s",s2);
       strcpy(stu[num].tel,s2); 
       break;

       case 5:ff=0;
       printf("                                    请输入新的E-mail地址:");
       scanf("%s",s2);
       strcpy(stu[num].mail,s2); 
       break;

       case 6:ff=0;
       printf("                                    请输入新的qq:");
       scanf("%s",s2);
       strcpy(stu[num].qq,s2);
       
       break; 

       case 7:ff=0;
       bao();
	    menu();
   
       case 8:ff=0;
	    menu();
       default:printf("                                    请在1-8之间选择!\n");ff=1;
       }}
 
		  
   } 
	menu();
}
void bao()
{  int i;
	FILE *fp;
       fp=fopen(o,"wb+"); 
       for(i=0;i<n;i++)
   {
       fprintf(fp,"%s %s %s %s %s %s %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
   fclose(fp);
}

void insert()
{  
   readfile();char ch1[10]={'m'},ch2[10]={'w'};
   int i=n,j,flag,fla,fl,mm=1,m,mmm=1,l=1,ll=1,num,cc;char b[100];
   fl=1;
   while(fl)
       {
           fl=0;
			  printf("                                    请输入待增加的人数（注意是数字）:");
           scanf("%s",b);
        
           
           m=atoi(b);
          if(0==m)
 {
  if('0'==*b)
   printf("%d\n",m);
  else
   {   printf("                                    您输入了非数字,请检查后重新录入!\n");
	fl=1;
   }
 }
       }
	 
	 
   do
   {
       flag=1;
       while(flag)
       {
           flag=0;
           printf("                                    请输入第%d个人的学号:",i+1);
           scanf("%s",stu[i].code);
        
           
           num=atoi(stu[i].code);
          if(0==num)
 {
  if('0'==*stu[i].code)
   printf("%d\n",num);
  else
   {printf("                                    您输入了非数字,请检查后重新录入!\n");
	flag=1;
   }
 }
   
           for(j=0;j<i;j++)
           if(strcmp(stu[i].code,stu[j].code)==0)
           {
               printf("                                    已有该学号,请检查后重新录入!\n");
               flag=1;
               break; 
           }
       }
       printf("                                    请输入第%d个学生的姓名:",i+1);
       scanf("%s",stu[i].name);
       printf("                                    请输入第%d个学生的性别:(m/w)",i+1);
	 	 mmm=1;
		  while(mmm)
		 {scanf("%s",stu[i].sex);
   if(strcmp(stu[i].sex,ch1)==0||strcmp(stu[i].sex,ch2)==0){mmm=0;ll=0;}
	 	 if(ll==0)break;
       if(ll==1)printf("                                    请输入m或w:");
		 
		 }	
		     
       printf("                                    请输入第%d个学生的地址:",i+1);
       scanf("%s",stu[i].add);
        fla=1;
			 while(fla)
       {
           fla=0;
			  printf("                                    请输入第%d个学生的电话:",i+1);
           scanf("%s",stu[i].tel);
        
           
           num=atoi(stu[i].tel);
          if(0==num)
 {
  if('0'==*stu[i].tel)
   printf("%d\n",num);
  else
   {   printf("                                    您输入了非数字,请检查后重新录入!\n");
	fla=1;
   }
 }
       }
       printf("                                    请输入第%d个学生的E-mail:",i+1);
       mm=1;while(mm)
		 {scanf("%s",stu[i].mail);
       for(cc=0;stu[i].mail[cc]!=10&&stu[i].mail[cc]!=13;cc++)
	 	 {if(stu[i].mail[cc]=='@'){mm=0;l=0;}}
	 	 if(l==0)break;
       if(l==1)
		 printf("                                    邮箱格式不准确请重新输入:");
		 }	    
        fl=1;
			 while(fl)
       {
           fl=0;
			  printf("                                    请输入第%d个学生的qq:",i+1);
      
			   scanf("%s",stu[i].qq);
        
           
           num=atoi(stu[i].qq);
          if(0==num)
 {
  if('0'==*stu[i].qq)
   printf("%d\n",num);
  else
   {   printf("                                    您输入了非数字,请检查后重新录入!\n");
	fl=1;
   }
 }
       }

       if(flag==0)
       i++;
       
   }
   while(i<n+m);
   n+=m;
	FILE *fp;
   fp=fopen(o,"w"); 
   for(i=0;i<n;i++)
   {
       fprintf(fp,"%s %s %s %s %s %s %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
   fclose(fp);
   printf("                                    录入完毕！\n\n");
  menu();
}
void delmenu() 
{  printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n"); 
   printf("                                    1.根据学号删除                   \n");
	printf("                                                                     \n"); 
   printf("                                    2.根据姓名删除                   \n");
   printf("                                                                     \n");
   printf("                                    3.根据性别删除                   \n");
   printf("                                                                     \n");
   printf("                                    4.根据地址删除                   \n");
   printf("                                                                     \n");
   printf("                                    5.根据电话删除                   \n");
   printf("                                                                     \n");
   printf("                                    6.根据E-mail删除                 \n");
   printf("                                                                     \n");
   printf("                                    7.根据qq删除                     \n");
   printf("                                                                     \n");
   printf("                                    8.删除所有联系人                 \n");
   printf("                                                                     \n");
   printf("                                    9.退出本菜单                     \n");
	printf("                                                                     \n");
	printf("                 ----------------------------------------------------\n");
	}
void del()
{  readfile();
   int i,j,j1,flag=0,flagg=0,way,count,s2,pp,kk,ff=1;
   char s1[LEN];
   delmenu(); 
   while(ff)
{  
	printf("                                    请选择:");
   fflush(stdin);scanf("%d",&way); 
    switch(way)
{
 	case 1:ff=0;
   j1=1;
   printf("                                    请输入要删除人的学号:");
   scanf("%s",s1);
   printf("编号  学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].code,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                   \n");
       printf(" %d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                    该学号不存在！\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                    请输入要删除人的编号:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                    该编号不存在！\n");
       if(flagg==1)
       {   printf("                                    删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                    删除成功!\n");}
		 
		 }bao();delmenu();break;
   
 	case 2:ff=0;
	 j1=1;
	 printf("                                    请输入要删除人的姓名:\n");
   scanf("%s",s1);
   printf(" 编号  学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].name,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                    \n");
       printf("%d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
    if(flag==0)
    printf("                                    该姓名不存在！\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
	
 case 3:ff=0;
	 j1=1;
   printf("                                   请输入要删除人的性别:");
   scanf("%s",s1);
   printf(" 编号   学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].sex,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                   \n");
       printf("%d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                   该性别不存在！\n");
   if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号:\n");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
	case 4:ff=0;
	 j1=1;
	 printf("                                   请输入要删除人的地址:\n");
   scanf("%s",s1);
   printf("编号  学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].add,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                      \n");
       printf(" %d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                   该地址不存在！\n");
    if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
	
   case 5: ff=0;j1=1;
	 printf("                                   请输入要删除人的电话:\n");
   scanf("%s",s1);
   printf("编号  学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].tel,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                      \n");
       printf(" %d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                   该电话不存在！\n");
  if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号:\n");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
	
case 6: ff=0;j1=1;
	 printf("                                   请输入要删除人的E-mail:");
   scanf("%s",s1);
   printf("编号   学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].mail,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                      \n");
       printf("%d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                   该姓名不存在！\n");
    if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号:\n");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
	
	case 7:ff=0;j1=1;
	 printf("                                   请输入要删除人的qq:");
   scanf("%s",s1);
   printf(" 编号  学号        姓名    性别   地址     电话           E-mail              qq\n");
	for(i=0;i<n;i++)
   if(strcmp(stu[i].qq,s1)==0)
   {    
       
	    stu[i].arrange=j1; 
	    flag=1;
	    printf("                                                                      \n");
       printf("%d  %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
	    j1++;
       
	}  
	
	 if(flag==0)
    printf("                                   该qq不存在！\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.按编号删除:\n");
      printf("                                                 \n");
      printf("                                    2.一键删除:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      printf("                                    请选择:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   请输入要删除人的编号:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   该编号不存在！\n");
       if(flagg==1)
       {   printf("                                   删除成功!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}
       printf("                                   删除成功!\n");}
		 
		 }bao();delmenu();break;
		 
   case 8:ff=0;
	for(i=n;i>=0;i--)
   {stu[i]=stu[i+1];
   n--;}bao();delmenu();break;
   
	case 9:ff=0;menu();break;
   default:printf("                                请在1-9之间选择！\n");ff=1;
	

}}} 

void display()
{ 
   int i;
   printf("                                   所有通讯人的信息如下:\n");
   printf(" 学号        姓名    性别   地址     电话           E-mail              qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }menu();
}

