#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int i,j,h,k,r,m,n,s,year,mon[12]={31,28,31,30,31,30,31,31,30,31,30,31},day[12];
	printf("请输入年份：");
	scanf("%d",&year);
	printf("想要排几行：");
	scanf("%d",&n);
	if(year%4==0&&year%100!=0||year%400==0)
		mon[1]=29;
	day[0]=(year+(year-1)/4-(year-1)/100+(year-1)/400)%7;
	for (m=1;m<12;m++)
		day[m]=(day[m-1]+mon[m-1])%7;
	for (i=1;i<=n;i++)
	{
		printf("_____________________   ");
	}
	printf("\n");
	for(i=1;i<=12/n+1;i++)
	{
		for(j=1;j<=10;j++)
		{
			for (r=1,s=(i-1)*n;r<=n&&s<12;r++,s++)
			{
				if (j==1)
					printf("%8d年%3d月      ",year,s+1);
				if (j==2||j==10)
					printf("_____________________");
				if (j==3)
					printf(" 日 一 二 三 四 五 六");
				for (k=(j-4)*7+1,h=1;k<=42&&h<=7;k++,h++)
				{
					if (k<=mon[s]+day[s])
					{
						if (j==4)
						{
							if (k<=day[s])
								printf("   ");
							else
								printf("%3d",k-day[s]);
						}
						else if (j!=1&&j!=2&&j!=3&&j!=10)
							printf("%3d",k-day[s]);
					}
					else
						printf("   ");
				}
				printf("   ");
			}
			printf("\n");	
		}
	}
	system("color B0");
	system("pause");
	return 0;
}