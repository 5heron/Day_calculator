#include<stdio.h>
#include<stdlib.h>
void main()
{
    int year,daycopy,copyofyear,validdaycase,simplifiedoffset,offsetsperyear,totaloffset,offsetof2003,month,day,leapyearoffset,daychecker;
    printf("Enter the year\n");
    scanf("%d",&year);
    /*Calculation of total offsets from 2003 january 1*/
    totaloffset=0;
    offsetof2003=2;
    leapyearoffset=0;
    copyofyear=year;
    if (year!=2003)
    {
        while (copyofyear!=2003)
        {
            offsetsperyear=1;
            if ((copyofyear%100)==0)
            {
                if ((copyofyear%400)==0)
                {
                    offsetsperyear=2;
                }
            }
            else if ((copyofyear%4)==0)
            {
                offsetsperyear=2;
            }
            totaloffset=(totaloffset+offsetsperyear);
            if (copyofyear>2003)
            {
                copyofyear=copyofyear-1;
            }
            else
            {
                copyofyear=copyofyear+1;
            }           
        }
        if ((year%100)==0)
        {
            if ((year%400)==0)
            {
                leapyearoffset=1;
                if (year>2003)
                {
                    totaloffset=totaloffset-1;
                }
            }        
        }    
        else if ((year%4)==0)
        {
            leapyearoffset=1;
            if (year>2003)
            {
                totaloffset=totaloffset-1;
            }
        }
        if (year>2003)
        {
            totaloffset=totaloffset+offsetof2003;
            simplifiedoffset = (totaloffset%7);
        }   
        else
        {
            totaloffset=offsetof2003-totaloffset;
            if (totaloffset<0)
            {
                totaloffset=(-totaloffset);
            }
            simplifiedoffset = (totaloffset%7);
            simplifiedoffset =(7-simplifiedoffset);
            simplifiedoffset =(simplifiedoffset%7);
        }
    }
    printf("Enter the month\n");
    scanf("%d",&month);
    if (month<1||month>12)
    {
        printf("Invalid input\n");
        exit(2);
    }
    printf("Enter the day\n"); 
    scanf("%d",&day);
    daycopy=day;
    if (year==2003)
    {
        simplifiedoffset=2;
    }
    switch (month)
    {
    case 1:day=(day+simplifiedoffset);
           validdaycase=1; 
        break;
    case 2:day=(day+simplifiedoffset+3);
        break;
    case 3:day=(day+simplifiedoffset+3+leapyearoffset);
            validdaycase=1;
        break;
    case 4:day=(day+simplifiedoffset+6+leapyearoffset);
            validdaycase=2;
        break;
    case 5:day=(day+simplifiedoffset+1+leapyearoffset);
            validdaycase=1;
        break;
    case 6:day=day+simplifiedoffset+4+leapyearoffset;
            validdaycase=2;
        break; 
    case 7:day=day+simplifiedoffset+6+leapyearoffset;
            validdaycase=1;
        break; 
    case 8:day=day+simplifiedoffset+2+leapyearoffset;
            validdaycase=1;
        break; 
    case 9:day=day+simplifiedoffset+5+leapyearoffset;
            validdaycase=2;
        break; 
    case 10:day=day+simplifiedoffset+leapyearoffset;
            validdaycase=1;
        break; 
    case 11:day=day+simplifiedoffset+3+leapyearoffset;
            validdaycase=2;
        break; 
    case 12:day=day+simplifiedoffset+5+leapyearoffset;
            validdaycase=1;
        break;    
    default:break;
    }
    if (validdaycase==1)
    {
        if (daycopy<1||daycopy>31)
        {
            printf("Invalid input \n");
            exit(3);
        }
    }
    else if (validdaycase==2)
    {
        if (daycopy<1||daycopy>30)
        {
            printf("Invalid input \n");
            exit(4);
        }
    }
    if (month==2)
    {
        if (leapyearoffset&&(daycopy<1||daycopy>29))
        {
            printf("Invalid input \n");
            exit(5);
        }
        else if (leapyearoffset==0)
        {
            if (daycopy<1||daycopy>28)
            {
            printf("Invalid input \n");
            exit(6);
            }
        }
    }
    daychecker=day%7;
    switch(daychecker)
    {
        case 0:printf("Sunday\n");
        break;
        case 1:printf("Monday\n");
        break;
        case 2:printf("Tuesday\n");
        break;
        case 3:printf("Wednesday\n");
        break;
        case 4:printf("Thursday\n");
        break;
        case 5:printf("Friday\n");
        break;
        case 6:printf("Saturday\n");
        break;
        default:printf("Invalid input\n");
    }
}