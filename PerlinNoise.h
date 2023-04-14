//
// Created by ainols on 13.04.23.
//

#ifndef MARCHING_SQUARES_PERLINNOISE_H
#define MARCHING_SQUARES_PERLINNOISE_H

#include <vector>
#include <map>

class PerlinNoise {

private:
    std::map<std::vector<unsigned int>, std::vector<float>> Gradients;
    float Fade(float t);
    std::vector<float> Gradient(unsigned int x, unsigned int y);

public:
    float Noise(float x, float y);

};


#endif //MARCHING_SQUARES_PERLINNOISE_H
