#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <cmath>


long int input(std::string title) {

    std::cout << title;
    long int n = 0;
    std::cin >> n;
    return (n);

};


long int rand_int(std::default_random_engine &gen, long int a, long int b) {

    std::uniform_int_distribution<long int> db(a, b);
    return (db(gen));

};


long int mod_pow(long int base, int exp, long int mod) {

    long int res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        };
 
        exp = exp >> 1;
        base = (base * base) % mod;
    };
    return (res);

};

 
long int pollard_rho(long int n) {

    if (n == 1) {
        return (n);
    };
 
    if (n % 2 == 0) {
        return (2);
    };

    std::default_random_engine gen;

    long int x = rand_int(gen, 2, n - 2);
    long int y = x;
    long int c = rand_int(gen, 1, n - 1);
    long int d = 1;  

    while (d == 1) {
        x = (mod_pow(x, 2, n) + c + n) % n;
        y = (mod_pow(y, 2, n) + c + n) % n;
        y = (mod_pow(y, 2, n) + c + n) % n;

        d = std::gcd(std::abs(x - y), n);
 
        if (d == n) {
            return (pollard_rho(n));
        };
    };
    return (d);

};
 

int main() {

    std::cout << "Pollard’s Rho Algorithm" << '\n';
    std::cout << "decomposition of a large odd integer n into its corresponding prime factors" << '\n';
    std::cout << "examples 143, 657, 1233, 1603, 10967535067, 14365657343543 ..." << '\n' << '\n';

    auto n = input("enter n: ");
    auto res = pollard_rho(n);
    std::cout << "result: " << res << ' ' << n / res << '\n';

    return (0);

};
