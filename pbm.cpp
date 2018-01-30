#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class PBM
{
        int width, height, maxval;
        string file;
        ofstream stream;
        vector<vector<int>> matrix;
    public:
        PBM(string filename, int rows, int cols, int max)
        {
            file=filename;
            width=cols;
            height=rows;
            maxval=max;
            matrix.resize(rows);
            for(int i=0; i<rows; i++)
            {
                matrix[i].resize(cols);
            }
        }


        void write(vector<vector<int>> &m)
        {
            cout << file << endl;
            stream.open(file);
            stream << "P1" << endl << m[1].size()-2 << " " << m.size()-2 << " " << maxval << endl;
            width=m[1].size();
            height=m.size();
            for(int r=1; r<height-1; r++)
            {
                for(int c=1; c<width-1; c++)
                {
                    cout << m[r][c] << " ";
                    stream << to_string((m[r][c]));
                    if(c!=width-2)
                    {
                        stream << " ";
                    }
                }
                cout << endl;
                stream << endl;
            }
            stream.close();
        }

        vector<vector<int>>& getMatrix()
        {
            return matrix;
        }

       int getRows() { return height; }
       int getCols() { return width; }
       void setFile(string f) { file=f; }
};


        
