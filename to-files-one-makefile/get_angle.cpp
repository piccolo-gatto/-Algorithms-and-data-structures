#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

int main(int argc, char* argv[]) {
    double x, y, z;
    std::stringstream name;
    /*name << argv[1] << argv[2];*/
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    while (in) {
        in >> x >> y >> z;
        out << 2.0 * sin(x) * sin(y) + cos(z) << std::endl;
        /*std::cout << 2.0 * sin(x) * sin(y) + cos(z) << std::endl;*/
    }
    return 0;
}
