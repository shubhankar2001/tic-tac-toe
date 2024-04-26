#include <iostream>
#include <ctime>

char GetUserChoice();
char GetComputerChoice();
void ShowChoice(char choice);
void ChooseWinner(char player, char computer);

int main()
{
    char player;
    char computer;

    player = GetUserChoice();
    std::cout << "Your choice: ";
    ShowChoice(player);

    computer = GetComputerChoice();
    std::cout << "Computers choice: ";
    ShowChoice(computer);

    ChooseWinner(player, computer);

    return 0;
}

char GetUserChoice()
{
    char player;

    do
    {
        std::cout << "Choose one of the following";
        std::cout << "Welcome to a Rock, Paper, Scissors Game \n";
        std::cout << "***********************************\n";
        std::cout << "Enter r for rock:\n ";
        std::cout << "Enter p for paper:\n ";
        std::cout << "Enter s for scissors:\n ";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}
char GetComputerChoice()
{
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    }

    return 0;
}
void ShowChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << " Rock ";
        break;
    case 'p':
        std::cout << " Paper ";
        break;
    case 's':
        std::cout << " Scissors ";
        break;
    }
}
void ChooseWinner(char player, char computer)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            std::cout << "Its a Tie\n";
        }
        else if (computer == 'p')
        {
            std::cout << "You loose\n";
        }
        else
        {
            std::cout << "You win\n";
        }
        break;

    case 'p':
        if (computer == 'p')
        {
            std::cout << "Its a Tie\n";
        }
        else if (computer == 's')
        {
            std::cout << "You loose\n";
        }
        else
        {
            std::cout << "You win\n";
        }
        break;
    case 's':
        if (computer == 's')
        {
            std::cout << "Its a Tie\n";
        }
        else if (computer == 'p')
        {
            std::cout << "You loose\n";
        }
        else
        {
            std::cout << "You win\n";
        }
        break;
    }
}