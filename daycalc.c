#include<stdio.h>
void dayselect(int day){
	(day<0)?printf("ERROR! : "):printf("Its a ");
	switch(day){
		case 0:printf("Sunday");
					 break;
		case 1:printf("Monday");
					 break;
		case 2:printf("Tuesday");
					 break;
		case 3:printf("Wednesday");
					 break;
		case 4:printf("Thursday");
					 break;
		case 5:printf("Friday");
					 break;
		case 6:printf("Saturday");
					 break;
		default:printf("Invalid input\n");
	}
}
void inyearchange(int ych,int year,int l){
	int jan1=6,offsetof[13]={0,0,3,3,6,1,4,6,2,5,0,3,5},m[13]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(year<2000){
		jan1+=7;
		ych*=(-1);
	}
	int month,day,leap=0;
	printf("Enter the Month : ");
	scanf("%d",&month);
	printf("Enter the Day : ");
	scanf("%d",&day);
	if(month>2&&l)
		leap=1;
	if(month<1||month>12||day<1)
		jan1=-1;
	if(month!=2)
		jan1=(day>m[month])?(-1):jan1;
	else if((l)?day>29:day>28)
		jan1=(-1);
	day--;
	if(jan1!=(-1))
		jan1=(jan1+ych+offsetof[month]+leap+day)%7;
	dayselect(jan1);
}
void yearchange(int inp){
	int preset=2000,mod=100,out=20,initcount,inmod,total,off=0,leap;
	inmod=inp/mod;
	out-=inmod;
	initcount=preset-inp;
	if(initcount<0)
		initcount*=-1,out*=-1,off=1;
	total=initcount;
	initcount/=4;		
	for(int i=0;i!=out;i+=1){
		if(i%4!=0)
			initcount-=1;
	}
	leap=inp%100==0?inp%400==0:inp%4==0;
	if(off&&leap)
		initcount-=1;
	initcount=((initcount*2)+(total-initcount+off))%7;
	inyearchange(initcount,inp,leap);
}
int main(int argc, char *argv[])
{
	int inp,leapcount;
	printf("Enter the input year : ");
	scanf("%d",&inp);
	yearchange(inp);
}