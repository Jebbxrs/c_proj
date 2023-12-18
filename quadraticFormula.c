/*This program computes the roots of a quadratic equation.
  Written by: Vince Jevy B. Tapdasam
  Date: November , 2023
  */
#include <stdio.h>
#include <math.h>
// Declaration of user-defined functions
void quadraticRoots(int a, int b, int c);
// Main function
int main()
{
    // Local Variables
    int a, b, c; 

    printf("\t\t    Quadratic Equation Root Calculator\n");
    printf("Enter the first constant  (a): "); // asks for first constant
    scanf(" %d", &a);
    printf("Enter the second constant (b): "); // asks for second constant
    scanf(" %d", &b);
    printf("Enter the third constant  (c): "); // asks for third constant
    scanf(" %d", &c);
    // Function call
    quadraticRoots(a, b, c);
    return 0;
}
/* quadraticRoots function:
   Prints out the roots of the equation.
*/
void quadraticRoots(int a, int b, int c)
{
    float discriminant; 
    float root1, root2; 
    //Computes for discriminant
    discriminant = b * b - (4 * a * c);
    //Conditional Statements
    if (a == 0 && b == 0) 
        printf("INVALID: There is no solution.\n"); 
    else if (a == 0) 
    {
        root1 = (float)-c / b;
        printf("The root of the equation is %.2f.\n", root1);
    } 
    else if (discriminant == 0) 
    {
        root1 = -b / (2 * a);
        printf("The root of the equation is: %.2f.\n", root1); 
    } 
    else if (discriminant < 0) 
        printf("INVALID: There are no real roots.\n");
    else 
    {
    //Computes for the two roots of the equation
        root1 = (float)(-b + sqrt(discriminant)) / (2 * a);
        root2 = (float)(-b - sqrt(discriminant)) / (2 * a);
    //Outputs the roots of the equation
        printf("The roots of the equation are: %.2f and %.2f.\n", root1, root2);
    }
    return;
}
