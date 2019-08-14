#include "forward_list.hpp"
namespace lib
{

    template<typename T>
    class reverse:private list<T>{
        public:
            reverse():list<T>(){}
            reverse(const std::initializer_list<T> arr):list<T>(arr){
                list<T>::print();
            }    
    };
} // namespace lib
