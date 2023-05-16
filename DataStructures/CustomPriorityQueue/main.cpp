#include "PriorityQueue.h"

int main()
{
    PriorityQueue<int, vec::my_vector<int>, std::less<int>> p;
    p.push(5);
    p.push(8);
    p.push(10);
    p.push(2);
    p.push(1);
    p.push(15);
    p.push(25);
    p.print();
}
