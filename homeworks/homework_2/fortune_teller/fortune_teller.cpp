#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::string_literals::operator""s;

int main()
{
    // No mechanism for erronous user input has been implemented.
    cout << "Welcome to the fortune teller program!"s << endl;
    cout << "Please enter your name: "s << endl;
    std::string name{};
    cin >> name;

    cout << "Please enter the time of year when you were born:"s << endl
         << "(pick from 'spring', 'summer', 'autumn', 'winter')" << endl;
    std::string time_of_year{};
    cin >> time_of_year;

    cout << "Please enter an adjective:"s << endl;
    std::string adjective_1{};
    cin >> adjective_1;

    cout << "Please enter another adjective:"s << endl;
    std::string adjective_2{};
    cin >> adjective_2;

    cout << endl;

    std::vector<std::string> adjectives{adjective_1, adjective_2};

    const int adjectives_size = adjectives.size();
    const int name_length = name.size();
    const int adjective_index = name_length % adjectives_size;
    std::string chosen_adjective = adjectives.at(adjective_index);

    const std::map<std::string, std::string> noun_map{{"spring"s, "STL guru"s}, {"summer"s, "C++ expert"s}, {"autumn"s, "coding beast"s}, {"winter"s, "software design hero"s}};

    const std::string noun = noun_map.at(time_of_year);

    const std::array ending_array_options{"eats UB for breakfast"s, "finds errors quicker than the compiler"s, "is not afraid of C++ error messages"s};

    const int ending_index = name.length() % ending_array_options.size();
    const std::string ending = ending_array_options.at(ending_index);

    cout << "Here is your description:"s << endl;

    const std::string description = name + ", the "s + chosen_adjective + " "s + noun + " that "s + ending;
    cout << description << endl;

    return 0;
}