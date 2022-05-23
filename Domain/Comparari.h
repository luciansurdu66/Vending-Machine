//
// Created by lucia on 5/18/2022.
//

#ifndef LAB09_10_COMPARARI_H
#define LAB09_10_COMPARARI_H
#include <cmath>
class Compares {
public:
    static bool equal(double a, double b) {
        return fabs(a - b) < 1e-6;
    }

    static bool notEqual(double a, double b) {
        return !equal(a, b);
    }

    static bool less(double a, double b) {
        return a < b && notEqual(a, b);
    }

    static bool greaterOrEqual(double a, double b) {
        return a > b || equal(a, b);
    }
};
#endif //LAB09_10_COMPARARI_H
