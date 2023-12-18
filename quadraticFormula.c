/*This program computes the roots of a quadratic equation.
  Written by: Vince Jevy B. Tapdasam
  Date: November  , 2023
  */
#include <stdio.h>
#include <math.h>
// Declaration of user-defined functions
void quadraticRoots(int a, int b, int c);
// Main function
int main()
{
    // Local Variables
    int const_a, const_b, const_c; 

    printf("\t\t    Quadratic Equation Root Calculator\n");
    printf("Enter the first constant  (a): "); // asks for first constant
    scanf(" %d", &const_a);
    printf("Enter the second constant (b): "); // asks for second constant
    scanf(" %d", &const_b);
    printf("Enter the third constant  (c): "); // asks for third constant
    scanf(" %d", &const_c);
    // Function call
    quadraticRoots(const_a, const_b, const_c);
    return 0;
}
/* quadraticRoots function:
   Prints out the roots of the equation.
*/
void quadraticRoots(int a, int b, int c)
{
    float dsc; 
    float root1, root2; 
    //Computes for discriminant
    dsc = b * b - (4 * a * c);
    //Conditional Statements
    if (a == 0 && b == 0) 
        printf("INVALID: There is no solution.\n"); 
    else if (a == 0) 
    {
        root1 = (float)-c / b;
        printf("The root of the equation is %.2f.\n", root1);
    } 
    else if (dsc == 0) 
    {
        root1 = -b / (2 * a);
        printf("The root of the equation is: %.2f.\n", root1); 
    } 
    else if (dsc < 0) 
        printf("INVALID: There are no real roots.\n");
    else 
    {
    //Computes for the two roots of the equation
        root1 = (float)(-b + sqrt(dsc)) / (2 * a);
        root2 = (float)(-b - sqrt(dsc)) / (2 * a);
    //Outputs the roots of the equation
        printf("The roots of the equation are: %.2f and %.2f.\n", root1, root2);
    }
    return;
}