#include <vector>
#include <string>
#include <algorithm>

class BigInteger {
    std::vector<int> d; // digits (LSB first)
    bool neg;

    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
        if (d.size() == 1 && d[0] == 0) neg = false;
    }

    bool absLess(const BigInteger& b) const {
        if (d.size() != b.d.size()) return d.size() < b.d.size();
        for (int i = d.size()-1; i >= 0; --i)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }

public:
    BigInteger() : d{0}, neg(false) {}
    
    BigInteger(const std::string& s) {
        if (s.empty()) { d = {0}; neg = false; return; }
        neg = s[0] == '-';
        for (int i = s.size()-1; i >= neg; --i) d.push_back(s[i]-'0');
        trim();
    }

    BigInteger(long long n) {
        neg = n < 0;
        n = std::abs(n);
        do { d.push_back(n%10); n /= 10; } while (n);
    }

    BigInteger operator+(const BigInteger& b) const {
        if (neg != b.neg) return neg ? b - (-*this) : *this - (-b);
        BigInteger r;
        r.neg = neg;
        for (size_t i = 0, c = 0; i < d.size() || i < b.d.size() || c; ++i) {
            if (i < d.size()) c += d[i];
            if (i < b.d.size()) c += b.d[i];
            r.d.push_back(c%10);
            c /= 10;
        }
        return r;
    }

    BigInteger operator-() const {
        BigInteger r = *this;
        if (r != BigInteger(0)) r.neg = !r.neg;
        return r;
    }

    BigInteger operator-(const BigInteger& b) const {
        if (neg != b.neg) return *this + (-b);
        if (absLess(b)) {
            BigInteger r = b - *this;
            r.neg = !neg;
            return r;
        }
        BigInteger r;
        r.neg = neg;
        for (size_t i = 0, br = 0; i < d.size(); ++i) {
            int diff = d[i] - br;
            if (i < b.d.size()) diff -= b.d[i];
            br = diff < 0 ? 1 : 0;
            r.d.push_back(diff + (br ? 10 : 0));
        }
        r.trim();
        return r;
    }

    BigInteger operator*(const BigInteger& b) const {
        BigInteger r;
        r.d.resize(d.size() + b.d.size());
        for (size_t i = 0; i < d.size(); ++i)
            for (size_t j = 0, c = 0; j < b.d.size() || c; ++j) {
                long long p = r.d[i+j] + d[i] * (j < b.d.size() ? b.d[j] : 0) + c;
                r.d[i+j] = p % 10;
                c = p / 10;
            }
        r.neg = neg != b.neg;
        r.trim();
        return r;
    }

    bool operator==(const BigInteger& b) const { return neg == b.neg && d == b.d; }
    bool operator<(const BigInteger& b) const {
        if (neg != b.neg) return neg;
        return neg ? b.absLess(*this) : absLess(b);
    }
    bool operator!=(const BigInteger& b) const { return !(*this == b); }
    bool operator>(const BigInteger& b) const { return b < *this; }
    bool operator<=(const BigInteger& b) const { return !(*this > b); }
    bool operator>=(const BigInteger& b) const { return !(*this < b); }

    std::string str() const {
        std::string s;
        if (neg) s += '-';
        for (auto it = d.rbegin(); it != d.rend(); ++it) s += char(*it + '0');
        return s.empty() ? "0" : s;
    }
};
