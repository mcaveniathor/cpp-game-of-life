#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "pbm.cpp"
using namespace std;
vector<vector<int>> tmp;
int gens, rows, cols;
bool alive(int row, int col)
{
    int total=0;
    if(tmp[row][col-1])
        total++;
    if(tmp[row][col+1])
        total++;
    if(tmp[row-1][col-1])
        total++;
    if(tmp[row-1][col])
        total++;
    if(tmp[row-1][col+1])
        total++;
    if(tmp[row+1][col])
        total++;
    if(tmp[row+1][col-1])
        total++;
    if(tmp[row+1][col+1])
        total++;
    return(total>1 && total<4);
}

void run(PBM &im, vector<vector<int>> &m, int gen)
{
    if(gen>gens)
    {
        return;
    }
    if(gen!=1)
    {
        for(int row=1; row<rows-1; row++)
        {
            for(int col=1; col<rows-1; col++)
            {
                tmp[row][col]=(int)alive(row, col);
            }
        }
    }
    else
    {
        for(int row=1; row<rows-1; row++)
        {
            for(int col=1; col<rows-1; col++)
            {
                tmp[row][col]=rand()%2;
            }
        }
    }

    im.setFile(to_string(gen)+".pbm");
    im.write(tmp);
    gen++;
    m=tmp;
    cout << endl;
    run(im, tmp, gen);
}
int main(int argc, char** argv)
{
    srand(time(nullptr));
    if(!(argc==4 && argv[1] && argv[2] && argv[3]))
    {
        cerr << "Usage: ./gol rows columns generations" << endl;
        exit(1);
    }
    else
    {
        rows=stoi(argv[1])+2;
        cols=stoi(argv[2])+2;
        gens=stoi(argv[3]);
    }
    PBM image=PBM("output.pbm", rows, cols, 1);
    tmp.resize(rows);
    for(int i=0; i<rows; i++)
    {
        tmp[i].resize(cols);
    }
    run(image, tmp, 1);
    return 0;
}


