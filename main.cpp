

#include <iostream>
#include <algorithm>
#include <list>

#include "Book.h"
#include "List_of_books.h"
#include "Function.h"

int main(int num, char* params[])
{
    std::string file_one;
    std::string file_output;
    
    

    if (!get_params(num, params, file_one, file_output)) {
        std::cout << "The parameter retrieval is working correctly\n";
        return 0;
    }
    
    execution(file_one, file_output);
    
     
}

