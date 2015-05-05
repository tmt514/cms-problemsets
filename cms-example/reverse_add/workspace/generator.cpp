#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <random>
#include <string>
#include <map>
using namespace std;

mt19937 rng(0x5EED);

int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}

void gen_sample(FILE *fp, int num) {
    assert(num <= 2);
    if (num == 1) fprintf(fp, "3\n");
    else if (num == 2) fprintf(fp, "8\n");
}

void gen_under_n(FILE *fp, int n) {
    int x = randint(1, n);
    fprintf(fp, "%d\n", x);
}

void gen_under_1e4(FILE *fp, int num) {
    gen_under_n(fp, 10000);
}

void gen_under_1e9(FILE *fp, int num) {
    gen_under_n(fp, 1000000000);
}

map<string, function<void(FILE*, int)>> gen_func = {
    {"sample", gen_sample},
    {"under_1e4", gen_under_1e4},
    {"under_1e9", gen_under_1e9}
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s num_test test_name\n", argv[0]);
        printf("Available test_name:");
        for (auto i : gen_func) printf(" %s", i.first.c_str());
        puts("");
        exit(1);
    }

    int ret_code = system("mkdir -p testdata");
    assert(ret_code == 0);

    int num_test = strtol(argv[1], NULL, 10);
    char *test_name = strdup(argv[2]);
    assert(num_test > 0);
    assert(gen_func.count(test_name));

    for (int i = 1; i <= num_test; i++) {
        char *path;
        asprintf(&path, "testdata/%s-%d.in", test_name, i);
        FILE *fp = fopen(path, "w");
        assert(fp != NULL);
        gen_func[test_name](fp, i);
    }
    return 0;
}
