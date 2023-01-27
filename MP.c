/*
     Description:      <Every turn, players can choose to move left, right, or shoot. Following the player's move, the enemy's turn begins, during that they will move in a right-down-left-down cycle. This game has a six by four grid layout.  The player and enemies can move along four columns. The opponent can move move down down 5 rows, while the player can only move the sixth.The player wins when his score reaches 100, but  loses when an enemy turns to his row, the sixth row.>
     Programmed by:    Miko Santos   S19A
     Last modified:    <30 November 2022>
     Version:          <1>
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(int*, char*, int*, int *, int *, int*, int*, int*, int*, int*,int*, char*, char*, char*);
void printMap2(int*, char*, int*, int*, int*, int*, int*, int*, char*, char*, char*);
void detectX(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);
void moveEnemy(int*, int*, int*, int*, int*, int*, int*, int*,int*);
int getAction(int*);
void moveLeft(int*); 
void moveRight(int*);
void updateX(int*, int*, int*, int*);
void randomX(int*, int*, int*);

int main()

{
    int nI1, nJ1, nI2, nJ2, nI3, nJ3, nC_1, nC_2, nC_3, nAction;
    nI1 = 0; nJ1 = 0; nI2 = 0; nJ2 = 1; nI3 = 0; nJ3 = 2;
    nC_1 = 0;  nC_2 = 0; nC_3 = 0;
    int nScore = 0;
    int nCounter = 0;
    int nPlaceP=0;
    char cFirstX = 'X';
    char cSecondX = 'X';
    char cThirdX = 'X';
    char cPlayerP = 'P';

     printMap2(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &cFirstX, &cSecondX, &cThirdX);
   
    //Iterate when the score is less than or equal to 100 and the enemy has not turned the player's row.
    while (nScore <= 100 )
    {
        //This if-statement will be utilized when any of the enemy turned to the player's row, the sixth row.
        if ((nI1==4 && nC_1%2==1) || (nI2==4 && nC_2%2==1) || (nI3==4 && nC_3%2==1))
        {
            nAction = getAction(&nScore);
            if((nAction==3 && (nJ1==nPlaceP || nJ2==nPlaceP || nJ3==nPlaceP)))
            {
                detectX(&nScore, &nPlaceP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3);
            }
            if (nAction==2)
            {
                moveRight(&nPlaceP);
            }
            if (nAction==1)
            {
                moveLeft(&nPlaceP);
            }
            printMap(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3, &cFirstX, &cSecondX, &cThirdX);

            if (nI1==5 || nI2==5 || nI3==5)
            {
                printf("DEFEATED!\n");
                nScore = 101;
            }
        }
        // Iterates when the score is less than a hundred. It will then ask the user for an action indicated on numbers 1,2,3.
        if (nScore < 100)
        {
            //Asking for action input, if the player chose 1 but it is already in column 1 (0 in code); or chose 2 but already in row 4 (3 in code);
            //or the action is not in the range from 1 to 3; then, it prints the current unchanged game map and then ask for another action input. Stop iterating when the input is correct. 
            do
            {
                nAction = getAction(&nScore);
                //In this part, after reqforan action input, it should print gameboard
                if ((nAction==1 && nPlaceP==0) || (nAction==2 && nPlaceP==3) || nAction>3 || nAction<=0)
                    printMap2(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &cFirstX, &cSecondX, &cThirdX);
            } while ((nAction==1 && nPlaceP==0) || (nAction==2 && nPlaceP==3) || nAction>3 || nAction<=0);

            //Iterates when the score less than or equal to 90. Then the program will execute depending on the action input prospectively. If the score is greater than 90, the program will exit this itertion.
            if (nScore <= 90)
            {
                switch (nAction)
                {
                    // Action No: 1 for moving the player to the left
                    case 1:
                        if (!(nAction == 1 && nPlaceP == 0))
                        {
                            moveLeft(&nPlaceP);
                            printMap(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3, &cFirstX, &cSecondX, &cThirdX);
                        }
                        else
                            printMap2(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &cFirstX, &cSecondX, &cThirdX);
                        nCounter++; break;

                    // Action No: 2 for moving the player to the right
                    case 2:
                        if (!(nAction == 2 && nPlaceP == 3))
                        {
                            moveRight(&nPlaceP);
                            printMap(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3, &cFirstX, &cSecondX, &cThirdX);
                        }
                        else
                            printMap2(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &cFirstX, &cSecondX, &cThirdX);
                        nCounter++; break;

                    // Action No: 3 for shooting or killing one enemy nearest and is aligned with the player's column.
                    case 3:
                        detectX(&nScore, &nPlaceP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3);
                        printMap(&nPlaceP, &cPlayerP, &nI1, &nJ1, &nI2, &nJ2, &nI3, &nJ3, &nC_1, &nC_2, &nC_3, &cFirstX, &cSecondX, &cThirdX);
                        nCounter++; break;
                }
            }
        }

        //If score is a hundred, then it prints the victory statement and exit the program by updating score to 101.
        //And giving this as parameter to the parent while-conditional statement to exit from the iteration and subsequetly ends the program.
        if (nScore == 100)
        {
            printf("VICTORY!\n");
            nScore = 101;
        }
    }
}

/*   <This function, gameboard, prints the game map depending on various and changing parameters every iteration>
     Precondition: <It is assumed that some parameters are different compared to the initial/previous iteration's parameter due to calling the automove() function.>
     @param <*placeP> <*placeP is the jth position, or column number, of the player.>
     @param <*PlayerP> <This is the character 'P' for displaying the player on the game map.>
     @param <*I1,*J1> <The ith position and jth position of the first 'X' enemy respectively.>
     @param <*I2,*J2> <The ith position and jth position of the second 'X' enemy respectively.>
     @param <*I3,*J3> <The ith position and jth position of the third 'X' enemy respectively.>
     @param <*C_1> <Counter for first 'X' enemy that involves in determining what movement to execute in the automove() function.>
     @param <*C_2> <Counter for second 'X' enemy that involves in determining what movement to execute in the automove() function.>
     @param <*C_3> <Counter for third 'X' enemy that involves in determining what movement to execute in the automove() function.>
     @param <*firstX, *secondX, *thirdX> <These are the characters for displaying the first, second, and third enemy on the game map respectively.>
     @return <This function returns nothing.>
*/

//Prints the game map depending on various parameters. Note that these parameters should constanly be updating.
void printMap(int *nPlaceP, char *cPlayerP, int *nI1, int *nJ1, int *nI2, int *nJ2, int *nI3, int *nJ3, int *nC_1,int *nC_2,int *nC_3, char *cFirstX, char *cSecondX, char *cThirdX)
{
    int nrow = 6;
    int ncolumn = 4;
    //
    moveEnemy(&*nI1, &*nJ1, &*nI2, &*nJ2, &*nI3, &*nJ3, &*nC_1, &*nC_2, &*nC_3);

    //These three following if-statements will substitute a space when an enemy has turned/ stepped to on the player's row.
    if (*nI1==5 && ((*nC_1%3)%2==1))
        *cFirstX = 32;
    if (*nI2==5 && ((*nC_2%3)%2==1))
        *cSecondX = 32;
    if (*nI3==5 && ((*nC_3%3)%2==1))
        *cThirdX = 32;
    //Prints the game map following the aboe parameters.
    for (int i=0; i<nrow; i++)
    {
        for (int j=0; j<ncolumn; j++)
        {
            if(i==*nI1 && j==*nJ1)
                printf("%c ", *cFirstX);
            else if (i==*nI2 && j==*nJ2)
                printf("%c ", *cSecondX);
            else if (i==*nI3 && j == *nJ3)
                printf("%c ", *cThirdX);
            else if (i==5 && j == *nPlaceP)
                printf("%c ", *cPlayerP);
            else
                printf(". ");
        }
        printf("\n");
    }

}
/*   <This function is being executed when the action input from the user is not possible or beyond the boundaries of the game map. Prints the game map with unchanged parameters.>
     Precondition: <This function only prints the game map with parameters from the previous iteration.>
     @param <*placeP> <The jth position of the player.>
     @param <*PlayerP> <The character for the player.>
     @param <*I1,*J1> <The ith position and jth position of the first 'X' enemy respectively.>
     @param <*I2,*J2> <The ith position and jth position of the second 'X' enemy respectively.>
     @param <*I3,*J3> <The ith position and jth position of the third 'X' enemy respectively.>
     @param <*firstX, *secondX, *thirdX> <These are the characters for displaying the first, second, and third enemy on the game map respectively.>
     @return <This function returns nothing.>
*/
void printMap2(int *nPlaceP, char *cPlayerP, int *nI1, int *nJ1, int *nI2, int *nJ2, int *nI3, int *nJ3, char *cFirstX, char *cSecondX, char *cThirdX)
{
    int nrow, ncolumn;
    nrow = 6;
    ncolumn = 4;
      for (int i=0; i<nrow; i++)
    {
        for (int j=0; j<ncolumn; j++)
        {
            if(i==*nI1 && j==*nJ1)
                printf("%c ", *cFirstX);
            else if (i==*nI2 && j==*nJ2)
                printf("%c ", *cSecondX);
            else if (i==*nI3 && j == *nJ3)
                printf("%c ", *cThirdX);
            else if (i==5 && j == *nPlaceP)
                printf("%c ", *cPlayerP);
            else
                printf(". ");
        }
        printf("\n");
    }
}
/*   <This function detects the enemy/ies that are aligned with the player in its respctive column. Then, kills the enemy closest to the player. Afterwards,
    calls the subfunction updateXij() to respawn it on the uppermost row(i=0) with randomized jth position. Lastly, it adds up 10 points to the score.>
     Precondition: <The action input should be 3- the fire laser. >
     @param <*score> <This is the score of the player. In this function is where it is added to 10.>
     @param <*placeP> <The jth position of the player. Checks if any enemy/ies is/are aligned to it then kills the one nearest to it.>
     @param <*I1,*J1> <The ith position and jth position of the first 'X' enemy respectively.>
     @param <*I2,*J2> <The ith position and jth position of the second 'X' enemy respectively.>
     @param <*I3,*J3> <The ith position and jth position of the third 'X' enemy respectively.>
     @param <*C_1> <Counter for first 'X' enemy involved as parameter in updateXij() function.>
     @param <*C_2> <Counter for second 'X' enemy involved as parameter in updateXij() function.>
     @param <*C_3> <Counter for third 'X' enemy involved as parameter in updateXij() function.>
     @return <This function returns nothing.>
*/

//Detect if there is/are enemy/ies that aligned with the player's column.
void detectX(int *nScore, int *nPlaceP, int *nI1, int *nJ1, int *nI2, int *nJ2, int *nI3, int *nJ3, int *nC_1, int *nC_2, int *nC_3)
{
    int nNumI;
    //If three enemies are on the same column with player, it detects, shoot, and kills the enemy nearest to it.
    //Then, respawn it by updating its ith and jth position to the uppermost row randomly.
    if (*nPlaceP ==*nJ1 && *nPlaceP ==*nJ2 && *nPlaceP ==*nJ3)
    {
        if (*nI1>*nI2)
        {
            if (*nI1>*nI3){
                nNumI = *nI1;
                updateX(&nNumI, &*nJ1, &*nC_1, &*nScore);
                *nI1 = nNumI;
            }
            else {
                nNumI = *nI3;
                updateX(&nNumI, &*nJ3, &*nC_3, &*nScore);
                *nI3 = nNumI;
            }
        }
        else
        {
            if (*nI2>*nI3){
                nNumI = *nI2;
                updateX(&nNumI, &*nJ2, &*nC_2, &*nScore);
                *nI2 = nNumI;
            }
            else{
                nNumI = *nI3;
                updateX(&nNumI, &*nJ3, &*nC_3, &*nScore);
                *nI3 = nNumI;
            }

        }
    }
    //If there are two enemies that aligned with the player's column. Combinations such as 1:2; 2:3; 1:3 and vice versa could be encountered.
    //It detects, shoots, and kills the enemy nearest to it. Then, respawn it by updating its ith and jth position to the uppermost row randomly.
    else if(*nPlaceP ==*nJ1 && *nPlaceP ==*nJ2)
    {
        if (*nI1>*nI2 || *nI1 == *nI2){
            nNumI = *nI1;
            updateX(&nNumI, &*nJ1, &*nC_1, &*nScore);
            *nI1 = nNumI;
        }
        else {
            nNumI = *nI2;
            updateX(&nNumI, &*nJ2, &*nC_2, &*nScore);
            *nI2 = nNumI;
        }
    }
    else if(*nPlaceP ==*nJ2 && *nPlaceP ==*nJ3)
    {
        if (*nI2>*nI3 || *nI2 == *nI3) {
            nNumI = *nI2;
            updateX(&nNumI, &*nJ2, &*nC_2, &*nScore);
            *nI2 = nNumI;
        }
        else {
            nNumI = *nI3;
            updateX(&nNumI, &*nJ3, &*nC_3, &*nScore);
            *nI3 = nNumI;
        }
    }
    else if(*nPlaceP ==*nJ1 && *nPlaceP ==*nJ3)
    {
        if (*nI1>*nI3 || *nI1 == *nI3) {
            nNumI = *nI1;
            updateX(&nNumI, &*nJ1, &*nC_1, &*nScore);
            *nI1 = nNumI;
        }
        else {
            nNumI = *nI3;
            updateX(&nNumI, &*nJ3, &*nC_3, &*nScore);
            *nI3 = nNumI;
        }
    }
   //Only one enemy is aligned with the player, it detects, shoots, and kills that enemy. Then, respawn it by updating its ith and jth position to the uppermost row randomly.
    else if (*nPlaceP ==*nJ1){
        nNumI = *nJ1;
        updateX(&*nI1, &nNumI, &*nC_1, &*nScore);
        *nJ1=nNumI;
    }

    else if (*nPlaceP ==*nJ2) {
        nNumI = *nJ2;
        updateX(&*nI2, &nNumI, &*nC_2, &*nScore);
        *nJ2=nNumI;
    }

    else if (*nPlaceP ==*nJ3) {
        nNumI = *nJ3;
        updateX(&*nI3, &nNumI, &*nC_3, &*nScore);
        *nJ3=nNumI;
    }
}
/*   <This function asks the user for an action input.>
     Precondition: <The game map should be printed first before the execution of this function.>
     @param <*score> <The score of the player; In this function, it only prints the current score.>
     @return <This function returns the action inputted by the user.>
*/
int getAction(int *nScore)
{
    int nNum;
    printf("Score: %d\n", *nScore);
    printf("Actions:\n");
    printf("1-move left\n");
    printf("2-move right\n");
    printf("3-fire laser\n");
    printf("Input action: ");
    scanf("%d\n", &nNum);
    printf("\n");
    return nNum;
}

/*   <This function moves the player to the left.>
     Precondition: <The action input should be one (1).>
     @param <*placeP> <The jth position of the player. In this function, current jth position is subtracted by 1>
     @return <This function returns nothing.>
*/
void moveLeft(int *nPlaceP)
{
    if(*nPlaceP != 0)
        *nPlaceP -= 1;
}

/*   <This function moves the player to the right.>
     Precondition: <The action input should be one (2).>
     @param <*placeP> <The jth position of the player. In this function, current jth position is  added by 1>
     @return <This function returns nothing.>
*/

void moveRight(int *nPlaceP)
{
    *nPlaceP += 1;
}

/*   <This subfunction is for the movement of the enemies by updating their ith and jth position on a right-down-left-down cycle.>
     Precondition: <This function only executes when its parent function, gameboard() function, is executed initially. Otherwise, the position of the enemies does not change.>
     @param <*X1i,*X1j> <Update the ith position and jth position of the first 'X' enemy respectively based on the its counter c1.>
     @param <*X2i,*X2j> <Update the ith position and jth position of the second 'X' enemy respectively based on the its counter c2.>
     @param <*X3i,*X3j> <Update the ith position and jth position of the third 'X' enemy respectively based on the its counter c3>
     @param <*c1> <Counter for first 'X' enemy. For counter is 0, it will move an enemy to the right; 1 to move downward; 2 to move to the left; and 3 to move downward.>
     @param <*c2> <Counter for second 'X' enemy. For counter is 0, it will move an enemy to the right; 1 to move downward; 2 to move to the left; and 3 to move downward.>
     @param <*c3> <Counter for third 'X' enemy. For counter is 0, it will move an enemy to the right; 1 to move downward; 2 to move to the left; and 3 to move downward.>
     @return <This function returns nothing.>
*/
void moveEnemy(int *nX1i, int *nX1j, int *nX2i, int *nX2j, int *nX3i, int *nX3j, int *nC1, int *nC2,int *nC3)
{
    switch (*nC1%4){
        case 0:
                if (*nX1j==0 || *nX1i%2==0)
                    *nX1j += 1;
                *nC1 +=1;
                break;
        case 1:
                if (*nX1i%2==0)
                    *nX1i += 1;
                *nC1 +=1;
                break;
        case 2:
                if (*nX1j==1 || *nX1i%2==1 )
                    *nX1j -= 1;
                *nC1 +=1;
                break;
        case 3:
                if (*nX1i%2==1)
                    *nX1i += 1;
                *nC1 +=1;
                break;
    }

    switch (*nC2%4){
        case 0:
                if (*nX2j==1|| *nX2i%2==0)
                    *nX2j += 1;
                *nC2 +=1;
                break;
        case 1:
                if (*nX2i%2==0)
                    *nX2i += 1;
                *nC2 +=1;
                break;
        case 2:
                if (*nX2j==2|| *nX2i%2==1)
                    *nX2j -= 1;
                *nC2 +=1;
                break;
        case 3:
                if (*nX2i%2==1)
                    *nX2i += 1;
                *nC2 +=1;
                break;
    }
    switch (*nC3%4){
        case 0:
                if (*nX3j==2|| *nX3i%2==0)
                    *nX3j += 1;
                *nC3 +=1;
                break;
        case 1:
                if (*nX3i%2==0)
                    *nX3i += 1;
                *nC3 +=1;
                break;
        case 2:
                if (*nX3j==3|| *nX3i%2==1)
                    *nX3j -= 1;
                *nC3 +=1;
                break;
        case 3:
                if (*nX3i%2==1)
                    *nX3i += 1;
                *nC3 +=1;
                break;
    }
}
/*   <This function updates the ith and jth position of the shooted enemy for respawning purposes.>
     Precondition: <Should be called first by the detectX() function>
     @param <*i, *j> <The ith and jth position of the killed enemy respectively. This function, then calls the randomX() function to get a random jth position.
     Then, set its ith postion to 0, displaying the enemy to the uppermost row and setting its counter to 0 in order to restart its movement pattern.>
     @return <This function returns nothing.>
*/

void updateX(int *nI, int *nJ, int *nCounter, int *nScore)
{
    randomX(&*nJ, &*nCounter, &*nScore);
    *nI = 0;
    *nCounter = 0;
}

/*   <Updating randomized jth position of the shooted enemy and updates the score by adding 10 to it.>
     Precondition: <Should be called first by the updateX() function.>
     @param <*j> <The jth position of the killed enemy. Generates a random jth position of the enemy for respawning.>
     @param <*counter> <If counter is equal to 0, then random jth position should only be either 0 or 1; else jth position ranges from 0 to 2>
     @param <*score> <In this fucntion is where the score is being update by adding 10 from current score by adding 10 points to it..>
     @return <This function returns nothing.>
*/
//Connected to above function. Used to gnerate random x position on the upper row.
void randomX(int *nJ, int *nCounter, int *nScore)
{
    if (*nCounter == 0)
    {
        int nLower, nUpper, nCount;
        nLower = 0, nUpper = 1, nCount = 1;
        srand(time(0));
        for (int i = 0; i < nCount; i++)
        {
            int nNum = (rand() % (nUpper - nLower + 1)) + nLower;
            *nJ = nNum;
        }
    }
    else
    {
        int nLower, nUpper, nCount;
        nLower = 0, nUpper = 2, nCount = 1;
        srand(time(0));
        for (int i = 0; i < nCount; i++)
        {
            int nNum = (rand() % (nUpper - nLower + 1)) + nLower;
            *nJ = nNum;
        }
    }
    *nScore += 10;
}
/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
<Miko Lumintac Santos> - <12256170> - <S19A>
******************************************************************************/
