//
// Created by ainols on 14.04.23.
//

#ifndef MARCHING_SQUARES_BOUNDS_H
#define MARCHING_SQUARES_BOUNDS_H

#include <vector>
#include <cmath>
#include <algorithm>

typedef struct {

    float x1;
    float y1;
    float x2;
    float y2;
    float slope;
    float offset;

} Line;

Line ComputeLine(float x1, float y1, float x2, float y2);
float LineEqualsX(Line Line, float x);
float LineEqualsY(Line Line, float y);

class Bounds {

private:
    std::vector<Line> Lines;

public:
    Bounds(std::vector<Line> Lines);
    bool InBounds(float x, float y);

};

Bounds BoundsFromPoints(std::vector<std::vector<unsigned int>> Points) {

    std::vector<Line> Lines;

    std::vector<unsigned int> UsedPoints;

    unsigned int CurrentPoint = 0;

    for (unsigned int i = 1; i < Points.size(); i++) {

        UsedPoints.push_back(CurrentPoint);

        unsigned int NextPoint;

        for (unsigned int j = 0; j < Points.size(); j++) {

            if (std::find(UsedPoints.begin(), UsedPoints.end(), j) != UsedPoints.end()) {

                continue;

            }

            unsigned int Dx = Points[CurrentPoint][0] - Points[NextPoint][0];
            unsigned int Dy = Points[CurrentPoint][1] - Points[NextPoint][1];

            unsigned int NewDx = Points[CurrentPoint][0] - Points[j][0];
            unsigned int NewDy = Points[CurrentPoint][1] - Points[j][1];

            if (NewDx * NewDx + NewDy * NewDy < Dx * Dx + Dy * Dy) {

                NextPoint = j;

            }

        }

        Lines.push_back(ComputeLine(Points[CurrentPoint][0], Points[CurrentPoint][1], Points[NextPoint][0], Points[NextPoint][1]));

        CurrentPoint = NextPoint;

    }

    return Bounds(Lines);

}

#endif //MARCHING_SQUARES_BOUNDS_H
