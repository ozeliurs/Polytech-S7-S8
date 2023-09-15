//
// Created by Maxime BILLY on 15/09/2023.
//

#include <fstream>

class Rat {
private:
    int num;
    unsigned int denom;

public:
    Rat() {
        num = 0;
        denom = 1;
    }

    Rat(int n) {
        num = n;
        denom = 1;
    }

    Rat(int p, unsigned int q) {
        if (q == 0) {
            throw std::invalid_argument("Denominator cannot be 0");
        }

        num = p;
        denom = q;
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

// subtraction operator overloading
Rat operator-(const Rat &r1, const Rat &r2) {
    return Rat(r1.getNum() * r2.getDenom() - r2.getNum() * r1.getDenom(), r1.getDenom() * r2.getDenom());
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

// opposite operator overloading
Rat operator-(const Rat &r) {
    return Rat(-r.getNum(), r.getDenom());
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



