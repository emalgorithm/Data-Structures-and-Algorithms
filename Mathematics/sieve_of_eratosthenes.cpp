const int MAX_N = (int)1e7;

bool isPrime[MAX_N];

void sieve_of_eratosthenes() {
    for(int i = 2; i < MAX_N; i++) {
        isPrime[i] = true;
    }
    
    int squareRoot = sqrt(MAX_N);
    for(int i = 2; i <= squareRoot; i++) {
        if(isPrime[i]) {
            for(int j = 2; i * j < MAX_N; j++) {
                isPrime[i * j] = false;
            }
        }
    }
}
