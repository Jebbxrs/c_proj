#include <stdio.h>
#include <ctype.h>

void calcHours (int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int *hourParked, int *minuteParked);
int returnRounded (int hourParked, int minuteParked);
double calcCharges (char vehicleType, int hourParked);
void printCharges (char vehicleType, int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int hourParked, int minuteParked, int roundedHours, double totalCharges);
void vehicleIdentifier (char vehicleType);

int main ()
{
    int hourEntered, minuteEntered, hourLeft, minuteLeft, roundedHours;
    double totalCharge;
    int hourParked, minuteParked;
    char vehicleType;

    printf("Type of vehicle? ");
    scanf("%c", &vehicleType);
    printf("Hour vehicle entered lot   (0 - 24)? ");
    scanf("%d", &hourEntered);
    printf("Minute vehicle entered lot (0 - 60)? ");
    scanf("%d", &minuteEntered);
    printf("Hour vehicle left lot      (0 - 24)? ");
    scanf("%d", &hourLeft);
    printf("Minute vehicle left lot    (0 - 60)? ");
    scanf("%d", &minuteLeft);
    printf("\n");

    if (hourEntered > hourLeft || (hourLeft == 24 && minuteLeft > 0))
        printf("ERROR: CANNOT STAY BEYOND MIDNIGHT. VEHICLE WILL BE TOWED AWAY.\n");
    else 
    {
        vehicleType = toupper(vehicleType);
        calcHours(hourEntered, minuteEntered, hourLeft, minuteLeft, &hourParked, &minuteParked);
        roundedHours = returnRounded(hourParked, minuteParked);
        totalCharge = calcCharges(vehicleType, roundedHours);
        printCharges(vehicleType, hourEntered, minuteEntered, hourLeft, minuteLeft, hourParked, minuteParked, roundedHours, totalCharge);
    }
    return 0;
}

void calcHours (int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int *hourParked, int *minuteParked)
{
    if (minuteLeft < minuteEntered)
    {
        minuteLeft += 60;
        --hourLeft;
    }
    *hourParked = hourLeft - hourEntered;
    *minuteParked = minuteLeft - minuteEntered;
    return;
}

int returnRounded (int hourParked, int minuteParked)
{
    if (minuteParked > 0)
        hourParked += 1;
    return hourParked;
}

double calcCharges (char vehicleType, int roundedHours)
{
    double vehicleRate;

    switch (vehicleType)
    {
        case 'C':
            if (roundedHours > 3)
                vehicleRate = 1.50 * (roundedHours - 3);
            else 
                vehicleRate = 0.00 * roundedHours;
            break;
        case 'T':
            if (roundedHours > 2)
                vehicleRate = 2.30 * (roundedHours - 2) + 1.00 * 2;
            else 
                vehicleRate = 1.00 * roundedHours;
            break;
        case 'B':
            if (roundedHours > 1)
                vehicleRate = 3.70 * (roundedHours - 1) + 2.00 * 1;
            else 
                vehicleRate = 2.00 * roundedHours;  
            break;
        default:
            break;
    }
    return vehicleRate;
}

void printCharges (char vehicleType, int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int hourParked, int minuteParked, int roundedHours, double totalCharges)
{   
    if (vehicleType == 'C' || vehicleType == 'T' || vehicleType == 'B')
    {
        printf("\t\t%10s\n\n", "PARKING LOT CHARGE");
        vehicleIdentifier(vehicleType);
        printf("TIME-IN:\t\t\t\t%c%02d : %02d\n", ' ', hourEntered, minuteEntered);
        printf("TIME-OUT:\t\t\t\t%c%02d : %02d\n", ' ', hourLeft, minuteLeft);
        printf("\t\t\t\t\t--------\n");
        printf("PARKING TIME\t\t\t\t%3c%02d:%02d\n", ' ', hourParked, minuteParked);
        printf("ROUNDED TOTAL\t\t\t\t%8d\n", roundedHours);
        printf("\t\t\t\t\t--------\n");  
        printf("TOTAL CHARGE\t\t\t\t%3c%4.2f",'$', totalCharges);
    }
    else
        printf("ERROR: INVALID VEHICLE TYPE. PROGRAM TERMINATED.\n");
    return;
}

void vehicleIdentifier (char vehicleType)
{
    if (vehicleType == 'C')
        printf("Type of Vehicle: %s\n", "Car");
    else if (vehicleType == 'T')
        printf("Type of Vehicle: %s\n", "Truck");
    else if (vehicleType == 'B') 
        printf("Type of Vehicle: %s\n", "Bus");
    return;
}