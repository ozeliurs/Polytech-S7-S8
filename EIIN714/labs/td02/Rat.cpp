//
// Created by Maxime BILLY on 15/09/2023.
//

#include <fstream>
#include <iostream>

int pgcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return pgcd(b, a % b);
}

class Rat {
private:
    int num;
    unsigned int denom;

public:
    Rat() : Rat(0, 1) {}

    Rat(int n) : Rat(n, 1) {}

    Rat(int p, unsigned int q) {
        if (q == 0) {
            throw std::invalid_argument("Denominator cannot be 0");
        }

        int gcd = pgcd(p, q);

        gcd = gcd < 0 ? -gcd : gcd;

        num = p / gcd;
        denom = q / gcd;
    }

    int getNum() const {
        return num;
    }

    unsigned int getDenom() const {
        return denom;
    }
};

// << operator overloading
std::ostream &operator<<(std::ostream &os, const Rat &r) {
    os << r.getNum() << "/" << r.getDenom();
    return os;
}

// >> operator overloading
std::istream &operator>>(std::istream &is, Rat &r) {
    int n;
    unsigned int d;
    char c;
    is >> n >> c >> d;
    r = Rat(n, d);
    return is;
}

// addition operator overloading
Rat operator+(const Rat &r1, const Rat &r2) {
    return Rat(r1.getNum() * r2.getDenom() + r2.getNum() * r1.getDenom(), r1.getDenom() * r2.getDenom());
}

// opposite operator overloading
Rat operator-(const Rat &r) {
    return Rat(-r.getNum(), r.getDenom());
}

// subtraction operator overloading
Rat operator-(const Rat &r1, const Rat &r2) {
    return r1 + (-r2);
}

// increment operator overloading
Rat operator++(const Rat &r) {
    return Rat(r.getNum() + r.getDenom(), r.getDenom());
}

// decrement operator overloading
Rat operator--(const Rat &r) {
    return Rat(r.getNum() - r.getDenom(), r.getDenom());
}

// multiplication operator overloading
Rat operator*(const Rat &r1, const Rat &r2) {
    return Rat(r1.getNum() * r2.getNum(), r1.getDenom() * r2.getDenom());
}

// division operator overloading
Rat operator/(const Rat &r1, const Rat &r2) {
    return Rat(r1.getNum() * r2.getDenom(), r1.getDenom() * r2.getNum());
}

// inverse operator overloading
Rat operator!(const Rat &r) {
    return Rat(r.getDenom(), r.getNum());
}

// equality operator overloading
bool operator==(const Rat &r1, const Rat &r2) {
    return r1.getNum() * r2.getDenom() == r2.getNum() * r1.getDenom();
}

// inequality operator overloading
bool operator!=(const Rat &r1, const Rat &r2) {
    return !(r1 == r2);
}

// less than operator overloading
bool operator<(const Rat &r1, const Rat &r2) {
    return r1.getNum() * r2.getDenom() < r2.getNum() * r1.getDenom();
}

// less than or equal operator overloading
bool operator<=(const Rat &r1, const Rat &r2) {
    return r1 < r2 || r1 == r2;
}

// greater than operator overloading
bool operator>(const Rat &r1, const Rat &r2) {
    return !(r1 <= r2);
}

// greater than or equal operator overloading
bool operator>=(const Rat &r1, const Rat &r2) {
    return !(r1 < r2);
}

int main() {
    Rat r1(1, 2);
    Rat r2(3, 4);

    // Empty constructor
    Rat r3;
    std::cout << "Rat() = " << r3 << std::endl;

    // Constructor with one parameter
    Rat r4(1);
    std::cout << "Rat(int) = " << r4 << std::endl;

    // << operator overloading
    std::cout << "1/2 = " << r1 << std::endl;

    // >> operator overloading
    // std::cin >> r1;

    // addition operator overloading
    std::cout << "r1 + r2 = " << (r1 + r2) << std::endl;

    // subtraction operator overloading
    std::cout << "r1 - r2 = " << (r1 - r2) << std::endl;

    // increment operator overloading
    std::cout << "++r1 = " << ++r1 << std::endl;

    // decrement operator overloading
    std::cout << "--r1 = " << --r1 << std::endl;

    // multiplication operator overloading
    std::cout << "r1 * r2 = " << (r1 * r2) << std::endl;

    // division operator overloading
    std::cout << "r1 / r2 = " << (r1 / r2) << std::endl;

    // opposite operator overloading
    std::cout << "-r1 = " << -r1 << std::endl;

    // inverse operator overloading
    std::cout << "!r1 = " << !r1 << std::endl;

    // equality operator overloading
    std::cout << "r1 == r2 = " << ((r1 == r2) == 0 ? "false" : "true") << std::endl;

    // inequality operator overloading
    std::cout << "r1 != r2 = " << ((r1 != r2) == 0 ? "false" : "true") << std::endl;

    // less than operator overloading
    std::cout << "r1 < r2 = " << ((r1 < r2) == 0 ? "false" : "true") << std::endl;

    // less than or equal operator overloading
    std::cout << "r1 <= r2 = " << ((r1 <= r2) == 0 ? "false" : "true") << std::endl;

    // greater than operator overloading
    std::cout << "r1 > r2 = " << ((r1 > r2) == 0 ? "false" : "true") << std::endl;

    // greater than or equal operator overloading
    std::cout << "r1 >= r2 = " << ((r1 >= r2) == 0 ? "false" : "true") << std::endl;

    return 0;
}



