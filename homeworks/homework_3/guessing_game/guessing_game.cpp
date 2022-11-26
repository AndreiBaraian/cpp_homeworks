#include <iostream>
#include <random>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const std::string welcome_message = "Welcome to the GUESSING GAME!\nI will generate a number and you will guess it!";

    cout << welcome_message << endl;
    cout << "Please provide the smallest number: " << endl;
    int smallest_number{0};
    cin >> smallest_number;
    cout << "Please provide the largest number: " << endl;
    int largest_number{0};
    cin >> largest_number;

    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_int_distribution<> distribution{smallest_number, largest_number};

    const int random_number = distribution(random_engine);

    cout << "I've generated a number. Try to guess it!" << endl;

    bool has_guessed = false;
    int n_guesses{0};

    while (!has_guessed)
    {
        n_guesses++;
        cout << "Please provide the next guess: ";
        int next_guess{0};
        cin >> next_guess;
        if (next_guess == random_number)
        {
            has_guessed = true;
        }
        else if (next_guess > random_number)
        {
            cout << "Your number is too big. Try again!" << endl;
        }
        else
        {
            cout << "Your number is too small. Try again!" << endl;
        }
    }

    cout << "You've done it! You guessed the number " << random_number << " in " << n_guesses << " guesses!" << endl;

    return 0;
}