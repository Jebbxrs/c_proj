/*This program computes and prints out the parking charges of a vehicle
  according to its respective vehicle type.
  Written by: Vince Jevy B. Tapdasan
  Date: November  , 2023
  */
#include <stdio.h>
#include <ctype.h>
// Declaration of User-defined functions
void calcHours (int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int *hourParked, int *minuteParked);
int returnRounded (int hourParked, int minuteParked);
double calcCharges (char vehicleType, int hourParked);
void printCharges (char vehicleType, int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int hourParked, int minuteParked, int roundedHours, double totalCharges);
void vehicleIdentifier (char vehicleType);
// Main function
int main ()
{
    // Local variables
    int hourEntered, minuteEntered, hourLeft, minuteLeft, roundedHours;
    double totalCharge;
    int hourParked, minuteParked;
    char vehicleType;
    // Input
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
    // Conditional statements
    if (hourEntered > 24 || hourLeft > 24 || hourEntered < 0 || hourLeft < 0)
    {
        printf("ERROR: THE NUMBER OF HOURS SHOULD NOT EXCEED 24 OR BE LESS THAN 0.\n");
        return 0;
    }
    else if (minuteEntered > 60 || minuteLeft > 60 || minuteEntered < 0 || minuteLeft < 0)
    {
        printf("ERROR: THE NUMBER OF MINUTES SHOULD NOT EXCEED 60 OR BE LESS THAN 0.\n");
        return 0;
    }
    else if (hourEntered > hourLeft || ((hourLeft == 24 || hourLeft == 0) && minuteLeft > 0))
    {
        printf("ERROR: CANNOT STAY BEYOND MIDNIGHT. VEHICLE WILL BE TOWED AWAY.\n");
        return 0;
    } 
    else 
    {
        vehicleType = toupper(vehicleType);
        // Function calls
        calcHours(hourEntered, minuteEntered, hourLeft, minuteLeft, &hourParked, &minuteParked);
        roundedHours = returnRounded(hourParked, minuteParked);
        totalCharge = calcCharges(vehicleType, roundedHours);
        printCharges(vehicleType, hourEntered, minuteEntered, hourLeft, minuteLeft, hourParked, minuteParked, roundedHours, totalCharge);
    }
}
/*calcHours function:
  Computes the amount of hours a vehicle is parked.
  */
void calcHours (int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int *hourParked, int *minuteParked)
{
    // Conditional statements
    if (minuteLeft < minuteEntered)
    {
        minuteLeft += 60;
        --hourLeft;
    }
    // Process
    *hourParked = hourLeft - hourEntered;
    *minuteParked = minuteLeft - minuteEntered;
    return;
}
/*returnRounded function:
 Rounds up the number of hours a vehicle is parked.
  */
int returnRounded (int hourParked, int minuteParked)
{
    int roundedHours;

    if (minuteParked > 0)
        roundedHours = hourParked + 1;            
    else 
        roundedHours = hourParked;
    return roundedHours;
}
/*calcCharges function:
  Computes for the total amount charged for parking,
  with different rates for every type of vehicle.
  */
double calcCharges (char vehicleType, int roundedHours)
{
    double parkingTotal;
    // Conditional statements
    switch (vehicleType)
    {
        case 'C':
            if (roundedHours > 3)
                parkingTotal = 1.50 * (roundedHours - 3);
            else 
                parkingTotal = 0.00 * roundedHours;
            break;
        case 'T':
            if (roundedHours > 2)
                parkingTotal = 2.30 * (roundedHours - 2) + 1.00 * 2;
            else 
                parkingTotal = 1.00 * roundedHours;
            break;
        case 'B':
            if (roundedHours > 1)
                parkingTotal = 3.70 * (roundedHours - 1) + 2.00 * 1;
            else 
                parkingTotal = 2.00 * roundedHours; 
            break;
    }
    return parkingTotal;
}
/*printCharges function:
  Prints out the parking charges.
  */
void printCharges (char vehicleType, int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, int hourParked, int minuteParked, int roundedHours, double totalCharges)
{   
    // Conditional statements
    if (vehicleType == 'C' || vehicleType == 'T' || vehicleType == 'B')
    {
        // Output
        printf("\t\t%10s\n\n", "PARKING LOT CHARGE");
        vehicleIdentifier(vehicleType);
        printf("TIME-IN:\t\t\t\t %02d : %02d\n", hourEntered, minuteEntered);
        printf("TIME-OUT:\t\t\t\t %02d : %02d\n", hourLeft, minuteLeft);
        printf("\t\t\t\t\t--------\n");
        printf("PARKING TIME\t\t\t\t   %02d:%02d\n", hourParked, minuteParked);
        printf("ROUNDED TOTAL\t\t\t\t%8d\n", roundedHours);
        printf("\t\t\t\t\t--------\n");  
        printf("TOTAL CHARGE\t\t\t\t %3c%4.2f\n",'$', totalCharges);
        return;
    }
    else 
    {
        printf("ERROR: INVALID VEHICLE TYPE. PROGRAM TERMINATED.\n");
        return;
    }
}
/*vehicleIdentifier function:
  Prints out the type of vehicle according to the user's input.
  */
void vehicleIdentifier (char vehicleType)
{
    // Conditional statements
    if (vehicleType == 'C')
        printf("Type of Vehicle: %s\n", "Car");
    else if (vehicleType == 'T')
        printf("Type of Vehicle: %s\n", "Truck");
    else if (vehicleType == 'B') 
        printf("Type of Vehicle: %s\n", "Bus");  
    return;
}