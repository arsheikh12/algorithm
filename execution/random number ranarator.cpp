/*

 Nayan Chandra (Nayan_C)
 Dhaka University of Engineering & Technology,Gazipur(DUET)
 CSE-21,ID-214001

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
   
    std::random_device rd;
    std::mt19937 gen(rd());

    
    int min = 1;
    int max = 100;

    
    std::uniform_int_distribution<> distr(min, max);

   
    for (int i = 0; i < 10; ++i)
     {
        int random_number = distr(gen);
        std::cout << "Random number " << i + 1 << ": " << random_number << std::endl;
    }

    return 0;
}
