#include <cstdio>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char * argv[]) {
    FILE* f1;
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution <double> distribution_elements(-1e4, 1e4);
    uniform_int_distribution <int> distribution_size(0, 1000000);

    int n;
    std::string fileName = "array";
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    else {
        if (argc == 3)
        {
            n = atoi(argv[1]);
            fileName = argv[2];
        }
        else {
            n = distribution_size(generator);
        }
    }

    freopen_s(&f1, ("..//" + fileName + ".in").c_str(), "wb", stdout);
    fwrite(&n, sizeof(n), 1, stdout);
    double * cur = new double[n];
    for (int i = 0; i < n; i++) {
        cur[i] = distribution_elements(generator);
    }
    fwrite(cur, sizeof(*cur), n, stdout);

    fclose(f1);
    return 0;
}