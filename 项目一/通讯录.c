#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<conio.h>//�õ�getch()
#define LEN 100
#define N 100
struct record 
{
char code[LEN]; // ѧ�� 
char name[LEN];// ���� 
char sex[LEN]; //�Ա� 
char add[LEN]; //��ַ 
char tel[LEN]; //�绰 
char mail[LEN];//���� 
char qq[LEN];//QQ
int  arrange;//��� 
}stu[N],st[N],temp;//�����˽ṹ������ �ṹ����� 
struct e//����û���Ϣ�Ľṹ�� 
{
  char a[10];//�û��� 
  char b[10];//���� 
  char c[10];//�ܱ���Ϣ 
}z[N];//�û��ṹ������ 
int n,d,dd;//nΪ¼��ͨѶ��Ϣ��������dΪ��ע����û�������ddΪ������������ 
char s[100],o[100],skk[100]; //sΪ�û��� o�Ǹ��û���¼����Ϣ��Ӧ���ļ���  skk�Ǳ�����Ϣ���ļ��� 
void sort();//���� 
void readfile();//��ȡ��Ϣ 
void seek();//��ѯ 
void modify();//�޸� 
void insert();//��� 
void del();//ɾ�� 
void display();//��ʾ 
void menu();//�˵� 
void login();//��¼ 
void registe();//ע�� 
void loginmodify();//�޸����� 
void getpassword();//�һ����� 
void delmenu();//ɾ���Ĳ˵� 
void blackreadfile();//����������Ϣ��ȡ 
void blacklist();//������ 
void save();//���� 
void export();//���� 
void backup();//���� 
void readbackup();//��ȡ������Ϣ 
void blackremove();//�Ƴ���������Ա 
void blacksave();//����������Ϣ���� 
void blackinsert();//��������� 
void ab();// ��ȡ�û���Ϣ�������û��������롢�ܱ���
int main()
{  
   int num,ff=1;
   printf("                 -------------- ��ӭʹ��ͨѶ¼����ϵͳ --------------\n");
   printf("                                                                     \n");
	printf("                                    1.��¼                           \n");
   printf("                                                                     \n");
   printf("                                    2.ע��                           \n");
   printf("                                                                     \n");
   printf("                                    3.�����޸�                       \n");
   printf("                                                                     \n");
   printf("                                    4.�һ�����                       \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(ff)//ff���ڿ���ѭ�� 
	{
		printf("                                     ��ѡ��:"); 
	   fflush(stdin);//���棬�������������ʱ���������ѭ�� 
		scanf("%d",&num);
	   switch(num)
		 {
		 	case 1:ff=0;login();break;
		 	case 2:ff=0;registe();break;
			case 3:ff=0;loginmodify();break;
			case 4:ff=0;getpassword();break; 
		 	default:printf("                                     ����1-4֮��ѡ��!\n");ff=1;
		 }
   }
   return 0;
}
void ab()//��ȡ�û���Ϣ�������û��������롢�ܱ��� 
{  
   int i=0;
	FILE *fp;
   fp=fopen("D:\\student.txt","r");  
   while(fscanf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c)==3)
   i++;
   d=i;
}
void registe() 
{  
   ab();
   printf("\n");
   int i=d,j,e=0,ee=0,flag,m,u,pp,ff=1;
	char ch[100];
   do
   {
       flag=1;
       while(flag)
       {
           flag=0;
           printf("                                    �������˺�:");
           scanf("%s",z[i].a);
           for(j=0;j<i;j++)
           if(strcmp(z[i].a,z[j].a)==0)
           {
               printf("\n                                    ���и��˺�,���������¼��!\n");
               flag=1;
               break; 
           }
       }
       printf("                                    ����������:");
        while((ch[e]=getch())!='\r')
		 {
		   printf("*");
 			e++;
 		 }
	    ch[e]='\0';
 		 printf("\n");
	    printf("                                    ���ٴ���������:");
       while((z[i].b[ee]=getch())!='\r')//ѭ������Ϊ���벻Ϊ�س��� 
		 {
		   printf("*");
 			ee++;
 		 }
		  z[i].b[ee]='\0';
 		  if(strcmp(ch,z[i].b)!=0)
	  {
	    printf("\n                                    �����������벻��ͬ��������ע�ᣡ");registe();}	 
	    printf("                 ----------------------------------------------------\n");
		 printf("                                                                 \n");
       printf("                                    ��ѡ���ܱ�����:              \n");
       printf("                                                                 \n");
       printf("                                    1.�����׵�����               \n");
       printf("                                                                 \n");
		 printf("                                    2.��ĸ�׵�����               \n");
	    printf("                                                                 \n");
		 printf("                                    3.��ӡ���������             \n");
       printf("                                                                 \n");
 	    printf("                                    4.��ĳ����                 \n");
       printf("                                                                 \n");
       printf("                                    5.�Զ����ܱ�����                 \n");
       printf("                                                                 \n");
		 printf("                 ----------------------------------------------------\n"); 
		 while(ff)
		 {
			 printf("                                    ��ѡ��:");
			 fflush(stdin);
			 scanf("%d",&pp);
          switch(pp) 
			 {
           case 1:ff=0;printf("                                   �����������׵�����:"); 
	               scanf("%s",z[i].c);break;        
	        case 2:ff=0;printf("                                   ��������ĸ�׵�����:"); 
	               scanf("%s",z[i].c);break;
	        case 3:ff=0;printf("                                   ��������ӡ���������:"); 
	               scanf("%s",z[i].c);break;
	        case 4:ff=0;printf("                                   ��������ĳ����:"); 
	               scanf("%s",z[i].c);break;
	        case 5:ff=0;printf("                                   ���������Զ�����ܱ���:"); 
	               scanf("%s",z[i].c);break;
	        default:printf("                                  ����1-5֮��ѡ��\n");ff=1;
		    }
		  }		     
       if(flag==0)
           i++; 
   }while(i<d++);
   d++;
   printf("                                   ע��ɹ���\n");
	FILE *fp;
   fp=fopen("D:\\student.txt","w"); 
   for(i=0;i<d;i++)
   {
       fprintf(fp,"%s  %s %s ",z[i].a,z[i].b,z[i].c);
   } 
	fclose(fp);
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
	printf("                                    1.��¼                           \n");
	printf("                                                                     \n");
   printf("                                    2.�˳�                           \n");
   printf("                                                                     \n");
   printf("                                    3.�����޸�                       \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n"); 
   ff=1;
	while(ff)
  {   printf("                                    ��ѡ��");
		fflush(stdin);
		scanf("%d",&u);
		switch(u)
		{
			case 1:ff=0;login();break;
		 	case 2:ff=0;exit(0);break;
		 	case 3:ff=0;loginmodify();break;
		 	default:printf("                                ����1-3֮��ѡ��\n");ff=1;
		}
	}
}  
void login() 
{  int i,kk,c,item,num,count=0,u;
   char s2[LEN]={"\0"};
   ab();
	printf("\n");
   for(i=0;i<n;i++)
   printf("%s %s %s",z[i].b,z[i].a,z[i].c);
   printf("                                     �������˺�:");
   scanf("%s",s);
   kk=0;
	while(kk<=3&&c>0)
		{i=0;
		 printf("\n                                    ����������:");
		 while(1)
	    {   
		     u=getch();
	        if(u==10||u==13) 
			  break;
			  printf("*");
	 		  s2[i]=u;
	        i++;
	    }
   s2[i]='\0';
   for(i=0;i<d;i++)
   if(strcmp(z[i].a,s)==0&&strcmp(z[i].b,s2)==0) 
	{
	printf("\n                                     ��¼�ɹ�!\n");count=1;break;}
	kk=kk+1;
	c=3-kk;
		if(count==1)
		{
		menu();
		break;
		}
	   if(count==0)
		{printf("\n                                     �������!������%d�λ���",c);}
		if(c==0)
		{printf("\n                                     ��������ѳ�������\n");exit(0); }      
   }
}	
void loginmodify()
{
	ab();
   int i=0,item,num,count=0,pp,flag=0,bb,u,c=0,ff=1;
   char s2[LEN],ee[100]; 
  	FILE *fp;  
   printf("\n")
   fp=fopen("D:\\student.txt","w");
   printf("                                ������ԭ�˺�:");
   scanf("%s",s);
   printf("                                ������ԭ����:");
   while(1)
   {   
	     u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  s2[i]=u;
        i++;
   }
  s2[i]='\0';
  for(i=0;i<d;i++)
  if(strcmp(z[i].a,s)==0&&strcmp(z[i].b,s2)==0) 
	{   
	    count=1;
       printf("                 ----------------------------------------------------\n");
       printf("                                                                 \n");
	    printf("                                ��У����ܱ�����:                \n");
		 printf("                                                                 \n"); 
       printf("                                1.�����׵�����                   \n");
		 printf("                                                                 \n"); 
		 printf("                                2.��ĸ�׵�����                   \n");
		 printf("                                                                 \n"); 
		 printf("                                3.��ӡ���������                 \n"); 
 	    printf("                                                                 \n"); 
	    printf("                                4.��ĳ����                     \n");
       printf("                                                                 \n"); 
		 printf("                                5.�Զ����ܱ�                     \n");
		 printf("                                                                 \n");
       printf("                 ----------------------------------------------------\n"); 
	     
		 while(ff)
		 {
		 printf("                                ��ѡ��:");
		 scanf("%d",&pp);
		 fflush(stdin);
		 switch(pp) 
		 {case 1:ff=0;printf("                                �����������׵�����");
		         scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
       if(flag==1)
       {
		  printf("                                �������µ�����:");
               while(1)
       { 
        u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  z[i].b[c]=u;
        c++;
       }
		z[i].b[c]='\0';
		}
               if(flag==0)printf("                                �𰸴���\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;

        case 2:ff=0;printf("                                ��������ĸ�׵�������"); 
              scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
    if(flag==1)
	 {
	 printf("                                �������µ����룺    ");
    while(1)
    {   
	     u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  z[i].b[c]=u;
        c++;
    }z[i].b[c]='\0';}
               if(flag==0)printf("                                �𰸴���\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 3:ff=0;printf("                                ��������ӡ��������£�"); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                �������µ����룺    ");
               while(1)
    {   u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  z[i].b[c]=u;
        c++;
    }z[i].b[c]='\0';}
               if(flag==0)printf("                                �𰸴���\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 4:ff=0;printf("                                ��������ĳ����:    "); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)flag=1;
               if(flag==1)
					{printf("                                �������µ����룺    ");
               while(1)
    {   u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  z[i].b[c]=u;
        c++;
    }z[i].b[c]='\0';}
               if(flag==0)printf("                                �𰸴���\n");
					fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);break;
					
        case 5:ff=0;printf("                                ���������Զ�����ܱ��𰸣�"); 
               scanf("%s",ee); 
               if(strcmp(z[i].c,ee)==0)
					flag=1;
               if(flag==1)
					{printf("                                �������µ����룺");
               while(1)
    {   u=getch();
        if(u==10||u==13) 
		  break;
		  printf("*");
 		  z[i].b[c]=u;
        c++;
    }z[i].b[c]='\0';}
               if(flag==0)printf("                                �𰸴���\n");
				   fprintf(fp,"%s %s %s",z[i].a,z[i].b,z[i].c);
               break;
					
        default:printf("                                ����1-5֮��ѡ��\n");ff=1;
		  }}		     
	
  }if(count==0){printf("                                ԭ��¼��Ϣ����ȷ!\n");exit(0);} 
   fclose(fp);
	if(flag==1)printf("\n                                �����޸ĳɹ���\n");
	printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	printf("                                         1.��¼                      \n");
	printf("                                                                     \n");
   printf("                                         2.�˳�                      \n");
   printf("                                                                     \n");
   printf("                                         3.�����޸�                  \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   ff=1;while(ff)
	{printf("                                          ��ѡ��");
	fflush(stdin);scanf("%d",&u);
	switch(u)
	{
	case 1:ff=0;login();break;
 	case 2:ff=0;exit(0);break;
 	case 3:ff=0;loginmodify();break;
 	default:printf("                                          ����1-3֮��ѡ��\n");ff=1;
	}}
}
void getpassword()
{int i;ab();printf("\n");
   int item,num,count=0,pp,flag=0,bb,u,ff=1;
   char s2[LEN],ee[100];
   printf("                                    ������ԭ�˺�:");
   scanf("%s",s);
       printf("                 ------------------------------------------------\n");
       printf("                                                                 \n");
       printf("                                ��ѡ���У����ܱ�����:          \n");
		 printf("                                                                 \n"); 
       printf("                                1.�����׵�����                   \n");
		 printf("                                                                 \n"); 
		 printf("                                2.��ĸ�׵�����                   \n");
		 printf("                                                                 \n"); 
		 printf("                                3.��ӡ���������                 \n"); 
 	    printf("                                                                 \n"); 
	    printf("                                4.��ĳ����                     \n");
       printf("                                                                 \n"); 
		 printf("                                5.�Զ����ܱ�                     \n");
		 printf("                                                                 \n");
		 printf("                 ------------------------------------------------\n"); 
	    while(ff)
	    {
		 printf("                                ��ѡ��:");
		 fflush(stdin);
		 scanf("%d",&pp);
		 switch(pp) 
		 {case 1:ff=0;printf("                               �����������׵�����:");
		         scanf("%s",ee); 
		         for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               ����ԭ����Ϊ:%s\n",z[i].b); count=1;
             }
					break;

        case 2:ff=0;printf("                               ��������ĸ�׵�����:"); 
              scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               ����ԭ����Ϊ:%s\n",z[i].b); count=1;
             }
					break;
					
        case 3:ff=0;printf("                               ��������ӡ���������:"); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               ����ԭ����Ϊ:%s\n",z[i].b); count=1;
             }
					break;
					
        case 4:ff=0;printf("                               ��������ĳ����:  "); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               ����ԭ����Ϊ:%s\n",z[i].b); count=1;
             }
					break;
					
        case 5:ff=0;printf("                               ���������Զ�����ܱ���:"); 
               scanf("%s",ee); 
               for(i=0;i<d;i++)
            if(strcmp(z[i].a,s)==0&&strcmp(z[i].c,ee)==0) 
	          {printf("                               ����ԭ����Ϊ:%s\n",z[i].b); count=1;
             }
					break;
					
        default:printf("                               ����1-5֮��ѡ��\n");ff=1;
		  }}		     
		  
   if(count==0){printf("                               ԭ��¼��Ϣ����ȷ!\n");exit(0);} 
   printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	printf("                                         1.��¼                      \n");
	printf("                                                                     \n");
   printf("                                         2.�˳�                      \n");
   printf("                                                                     \n");
   printf("                                         3.�����޸�                  \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   ff=1;while(ff)
	{printf("                                         ��ѡ��");
	fflush(stdin);
	scanf("%d",&u);
	switch(u)
	{
	case 1:ff=0;login();break;
 	case 2:ff=0;exit(0);break;
 	case 3:ff=0;loginmodify();break;
 	default:printf("                                    ����1-3֮��ѡ��!\n");ff=01;
	}}
}

void readfile()//��ȡ��¼���ͨѶ¼��Ϣ 
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

void menu()
{  
   int num,mm=1,ff=1;
	readfile(); 
	system("color f0");
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                     1.��ѯ                     \n");
   printf("                                                                     \n");
   printf("                                     2.�޸�                     \n");             
   printf("                                                                     \n");
   printf("                                     3.����                     \n");         
   printf("                                                                     \n");
   printf("                                     4.ɾ��                     \n");
   printf("                                                                     \n");
   printf("                                     5.��ʾ                     \n");
   printf("                                                                     \n");
   printf("                                     6.����                     \n");                                
   printf("                                                                     \n");
	printf("                                     7.����                     \n");  
   printf("                                                                     \n");
	printf("                                     8.����                     \n"); 
   printf("                                                                     \n");
	printf("                                     9.������                   \n");  
   printf("                                                                     \n");
	printf("                                     0.�˳�                     \n"); 
	printf("                                                                     \n");                                              
   printf("                 ----------------------------------------------------\n");
	printf("                                                                     \n");
	while(ff)
	{
	printf("                                     ��ѡ��:");
   fflush(stdin);scanf("%d",&num);
   switch(num)
   {  
       case 1:ff=0;seek();break;
       case 2:ff=0;modify();break;
       case 3:ff=0;insert();break;
       case 4:ff=0;del();break;
       case 5:ff=0;display();break;
       case 6:ff=0;sort();break;
       case 7:ff=0;export();break;
       case 8:ff=0;backup();break;
       case 9:ff=0;blacklist();break;
		 case 0:ff=0;exit(0);break;
       default:printf("                                    ����0-9֮��ѡ��!\n");ff=1;
  }
  }
}
void readbackup()
{  
   FILE *fp;
   int i=0;char sk[100];
   fp=fopen(skk,"r");
	for(i=0;i<n;i++)
   {
   fscanf(fp,"%s %s %s %s %s %s %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   } 
	fclose(fp); 
}	 
void backup()
{  int pp,ff=1;
   readbackup();
   FILE *fp;
   int i=0;char sk[100];
   sprintf(skk,"%s.����",o);
   fp=fopen(skk,"w");
	fprintf(fp,"%s %s %s %s %s %s %s\n","ѧ��", "����","�Ա�","��ַ","�绰","E-mail","qq");
   printf("                 ----------------------------------------------------\n");
	printf("                                                        \n");
	printf("                                    1.��ӵ�ǰ��Ϣ������\n");
	printf("                                                        \n");
	printf("                                    2.��ʾ���б���      \n");
	printf("                                                        \n");
	printf("                                    3.�˳����˵�     \n");
	printf("                                                        \n");
	 printf("                 ----------------------------------------------------\n");
	while(ff)
{	printf("                                    ��ѡ��:");
	fflush(stdin);scanf("%d",&pp);
	switch(pp)
	{
		case 1: ff=0;
	for(i=0;i<n;i++)
   {
	fprintf(fp,"%s      %s        %s        %s        %s      %s           %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
	printf("                                    ���ݳɹ���\n");break;fclose(fp); 
      
	case 2:ff=0;
	   readbackup();
		printf("                                   ���б��ݵ���Ϣ����:\n");
  printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
 
		printf("                                                                 \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
	break;

   case 3:ff=0;menu();break;
   
	default:printf("                                    ����1-3֮��ѡ��!\n");ff=1;
}
}
	 menu();
	
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
	printf("                                    1.��ѧ������                     \n");
	printf("                                                                     \n");
   printf("                                    2.����������                     \n");
	printf("                                                                     \n");
   printf("                                    3.���Ա�����                     \n");
  	printf("                                                                     \n");
   printf("                                    4.����ַ����                     \n");
  	printf("                                                                     \n");
   printf("                                    5.���绰����                     \n");
  	printf("                                                                     \n");
   printf("                                    6.��E-mail����                   \n");
  	printf("                                                                     \n");
   printf("                                    7.��qq����                       \n");
  	printf("                                                                     \n");
   printf("                                    8.�˳����˵�                     \n");
  	printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(ff)
   {
	printf("                                    ��ѡ��:");
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
	
	default:printf("                                    ����1-8֮��ѡ��");ff=1;
	
	} }
	printf("                                   ����ͨѶ�˵���Ϣ����:\n");
   printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
	save();		
}  
void export()
{  
   int i;
   char sk[100];
   sprintf(sk,"%s.csv",o);
	FILE * fp=fopen(sk,"w");
	fprintf(fp,"%6s %7s %5s %8s %10s %14s %14s\n","ѧ��", "����","�Ա�","��ַ","�绰","E-mail","qq");

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
   char s1[100];
   printf("                 ----------------------------------------------------\n");	
   printf("                                                                     \n");
   printf("                                    1.��ѧ�Ų�ѯ                     \n");
   printf("                                                                     \n");
   printf("                                    2.��������ѯ                     \n");
   printf("                                                                     \n");
   printf("                                    3.ģ������                       \n");
   printf("                                                                     \n");
   printf("                                    4.�˳����˵�                     \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
   while(mm)
   {
       printf("                                    ��ѡ��:");
       fflush(stdin); scanf("%d",&item);
       flag=0;
       switch(item)
       {
           case 1:
           printf("                                    ������Ҫ��ѯ���˵�ѧ��:  ");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           if(strcmp(stu[i].code,s1)==0)
           {
               flag=1;
               
   printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
   printf("                                                                     \n");
   printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
           if(flag==0)
           printf("                                    �ñ�Ų����ڣ�\n"); 
           break;

           case 2:
           printf("                                    ������Ҫ��ѯ���˵�����:  ");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           if(strcmp(stu[i].name,s1)==0)
           {
               flag=1;
               printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
               printf("                                                                   \n");
               printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
           }
           if(flag==0)
           printf("                                    �����������ڣ�\n"); 
           break;
        
           case 3:
			  printf("                                    �����ѯ�ؼ��֣�");
           scanf("%s",s1);
           for(i=0;i<n;i++)
           {
               for(k=0,j=0;stu[i].name[k]!='\0'&&s1[j]!='\0';)
               {
           if(stu[i].name[k]==s1[j]||stu[i].code[k]==s1[j]||stu[i].sex[k]==s1[j]||stu[i].add[k]==s1[j]||stu[i].tel[k]==s1[j]||stu[i].mail[k]==s1[j]||stu[i].qq[k]==s1[j]){k++;j++;}
			  else {k=k-j+1;j=0;}
            }//���������ز��ҷ� ԭ���õ�strstr������Kmp�㷨����bug �������ز��ҷ���ʵҲ����bug(��¡--�£� 
            if(s1[j]=='\0'){
			                  printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
                           printf("                                                                       \n");
                           printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);}}
				if(s1[j]!='\0')printf("                                    �ùؼ��ֲ����ڣ�\n");break; 
         					
           case 4:mm=0;break;
           default:printf("                                    ����1-4֮��ѡ��\n");break;
          
       }
   }menu();
}
void modify() 
{  
   readfile();
   int i,item,num;
   char sex1[3],s1[LEN+1],s2[LEN+1]; 
   printf("\n                                    ������ҪҪ�޸ĵ��˵�ѧ��:");
   scanf("%s",s1);
   for(i=0;i<n;i++)
   if(strcmp(stu[i].code,s1)==0) 
   {num=i;
   printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
   printf("                                                                       \n");
   printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }
	printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                    1.�޸�����                       \n");
	printf("                                                                     \n"); 
   printf("                                    2.�޸��Ա�                       \n");
   printf("                                                                     \n");
   printf("                                    3.�޸ĵ�ַ                       \n");
   printf("                                                                     \n");
   printf("                                    4.�޸ĵ绰����                   \n");
   printf("                                                                     \n");
   printf("                                    5.�޸�E-mail��ַ                 \n");
   printf("                                                                     \n");
   printf("                                    6.�޸�qq                         \n");
   printf("                                                                     \n");
   printf("                                    0.ȷ���޸Ĳ��˳����˵�                     \n");
   printf("                                                                     \n");
   printf("                 ----------------------------------------------------\n");
  while(1)
   {
       printf("                                    ��ѡ���Ӳ˵����:");
       scanf("%d",&item);
       switch(item)
       {
           case 1:
           printf("                                    �������µ�����:");
           scanf("%s",s2);
           strcpy(stu[num].name,s2); 
           break;

       case 2:
       printf("                                    �������µ��Ա�:");
       scanf("%s",sex1);
       strcpy(stu[num].sex,sex1); 
       break;

       case 3:
       printf("                                    �������µĵ�ַ:");
       scanf("%s",s2);
       strcpy(stu[num].add,s2); 
       break;

       case 4:
       printf("                                    �������µĵ绰����:");
       scanf("%s",s2);
       strcpy(stu[num].tel,s2); 
       break;

       case 5:
       printf("                                    �������µ�E-mail��ַ:");
       scanf("%s",s2);
       strcpy(stu[num].mail,s2); 
       break;

       case 6:
       printf("                                    �������µ�qq:");
       scanf("%s",s2);
       strcpy(stu[num].qq,s2);
       break; 

       case 0:
      save();
	   menu();
   
       default:printf("                                    ����0-6֮��ѡ��\n");
       }
   }
}
void save()
{  
   int i;
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
			  printf("                                    ����������ӵ�����:");
           scanf("%s",b);
        
           
           m=atoi(b);
          if(0==m)
 {
  if('0'==*b)
   printf("%d\n",m);
  else
   {   printf("                                    �������˷�����,���������¼��!\n");
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
           printf("                                    �������%d���˵�ѧ��:",i+1);
           scanf("%s",stu[i].code);
        
           
           num=atoi(stu[i].code);
          if(0==num)
 {
  if('0'==*stu[i].code)
   printf("%d\n",num);
  else
   {printf("                                    �������˷�����,���������¼��!\n");
	flag=1;
   }
 }
   
           for(j=0;j<i;j++)
           if(strcmp(stu[i].code,stu[j].code)==0)
           {
               printf("                                    ���и�ѧ��,���������¼��!\n");
               flag=1;
               break; 
           }
       }
       printf("                                    �������%d��ѧ��������:",i+1);
       scanf("%s",stu[i].name);
       printf("                                    �������%d��ѧ�����Ա�:(m/w)",i+1);
	 	 mmm=1;
		  while(mmm)
		 {scanf("%s",stu[i].sex);
   if(strcmp(stu[i].sex,ch1)==0||strcmp(stu[i].sex,ch2)==0){mmm=0;ll=0;}
	 	 if(ll==0)break;
       if(ll==1)printf("                                    ������m��w:");
		 
		 }	
		     
       printf("                                    �������%d��ѧ���ĵ�ַ:",i+1);
       scanf("%s",stu[i].add);
        fla=1;
			 while(fla)
       {
           fla=0;
			  printf("                                    �������%d��ѧ���ĵ绰:",i+1);
           scanf("%s",stu[i].tel);
        
           
           num=atoi(stu[i].tel);
          if(0==num)
 {
  if('0'==*stu[i].tel)
   printf("%d\n",num);
  else
   {   printf("                                    �������˷�����,���������¼��!\n");
	fla=1;
   }
 }
       }mm=1;
       printf("                                    �������%d��ѧ����E-mail:",i+1);
       while(mm)
		 {scanf("%s",stu[i].mail);
       for(cc=0;stu[i].mail[cc]!=10&&stu[i].mail[cc]!=13;cc++)
	 	 {if(stu[i].mail[cc]=='@'){mm=0;l=0;}}
	 	 if(l==0)break;
       if(l==1)
		 printf("                                    �����ʽ��׼ȷ����������:");
		 }	    
        fl=1;
			 while(fl)
       {
           fl=0;
			  printf("                                    �������%d��ѧ����qq:",i+1);
      
			   scanf("%s",stu[i].qq);
        
           
           num=atoi(stu[i].qq);
          if(0==num)
 {
  if('0'==*stu[i].qq)
   printf("%d\n",num);
  else
   {   printf("                                    �������˷�����,���������¼��!\n");
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
   printf("                                    ¼����ϣ�\n\n");
   menu();
}
void delmenu() 
{  
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n"); 
   printf("                                    1.����ѧ��ɾ��                   \n");
	printf("                                                                     \n"); 
   printf("                                    2.��������ɾ��                   \n");
   printf("                                                                     \n");
   printf("                                    3.�����Ա�ɾ��                   \n");
   printf("                                                                     \n");
   printf("                                    4.���ݵ�ַɾ��                   \n");
   printf("                                                                     \n");
   printf("                                    5.���ݵ绰ɾ��                   \n");
   printf("                                                                     \n");
   printf("                                    6.����E-mailɾ��                 \n");
   printf("                                                                     \n");
   printf("                                    7.����qqɾ��                     \n");
   printf("                                                                     \n");
   printf("                                    8.ɾ��������ϵ��                 \n");
   printf("                                                                     \n");
   printf("                                    9.�˳����˵�                     \n");
	printf("                                                                     \n");
	printf("                 ----------------------------------------------------\n");}
void del()
{  
   readfile();
   int i,j,j1,flag=0,flagg=0,way,count,s2,pp,kk,ff=1,fff=1,p;
   char s1[LEN];
   delmenu(); 
   while(ff)
{  
	printf("                                    ��ѡ��:");
   fflush(stdin);scanf("%d",&way); 
    switch(way)
{
 	case 1:ff=0;
   j1=1;
   printf("                                    ������Ҫɾ���˵�ѧ��:");
   scanf("%s",s1);
   printf("���  ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                    ��ѧ�Ų����ڣ�\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
       fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		 
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
   
 	case 2:ff=0;
	 j1=1;
	 printf("                                    ������Ҫɾ���˵�����:");
   scanf("%s",s1);
   printf(" ���  ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                    �����������ڣ�\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		 
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
 case 3:ff=0;
	 j1=1;
   printf("                                   ������Ҫɾ���˵��Ա�:");
   scanf("%s",s1);
   printf(" ���   ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                   ���Ա𲻴��ڣ�\n");
   if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
 fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		 
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
	case 4:ff=0;
	 j1=1;
	 printf("                                   ������Ҫɾ���˵ĵ�ַ:");
   scanf("%s",s1);
   printf("���  ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                   �õ�ַ�����ڣ�\n");
    if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
       fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		 
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
	
   case 5: ff=0;j1=1;
	 printf("                                   ������Ҫɾ���˵ĵ绰:");
   scanf("%s",s1);
   printf("���  ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                   �õ绰�����ڣ�\n");
  if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		 
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
	
case 6: ff=0;j1=1;
	 printf("                                   ������Ҫɾ���˵�E-mail:");
   scanf("%s",s1);
   printf("���   ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                   ��E-mail�����ڣ�\n");
    if(flag==1)
   {   printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
      fff=1;
		while(fff)
		{printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {   save();printf("                                   ɾ���ɹ�!\n");
       n--;
       del();}
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
       printf("                                   ɾ���ɹ�!\n");save();del();}
		 
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
      }}break;
	
	case 7:ff=0;j1=1;
	 printf("                                   ������Ҫɾ���˵�qq:");
   scanf("%s",s1);
   printf(" ���  ѧ��        ����    �Ա�   ��ַ     �绰           E-mail              qq\n");
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
    printf("                                   ��qq�����ڣ�\n");
    if(flag==1)
   {  printf("                 ----------------------------------------------------\n");
	   printf("                                                 \n");
		printf("                                    1.�����ɾ��:\n");
      printf("                                                 \n");
      printf("                                    2.һ��ɾ��:  \n");
      printf("                                                 \n");
      printf("                 ----------------------------------------------------\n");
     fff=1;
	  while(fff) 
	  {printf("                                    ��ѡ��:");
      scanf("%d",&pp);
      if(pp==1)
      { fff=0;printf("                                   ������Ҫɾ���˵ı��:");
	    scanf("%d",&s2);
       for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {flagg=1;
       for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       if(flagg==0)
       printf("                                   �ñ�Ų����ڣ�\n");
       if(flagg==1)
       {  save();printf("                                   ɾ���ɹ�!\n");
       n--;
       }
		 }
       
       if(pp==2)
       {fff=0;s2=1;
       while(s2<=j1)
       {for(i=0;i<n;i++)
       if(stu[i].arrange==s2)
       {for(j=i;j<n-1;j++)
       stu[j]=stu[j+1];}
       n--;
       s2++;}save();
       printf("                                   ɾ���ɹ�!\n");}
		  
		 if(pp!=1&&pp!=2)
		 {printf("                                      ��ѡ��1��2\n");fff=1;}
       }}del();break;
		 
   case 8:ff=0;fff=1;
    while(fff)
	 {printf("                                      1.ȷ��ɾ��\n");
	  printf("                                      2.����\n");
	  printf("                                      ��ѡ��");
     fflush(stdin);scanf("%d",&p);
    if(p==1)
	{fff=0;
	for(i=n;i>=0;i--)
   stu[i]=stu[i+1];
   n--; save();printf("                                   ɾ���ɹ�!\n");del();
	}
 if(p==2){fff=0;del();}
 if(p!=1&&p!=2){printf("                                      ��ѡ��1��2\n");fff=1;}}
	break;
   
	case 9:ff=0;menu();break;
   default:printf("                                ����1-9֮��ѡ��\n");ff=1;
	

}}} 

void display()
{  
   int i;
   printf("                                   ����ͨѶ�˵���Ϣ����:\n");
   printf(" ѧ��        ����    �Ա�   ��ַ     �绰           E-mail     qq\n");
   printf("                                                                     \n");
   for(i=0;i<n;i++)
   { 
       printf("%s   %s   %s    %s    %s    %s    %s\n",stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   }menu();
}

void blacksave()
{  int i;
	FILE *fp;
   fp=fopen("D://������.txt","w");
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
   fp=fopen("D://������.txt","r");
   while(fscanf(fp,"%s %s %s %s %s %s %s\n",st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq)==7)
   i++;
   fclose(fp);
   dd=i;
}
void blackremove()
{  int flagg=0,j1,i,j,q,ff;
   readfile();
   j1=1;printf("\n");
   printf("���к�������Ա����Ϣ����:\n");
   printf("���      ѧ��        ����        �Ա�           ��ַ       �绰     E-mail    qq\n");
   printf("                                                                   \n");
   for(i=0;i<dd;i++)
   {   st[i].arrange=j1;
   printf("%d     %s   %s   %s    %s    %s    %s    %s\n",st[i].arrange,st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq);
   j1++;} 
	blackreadfile();
	printf("                                    ��������Ҫ�Ƴ���������Ա�ı��"); 
   scanf("%d",&q);
   for(i=0;i<dd;i++)
   if(st[i].arrange==q)
   {ff=n;stu[ff]=st[i];
   	n++;save();
	flagg=1;
   for(j=i;j<n-1;j++)
   st[j]=st[j+1];
   dd--;blacksave();}
   if(flagg==0)
   printf("                                    �ñ�Ų����ڣ�\n");
   printf("                                    �ɹ��Ƴ��ú����� ԭͨѶ¼�ѻָ�����ϵ�ˣ�\n\n");
	menu();}

void blackinsert()
{  int flagg=0,j1,i,j,q,ff;
   readfile();
   j1=1;printf("\n");
   printf("����ͨѶ�˵���ϢΪ:\n");
   printf("���      ѧ��        ����     �Ա�      ��ַ     �绰     E-mail    qq\n");
   printf("                                                               \n");
   for(i=0;i<n;i++)
   {   stu[i].arrange=j1;
   printf("%d      %s   %s   %s    %s    %s    %s    %s\n",stu[i].arrange,stu[i].code,stu[i].name,stu[i].sex,stu[i].add,stu[i].tel,stu[i].mail,stu[i].qq);
   j1++;} 
	blackreadfile();
	printf("                                    ������������������ı��"); 
   scanf("%d",&q);
   for(i=0;i<n;i++)
   if(stu[i].arrange==q)
   {ff=dd;st[ff]=stu[i];
  	dd++;
	flagg=1;
   for(j=i;j<n-1;j++)
   stu[j]=stu[j+1];
   n--;save();}
   if(flagg==0)
   printf("                                    �ñ�Ų����ڣ�\n");
   blacksave();
	printf("                                    �ɹ���ӵ������� ԭͨѶ¼��ɾ������ϵ�ˣ�\n\n");menu();} 
   
	void blacklist()
{ int i,ff=1;printf("\n");
   printf("                 ----------------------------------------------------\n");
   printf("                                                                     \n");
   printf("                                    1.��Ӻ�������Ա                 \n");
   printf("                                                                     \n");
	printf("                                    2.�Ƴ���������Ա                 \n");
	printf("                                                                     \n");
	printf("                                    3.��ʾ��������Ա                 \n");
	printf("                                                                     \n");
	printf("                                    4.�˳����˵�                     \n");
	printf("                                                                     \n");
	printf("                 ----------------------------------------------------\n");
	int pp;
	while(ff)
	{printf("                                    ��ѡ��:");
	fflush(stdin);scanf("%d",&pp);
   switch(pp)
	{
	case 1:ff=0;blackinsert();break;
	case 2:ff=0;blackremove();break; 
   case 3:ff=0;
   blackreadfile();
	printf("���к�������Ա����Ϣ����:\n");
   printf("ѧ��      ����      �Ա�         ��ַ         �绰        E-mail     qq\n");
   printf("                                                                \n");
   for(i=0;i<dd;i++)
   printf("%s   %s   %s    %s    %s    %s    %s\n",st[i].code,st[i].name,st[i].sex,st[i].add,st[i].tel,st[i].mail,st[i].qq);
   break;
	case 4:ff=0;menu();break;
	default:printf("                                    ����1-4֮��ѡ��\n");ff=1;
} } }

	