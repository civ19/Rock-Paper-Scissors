#include <iostream>
#include <ctime>
#include <cctype>
#include <string>
#include <limits>

void rock_start(int bturn, char turn)
{
    void game(int bturn, char turn);
    char prompt;

    while(true)
    {
        std::cout << "Welcome to rock paper scissors! Press X to start: ";
        std::cin >> prompt;

        prompt = std::toupper(prompt);

        if(prompt!= 'X')
        {
            std::cout << "Wrong button." << "\n";
            continue;
        }

        break;
    }

    game(bturn, turn);

}
//improvement: add a rounds sytem where the player can choose how many rounds they wanna play for 
void game(int bturn, char turn)
{
    srand(time(0));
    int rounds;
    int bscore = 0;
    int score = 0;

    std::cout << "\n" << "How many rounds would you like to play for? ";
    std::cin >> rounds;


    std::cout << "\n" << "Press R for rock, P for paper, and S for scissors." << "\n\n";

    for(int i = 0; i<rounds; i++)
    {
        bturn = rand()%3 + 1;

        while(true)
        {
            std::cout << "Your turn: ";
            std::cin >> turn;
            turn = std::toupper(turn);
            if(turn!='R' && turn != 'P' && turn!= 'S')
            {
                std::cout << "Invalid Move." << "\n";
                continue;
            }
            else {
                break;
            }
        }

        if(turn == 'R')
        {
            switch(bturn)
            {
                case 1:
                    std::cout << "AI chose Rock. Tie." << "\n";
                break;

                case 2:
                    std::cout << "AI Chose Paper. You lose." << "\n";
                    bscore++;
                break;

                case 3:
                    std::cout << "AI chose Scissors. You win!" << "\n";
                    score++;
                break;
            }
        }

        if(turn == 'P')
        {
            switch(bturn)
            {
                case 1:
                    std::cout << "AI chose Rock. You win!." << "\n";
                    score++;
                break;

                case 2:
                    std::cout << "AI Chose Paper. Tie." << "\n";
                break;

                case 3:
                    std::cout << "AI chose Scissors. You lose." << "\n";
                    bscore++;
                break;
            }
        }

        if(turn == 'S')
        {
            switch(bturn)
            {
                case 1:
                    std::cout << "AI chose Rock. You lose." << "\n";
                    bscore++;
                break;

                case 2:
                    std::cout << "AI Chose Paper. You win!" << "\n";
                    score++;
                break;

                case 3:
                    std::cout << "AI chose Scissors. Tie." << "\n";
                break;
            }
        }
        
    }

    std::cout << "\n" << "*********************" << "\n";
    std::cout << "The results are in!" << "\n";
    std::cout << "*********************" << "\n\n";

    std::cout << "Player: "<< score <<" points" << "\n";
    std::cout << "AI: "<< bscore <<" points" << "\n\n";

    if(score>bscore)
    {
        std::cout << "You win the game!" << "\n";
    }
    else if(bscore>score)
    {
        std::cout << "AI wins. Better luck next time." << "\n";
    }
    else if(score==bscore)
    {
        std::cout << "It's a tie! Good attempt." << "\n";
    }

    std::cout << "Thank you for playing!" << std::endl;
    std::cout << "Press enter to close the game" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear any leftover input
    std::cin.get(); // wait for Enter

}


//void recursion(){}

int main()
{

    int bturn;
    char turn;

    rock_start(bturn, turn);
    
}
