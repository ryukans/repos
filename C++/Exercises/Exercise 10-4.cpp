#include <iostream>
#include <vector>
#include <ctime>

#define INVALID_TYPE -1
#define ROCK 0
#define PAPER 1
#define SCISSORS 2

using namespace std;

int computer, player;
int player_score, comuter_score;

void player_play(void);
void computer_play(void);

int main()
{
    cout << "Choose 1.Rock - 2.Paper - 3.Scissors\nType the number or write the entire word\n\n";
    string type;

    while (cin >> type) {
        player_play();
        if (player == INVALID_TYPE) continue;
        computer_play();
        set_score();
        cout << "Player: " << player << " Com: " << computer << endl;
    }

    return 0;
}

void player_play()
{
    string choice;

    cin >> choice;

    if (choice == "rock" || choice == "r" || choice == "1")
        player = ROCK;
    else if (choice == "paper" || choice == "p" || choice == "2")
        player = PAPER;
    else if (choice == "scissors" || choice == "s" || choice == "3")
        player = SCISSORS;
    else
        player = INVALID_TYPE;
}


void computer_play()
{
    int static i = 1;
    i = 2*(i+1);

    int seed = (time(0)+i)*0x7FFFFFFF;
    ++i;

    computer = seed*128 % 3;
}


void set_score()
{
    // all cases the player would lose
    if (player == ROCK && computer == PAPER)    // paper beats rock
        ++computer_score;
    else if (player == PAPER && computer == SCISSORS)   // scissors beat paper
        ++computer_score;
    else if (player == SCISSORS && computer == ROCK)    // rock beats scissors
        ++computer_score;
    else // all other cases the player would win
        ++player_score;


}


