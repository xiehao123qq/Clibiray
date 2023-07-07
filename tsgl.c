#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book{
	char name[40];
	char author[30];
	char jyzt[40];
};
struct yonghu{
	char zhanghu[20];
	char mima[20];
};
struct yonghu yh2;
struct yonghu yh3;
int tslr();
int tscx();
int yhzc();
int tsjy();
int tsjs();
int j=0;
int m=0;
int sjm()
{
	system("cls");
	printf("****************************************\n");
	printf("                                        \n");
	printf("                                        \n");
	printf("         欢迎来到图书管理系统           \n");
	printf("                                        \n");
	printf("             请选择功能                 \n");
	printf("             1.图书录入                 \n");
	printf("           2.用户注册与登录             \n");
	printf("             3.图书借阅                 \n");
	printf("             4.图书查询                 \n");
	printf("             q.退出程序                           \n");
	printf("             (请按键选择)               \n");
	printf("****************************************\n");
	return 0;
}
int sjmsx()
{
	char ch;
	ch=getchar();
	while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='q')
	{
		printf("请重新正确输入(1,2,3,4,q)");
		//while(getchar()!='\n')
		//continue;
		ch=getchar();
		while(getchar()!='\n')
		continue;
	 } 
	 switch(ch)
	 {
	 	case '1': tslr();break;
	 	case '2': yhzc();break;
	 	case '3': tsjy();break;
	    case '4': tscx();break;
	    default: break;
	 }
	 //ch=getchar();
	 return 0;
 } 
 int tslr()
 { 
 	system("cls");
 	if(yh3.zhanghu==yh2.zhanghu)
 	printf("亲爱的%s，",yh3.zhanghu); 
 	int j=0; 
 	struct book shu[50];
 	char i='1';
	while(i=='1')
	{
		printf("请输入书名:");
		scanf("%s",&shu[j].name);
		while(getchar()!='\n')
		continue;
		printf("请输入作者：");
		scanf("%s",&shu[j].author);
		char x[40]="未借阅";
		strcpy(shu[j].jyzt,x);
		j++; 
		while(getchar()!='\n')
		continue;
		printf("\n1.继续录入图书\n");
		printf("%s",x);
		printf("  0.结束录入\n");
		i=getchar();
	    while(getchar()!='\n')
		continue;
	 } 
 	int ch;
 	FILE *fp;
 	fp=fopen("book.txt","a");
 	if(fp!=NULL)
 	{
 			int k=0;
 		for(k=0;k<j;k++)
 		{
		 fwrite(&shu[k],sizeof(struct book),1,fp);
		 printf("k\n"); 
		} 
	 }
 	fclose(fp);
 }
 int sytscx()
 {
 	system("cls");
 	if(strcmp(yh3.zhanghu,yh2.zhanghu)==0)
 	printf("亲爱的%s，",yh3.zhanghu); 
 	struct book shucha;
 		FILE *fp ;
		fp=fopen("book.txt","ab+");
		if(fp!=NULL)
		printf("成功打开文件\n"); 
		while(fread(&shucha,sizeof(struct book),1,fp))
		{
				printf("书名：%s,作者：%s,状态：%s\n",shucha.name,shucha.author,shucha.jyzt);
		}
		fclose(fp);
  } 
 int tsjs()
 {
 	system("cls");
 	if(strcmp(yh3.zhanghu,yh2.zhanghu)==0)
 	printf("亲爱的%s，",yh3.zhanghu); 
 	struct book shu;
 	char x[30];
 	printf("请输入你要检索的书名：");
	scanf("%s",&x);
	FILE *fp;
	fp=fopen("book.txt","a+");
	if (fp!=NULL)
	printf("成功打开文件\n");
	int k;
	while(strcmp(x,shu.name)!=0)
	{
		fread(&shu,sizeof(struct book),1,fp);

		
	}
	/*if(feof(fp)==0)
	{
		system("cls");
		printf("对不起，系统中没有这本书的存在\n");
	}
	else*/
	printf("书名：%s，作者：%s,状态：%s\n",shu.name,shu.author,shu.jyzt);
	fclose(fp);
 }
 int tscx()
 {
 	system("cls");
 	if(strcmp(yh3.zhanghu,yh2.zhanghu)==0)
 	printf("亲爱的%s，",yh3.zhanghu); 
 	int ch;
 	printf("是否要查看现有图书，是请输入1\n");
 	printf("你也可以通过书名来搜索系统中的书籍，请输入2\n"); 
	 scanf("%d",&ch);
	 switch(ch)
	 {
	 	case 1: sytscx();break;
	 	case 2: tsjs();break;
	 }
	 printf("退出查询请输入2\n");
	 scanf("%d",&ch);
	 if(ch==2)
	 {
	 	return 0;
	  } 
	  else
	  {
	
	  }
 }
 int dl()
 {
 	int ch;
 	char x[20];
 	char y[20];
 		FILE*fp;
 		fp=fopen("yonghu.txt","a+");
 		printf("请输入你的账号：");
 		scanf("%s",&x);
 		while(strcmp(x,yh2.zhanghu)!=0)
	{
		fread(&yh2,sizeof(struct yonghu),1,fp);
	}
	printf("请输入你的密码：");
	scanf("%s",&y);
	if(strcmp(y,yh2.mima)==0)
	{
		strcpy(yh3.zhanghu,yh2.zhanghu);
		system("cls");
		printf("亲爱的%s,登录成功",x);
		 m=1;
	}
	else
	{
		system("cls");
		printf("密码错误，登录失败\n");
	}
	fclose(fp);
	printf("退出查询请输入2\n");
	 scanf("%d",&ch);
	 if(ch==2)
	 {
	 	return 0;
	  } 
	  else
	  {
	
	  }
 } 
 int zc()
 {
 	int ch;
 	struct yonghu yh;
 	printf("请输入你想要注册的账号：");
 	scanf("%s",&yh.zhanghu); 
 	printf("请输入你想要的密码：");
	scanf("%s",&yh.mima);
	FILE*fp;
	fp=fopen("yonghu.txt","a+"); 
	if(fp!=NULL)
	fwrite(&yh,sizeof(struct yonghu),1,fp); 
	printf("注册成功\n");
	fclose(fp);
	printf("退出查询请输入2\n");
	 scanf("%d",&ch);
	 if(ch==2)
	 {
	 	return 0;
	  } 
	  else
	  {
	
	  }
 }
 int yhzc()
 {
 	/*int ch;
 	printf("功能正在开发中，请输入1退出");
	 scanf("%d",&ch); 
	 	while(getchar()!='\n')
		continue;
		*/
	printf("请选择\n");
	printf("  1.登录\n");
	printf("  2.注册\n");
	printf("  q.退出选择\n");
	char ch;
	ch=getchar();
	while(ch!='1'&&ch!='2'&&ch!='q')
	{
		printf("请重新正确输入(1,2,q)");
		//while(getchar()!='\n')
		//continue;
		ch=getchar();
		while(getchar()!='\n')
		continue;
	}
	switch(ch)
	 {
	 	case '1': dl();break;
	 	case '2': zc();break;
	 	case 'q': return 0;
	    default: break;
	 }
 }
 int tsjy()
 {
 	int ch; 
 	/*int ch;
 	printf("功能正在开发中，请输入1退出"); 
 	scanf("%d",&ch);
 		while(getchar()!='\n')
		continue;*/
    struct book shu;
	if(m==1)
	{
		printf("亲爱的：%s，请输入你想要借阅的图书:",yh2.zhanghu);
		char x[30];
		scanf("%s",&x);
		FILE *fp;
		fp=fopen("book.txt","ab+");
		if (fp!=NULL)
		printf("成功打开文件\n");
		int k;
		while(strcmp(x,shu.name)!=0)
		{
			fread(&shu,sizeof(struct book),1,fp);

		
		}
		//printf("书名：%s，作者：%s,状态：%s\n",shu.name,shu.author,shu.jyzt);
		if(strcmp("未借阅",shu.jyzt)==0)
	{
		printf("借阅成功");
		strcpy(shu.jyzt,"已借阅");
	fwrite(&shu,sizeof(struct book),1,fp);
	 } 
	 else
	 {
	 	printf("对不起，此书已被他人借阅"); 
	 }
	fclose(fp);
	printf("退出查询请输入2\n");
	 scanf("%d",&ch);
	 if(ch==2)
	 {
	 	return 0;
	  } 
	  else
	  {
			
	  }
}
else
{
	int ch;
	printf("请先登录，再进行图书借阅");
	 printf("退出查询请输入2\n");
	 scanf("%d",&ch);
	 if(ch==2)
	 {
	 	return 0;
	  } 
	  else
	  {
	
	  } 
}
	 
 }
 int main()
{
 	while(1)
 	{
 		
	 
	 sjm();
     sjmsx();
 	}
 } 
