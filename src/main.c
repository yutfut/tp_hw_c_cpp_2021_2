#include <stdlib.h>

#include "../include/header.h"

int main() {
    struct project *my_project = create();
    int bool = input(my_project);
    if(bool)
        return 1;
    entering_selection_parameters(my_project);
    return 0;
}