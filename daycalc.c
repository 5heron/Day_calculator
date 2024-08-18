#include<stdio.h>
int in_yr_change(int no_yr_offsets,int year,int leap, int month, int day){
	int jan1=6;
	if(year<2000){
		jan1 += 7;
		no_yr_offsets *= (-1);
	}
	if(month < 3)
		leap = 0;
	day--;
	int offsetof[12]={0,3,3,6,1,4,6,2,5,0,3,5};
	return (jan1 + no_yr_offsets + offsetof[month - 1] + leap + day) % 7;
}
int is_valid(int month, int day, int leap){
	int no_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(month < 1 || month > 12 || day < 1)
		return 0;
	if(month != 2){
		if(day > no_days[month - 1])
			return 0;
	}
	else if((leap) ? day > 29 : day > 28)
		return 0;
	return 1;
}
int n_yr_offsets(int inp, int leap){
	int temp = 2000 - inp;	
	int leap_of_2000 = 0, no_leap_yrs = temp / 4 - temp / 100 + temp / 400; 
	if(temp < 0){
		temp *= -1;
		no_leap_yrs *= -1;
		leap_of_2000 = 1;
		if(leap)
			no_leap_yrs-=1;
	}
	int total = temp;
	return ((no_leap_yrs * 2) + (total - no_leap_yrs + leap_of_2000)) % 7; 
}
int main(int argc, char *argv[])
{
	int inp;
	printf("Enter the input year : ");
	scanf("%d",&inp);
	int month,day;
	printf("Enter the Month : ");
	scanf("%d",&month);
	printf("Enter the Day : ");
	scanf("%d",&day);
	int leap = inp % 100 == 0 ? inp % 400 == 0 : inp % 4 == 0;
	if(is_valid(month,day,leap)){
		int no_yr_offsets = n_yr_offsets(inp, leap);
		day = in_yr_change(no_yr_offsets, inp, leap, month, day);
		char days[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
		printf("Its a %s\n",days[day]);
	}
	else
		printf("ERROR : Invalid input\n");	
}