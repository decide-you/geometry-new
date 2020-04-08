#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int number_of_strings()
{
    ifstream start("import figures.txt", ios::in | ios::binary);
    if (!start) {
    	cout << "File with shapes not found, maybe you renamed it"<<endl;
        return 0;
    }

    int count = 0;
    while (start.ignore(numeric_limits<streamsize>::max(), '\n')) {
        if (!start.eof())
            count++;
    }

    start.close();
    return count;
}

int main()
{
    const int len = 50, strings = number_of_strings();
    const char ch = '\n';
    char mass[len][strings];

    ifstream work("import figures.txt", ios::in | ios::binary);

    for (int r = 0; r < strings; r++) {
        work.getline(mass[r], len - 1, ch);
        cout << "String " << r + 1 << " = " << mass[r] << endl;
    }

    work.close();
    return 0;
}
