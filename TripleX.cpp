#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\nWelcome To\n";
    std::cout << "==========================***=============================\n";
    std::cout << "     ___      _                 _                       \n";
    std::cout << "    / _ \\    | |               | |                      \n";
    std::cout << "   / /_\\ \\ __| |_   _____ _ __ | |_ _   _ _ __ ___ _ __ \n";
    std::cout << "   |  _  |/ _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\ '__|\n";
    std::cout << "   | | | | (_| |\\ V /  __/ | | | |_| |_| | | |  __/ |   \n";
    std::cout << "   \\_| |_/\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|_|   \n";
    std::cout << "\n==========================***=============================\n";
    std::cout << "\nYou are a treasure hunter trying to solve an level " << Difficulty;
    std::cout << " ancient mystery to open the treasure chest!\nYou need to enter the correct codes to continue...\n";
    std::cout << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeOne = rand() % Difficulty + Difficulty;
    const int CodeTwo = rand() % Difficulty + Difficulty;
    const int CodeThree = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeOne + CodeTwo + CodeThree;
    const int CodeProduct = CodeOne * CodeTwo * CodeThree;

    std::cout << "* There are 3 numbers in the code\n";
    std::cout << "* The codes add-up to : " << CodeSum << std::endl;
    std::cout << "* The codes multiply to give : " << CodeProduct << std::endl;

    int GuessOne, GuessTwo, GuessThree;
    std::cout << "Enter your guesses : ";
    std::cin >> GuessOne >> GuessTwo >> GuessThree;

    int GuessSum = GuessOne + GuessTwo + GuessThree;
    int GuessProduct = GuessOne * GuessTwo * GuessThree;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Congratulations!! You've solved part of the mystery!\n";
        return true;
    }
    else
    {
        std::cout << "You entered the wrong code! Retry again!\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "Congratulations!! You've solved the mystery and you've acquired the treasure!!!";   
    return 0;
}