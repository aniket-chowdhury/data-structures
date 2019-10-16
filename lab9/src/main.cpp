#include "print.hpp"
#include "binary_tree.hpp"
#include <string>
#include <iostream>
#include <utility>
#include "nodes.hpp"

template<typename first,typename second>
std::ostream& operator << (std::ostream& os,const std::pair<first,second> p)
{
    os << p.first << " " << p.second << "";
    return os;
}



int main(int argc, char *argv[])
{
    lib::print("");


    lib::BST<std::pair<std::string,int>> b;
    b.insert(std::make_pair<std::string,int>("Biren",18));
    b.inorder();
    lib::print("\n");


    b.insert(std::make_pair<std::string,int>("Ram_Kishan",36));
    b.inorder();
    lib::print("\n");

    b.insert(std::make_pair<std::string,int>("Johny_Dep",56));
    b.inorder();
    lib::print("\n");

    b.insert(std::make_pair<std::string,int>("Abbi_Narayan_singh",23));
    b.inorder();
    lib::print("\n");
    lib::print("\n");
    
    
    lib::BST b1({1,10,3,2,6,5});
    lib::print("Preorder =");
    b1.postorder();
    lib::print("\n");


    lib::print("Postorder =");
    b1.preorder();
    lib::print("\n");

    lib::print("Maximum =");
    b1.maximum();
    lib::print("\n");
    
    lib::print("Sum =");
    lib::print(b1.add()); 
    lib::print("\n");
    return 0;
}

