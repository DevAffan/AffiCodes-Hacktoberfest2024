#include<iostream>
#include<memory> // for std::shared_ptr


class UDT{
    public:
        // Constructor ( Called on creation)
        UDT(){std::cout << "UDT Created " << '\n';}
        // Destructor (Called on destruction)
        ~UDT(){std::cout << "UDT Destroyed" << '\n';}
};



int main(){

    // Creating a shared pointer
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    {
        // Then in new block , I share the resource 
    std::shared_ptr<UDT> ptr2 = ptr1;
        // Our reference count is updated
    std::cout << "usecount : " << ptr2.use_count() << std::endl;
    } // ptr2 is 'freed'

    // Then we check our updated reference count
    std::cout << "usecount : " << ptr1.use_count() << std::endl;




    return 0;
}
