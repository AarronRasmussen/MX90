#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <numeric>

void makeGrid(const int size) {
    std::vector<std::vector<int>> vec(size, std::vector<int>(size));

    //test fill each subvector
    std::for_each(vec.begin(), vec.end(), [](std::vector<int> &subVec) {
        std::iota(subVec.begin(), subVec.end(), 1);
    });

    //print out each vector's data
    std::for_each(vec.begin(), vec.end(), [](std::vector<int> &subVec) {
        std::copy(subVec.begin(), subVec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    });
}

std::vector<int> selectColumn(const std::vector<std::vector<int>>& grid, int row, int column, size_t size) {
    std::vector<int> bits;

    for(size_t i = 0; i < size; i++) {
        bits.push_back(grid[row + i][column]);
    }

    return bits;
}

int binaryToDecimal(std::vector<int>& bits) {
    size_t power = bits.size() - 1;
    int value = 0;

    std::reverse(bits.begin(), bits.end());

    std::for_each(bits.begin(), bits.end(), [&](int n){
       if(n == 1) {
           value += pow(2, power);
       }

       power -= 1;

    });

    return value;
}


int main() {
    //Eventually this will auto make the grids needed for the challenge
    makeGrid(8);

    //Hand made the first grid to test other functions.. and "IT'S WORKING!"
    std::vector<std::vector<int>> gridVector = {{1,0,0,0,0,0,0,0}, {1,0,1,1,1,1,1,1}, {1,1,0,0,0,0,0,1},
                                                {0,1,0,1,1,1,0,1}, {0,1,1,0,0,1,1,1}, {0,0,1,0,0,0,0,1}, {1,0,1,0,1,1,0,1},
                                                {1,1,1,1,0,1,1,1}};

    std::vector<int> bitVector = selectColumn(gridVector, 2, 1, 5);

    std::cout << "Integer value of the selected bits: " << binaryToDecimal(bitVector) << std::endl;
}