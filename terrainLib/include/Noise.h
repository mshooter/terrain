#ifndef NOISE_H
#define NOISE_H

#include <array>
// http://blog.kazade.co.uk/2014/05/a-public-domain-c11-1d2d3d-perlin-noise.html
class Noise
{
public:
    // constructor default
    Noise();
    // constructor
    Noise(double _persistence, double _frequency, double _amplitude, int _octaves,int _randomSeed);
    // copy consructor for 3D noise
    Noise(uint32_t seed=0);
    // deconstructor
    ~Noise(){;}
    // get height
    double getNoise(double _x, double _y) const;
    // setters
    void setNoise(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed);
    // 3D noise
    double get3Dnoise(double x, double y, double z) ;

private:

    double Total(double i, double j) const;
    double GetValue(double x, double y) const;
    double Interpolate(double x, double y, double a) const;
    double PNoise(int x, int y) const;

    double fade3D(double _t);
    double lerp3D(double _t, double _a, double _b);
    double grad3D(int hash, double x, double y, double z);

    double m_persistence;
    double m_frequency;
    double m_amplitude;
    int m_octaves;
    int m_randomseed;

    std::array<int, 512> p;

};


#endif // NOISE_H
