# include "FMConsole.h"
# include <iostream>
# include <fstream>

using namespace std;

int main()
{
    ofstream outfile("test_FMConsole.log");
    cout.rdbuf( outfile.rdbuf() );
    cerr.rdbuf( outfile.rdbuf() );

    FMConsole *agent = new FMConsole();
    delete agent;

    outfile.flush();
    outfile.close();

    return 0;
}
