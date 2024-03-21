#include<stdio.h>
#include<stdlib.h>

struct Day
{
    char *dayName;
    int date;
    char *dayActivity;

};

struct Day *createCalender()
{
    struct Day *calender = (struct Day*)malloc(7 * sizeof(struct Day));
    return calender;
}

void readData(struct Day *calender)
{
    for(int i = 0; i < 7; i++)
    {
        printf("Enter the Details: \n");
        calender[i].dayName = (char*)malloc(20 * sizeof(char));
        calender[i].dayActivity = (char*)malloc(100 * sizeof(char));

        printf("Enter Day Name: ");
        scanf("%s", calender[i].dayName);

        printf("Enter Date: ");
        scanf("%d", &calender[i].date);

        printf("Enter Activity Description: ");
        scanf("%s", calender[i].dayActivity);

    }
}

void displayCalender(struct Day *calender)
{
    for(int i = 0; i < 7; i++)
    {
        printf("Day %d: %s, Date: %d, Activity Description: %s\n", i+1, calender[i].dayName, calender[i].date, calender[i].dayActivity);
    }
}

void freeMemory(struct Day *calender)
{
    for(int i = 0; i < 7; i++)
    {
        free(calender[i].dayName);
        free(calender[i].dayActivity);
    }
    free(calender);
}

int main()
{
    struct Day *calender = createCalender();
    readData(calender);
    displayCalender(calender);
    freeMemory(calender);
    return 0;
}