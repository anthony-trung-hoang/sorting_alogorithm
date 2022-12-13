#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int size = 10;
    int numbers;
    ofstream output;
    string size_string_file = to_string(size);
    string filename = "random" + size_string_file + ".txt";
    cout << filename;
    output.open(filename);
    output << size << endl;
    for (int i = 0; i < size; i++)
    {
        numbers = rand() % 1001;
        output << numbers << endl;
    }
    cout << "Data appended" << endl;
    return 0;
}