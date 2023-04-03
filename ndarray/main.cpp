#include <iostream>
#include "ndarray.h"

using namespace std;


int main() {
    NDArray <int> a(2, 3);
    a.fillOnes();
    a.print();
    NDArray<int> b(4, 4);
    b.fillZeros();
    b.print();
    NDArray <int> c(3, 4);
    c.fillRandoms(-50, 1000);
    NDArray <int> d(3, 4);
    d.fillRandoms(0, 500);
    d.print();
    d.transpose().print();
    (c + d).print();
    (d - c).print();
    (c * d).print();
    (c / d).print();
    c.matmul(a.transpose()).print();
    NDArray <int> e({ 0, 1, 2, 3, 4, 5 }, 2, 3);
    e.print();
    e.min(0).print();
    e.min(1).print();
    e.max(0).print();
    e.max(1).print();
    NDArray <float> f({ 0,1.3,2.5,3.3,5.0,3.4 }, 2, 3);
    f.print();
    f.mean(0).print();
    f.mean(1).print();

    return 0;
}