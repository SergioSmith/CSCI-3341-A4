#include <stdio.h>

struct Room
{
    char name[5];
    char computerType;
    int numOfComputers;
};

int main()
{
    const int numOfRooms;
    int roomNumber, theNum, choosen;
    char wOrL;
    

    printf("How many rooms do you want to input? ");
    scanf("%d", &numOfRooms);

    struct Room arr[numOfRooms];
    

    for (int i = 1; i <= numOfRooms; i++)
    {

        printf("\nPlease input information for room 1: ");
        printf("\nName?");
        scanf("%d", &roomNumber);

        printf("\nType('W' or 'L')? ");
        scanf("%c", &wOrL);

        printf("\nNumber? ");
        scanf("%d", &theNum);
        struct Room s =  {roomNumber, wOrL, theNum};
        struct Room* ps = &s;
        arr[i-1] = *ps;
    }

    printf("\nWhich of the following four groups do you want to print? (1) rooms with Windows computers (2) rooms with Linux computers (3) rooms with the largest number of computers (4) rooms with the least number of computers.");
    scanf("%d", &choosen);

    if (choosen == 1) mostW(arr, numOfRooms);
    if (choosen == 2) mostL(arr, numOfRooms);
    
    return 0;
}

void mostW(struct Room arr[], int size)
{
    struct Room greatest = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i].computerType == 'l' || 'L') continue;
        
        if (greatest.numOfComputers < arr[i].numOfComputers)
            greatest = arr[i];
    }
    printf("Room %s has %n Windows computers.", arr[0].name, arr[0].numOfComputers);
}

void mostL(struct Room arr[], int size)
{
    struct Room greatest = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i].computerType == 'l' || 'L') continue;
        
        if (greatest.numOfComputers < arr[i].numOfComputers)
            greatest = arr[i];
    }
    printf("Room %s has %n Windows computers.", greatest.name,  greatest.numOfComputers);
}