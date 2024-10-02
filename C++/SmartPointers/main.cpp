#include<iostream>
#include<memory> // for std::unique_ptr


class UDT{
    public:
        // Constructor ( Called on creation)
        UDT(){std::cout << "UDT Created " << '\n';}
        // Destructor (Called on destruction)
        ~UDT(){std::cout << "UDT Destroyed" << '\n';}
};


int main(){

    // UDT dev;
    std::make_shared<UDT>&&(new UDT);

    // we can also do this by unique_ptr
    // Creating one unique pointer
    std::unique_ptr<UDT> dev = std::unique_ptr<UDT>(new UDT);

    // We're allowed to 'move' a unique pointer
    // But we cannot 'copy' the unique pointer
    std::unique_ptr<UDT> k = std::move(dev);



    // Creating 'array' that is pointed to one unique pointer
    // std::unique_ptr<UDT[]>dev_array = std::unique_ptr<UDT[]>(new UDT[10]);

    // The equivalent , to the line above is:
    // this is more prefered syntax
    std::unique_ptr<UDT[]>dev_array = std::make_unique<UDT[]>(10);

    return 0;
}