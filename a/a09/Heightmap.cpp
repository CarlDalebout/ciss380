#include <string>
#include <cmath>
#include "Heightmap.h"



void       Heightmap::Diamond_Square()
{   
    int N = pow(n_, 2) + 1;
    float M = 0.25 * N; 
    float roughness = 1.5;

    heightmap_[0][0]        = 1;//((float)rand() / RAND_MAX * M*2) - M;
    heightmap_[0][N-1]      = 1;//((float)rand() / RAND_MAX * M*2) - M;
    heightmap_[N-1][0]      = 1;//((float)rand() / RAND_MAX * M*2) - M;
    heightmap_[N-1][N-1]    = 1;//((float)rand() / RAND_MAX * M*2) - M;

    for(int w = pow(2, n_); w > 0; w /= 4)
    {
        int S = pow(2, n_) / w;
        float average = 0;
        int row = 0;
        int col = 0;

        // Diamond Step
        for(int j = 0; j < S; ++j)
        {
            average = 0;
            if(j == S/2)
            {
                row += w;
                col  = 0;
            }
            average += heightmap_[row][col];
            average += heightmap_[row][col+w];
            average += heightmap_[row+w][col+w];
            average += heightmap_[row+w][col];
            heightmap_[w/2][w/2] = average /2 + 1;//((float)rand() / RAND_MAX * M*2) - M;
            col += w;
        } 

        average = 0;
        // Square Step
        for(int j = 0; j < S; ++j)
        {
            
        }

        M = M * pow(2,-roughness);
    }
}   

Heightmap  Heightmap::resize(int n)
{
    Heightmap temp(n);
    if(n > n_)
    {
        for(long unsigned int i = 0; i < heightmap_.size(); ++i)
            for(long unsigned int j = 0; j < heightmap_[i].size(); ++j)
                temp.heightmap_[i][j] = heightmap_[i][j];
        heightmap_ = temp.heightmap_;
    }
    else
    {
        for(long unsigned int i = 0; i < temp.heightmap_.size(); ++i)
            for(long unsigned int j = 0; j < temp.heightmap_[i].size(); ++j)
                temp.heightmap_[i][j] = heightmap_[i][j];
        heightmap_ = temp.heightmap_;
    }
    return temp;
}

std::ostream & operator<<(std::ostream& cout, const Heightmap& heightmap)
{
    for(long unsigned int i = 0; i < heightmap.heightmap().size(); ++i)
    {
        std::string dir = "";
        cout << "|";
        for(long unsigned int j = 0; j < heightmap.heightmap()[i].size(); ++j)
        {
            cout << dir << heightmap.heightmap()[i][j];
        }
        cout << "|\n";
    }
    return cout;
}