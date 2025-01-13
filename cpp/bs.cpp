////////////////////////////////////////////////////////////////////////////////
// LIBRARIES ///////////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACES //////////////////////////////////////////////////////////////////
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS ///////////////////////////////////////////////////////////////////

bool is_help(string arg1)
{
    return ((arg1 == "-h" || arg1 == "--help") ? true : false);
}

////////////////////////////////////////////////////////////
void convert_list(int &argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        string arg = argv[i];
        int d;
        cout << arg << "\t==>\t";

        if (arg.starts_with("0x"))
        {
            d = stoi(arg.substr(2), nullptr, 16);
        }
        else if (arg.starts_with("0b"))
        {
            d = stoi(arg.substr(2), nullptr, 2);
        }
        else
        {
            d = stoi(arg);
        }

        cout << format("{:#x}", d) << "\t"
             << d << "\t"
             << format("{:#b}", d) << endl;
    }
}

////////////////////////////////////////////////////////////

void print_help(char *argv0)
{
    int argc = 4;
    char **arr = new char *[argc];
    arr[0] = strdup("./bs");
    arr[1] = strdup("0xf"); // examples
    arr[2] = strdup("0b1010");
    arr[3] = strdup("11");

    cout
        << "USAGE:\t\t" << "bs <number1> <number2> ..." << endl
        << endl
        << "Prepend hexadecimal values with \"0x\" and binary values with \"0b\""
        << endl
        << "EXAMPLES:" << endl
        << "================:" << endl;
    convert_list(argc, arr);
}

////////////////////////////////////////////////////////////////////////////////
// MAIN ////////////////////////////////////////////////////////////////////////

// int argc :: number of CL arguments including the call to program, e.g.
// 0='./bs', 1='arg1', ... char* argv[] :: pointer to array of character pointers
int main(int argc, char *argv[])
{
    /* Debug input
    cout << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << "\t";
    }
    cout << endl;
    //*/

    if (argc <= 1 || is_help(argv[1]))
    {
        print_help(argv[0]);
    }
    else
    {
        convert_list(argc, argv);
    }

    return 0;
}