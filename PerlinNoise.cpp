//
// Created by ainols on 13.04.23.
//

#include "PerlinNoise.h"
#include <cstdlib>
#include <cmath>

float PerlinNoise::Fade(float t) {

    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);

}

std::vector<float> PerlinNoise::Gradient(unsigned int x, unsigned int y) {

    if (Gradients.find({x, y}) == Gradients.end()) {

        float randomX = (float)std::rand() / (float)RAND_MAX;
        float randomY = (float)std::rand() / (float)RAND_MAX;

        float magnitude = sqrt(randomX * randomX + randomY * randomY);

        Gradients[{x, y}] = {randomX / magnitude, randomY / magnitude};

    }

    return Gradients[{x, y}];

}

float PerlinNoise::Noise(float x, float y) {

    float x0 = floor(x);
    float y0 = floor(y);
    float x1 = x0 + 1;
    float y1 = y0;
    float x2 = x0;
    float y2 = y0 + 1;
    float x3 = x0 + 1;
    float y3 = y0 + 1;

    std::vector<float> g0 = Gradient(x0, y0);
    std::vector<float> g1 = Gradient(x1, y1);
    std::vector<float> g2 = Gradient(x2, y2);
    std::vector<float> g3 = Gradient(x3, y3);

    float t0 = x - x0;
    float f0 = Fade(t0);

    float t1 = y - y0;
    float f1 = Fade(t1);

    float p0p1 = (1 - f0) * (g0[0] * t0 + g0[1] * t1) + f0 * (g1[0] * (x - x1) + g1[1] * (y - y1));
    float p2p3 = (1 - f0) * (g2[0] * (x - x2) + g2[1] * (y - y2)) + f0 * (g3[0] * (x - x3) + g3[1] * (y - y3));

    return (1.0 - f1) * p0p1 + f1 * p2p3;

}
