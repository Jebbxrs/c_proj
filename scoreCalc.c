/*This program computes the average of three given scores and prints out the respective grade.
  Written by: Vince Jevy B. Tapdasan
  Date: November  , 2023
  */
#include <stdio.h>
#include <stdlib.h>
// Declaration of user-defined functions
void storeInput(int *score1, int *score2, int *score3);
float calcAvgScore(int score1, int score2, int score3); 
void printGrade(int score1, int score2, int score3, float avgScore);
// Main function
int main()
{   
    // Local Declarations
    int score1, score2, score3;
    float avgScore;

    // Function Calls
    storeInput(&score1, &score2, &score3); 
    avgScore = calcAvgScore(score1, score2, score3);
    printGrade(score1, score2, score3, avgScore);
    return 0;
}
/*storeInput function:
Prompts the user to input three scores from 1-100 and stores them
into pointer variables.
*/
void storeInput(int *score1, int *score2, int *score3)
{
    printf("Enter the first score (0-100):  ");
    scanf("%d", score1);
    printf("Enter the second score (0-100): ");
    scanf("%d", score2);
    printf("Enter the third score (0-100):  ");
    scanf("%d", score3);
    return;
}
/*calcAvgScore function:
Computes and returns the average of the three scores.
*/
float calcAvgScore(int score1, int score2, int score3)
{
    float avgScore;

    if (score1 > 100 || score2 > 100 || score3 > 100 || score1 < 0 || score2 < 0 || score3 < 0)
    {
        printf("INVALID: Score must only be between 0 and 100.\n");
        exit;
    } 
    else
        avgScore = (score1 + score2 + score3) / 3.0;
    return avgScore;
} 
/*printGrade function:
Determines the grade respective to the average scores 
and prints it out.
*/
void printGrade(int score1, int score2, int score3, float avgScore)
{
    // Local Declarations
    char grade;

    if (avgScore >= 90)
        grade = 'A';
    else if (avgScore < 90 && avgScore >= 70)
    {
        if (score3 > 90)
            grade = 'A';
        else 
            grade = 'B';
    }
    else if (avgScore < 70 && avgScore >= 50)
    {
        float pseudoAvg = (score2 + score3) / 2;

        if (pseudoAvg > 70)
            grade = 'C';
        else 
            grade = 'D';
    }
    else if (avgScore < 50)
        grade = 'F';
    // Output
    printf("Average Score: %.2f\n", avgScore);
    printf("Grade:\t%c\n", grade);
    return;
}
