#include "time_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <windows.h>

/* TBD Update - Implement a Debug MODE for Developers */
/* TBD Update - When user select YES at Stop Tracker menu , the program show unreal information*/
/* TBD Update - Secure the file where data are stored (output)
/* TBD Update - Ask user for a e-mail adress option in menu and at the end send a E-mail with specific information about spend time*/
/* TBD Continuous Update - Do Code optimization as much as you can */

/*This function control the menu of the program
STATUS : DONE and TESTED*/
/*
void MessageBoxTime()
{
Get_Time(PRINT_INACTIVE);
Get_Date(PRINT_INACTIVE);
S8 time_date[FILE_LENGHT] = "The START time is : ";
S32  stop_time_alegere;
S8 Total_Time[FILE_LENGHT];

strcat(time_date,__TIME__);
strcat(time_date,"\n");
strcat(time_date,"Date: : ");
strcat(time_date,__DATE__);
/**********************************************************************/
MessageBox(NULL,"Welcome to Time Tracker Application !\n\nPlease select a option:\n\n1. Start Time Tracker\n\n2. Stop Time Tracker\n\n",           "############    Time_Tracker    ############          ",MB_DEFAULT_DESKTOP_ONLY);
/**********************************************************************/
S32  start_time_alegere = MessageBox(NULL,"Start Time Tracker",           "############    Time_Tracker    ############          ",MB_YESNO);

/*Control the logic of the menu*/
succes_write_file = Read_Start_Stop_Flag();

if(start_time_alegere == IDYES && succes_write_file == FALSE )
{
    /**********************************************************************/
    MessageBox(NULL,time_date,"############    Time_Tracker    ############          ", MB_DEFAULT_DESKTOP_ONLY);
    /**********************************************************************/
    succes_write_file = TRUE;
    Get_Time(PRINT_INACTIVE);
    Get_Date(PRINT_INACTIVE);
    SaveTimeAndDate(PRINT_INACTIVE);
}
else if(start_time_alegere == IDYES && succes_write_file == TRUE)
{
        /**********************************************************************/
        MessageBox(NULL,"You already Start the Time Tracker.\nDo you want to stop the Tracker?" ," ############    Time_Tracker    ############          ",MB_ICONEXCLAMATION );
        /**********************************************************************/
        goto STOP;
}
else
{
    STOP:
    /**********************************************************************/
    stop_time_alegere = MessageBox(NULL,"Stop Time Tracker",           "############    Time_Tracker    ############          ",MB_YESNO);
    /**********************************************************************/
    if(stop_time_alegere == IDYES)
    {
        printTime_Difference();
        strcpy(Total_Time,the_diff);
        strcat(Total_Time,"\nA E-mail to your was sent to your address!");
        /**********************************************************************/
        MessageBox(NULL,Total_Time," ############    Time_Tracker    ############          ",MB_DEFAULT_DESKTOP_ONLY);
        /**********************************************************************/
        RemoveTextFromFile();

    }
    else
    {
        /**********************************************************************/
        MessageBox(NULL,"Thank you for choosing Time Tracker!\nHave a nice day !","############    Time_Tracker    ############          ",MB_DEFAULT_DESKTOP_ONLY);
        /**********************************************************************/
    }

}

}

*/
/*This function create a string that store the computed spend time
STATUS : DONE and TESTED*/
void printTime_Difference()
{
      CURRENT_TIME stop_time = ComputationTime();
      printf("%d",stop_time.hour_integer);
      S8 ShownTime[FILE_LENGHT] = "The time spend is : ";
      S8 hours[SEC_MIN_HOUR_LENGTH];
      S8 minutes[SEC_MIN_HOUR_LENGTH];
      S8 seconds[SEC_MIN_HOUR_LENGTH];

      itoa(stop_time.hour_integer,hours,DECIMALL);
      itoa(stop_time.minutes_integer,minutes,DECIMALL);
      itoa(stop_time.seconds_integer,seconds,DECIMALL);
      printf("\nTime spend is: %d:%d:%d",stop_time.hour_integer,stop_time.minutes_integer,stop_time.seconds_integer);

      strcat(ShownTime,hours);
      strcat(ShownTime,SEPARATOR);
      strcat(ShownTime,minutes);
      strcat(ShownTime,SEPARATOR);
      strcat(ShownTime,seconds);
      strcpy(the_diff,ShownTime);
      printf("%s",the_diff);
}



/*This function is used to compute difference between two time intervals
STATUS: DONE and TESTED*/
CURRENT_TIME differenceBetweenTimePeriod(CURRENT_TIME start, CURRENT_TIME stop)
{

    CURRENT_TIME diff;
    if(stop.seconds_integer > start.seconds_integer){
        --start.minutes_integer;
        start.seconds_integer += 60;
    }

    diff.seconds_integer = start.seconds_integer - stop.seconds_integer;
    diff.seconds_integer = abs(diff.seconds_integer);
    if(stop.minutes_integer > start.minutes_integer){
        --start.hour_integer;
        start.minutes_integer += 60;
    }

    diff.minutes_integer = start.minutes_integer - stop.minutes_integer;
    diff.minutes_integer = abs(diff.minutes_integer);
    diff.hour_integer = start.hour_integer - stop.hour_integer;
    diff.hour_integer = abs(diff.hour_integer);
    if(stop.hour_integer < start.hour_integer)
    {
        diff.hour_integer = 24 - diff.hour_integer;
    }
    return diff;
    printf("%d",diff.hour_integer);
    printf("%d",diff.minutes_integer);
    printf("%d",diff.seconds_integer);

}

/*This function read from the file char by char
STATUS: DONE and TESTED*/
char *readFile(S8 *fileName)
{
    FILE *file = fopen(fileName, "r");
    S8 *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    code = malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;

    }
    // don't forget to terminate with the null character
    code[n] = '\0';

    fclose(file);
    return code;
}


/*This function return the Time from the inline function __TIME_ and populate the structure date_flow
STATUS: DONE and TESTED*/
void Get_Time(S8 *print)
{
    S8 the_time[TIME_LENGTH];
    S8 hour[SEC_MIN_HOUR_LENGTH];
    S8  minutes[SEC_MIN_HOUR_LENGTH];
    S8  seconds[SEC_MIN_HOUR_LENGTH];
    /*Store the time in the Structure  time_flow */
    strcpy(the_time,__TIME__);

    hour[HOUR_POSITION_0] = the_time[0];
    hour[HOUR_POSITION_1] = the_time[1];
    hour[BACK_SLASH_HOUR] = BACK_SLASH;

    minutes[MINUTE_POSITION_0] = the_time[3];
    minutes[MINUTE_POSITION_1] = the_time[4];
    minutes[BACK_SLASH_MINUTE] = BACK_SLASH;

    seconds[SECOND_POSITION_0] = the_time[6];
    seconds[SECOND_POSITION_1] = the_time[7];
    seconds[BACK_SLASH_SECOND] = BACK_SLASH;

    time_flow.hour_integer = atoi(hour);
    time_flow.minutes_integer = atoi(minutes);
    time_flow.seconds_integer = atoi(seconds);

     if(strcmp(print,"print") == STRING_ARE_EQUAL)
     {
     printf("\nThe time is : ");
     printf("%d:%d:%d ",time_flow.hour_integer,time_flow.minutes_integer,time_flow.seconds_integer);
     }
}

/*This function return the Date from the inline function __DATE_ and populate the structure date_flow
STATUS: DONE and TESTED*/
void Get_Date(S8 *print)
{

    S8 the_date[DATE_LENGTH];
    S8 month[MONTH_LENGTH];
    S8 day[DAY_LENGTH];
    S8 year[YEAR_LENGHT];

    /*Store the time in the Structure  time_flow */
    strcpy(the_date,__DATE__);

    month[MONTH_POSITION_0] = the_date[0];
    month[MONTH_POSITION_1] = the_date[1];
    month[MONTH_POSITION_2] = the_date[2];
    month[BACK_SLASH_MONTH] = BACK_SLASH;

    day[DAY_POSITION_0] = the_date[4];
    day[DAY_POSITION_1] = the_date[5];
    day[BACK_SLASH_DAY] = BACK_SLASH;

    year[YEAR_POSITION_0] = the_date[7];
    year[YEAR_POSITION_1] = the_date[8];
    year[YEAR_POSITION_2] = the_date[9];
    year[YEAR_POSITION_3] = the_date[10];
    year[BACK_SLASH_YEAR] = BACK_SLASH;;

    if(strcmp(month,"Nov") == STRING_ARE_EQUAL)
    {
        date_flow.month_integer = 11;
    }
     else if(strcmp(month,"Dec") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 12;
    }
    else if(strcmp(month,"Jan") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 1;
    }
    else if(strcmp(month,"Feb") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 2;
    }
    else if(strcmp(month,"Mar") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 3;
    }
    else if(strcmp(month,"Apr") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 4;
    }
    else if(strcmp(month,"May") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 5;
    }
    else if(strcmp(month,"Jun") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 6;
    }
    else if(strcmp(month,"Jul") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 7;
    }
    else if(strcmp(month,"Aug") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 8;
    }
    else  if(strcmp(month,"Sep") == STRING_ARE_EQUAL )
    {
        date_flow.month_integer = 9;
    }
    else
    {
        date_flow.month_integer = 10;
    }

    date_flow.day_integer = atoi(day);
    date_flow.year_integer = atoi(year);
     if(strcmp(print,"print") == STRING_ARE_EQUAL)
     {
        printf("\nThe date is : %d.%d.%d ",date_flow.day_integer,date_flow.month_integer,date_flow.year_integer);
     }
}


/*This function save the data from data_flow and time_flow structure in the file output.Also , the flag succes_write_file is store at the end of the file
STATUS: DONE and TESTED*/
void SaveTimeAndDate(char *print)
{

   /*Write the time to time_output file*/
     FILE *out;
     out = fopen("output","w+");
     if(out == NULL)
    {
        printf("Error writting file!");
    }
    fprintf(out,"%d#%d#%d#%d#%d#%d#%d",time_flow.hour_integer,time_flow.minutes_integer,time_flow.seconds_integer,date_flow.day_integer,date_flow.month_integer,date_flow.year_integer,succes_write_file);
    fclose(out);
    if(strcmp(print,"print") == STRING_ARE_EQUAL)
    {
        printf("\nThe start time is : %d:%d:%d",time_flow.hour_integer,time_flow.minutes_integer,time_flow.seconds_integer);
    }
}

/*This function read the saved time from file and also compute the difference between two known time intervals
STATUS : DONE and TESTED*/
CURRENT_TIME ComputationTime()
{

    CURRENT_TIME stop_time;
    CURRENT_TIME local_debug = time_flow;
    S8 hours_spend;
    S8 minutes_spend;
    S8 seconds_spend;
    U8 lenght_time_from_file = 8;
    S8 *fileName = "output";
    S8 time_from_file[FILE_LENGHT];
    S8 hour[SEC_MIN_HOUR_LENGTH] = "0";
    S8 minutes[SEC_MIN_HOUR_LENGTH]= "0";
    S8 seconds[SEC_MIN_HOUR_LENGTH] = "0";
    strcpy(time_from_file,readFile(fileName));
    printf("%s",time_from_file);

    hour[0] = time_from_file[0];
    hour[1] = time_from_file[1];
    if(hour[1] != '#')
    {
       minutes[0] = time_from_file[3];
       minutes[1] = time_from_file[4];
       if(minutes[1] != '#')
       {
           seconds[0] = time_from_file[6];
           seconds[1] = time_from_file[7];
       }
       else
       {
           seconds[0] = time_from_file[5];
           seconds[1] = time_from_file[6];
       }
    }
    else
    {
        minutes[0] = time_from_file[2];
        minutes[1] = time_from_file[3];
        if(minutes[1] != '#')
        {
           seconds[0] = time_from_file[5];
           seconds[1] = time_from_file[6];
        }
       else
       {
           seconds[0] = time_from_file[4];
           seconds[1] = time_from_file[5];
       }
    }

    hours_spend = atoi(hour);
    minutes_spend = atoi(minutes);
    seconds_spend = atoi(seconds);

    stop_time.hour_integer = hours_spend;
    stop_time.minutes_integer  = minutes_spend;
    stop_time.seconds_integer = seconds_spend;
    printf("\nTime from file is: %d:%d:%d",stop_time.hour_integer,stop_time.minutes_integer,stop_time.seconds_integer);
    printf("\nTime from file is: %d:%d:%d",time_flow.hour_integer,time_flow.minutes_integer,time_flow.seconds_integer);

    /*Computation Method for  time */
    return (differenceBetweenTimePeriod(time_flow,stop_time));
}

/*This function read the Start Stop flag from the file (flag = succes_write_file global variable)*
STATUS: DONE and TESTED*/
int Read_Start_Stop_Flag()
{
    S8 *fileName = "output";
    S8 information_from_file[FILE_LENGHT];
    strcpy(information_from_file,readFile(fileName));
    S8 flag[2];
    switch(strlen(information_from_file))
    {
    case 21:
        flag[FLAG_POS_0] = information_from_file[20];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 20:
        flag[FLAG_POS_0] = information_from_file[19];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 19:
        flag[FLAG_POS_0] = information_from_file[18];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 18:
        flag[FLAG_POS_0] = information_from_file[17];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 17:
        flag[FLAG_POS_0] = information_from_file[16];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 16:
        flag[FLAG_POS_0] = information_from_file[15];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 15:
        flag[FLAG_POS_0] = information_from_file[14];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    case 1:
        flag[FLAG_POS_0] = information_from_file[13];
        flag[FLAG_SEPARATOR] = BACK_SLASH;
        break;
    default:
        exit(1);
        /*This should not be reached*/
        break;
    }
    return (atoi(flag));
}

/*This function clear the file
STATUS: DONE and TESTED*/
void RemoveTextFromFile()
{
    FILE *out;
     out = fopen("output","w+");

     if(out == NULL)
    {
     printf("Error writting file!");

    }
    fprintf(out,"%d",0);
    fclose(out);
}





