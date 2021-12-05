/*
Snake-Ladder Game
Group Members
MUHAMMAD SHAHZAIB SHAFIQ-20F-0317-D1
MUHAMMAD EHSAN AKTHAR-20F-0312-D1
*/

/*
Game Details
This is a snake ladder game for 4 players
this game has a stable code and suppose to do its job completely
it includes
functions
arrays
*/
//header files
#include <iostream>
//used to add or change colors 
#include <Windows.h>
//used for genrating  a random no with changing time
#include <ctime>
//used to clear screen
#include<stdlib.h>
//used for string opreations
#include<string>
using namespace std;
//function for player names
void players();
//function to draw/create board
void draw();
//function for writing on bord
void Board(int x, int y);
//function for rooling dice
void Dice(string name);
//function for generating a random number
int randomNo(int number);
//function o caluculate scores
int Scores(int a, int b);
void bonus(int f);
//function for bonus given by winner
int snake_ladder(int t);
//global variable to save player names 
string player1, player2, player3, player4;
//global varibles to save players scores
int score, score1 = 0, score2 = 0, score3 = 0, score4 = 0;
//arrays for processing score
int p1[120], p2[120], p3[120], p4[120], n;
//storing player data
int ply1 = 0, ply2 = 0, ply3 = 0, ply4 = 0, Count = 0;
//main function
int main()
{
    //display rules
    system("color 2F");



    cout << "\nRead The Rules First\nAfter Reading The Rules Game Will Start Automatically after some time\n ";


    //game rules
    cout << "\n1-The players will move their pieces from left to right\n"
        << "\n\n2-When a player lands on a top of a snake,they will slide down to the bottom of the snake.\n"
        << "\n\n3-landing on the bottom of a snake the player will remain in the same spot until their next turn\n"
        << "\n\n4-When a player lands at the base of a ladder, it immediately climbs to the top of the ladder.\n"
        << "\n\n5-landing at the top of a ladder the player will stay there until the next turn\n"
        << "\n\n6-The first player that reaches the highest space on the board, 100, wins the game.\n";

    //pause of 5 sec for reading rules

    Sleep(5000);
    system("color 7");
    //clear screen for game
    system("CLS");
    //calling draw function 
    draw();
    //callig board function
    Board(4, 5);
    /*
    its a built-in c++ function
    it will point on a location
    it will draw on screen by using x-y cordinates
    */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cin.get();
    //do while loop to perform all opreations repeatley
    do
    {
        //condition to check scores for winner
        if (score1 < 100)
        {
            //asign score of player 1 to variable score 
            score = score1;
            //passing name of player  1 to dice function to roll dice
            Dice(player1);
            //give value of score to player 1
            score1 = score;
            //call score function for player 2 to calculate its score
            score2 = Scores(score1, score2);
            //call score function for player 3 to calculate its score
            score3 = Scores(score1, score3);
            //call score function for player 4 to calculate its score
            score4 = Scores(score1, score4);
            //call snake and ladder function to check if player has arrived on a skake or ladder
            score1 = snake_ladder(score1);
            score1 = snake_ladder(score1);
            bonus(score1);
        }
        //all same conditions will be checked for Player 2 now
        if (score2 < 100)
        {
            score = score2;
            Dice(player2);
            score2 = score;
            score1 = Scores(score2, score1);
            score3 = Scores(score2, score3);
            score4 = Scores(score2, score4);
            score2 = snake_ladder(score2);
            score2 = snake_ladder(score2);
            bonus(score2);
        }
        //all same conditions will be checked for Player 3 now
        if (score3 < 100)
        {
            score = score3;
            Dice(player3);
            score3 = score;
            score3 = Scores(score3, score2);
            score3 = Scores(score3, score1);
            score4 = Scores(score3, score4);
            score3 = snake_ladder(score3);
            score3 = snake_ladder(score3);
            bonus(score3);
        }
        //all same conditions will be checked for Player 4 now
        if (score4 < 100)
        {
            score = score4;
            Dice(player4);
            score4 = score;
            score2 = Scores(score4, score2);
            score3 = Scores(score4, score3);
            score1 = Scores(score4, score1);
            score4 = snake_ladder(score4);
            score4 = snake_ladder(score4);
            bonus(score4);
        }//while loop execues until it is  true
    } while (true);

}
//function to draw/create board
void draw()
{
    //declare board size
    int num = 100;
    //declare other variables
    int x = 1, y = 1, count = 1, c = 50, xx = 1, yy = 1;
    players();
    for (int i = 1; i <= 10; i++)
    {
        (c == 50) ? (c = 70) : (c = 50);

        x = 1, y = 3 * i;
        for (int j = 1; j <= 10; j++)
        {
            (c == 50) ? (c = 70) : (c = 50);
            //set pattern on console
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
            //pusing value of x-y cordinates
            Board(x, y);
            //spaces on board
            cout << "     ";
            //incresing y axis side
            Board(x, ++y);
            cout << "  " << num << "  ";
            num--;
            Board(x, ++y);
            cout << "     ";
            x += 5, y = 3 * i;
        }
    }




}


//player function to maintain player scores and data 
void players()
{
    //geeting player names
    cout << "Enter your names \n";
    cout << "Player-1\n";
    cin >> player1;
    //label is used to return here after executing next few lines if name repeats
label:
    cout << "Player-2\n ";
    cin >> player2;
    if (player1 == player2)
    {//display that name is already taken
        cout << "Name is used Before\n";
        //goto command used to move to specific line
        goto label;
    }
    //same label for condition name repetation 
label1:
    cout << "Player-3\n ";
    cin >> player3;
    if (player3 == player2 || player2 == player1)
    {
        cout << "Name is used Before\n";
        goto label1;
    }
label2:
    cout << "Player-4\n ";
    cin >> player4;
    if (player4 == player1 || player4 == player2 || player4 == player3)
    {
        cout << "\n";
        goto label2;
    }

}
int randomNo(int number)
{
    int Num;
    srand(time(0));
    Num = rand() % number + 1;
    return Num;
}
int Scores(int a, int b)
{
    if (a == b)
        b = 0;
    return b;
}
void bonus(int f)
{
    string name;
    if (f >= 100)
    {
        system("color 1F");
        //display this for a winner
        cout << "\n\nCONGRATULATIONS\n";
        cout << "\nYou Won The Snake Ladder Game\n";
        cout << "\nNow you can reward 6 points to any other player\n";
        cout << "\nType the name of the Player you want to give 6 points\n ";
        Sleep(2000);
        system("color 7");
        cin >> name;
        if (name == player1)
            score1 = score1 + 6;
        else if (name == player2)
            score2 = score2 + 6;
        else if (name == player3)
            score3 = score3 + 6;
        else if (name == player4)
            score4 = score4 + 6;
    }

}
int snake_ladder(int t)
{
    switch (t)
    {
        //cases for ladder
    case 12:
        t = 30;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");
        break;
    case 18:
        t = 42;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");

        break;
    case 46:
        t = 56;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");
        break;
    case 51:
        t = 72;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");
        break;
    case 81:
        t = 92;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");
        break;
    case 86:
        t = 98;
        system("color 2F");
        cout << "\nCONGRATULATONS You Got Ladder \n";
        Sleep(2000);
        system("color 7");
        break;



        //cases for snakes

    case 14:
        t = 5;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    case 29:
        t = 17;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    case 32:
        t = 24;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    case 54:
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        t = 23;
        break;
    case 65:
        t = 34;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    case 91:
        t = 37;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    case 69:
        t = 4;
        system("color 4F");
        cout << "\nYou are Bitenup by Snake\n";
        Sleep(2000);
        system("color 7");
        break;
    }
    return t;
}

void Dice(string name)
{

label10:
    cout << name << " \n Your Turn TURN\n" << endl;
    system("pause");
    n = randomNo(6);
    cout << "\nYou got " << n << endl;
    if (n == 6)
    {
        Count++;
        score = score + n;
        cout << "\nCONGRATULATIONS!ROLL DICE AGAIN! \n";
        goto label10;
    }
    if (Count > 0 && score != 0)
        score = score + n;
    cout << name << "\n You are at POISTION = " << score << endl;
    if (name == player1)
    {
        p1[ply1] = n;
        ply1++;
    }
    else if (name == player2)
    {
        p2[ply2] = n;
        ply2++;
    }
    else if (name == player3)
    {
        p3[ply3] = n;
        ply3++;
    }
    else if (name == player4)
    {
        p4[ply4] = n;
        ply4++;
    }

}
//code for drawing board
void Board(int x, int y)
{
    COORD coord = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
