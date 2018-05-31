/*#ifndef FILTERBUTTERWORTH_H
#define FILTERBUTTERWORTH_H


class FilterButterworth
{
public:
    FilterButterworth();

private:
    float resonance;

    float frequency;
    int sampleRate;
    PassType passType;

    float c, a1, a2, a3, b1, b2;

    /// <summary>
    /// Array of input values, latest are in front
    /// </summary>
    float[] inputHistory;

    /// <summary>
    /// Array of output values, latest are in front
    /// </summary>
    float[] outputHistory;
};

#endif // FILTERBUTTERWORTH_H*/
