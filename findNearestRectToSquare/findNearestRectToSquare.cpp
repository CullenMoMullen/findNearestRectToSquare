// findNearestRectToSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Find the grid that is nearest to a square, with an area that will fit cells of area n (input)
//Additionally the area of the grid should be no larger than 2 more than the number of cells.


/*  Ex: n = 2
    Possible Solution 1:
    width = 2, height = 1
    ____ ____
   |    |    |
   |____|____|
   
    Possible Solution 2: (correct solution since it is closest to a square)
    width = 2, height = 2
    ____ ____
   |    |    |
   |____|____|
   |    |    |
   |____|____|

*/


#include <iostream>
using namespace std;

std::pair<int, int> findNearestSquare(int n) {
    //handle case where N = 1
    if (n == 1) {
        return make_pair(1, 1);
    }

    //Find all x,y pairs whose product is between [N,N+2]
    pair<int, int> closestPair = make_pair<int, int>(n + 1, 0); //init to something larger than possible
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (x * y >= n && x * y <= n + 2) {
                if (abs(x - y) < abs(closestPair.first - closestPair.second)) {
                    closestPair = make_pair(x, y);
                }
            }
        }
    }

    return closestPair;
}

int main()
{
    for (int i = 1; i < 100; ++i) {
        auto result = findNearestSquare(i);
        cout << "N=" << i << "\t{" << result.first << ", " << result.second << "}" << " - " << result.first*result.second << endl;
    }
}
