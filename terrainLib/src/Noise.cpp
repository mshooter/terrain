#include "Noise.h"
# include <algorithm>
#include <random>
#include <numeric>
#include <cmath>

Noise::Noise()
{
}

Noise::Noise(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomSeed)
{
    m_persistence = _persistence;
    m_frequency = _frequency;
    m_amplitude = _amplitude;
    m_octaves = _octaves;
    m_randomseed = 2 + _randomSeed * _randomSeed;
}

double Noise::getNoise(double _x, double _y) const
{
    return m_amplitude * Total(_x, _y);
}

void Noise::setNoise(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed)
{
    m_persistence = _persistence;
    m_frequency = _frequency;
    m_amplitude = _amplitude;
    m_octaves = _octaves;
    m_randomseed = 2 + _randomseed * _randomseed;
}

double Noise::Total(double i, double j) const
{
    double t = 0.0f;
    double amp = 1;
    double freq = m_frequency;

    for(int k =0 ; k < m_octaves; ++k)
    {
        t += GetValue(j * freq + m_randomseed, i * freq + m_randomseed) * amp;
        amp *= m_persistence;
        freq *= 2;
    }
    return t;
}

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

double Noise::Interpolate(double x, double y, double a) const
{
    double negA = 1.0 - a;
    double negASqr = negA * negA;
    double fac1 = 3.0 * (negASqr) - 2.0 * (negASqr * negA);
    double aSqr = a * a;
    double fac2 = 3.0 * aSqr - 2.0 * (aSqr * a);

    return x * fac1 + y * fac2; //add the weighted factors
}

double Noise::PNoise(int x, int y) const
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    int t = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff;
    return 1.0 - double(t) * 0.931322574615478515625e-9;/// 1073741824.0);
}

double Noise::fade3D(double _t)
{
    return _t * _t * _t * (_t * (_t * 6 -15) + 10);
}

double Noise::lerp3D(double _t, double _a, double _b)
{
    return _a + _t * (_b - _a);
}

double Noise::grad3D(int hash, double x, double y, double z)
{
    int h = hash & 15;
    double u = h < 8 ? x : y;
    double v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

Noise::Noise(uint32_t seed)
{
    if(!seed)
    {
        seed = time(0);
    }

    auto mid_range = p.begin() + 256;
    std::mt19937 engine(seed);
    // generate sequential numbers in the loop
    std::iota(p.begin(), mid_range, 0);
    // shuffle lower half
    std::shuffle(p.begin(), mid_range, engine);
    // copy lower half to the upper half
    std::copy(p.begin(), mid_range, mid_range);
    // p now has the numbers 0-255, shuffled and duplicated
}

double Noise::get3Dnoise(double x, double y, double z)
{
   //See here for algorithm: http://cs.nyu.edu/~perlin/noise/
   const int32_t X = static_cast<int32_t>(std::floor(x)) & 255;
   const int32_t Y = static_cast<int32_t>(std::floor(y)) & 255;
   const int32_t Z = static_cast<int32_t>(std::floor(z)) & 255;

   x -= std::floor(x);
   y -= std::floor(y);
   z -= std::floor(z);

   double u = fade3D(x);
   double v = fade3D(y);
   double w = fade3D(z);

   auto A = p[X] + Y;
   auto AA = p[A] + Z;
   auto AB = p[A + 1] + Z;
   auto B = p[X + 1] + Y;
   auto BA = p[B] + Z;
   auto BB = p[B + 1] + Z;

   auto PAA = p[AA];
   auto PBA = p[BA];
   auto PAB = p[AB];
   auto PBB = p[BB];
   auto PAA1 = p[AA + 1];
   auto PBA1 = p[BA + 1];
   auto PAB1 = p[AB + 1];
   auto PBB1 = p[BB + 1];

   const auto a = lerp3D(v,
                         lerp3D(u, grad3D(PAA, x, y, z), grad3D(PBA, x-1, y, z)),
                         lerp3D(u, grad3D(PAB, x, y-1, z), grad3D(PBB, x-1, y-1, z))
                         );
   const auto b = lerp3D(v,
                         lerp3D(u, grad3D(PAA1, x, y, z-1), grad3D(PBA1, x-1, y, z-1)),
                         lerp3D(u, grad3D(PAB1, x, y-1, z-1), grad3D(PBB1, x-1, y-1, z-1))
                         );
   return lerp3D(w,a,b);
}
