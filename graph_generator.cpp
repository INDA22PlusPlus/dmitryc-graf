#include <iostream>
#include<cstdlib>
#include <fstream>

using namespace std;

int main() {
//    ofstream MyFile("large_graph_random.txt");

    int n = 20000, m = 30000;
    int range = 20000;

//    MyFile << n << " " << m << endl;
    cout << n << " " << m << endl;
    for (int edge = 0; edge < m; edge++) {
        int from = rand() % n;
        int to = rand() % n;
        int weight = -range + (rand() % range * 2);
//        MyFile << from << " " << to << " " << weight << endl;
        cout << from << " " << to << " " << weight << endl;
    }

//    MyFile << "0 0" << endl;
    cout << "0 0 0" << endl;

//    MyFile.close();

    return 0;
}