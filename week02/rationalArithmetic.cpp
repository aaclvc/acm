/* Aida Colovic
 *
 * Kattis Problem   : Rational Arithmetic
 * Problem ID       : rationalarithmetic
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.4
 *
 */

#include <iostream>

class Fraction
{
private:
    long long _numerator;
    long long _denominator;

    long gcd(long long a, long long b)
    {
        if (a<0) a = -a;
        if (b<0) b = -b;

        if (a == 0 && b != 0) return b;
        else if (a != 0 && b == 0) return a;

        while (b!=0)
        {
            a %= b;
            if (a==0) return b;
            b %= a;
        }
        return a;
    }
public:
    Fraction(long long numerator, long long denominator)
    {
        _numerator   = numerator;
        _denominator = denominator;
    }
    void print()
    {
        std::cout << this->_numerator << " / " << this->_denominator << std::endl;
    }

    Fraction operator+(const Fraction& other)
    {
        Fraction result(1, 1);

        result._numerator   = this->_numerator*other._denominator + other._numerator*this->_denominator;
        result._denominator = this->_denominator * other._denominator;

        long long factor = gcd(result._numerator, result._denominator);
        if (factor)
        {
            result._numerator   /= factor;
            result._denominator /= factor;
        }
        return result;
    }

    Fraction operator-(const Fraction& other)
    {
        Fraction result(1, 1);

        result._numerator   = this->_numerator*other._denominator - other._numerator*this->_denominator;
        result._denominator = this->_denominator * other._denominator;

        long long factor = gcd(result._numerator, result._denominator);
        if (factor)
        {
            result._numerator   /= factor;
            result._denominator /= factor;
        }
        return result;
    }

    Fraction operator*(const Fraction& other)
    {
        Fraction result(1, 1);

        result._numerator   = this->_numerator   * other._numerator;
        result._denominator = this->_denominator * other._denominator;

        long long factor = gcd(result._numerator, result._denominator);
        if (factor)
        {
            result._numerator   /= factor;
            result._denominator /= factor;
        }
        return result;
    }
    Fraction operator/(const Fraction& other)
    {
        Fraction result(1, 1);

        result._numerator   = this->_numerator   * other._denominator;
        result._denominator = this->_denominator * other._numerator;

        long long factor = gcd(result._numerator, result._denominator);
        if (factor)
        {
            result._numerator   /= factor;
            result._denominator /= factor;
        }
        return result;
    }
};


int main(void)
{
    int cases = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        long long x1, x2, y1, y2;
        char op;
        scanf("%lld %lld %c %lld %lld", &x1, &x2, &op, &y1, &y2);

        Fraction first(x1, x2);
        Fraction second(y1, y2);
        Fraction result(1, 1);

        if (op == '+')
        {
            result = first + second;
            result.print();
        }
        else if (op == '-')
        {
            result = first - second;
            result.print();
        }
        else if (op == '*')
        {
            result = first * second;
            result.print();
        }
        else if (op == '/')
        {
            result = first / second;
            result.print();
        }
    }

    return 0;
}