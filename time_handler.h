#ifndef GRANDPARENT_H
#define GRANDPARENT_H

#define FALSE 0
#define TRUE 1
#define PRINT_ACTIVE "print"
#define PRINT_INACTIVE  "nonprint"
#define SEC_MIN_HOUR_LENGTH     3
#define TIME_LENGTH             9
#define DATE_LENGTH             12
#define BACK_SLASH              '\0'
#define MONTH_LENGTH            4
#define DAY_LENGTH              3
#define YEAR_LENGHT             5
#define STRING_ARE_EQUAL        0
#define FILE_LENGHT             100
#define DECIMALL                 0
#define SEPARATOR               ":"
#define FLAG_LENGTH             2
#define FLAG_POS_0              0
#define FLAG_SEPARATOR          1
#define FLAG_POS_IN_FILE        14
#define HOUR_POSITION_0         0
#define HOUR_POSITION_1         1
#define BACK_SLASH_HOUR         2
#define MINUTE_POSITION_0       0
#define MINUTE_POSITION_1       1
#define BACK_SLASH_MINUTE       2
#define SECOND_POSITION_0       0
#define SECOND_POSITION_1       1
#define BACK_SLASH_SECOND       2
#define MONTH_POSITION_0        0
#define MONTH_POSITION_1        1
#define MONTH_POSITION_2        2
#define BACK_SLASH_MONTH        3
#define DAY_POSITION_0          0
#define DAY_POSITION_1          1
#define BACK_SLASH_DAY          2
#define YEAR_POSITION_0         0
#define YEAR_POSITION_1         1
#define YEAR_POSITION_2         2
#define YEAR_POSITION_3         3
#define BACK_SLASH_YEAR         4


typedef unsigned char U8;
typedef unsigned int U32;
typedef int S32;
typedef  char S8;

U8 succes_write_file;
U8 flag_choice;
S8 the_diff[FILE_LENGHT];
typedef struct CURRENT_TIME_TAG
{
    S8 hour_integer;
    S8 minutes_integer;
    S8 seconds_integer;
}CURRENT_TIME;

typedef struct CURRENT_DATE_TAG
{
    U8 day_integer;
    U8 month_integer;
    U32 year_integer;
}CURRENT_DATE;

CURRENT_TIME time_flow;
CURRENT_DATE date_flow;



S8 *readFile(S8 *fileName);
void Get_Time(S8 *print);
void Get_Date(S8 *print);
void SaveTimeAndDate();
CURRENT_TIME ComputationTime();
CURRENT_TIME differenceBetweenTimePeriod(CURRENT_TIME start, CURRENT_TIME stop);
int Read_Start_Stop_Flag();
void RemoveTextFromFile();
void printTime_Difference();
void MessageBoxTime();










#endif /* GRANDPARENT_H */
