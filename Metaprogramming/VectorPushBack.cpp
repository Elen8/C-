#include <iostream>
#include <vector>

template <typename T, typename... Args>
void push_back_values(std::vector<T>& vec, Args&&... args)
{
    //fold expression
    (vec.push_back(std::forward<Args>(args)), ...);
}

int main()
{
    std::vector<int> myVec;
    push_back_values(myVec, 1, 5, 7, 9, 12);


    std::cout << "Vector elements: ";
    for (const auto& value : myVec)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
