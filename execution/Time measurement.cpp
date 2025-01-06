// C++ program to find out execution time of
// of functions
#include <algorithm>
/*

 Nayan Chandra (Nayan_C)
 Dhaka University of Engineering & Technology,Gazipur(DUET)
 CSE-21,ID-214001

*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int main()
{

    

    // Get starting timepoint
    auto start = high_resolution_clock::now();

     // aikhane call function ta dite hobe
    

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

   
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}
