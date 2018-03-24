#include <algorithm>
#include <random>
#include <numeric>
#include <cmath>
#include "Noise.h"

//------------------------------------------------------------------------------------------------------------------------------------------
Noise::Noise(double _frequency, double _amplitude, int _octaves, int _randomSeed, double _persistence)
{
    m_persistence = _persistence;
    m_frequency = _frequency;
    m_amplitude = _amplitude;
    m_octaves = _octaves;
    m_randomseed = 2 + _randomSeed * _randomSeed;
}
//------------------------------------------------------------------------------------------------------------------------------------------
double Noise::getNoise(double _x, double _y) const
{
    return m_amplitude * Total(_x, _y);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Noise::setNoise(double _frequency, double _amplitude, int _octaves, int _randomseed, double _persistence)
{
    m_persistence = _persistence;
    m_frequency = _frequency;
    m_amplitude = _amplitude;
    m_octaves = _octaves;
    m_randomseed = 2 + _randomseed * _randomseed;
}
//------------------------------------------------------------------------------------------------------------------------------------------
/// The following section is from :-
/// Nick Banks (2011). Perlin Noise Generation for Terrain [online]. [Accessed 2018].
/// Available from: " http://stackoverflow.com/questions/4753055/perlin-noise-generation-for-terrain".
double Noise::Total(double i, double j) const
{
    double t = 0.0f;
    double freq = m_frequency;
    double amp = 1;

    for(int k =0 ; k < m_octaves; ++k)
    {
        t += GetValue(j * freq + m_randomseed, i * freq + m_randomseed);
        amp *= m_persistence;
        freq *= 2;
    }
    return t;
}
//------------------------------------------------------------------------------------------------------------------------------------------
double Noise::GetValue(double x, double y) const
{
    int Xint = (int)x;
    int Yint = (int)y;
    double Xfrac = x - Xint;
    double Yfrac = y - Yint;

    //noise values
    double n01 = PNoise(Xint-1, Yint-1);
    double n02 = PNoise(Xint+1, Yint-1);
    double n03 = PNoise(Xint-1, Yint+1);
    double n04 = PNoise(Xint+1, Yint+1);
    double n05 = PNoise(Xint-1, Yint);
    double n06 = PNoise(Xint+1, Yint);
    double n07 = PNoise(Xint, Yint-1);
    double n08 = PNoise(Xint, Yint+1);
    double n09 = PNoise(Xint, Yint);

    double n12 = PNoise(Xint+2, Yint-1);
    double n14 = PNoise(Xint+2, Yint+1);
    double n16 = PNoise(Xint+2, Yint);

    double n23 = PNoise(Xint-1, Yint+2);
    double n24 = PNoise(Xint+1, Yint+2);
    double n28 = PNoise(Xint, Yint+2);

    double n34 = PNoise(Xint+2, Yint+2);

    //find the noise values of the four corners
    double x0y0 = 0.0625*(n01+n02+n03+n04) + 0.125*(n05+n06+n07+n08) + 0.25*(n09);
    double x1y0 = 0.0625*(n07+n12+n08+n14) + 0.125*(n09+n16+n02+n04) + 0.25*(n06);
    double x0y1 = 0.0625*(n05+n06+n23+n24) + 0.125*(n03+n04+n09+n28) + 0.25*(n08);
    double x1y1 = 0.0625*(n09+n16+n28+n34) + 0.125*(n08+n14+n06+n24) + 0.25*(n04);

    //interpolate between those values according to the x and y fractions
    double v1 = Interpolate(x0y0, x1y0, Xfrac); //interpolate in x direction (y)
    double v2 = Interpolate(x0y1, x1y1, Xfrac); //interpolate in x direction (y+1)
    double fin = Interpolate(v1, v2, Yfrac);  //interpolate in y direction

    return fin;
}
//------------------------------------------------------------------------------------------------------------------------------------------
double Noise::Interpolate(double x, double y, double a) const
{
    double negA = 1.0 - a;
    double negASqr = negA * negA;
    double fac1 = 3.0 * (negASqr) - 2.0 * (negASqr * negA);
    double aSqr = a * a;
    double fac2 = 3.0 * aSqr - 2.0 * (aSqr * a);

    return x * fac1 + y * fac2; //add the weighted factors
}
//------------------------------------------------------------------------------------------------------------------------------------------
double Noise::PNoise(int x, int y) const
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    int t = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff;
    return 1.0 - double(t) * 0.931322574615478515625e-9;/// 1073741824.0);
}
/// end of citation
