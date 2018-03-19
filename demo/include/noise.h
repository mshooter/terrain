#ifndef NOISE_H
#define NOISE_H


class Noise
{
public:
    // constructor default
    Noise();
    // constructor
    Noise(double _persistence, double _frequency, double _amplitude, int _octaves,int _randomSeed);
    // deconstructor
    ~Noise(){;}
    // get height
    double getNoise(double _x, double _y) const;
    // setters
    void setNoise(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed);

private:

    double Total(double i, double j) const;
    double GetValue(double x, double y) const;
    double Interpolate(double x, double y, double a) const;
    double PNoise(int x, int y) const;

    double m_persistence;
    double m_frequency;
    double m_amplitude;
    int m_octaves;
    int m_randomseed;


};


#endif // NOISE_H
