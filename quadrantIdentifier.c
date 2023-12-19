/*This program identifies what quadrant a certain angle belongs to.
  Written by: Vince Jevy B. Tapdasan
  Date: November  , 2023
  */
#include <stdio.h>
// Declaration of user-defined function(s)
double getInput();
void printQuadrant(double angle);

//Main function
int main()
{   
    double angle; 
    // Function call
    angle = getInput();
    printQuadrant(angle);
    return 0;
}
/*getInput function:
  Prompts the user to enter an angle from 0° to 360°.
*/
double getInput()
{
    // Local variables
    double angle;
    // Input
    printf("\t\t%10s\n", "Quadrant Identifier");
    printf("Enter an angle: "); 
    scanf("%lf", &angle);
    return angle;
}
/*printQuadrant function: 
  Determines which quadrant the input angle is found.
*/
void printQuadrant(double angle)
{
    // Local variables
    int quadrant; 
    // Conditional Statements
    if (angle == 0 || angle == 360)
        printf("The angle lies on the positive x-axis.\n");
    else if (angle == 90)
        printf("The angle lies on the positive y-axis.\n");
    else if (angle == 180)
        printf("The angle lies on the negative x-axis.\n");       
    else if (angle == 270)
        printf("The angle lies on the negative y-axis.\n");        
    else if (angle > 0 && angle < 90)
        quadrant = 1;
    else if (angle > 90 && angle < 180)
        quadrant = 2;
    else if (angle > 180 && angle < 270)
        quadrant = 3;
    else if (angle > 270 && angle < 360)
        quadrant = 4;
    else 
    {
        printf("The angle you entered is invalid.\n");
        return;
    }
    // Output
    printf("The angle is found in quadrant %d.\n", quadrant); 
    return;
} 