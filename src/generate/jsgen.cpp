#include <iostream>


class Program {
public:
    void print(std::ostream& out) {
        out << "var x = 1" << std::endl;
        out << "(function foo() { return x++; })();" << std::endl;
    };
};



int main(int argc, char* argv[]) {
    
    std::cout << "JSmith" << std::endl;
    
    // Read parameters on how random/how large etc
    
    // Intantiate new random program, and print it to stdout (or to file)
    
    (new Program())->print(std::cout);
    
    return 0;
}






