#include <iostream>

using namespace std;
#define v 6
void inti(int mat[3][6])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            mat[i][j] = 0;
        }
    }
}
void addedge(int mat[3][6], int start, int endvertix)
{
    mat[start][endvertix] = 1;
}
void printmat(int mat[3][6])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int array_in_graph[3][6];
    inti(array_in_graph);
    addedge(array_in_graph, 1, 2);
    addedge(array_in_graph, 2, 1);
    addedge(array_in_graph, 2, 3);
    addedge(array_in_graph, 3, 2);
    addedge(array_in_graph, 1, 3);
    addedge(array_in_graph, 3, 1);

    printmat(array_in_graph);
    return 0;
}