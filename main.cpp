#include "Application.h"
#include "PerlinNoise.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {

    std::srand(std::time(nullptr));

    PerlinNoise Noise;

    float NoiseScale = 50;

    std::vector<std::vector<float>> Points;

    unsigned int PointWidth = 100;
    unsigned int PointHeight = 100;

    for (unsigned int x = 0; x < PointWidth; x++) {

        std::vector<float> Row;

        for (unsigned int y = 0; y < PointHeight; y++) {

            Row.push_back(Noise.Noise((float)x / NoiseScale, (float)y / NoiseScale));

        }

        Points.push_back(Row);

    }

    Application App("Marching Squares", 800, 800, Points);

    return App.OnExecute();
}