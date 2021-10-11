#include <stdlib.h>

#include "../include/header.h"

int main() {
    struct project *my_project = NULL;
    create(&my_project);
    entering_selection_parameters(my_project);
    return 0;
}