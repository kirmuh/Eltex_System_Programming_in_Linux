#include <stdio.h>
#include "calc.h"
#include "io.h"
#include "helper.h"

int main() {
    int a = 5, b = 3;

    int sum = add(a, b);
    int diff = subtract(a, b);
    int sq = square(a);

    print_result(sum);
    print_result(diff);
    print_result(sq);

    return 0;
}