#include <iostream>
#include <ctime>

void clearScreen() {
#ifdef _WIN32
    system("CLS"); // For Windows
#else
    system("clear"); // For Unix/Linux/Mac
#endif
}

std::string centerLine(const std::string& line, int terminalWidth) {
    int padding = (terminalWidth - static_cast<int>(line.size())) / 2;
    return std::string(std::max(0, padding), ' ') + line;
}

// Function to draw the game board with numbers
void drawingBoard_with_number(char* spaces) {
    const int terminalWidth = 80; // Adjust the width based on your terminal

    // Draw the board
    std::cout << std::endl << centerLine("  1  |  2  |  3  ", terminalWidth) << std::endl;
    std::cout << centerLine("_____|_____|_____", terminalWidth) << std::endl;
    std::cout << centerLine("  4  |  5  |  6  ", terminalWidth) << std::endl;
    std::cout << centerLine("_____|_____|_____", terminalWidth) << std::endl;
    std::cout << centerLine("  7  |  8  |  9  ", terminalWidth) << std::endl;
    std::cout << std::endl;
}


void drawBoard(char* spaces) {
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
}

void playerMove(char* spaces, char player)
{
    int number;
    do {
        std::cout << "player 1 " << "Enter a spot to place a marker (1 - 9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
}

void playerMove2(char* spaces, char player2)
{
    int number;
    do {
        std::cout << "Player 2 " << "Enter a spot to place a marker (1 - 9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player2;
            break;
        }
    } while (!number > 0 || !number < 8);
}

void computerMove(char* spaces, char computer)
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkwinner(char* spaces, char player, char computer)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";

    }
    else {
        return false;
    }
    return true;
}

bool checktie(char* spaces)
{
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "IT,S A TIE!\n";
    return true;
}


char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}



int main() {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; // Initialize with spaces
    char player = ' ';
    char player2 = ' ';
    char option = ' ';
    char computer = ' ';
    bool running = true;
    char playagain;
    const int terminalWidth = 80;

    do {
        // Reset game state
        for (int i = 0; i < 9; i++) spaces[i] = ' '; // Clear the board
        running = true;

        drawingBoard_with_number(spaces);
        std::cout << centerLine("The number represents the spot you can choose.", terminalWidth) << std::endl << std::endl;

        std::cout << "does player want to play with player or computer: P or C: ";
        std::cin >> option;
        option = toLower(option);
        std::cout << "Pick What You Want To Be: X or O: ";
        std::cin >> player;
        player = toLower(player);

        if (player == 'x') {
            computer = 'o';
            player2 = 'o';
        }
        else if (player == 'o') {
            computer = 'x';
            player2 = 'x';
        }
        if (option == 'c') {
            drawBoard(spaces);
            while (running) {
                playerMove(spaces, player);
                clearScreen();
                drawingBoard_with_number(spaces);
                drawBoard(spaces);
                if (checkwinner(spaces, player, computer)) {
                    running = false;
                    break;
                }

                else if (checktie(spaces)) {
                    running = false;
                    break;
                }
                computerMove(spaces, computer);
                clearScreen();
                drawingBoard_with_number(spaces);
                drawBoard(spaces);
                if (checkwinner(spaces, player, computer)) {
                    running = false;
                    break;
                }
                else if (checktie(spaces)) {
                    running = false;
                    break;
                }
            }
        }

        else if (option == 'p') {
            drawBoard(spaces);
            while (running) {
                playerMove(spaces, player);
                clearScreen();
                drawingBoard_with_number(spaces);
                drawBoard(spaces);
                if (checkwinner(spaces, player, player2)) {
                    running = false;
                    break;
                }

                else if (checktie(spaces)) {
                    running = false;
                    break;
                }
                playerMove2(spaces, player2);
                clearScreen();
                drawingBoard_with_number(spaces);
                drawBoard(spaces);
                if (checkwinner(spaces, player, player2)) {
                    running = false;
                    break;
                }
                else if (checktie(spaces)) {
                    running = false;
                    break;
                }
            }
        }
        std::cout << std::endl << "Do you want to play again? (Yes = Y or NO = N): ";
        std::cin >> playagain;
        playagain = std::tolower(playagain);

    } while (playagain == 'y');

    std::cout << "THANKS FOR PLAYING!\n";
    return 0;
}