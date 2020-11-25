// C++ program to demonstrate the use of std::unique 
std::unique is used to remove duplicates of any element present consecutively in a range[first, last).
 It performs this task for all the sub-groups present in the range having the same element present consecutively.
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
int main() 
{ 
    vector<int> v, i; 
   v.push_back(1);v.push_back(1);v.push_back(3);v.push_back(3);v.push_back(4);
    vector<int>::iterator ip; 
  
    // Using std::unique 
    ip = std::unique(v.begin(), v.begin() + 5); 
    // Now v becomes {1 3 10 1 3 7 8 * * * * *} 
    // * means undefined 
  
    // Resizing the vector so as to remove the undefined terms 
    v.resize(std::distance(v.begin(), ip)); 
  
    // Displaying the vector after applying std::unique 
    for (ip = v.begin(); ip != v.end(); ++ip) { 
        cout << *ip << " "; 
    } 
  
    return 0; 
} 
