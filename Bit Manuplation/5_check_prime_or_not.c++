#include <bits/stdc++.h>
using namespace std;


bool is_prime(unsigned int n) { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if ((n & 1) == 0) // Check if n is even using bitwise AND. 
        return false; 
 
    for (unsigned int i = 5; i * i <= n; i += 6) { 
        if ((n % i == 0) || (n % (i + 2) == 0)) 
            return false; 
    } 
 
    return true; 
} 

int main(void) {

    return 0;
}