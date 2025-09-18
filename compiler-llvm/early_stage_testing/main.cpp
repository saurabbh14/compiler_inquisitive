#include <iostream>
#include "node.h"
extern NBlock* programBlock;
extern int yyparse();

void open_file(const char* filename) {
        // openfile
        freopen(filename, "r", stdin);
}


int main(int argc, char **argv)
{  
    if (argc > 1) {
            open_file(argv[1]);
    }
	
    std::cout << "Hello World " << argc << std::endl;	
    yyparse();
    std::cout << programBlock << std::endl;
    std::cout<<"End World";
    return 0;
}
