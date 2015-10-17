//Euclidean algorithm for GCD
//As a precondition we have that a >= b

int gcd(int a, int b) {
    if(b == 0) { //Base case
        return a;
    }
    
    int remainder = a % b;
    return gcd(b, remainder);
}

//This algorithm for LCM uses the fact that a * b = gcd(a, b) * lcm(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
