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
	printf("         ��ӭ����ͼ�����ϵͳ           \n");
	printf("                                        \n");
	printf("             ��ѡ����                 \n");
	printf("             1.ͼ��¼��                 \n");
	printf("           2.�û�ע�����¼             \n");
	printf("             3.ͼ�����                 \n");
	printf("             4.ͼ���ѯ                 \n");
	printf("             q.�˳�����                           \n");
	printf("             (�밴��ѡ��)               \n");
	printf("****************************************\n");
	return 0;
}
int sjmsx()
{
	char ch;
	ch=getchar();
	while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='q')
	{
		printf("��������ȷ����(1,2,3,4,q)");
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
 	printf("�װ���%s��",yh3.zhanghu); 
 	int j=0; 
 	struct book shu[50];
 	char i='1';
	while(i=='1')
	{
		printf("����������:");
		scanf("%s",&shu[j].name);
		while(getchar()!='\n')
		continue;
		printf("���������ߣ�");
		scanf("%s",&shu[j].author);
		char x[40]="δ����";
		strcpy(shu[j].jyzt,x);
		j++; 
		while(getchar()!='\n')
		continue;
		printf("\n1.����¼��ͼ��\n");
		printf("%s",x);
		printf("  0.����¼��\n");
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
 	printf("�װ���%s��",yh3.zhanghu); 
 	struct book shucha;
 		FILE *fp ;
		fp=fopen("book.txt","ab+");
		if(fp!=NULL)
		printf("�ɹ����ļ�\n"); 
		while(fread(&shucha,sizeof(struct book),1,fp))
		{
				printf("������%s,���ߣ�%s,״̬��%s\n",shucha.name,shucha.author,shucha.jyzt);
		}
		fclose(fp);
  } 
 int tsjs()
 {
 	system("cls");
 	if(strcmp(yh3.zhanghu,yh2.zhanghu)==0)
 	printf("�װ���%s��",yh3.zhanghu); 
 	struct book shu;
 	char x[30];
 	printf("��������Ҫ������������");
	scanf("%s",&x);
	FILE *fp;
	fp=fopen("book.txt","a+");
	if (fp!=NULL)
	printf("�ɹ����ļ�\n");
	int k;
	while(strcmp(x,shu.name)!=0)
	{
		fread(&shu,sizeof(struct book),1,fp);

		
	}
	/*if(feof(fp)==0)
	{
		system("cls");
		printf("�Բ���ϵͳ��û���Ȿ��Ĵ���\n");
	}
	else*/
	printf("������%s�����ߣ�%s,״̬��%s\n",shu.name,shu.author,shu.jyzt);
	fclose(fp);
 }
 int tscx()
 {
 	system("cls");
 	if(strcmp(yh3.zhanghu,yh2.zhanghu)==0)
 	printf("�װ���%s��",yh3.zhanghu); 
 	int ch;
 	printf("�Ƿ�Ҫ�鿴����ͼ�飬��������1\n");
 	printf("��Ҳ����ͨ������������ϵͳ�е��鼮��������2\n"); 
	 scanf("%d",&ch);
	 switch(ch)
	 {
	 	case 1: sytscx();break;
	 	case 2: tsjs();break;
	 }
	 printf("�˳���ѯ������2\n");
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
 		printf("����������˺ţ�");
 		scanf("%s",&x);
 		while(strcmp(x,yh2.zhanghu)!=0)
	{
		fread(&yh2,sizeof(struct yonghu),1,fp);
	}
	printf("������������룺");
	scanf("%s",&y);
	if(strcmp(y,yh2.mima)==0)
	{
		strcpy(yh3.zhanghu,yh2.zhanghu);
		system("cls");
		printf("�װ���%s,��¼�ɹ�",x);
		 m=1;
	}
	else
	{
		system("cls");
		printf("������󣬵�¼ʧ��\n");
	}
	fclose(fp);
	printf("�˳���ѯ������2\n");
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
 	printf("����������Ҫע����˺ţ�");
 	scanf("%s",&yh.zhanghu); 
 	printf("����������Ҫ�����룺");
	scanf("%s",&yh.mima);
	FILE*fp;
	fp=fopen("yonghu.txt","a+"); 
	if(fp!=NULL)
	fwrite(&yh,sizeof(struct yonghu),1,fp); 
	printf("ע��ɹ�\n");
	fclose(fp);
	printf("�˳���ѯ������2\n");
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
 	printf("�������ڿ����У�������1�˳�");
	 scanf("%d",&ch); 
	 	while(getchar()!='\n')
		continue;
		*/
	printf("��ѡ��\n");
	printf("  1.��¼\n");
	printf("  2.ע��\n");
	printf("  q.�˳�ѡ��\n");
	char ch;
	ch=getchar();
	while(ch!='1'&&ch!='2'&&ch!='q')
	{
		printf("��������ȷ����(1,2,q)");
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
 	printf("�������ڿ����У�������1�˳�"); 
 	scanf("%d",&ch);
 		while(getchar()!='\n')
		continue;*/
    struct book shu;
	if(m==1)
	{
		printf("�װ��ģ�%s������������Ҫ���ĵ�ͼ��:",yh2.zhanghu);
		char x[30];
		scanf("%s",&x);
		FILE *fp;
		fp=fopen("book.txt","ab+");
		if (fp!=NULL)
		printf("�ɹ����ļ�\n");
		int k;
		while(strcmp(x,shu.name)!=0)
		{
			fread(&shu,sizeof(struct book),1,fp);

		
		}
		//printf("������%s�����ߣ�%s,״̬��%s\n",shu.name,shu.author,shu.jyzt);
		if(strcmp("δ����",shu.jyzt)==0)
	{
		printf("���ĳɹ�");
		strcpy(shu.jyzt,"�ѽ���");
	fwrite(&shu,sizeof(struct book),1,fp);
	 } 
	 else
	 {
	 	printf("�Բ��𣬴����ѱ����˽���"); 
	 }
	fclose(fp);
	printf("�˳���ѯ������2\n");
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
	printf("���ȵ�¼���ٽ���ͼ�����");
	 printf("�˳���ѯ������2\n");
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
