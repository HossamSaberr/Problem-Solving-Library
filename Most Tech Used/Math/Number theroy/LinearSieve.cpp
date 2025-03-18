struct LinearSieve {
    vector<int> primes;
    vector<int> smallest_prime;
    vector<int> phi;     /* phi[i] = number of integers in [1, i] that are coprime to i*/vector<int> mu;      /* mu[i] = 1 if i is square-free with even number of prime factors, mu[i] = -1 if i is square-free with odd number of prime factors, mu[i] = 0 if i has a squared prime factor*/vector<int> sum_mu;  /* sum_mu[i] = sum of mu[j] for j in [1, i]*/vector<int> sum_phi; /* sum_phi[i] = sum of phi[j] for j in [1, i]*/LinearSieve(
            int n) {
        smallest_prime.resize(n + 1);
        phi.resize(n + 1);
        mu.resize(n + 1);
        sum_mu.resize(n + 1);
        sum_phi.resize(n + 1);
        phi[1] = 1;
        mu[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (smallest_prime[i] == 0) {
                smallest_prime[i] = i;
                primes.push_back(i);
                phi[i] = i - 1;
                mu[i] = -1;
            }
            for (int j = 0; j < primes.size() && primes[j] <= smallest_prime[i] && i * primes[j] <= n; j++) {
                smallest_prime[i * primes[j]] = primes[j];
                if (smallest_prime[i] == primes[j]) {
                    phi[i * primes[j]] = phi[i] * primes[j];
                    mu[i * primes[j]] = 0;
                }
                else {
                    phi[i * primes[j]] = phi[i] * (primes[j] - 1);
                    mu[i * primes[j]] = -mu[i];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            sum_mu[i] = sum_mu[i - 1] + mu[i];
            sum_phi[i] = sum_phi[i - 1] + phi[i];
        }
    }

    bool is_prime(int n) { return smallest_prime[n] == n; }

    vector<int> factorize(int n) {
        vector<int> factors;
        while (n > 1) {
            factors.push_back(smallest_prime[n]);
            n /= smallest_prime[n];
        }
        return factors;
    }
};