#include <iostream>
#include <concepts>
#include <numeric>

template<typename I> requires std::integral<I>
class rational
{
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) return;
        I divcomune = std::gcd(num_, den_);
        num_ /= divcomune;
        den_ /= divcomune;
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    I num() const { return num_; }
    I den() const { return den_; }

    rational()
        : num_(I{0}), den_(I{1})
    {}
    
    rational(const I& n, const I& d)
        : num_(n), den_(d) 
    {
        if (den_ != 0) {
            simplify();
        }
    }

    rational& operator+=(const rational& other) {
        if(den_ != 0 && other.den_ != 0) {
            num_ = num_ * other.den_ + other.num_ * den_; 
            den_ = den_ * other.den_;
            simplify();
        }
        else {
            if((den_ == 0 && num_ != 0) || (other.den_ == 0 && other.num_ != 0)) {
                if(den_ == 0) {
                    num_ = num_;
                    den_ = 0;
                }
                else {
                    num_ = other.num_;
                    den_ = 0;
                }
            } 
            else if((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) { 
                num_ = 0;
                den_ = 0;
            }
        }
        return *this;
    }

    rational operator+(const rational& other) const { 
       rational ret = *this;
       ret += other;
       return ret; 
    }

    rational& operator-=(const rational& other) { 
        if(den_ != 0 && other.den_ != 0) { 
            num_ = num_ * other.den_ - other.num_ * den_; 
            den_ = den_ * other.den_;
            simplify();
        }
        else {
            if((den_ == 0 && num_ != 0) || (other.den_ == 0 && other.num_ != 0)) {
                if(den_ == 0) {
                    num_ = num_;
                    den_ = 0;
                }
                else {
                    num_ = other.num_;
                    den_ = 0;
                }
            }
            else if((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
                num_ = 0;
                den_ = 0;
            }
        }
        return *this;
    }

    rational operator-(const rational& other) const {
       rational ret = *this;
       ret -= other;
       return ret; 
    }

    rational& operator*=(const rational& other) {
        num_ = num_ * other.num_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this; 
        ret *= other;
        return ret; 
    }

    rational& operator/=(const rational& other) {
        num_ = num_ * other.den_;
        den_ = den_ * other.num_;
        simplify();
        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this; 
        ret /= other;
        return ret; 
    }
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0) os << "NaN";
        else os << (r.num() > 0 ? "+inf" : "-inf");
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}