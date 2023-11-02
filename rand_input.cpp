#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

int n_range = 500000;
int m_range = 500000;

int main() {
    srand(static_cast<unsigned>(std::time(nullptr)));
    vector<std::pair<int, char> > operations;

    // 生成 n 个大写字母 'A' ~ 'Z' 组成的字符串
    int n = rand() % ( n_range + 1);
    // int n = 500000;
    string initialBeads;
    for (int i = 0; i < n; i++) {
        char bead = 'A' + rand() % 26;
        if( i >= 2 )
        {
            while( bead == initialBeads[ i - 1 ] && bead == initialBeads[ i - 2 ])
                bead = 'A' + rand() % 26;    
        }
        initialBeads += bead;
    }

    ofstream outputFile("test.in");
    int position = rand() % ( n+ 1 );
    char bead = 'A' + rand() % 26;
    operations.push_back( make_pair( position, bead ) );
    outputFile << initialBeads << endl;
    outputFile << 1 << endl;
    outputFile << position << " "  << bead << endl;
    outputFile.close();

    // 生成 m 次操作
    system("g++ data_check.cpp -o check");
    int m = rand() % ( m_range + 1);
    // int m = 500000;
    for( int i = 0; i < m - 1; i++ )
    {

        system("./check < test.in > test.out");
        ifstream inputFile("test.out");
        string new_initialBeads;
        getline(inputFile, new_initialBeads);
        if( new_initialBeads[ 0 ] > 'Z' || new_initialBeads[ 0 ] < 'A')
            abort();
        inputFile.close();
        ofstream outputFile("test.in");
        int position = rand() % ( n+ 1 );
        char bead = 'A' + rand() % 26;
        operations.push_back( make_pair( position, bead ) );
        outputFile << new_initialBeads << endl;
        outputFile << 1 << endl;
        outputFile << position << " "  << bead << endl;
        outputFile.close();
    }

    // 输出 m 次操作
    cout << initialBeads << endl;
    cout << m << endl;
    for (int i = 0; i < m; i++ ) {
        cout << operations[ i ].first << " " << operations[ i ].second << std::endl;
    }

    return 0;
}
