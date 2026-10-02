#include <iostream>
#include <vector>
using namespace std;

int checkHighLow(int randomNumber, int userNumber)
{
    if (userNumber > randomNumber)
        return 1; // high

    return 0; // low
}

int main()
{
    // Getting a random number between 0 and 100
    srand(time(0));
    int randomNumber = rand() % 101;

    vector<int> numberLine(101);
    for (int i = 0; i < 101; i++)
        numberLine[i] = i;

    vector<bool> numberLineLeft(101, false);

    int chances = 5;
    while (chances > 0)
    {
        for (int i = 0; i < 101; i++)
        {
            if (i != 1 && (i - 1) % 25 == 0)
                cout << endl;
            if (!numberLineLeft[i])
                cout << numberLine[i] << " ";
            else
                cout << "* ";
        }
        cout << endl;

        cout << "(Chances left: " << chances << ") ";

        int userNumber;
        cout << "Guess Your Number: ";
        cin >> userNumber;

        if (userNumber == randomNumber)
        {
            cout << "----------" << endl;
            cout << "You Won" << endl;
            cout << "----------" << endl;
            return 0;
        }

        if (checkHighLow(randomNumber, userNumber))
        {
            for (int i = userNumber; i <= 100; i++)
                numberLineLeft[i] = true;
        }
        else
        {
            for (int i = 0; i <= userNumber; i++)
                numberLineLeft[i] = true;
        }

        cout << (checkHighLow(randomNumber, userNumber) ? "High" : "Low") << endl;

        chances--;
    }
    cout << "----------" << endl;
    cout << "You Lose" << endl;
    cout << "----------" << endl;
    cout << "Number was: " << randomNumber << endl;

    return 0;
}