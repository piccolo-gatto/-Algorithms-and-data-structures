#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

double random_angle() {
    return (-314.0 + rand() / 314.0) / 100.0;
}

int main(int argc, char* argv[]) {
    //int n;
    //std::cin >> n;
    /*n = atoi(argv[1]);*/
    double x, y, z;
    std::ofstream out(argv[2]);
    for (int i = 0; i < atoi(argv[1]); i++) {
        x = random_angle();
        y = random_angle();
        z = random_angle();
        out << x << " " << y << " " << z << std::endl;
        /*std::cout << x << " " << y << " " << z << std::endl;*/
    }
    return 0;
}
