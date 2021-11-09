#include <stdlib.h>

#include "../include/header.h"

int main() {
    struct project *my_project = create_project();
    int bool = input_size(my_project);
    if(bool)
        return 1;
    bool = input(my_project);
    if(bool)
        return 1;
    entering_selection_parameters(my_project);
    delete_project(my_project);
    return 0;
}