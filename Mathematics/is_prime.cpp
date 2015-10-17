//The algorithm tries to divide n by each odd number (and by 2) up to the 
//square root of n

bool is_prime(int n) {
    if(n < 2) 
        return false;
    if(n == 2) 
        return true;
    if(n % 2 == 0)
        return false;

    int squareRoot = sqrt(n);
    
    for(int i = 3; i <= squareRoot; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}
