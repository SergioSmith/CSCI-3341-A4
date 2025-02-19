#include <stdio.h>
struct Room
{
    char name[5];
    char computerType;
    int numOfComputers;
};
void mostW(struct Room arr[], int size);
void mostL(struct Room arr[], int size);
void mostComputers(struct Room arr[], int size);
void leastComputers(struct Room arr[], int size);

int main()
{
    int roomNumber, theNum, choosen, numOfRooms;
    char wOrL;
    struct Room arr[100];

    printf("How many rooms do you want to input? ");
    scanf("%d", &numOfRooms);

    for (int i = 1; i <= numOfRooms; i++)
    {

        printf("\nPlease input information for room 1: ");
        printf("\nName? ");
        scanf("%d", &roomNumber);

        printf("Type('W' or 'L')? ");
        scanf(" %c", &wOrL);

        printf("Number? ");
        scanf("%d", &theNum);
        struct Room s = {roomNumber, wOrL, theNum};
        struct Room *ps = &s;
        arr[i - 1] = *ps;
    }

    printf("\nWhich of the following four groups do you want to print? (1) rooms with Windows computers (2) rooms with Linux computers (3) rooms with the largest number of computers (4) rooms with the least number of computers.\n");
    scanf(" %d", &choosen);

    if (choosen == 1)
        mostW(arr, numOfRooms);
    if (choosen == 2)
        mostL(arr, numOfRooms);
    if (choosen == 3)
        mostComputers(arr, numOfRooms);
    if (choosen == 4)
        ;
    leastComputers(arr, numOfRooms);

    return 0;
}

void mostW(struct Room arr[], int size)
{
    struct Room mostW = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i].computerType == 'L')
            continue;

        if (mostW.numOfComputers < arr[i].numOfComputers)
            mostW = arr[i];
    }
    printf("Room %s has %d Windows computers.", mostW.name, mostW.numOfComputers);
}

void mostL(struct Room arr[], int size)
{
    struct Room mostL = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i].computerType == 'L')
            continue;

        if (mostL.numOfComputers < arr[i].numOfComputers)
            mostL = arr[i];
    }
    printf("Room %s has %d Windows computers.", mostL.name, mostL.numOfComputers);
}

void mostComputers(struct Room arr[], int size)
{
    struct Room greatest = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (greatest.numOfComputers < arr[i].numOfComputers)
            greatest = arr[i];
    }

    if (greatest.computerType == 'L')
        printf("Room %s has %d Linux computers.", greatest.name, greatest.numOfComputers);
    else if (greatest.computerType == 'W')
        printf("Room %s has %d Windows computers.", greatest.name, greatest.numOfComputers);
}

void leastComputers(struct Room arr[], int size)
{
    struct Room least = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (least.numOfComputers > arr[i].numOfComputers)
            least = arr[i];
    }

    if (least.computerType == 'L')
        printf("Room %s has %d Linux computers.", least.name, least.numOfComputers);
    else if (least.computerType == 'W')
        printf("Room %s has %d Windows computers.", least.name, least.numOfComputers);
}