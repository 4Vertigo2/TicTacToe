#include <iostream>
#include <vector>

bool checkWin(const std::vector<std::vector<std::string>> &);
void addMark(std::vector<std::vector<std::string>> &, int, int, bool);
void printMatrix(const std::vector<std::vector<std::string>> &);
bool checkVector(std::vector<std::string>);

int main()
{
    std::string playerOneChoice, playerTwoChoice;
    std::cout << "Player One choose x or o" << std::endl;
    std::cin >> playerOneChoice;

    if (playerOneChoice == "x")
    {
        playerTwoChoice = "o";
    }
    else
    {
        playerTwoChoice = "x";
    }

    std::vector<std::vector<std::string>> matrix(3, std::vector<std::string>(3, "0"));

    int counter = 0;
    bool turn;

    do
    {
        int x, y;
        turn = counter % 2 == 0;
        printMatrix(matrix);
        if (turn)
        {
            std::cout << "Player One enter x and y:" << std::endl;
        }
        else
        {
            std::cout << "Player Two enter x and y:" << std::endl;
        }

        std::cin >> x >> y;
        addMark(matrix, x, y, turn);
        counter++;

    } while (checkWin(matrix));

    printMatrix(matrix);

    if (turn)
    {
        std::cout << "Player One wins" << std::endl;
    }
    else
    {
        std::cout << "Player Two wins" << std::endl;
    }

    return 0;
}

void printMatrix(const std::vector<std::vector<std::string>> &matrix)
{
    for (auto row : matrix)
    {
        for (auto columns : row)
        {
            std::cout << columns << " ";
        }
        std::cout << std::endl;
    }
}

void addMark(std::vector<std::vector<std::string>> &matrix, int x, int y, bool turn)
{
    if (turn)
    {
        matrix[x - 1][y - 1] = "x";
    }
    else
    {
        matrix[x - 1][y - 1] = "o";
    }
}

bool checkVector(std::vector<std::string> matrix)
{
    std::string firstElement = matrix[0];

    for (std::string element : matrix)
    {
        if (firstElement != element || element == "0")
        {
            return false;
        }
    }
    return true;
}

bool checkWin(const std::vector<std::vector<std::string>> &matrix)
{
    bool win = true;
    std::vector<std::string> check;
    check.reserve(3);

    //horizontal check
    for (std::vector<std::string> rows : matrix)
    {
        if (checkVector(rows))
        {
            win = false;
        }
    }
    //vertical check
    for (int i = 0; i < 3; i++)
    {
        check.clear();
        for (int j = 0; j < 3; j++)
        {
            check.push_back(matrix[j][i]);
        }
        if (checkVector(check))
        {
            win = false;
        }
    }
    
    check.clear();
    //diagonal check
    for (int i = 0; i < 3; i++)
    {

        check.push_back(matrix[i][i]);
    }

    if (checkVector(check))
    {
        win = false;
    }

    check.clear();

    //reverse diagonal
    for (int i = 2; i >= 0; i--)
    {

        check.push_back(matrix[i][i]);
    }

    if (checkVector(check))
    {
        win = false;
    }

    return win;
}
