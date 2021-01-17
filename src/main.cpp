// Calculate the sine of small angles < 5 radians
// ----------------------------------------------------------------------------
// Matthew James Lewis - VE6JI
// Green::Box(Code)
// ve6mjl@gmail.com
// ----------------------------------------------------------------------------

#include <iostream>
namespace ve6ji
{
    double Sin(double x);
    unsigned long long Fac(int n);
    long double Pow(double x, int y);

} // namespace ve6ji

int main(int argc, char const *argv[])
{
    /* code */
    double angle = 0.55; //radians
    std::cout << ve6ji::Fac(23) << std::endl;
    std::cout << ve6ji::Pow(1.283,23) << std::endl;
    ve6ji::Sin(angle);
    std::cout.precision(12);
    std::cout << "The Sine of the angle : " << angle << " is " << ve6ji::Sin(angle) << std::endl;
    return 0;
}

double ve6ji::Sin(double x)
{
    // Calculate the Sine of an angle using taylor approx
    return x - (ve6ji::Pow(x, 3) / ve6ji::Fac(3)) + (ve6ji::Pow(x, 5) / ve6ji::Fac(5)) - (ve6ji::Pow(x, 7) / ve6ji::Fac(7)) 
    + (ve6ji::Pow(x, 9) / ve6ji::Fac(9)) - (ve6ji::Pow(x, 11) / ve6ji::Fac(11)) + (ve6ji::Pow(x, 13) / ve6ji::Fac(13))
    - (ve6ji::Pow(x, 15) / ve6ji::Fac(15)) + (ve6ji::Pow(x, 17) / ve6ji::Fac(17)) - (ve6ji::Pow(x, 19) / ve6ji::Fac(19))
    + (ve6ji::Pow(x, 21) / ve6ji::Fac(21)) - (ve6ji::Pow(x, 23) / ve6ji::Fac(23));
}

unsigned long long ve6ji::Fac(int n)
{
    // Recursive factorial function
    if (n <= 1)
    {
        return 1;
    }
    return (n * ve6ji::Fac(n - 1));
}

long double ve6ji::Pow(double x, int y)
{
    if (y == 0)
    {
        return 1.0;
    }
    if (y == 1)
    {
        return x;
    }
    return x * ve6ji::Pow(x, y - 1);
}