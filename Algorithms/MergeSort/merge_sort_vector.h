#ifndef MERGE_SORT_VECTOR
#define MERGE_SORT_VECTOR
#include <vector>

template<typename T>
void merge_vector(std::vector<T>&, int, int, int );

template<typename T>
void merge_sort_vector(std::vector<T>&, int, int);

template<typename T>
void set_data_vector(std::vector<T>&);

template<typename T>
void get_data_vector(std::vector<T>&);

#include "impl.hpp"
#endif //MERGE_SORT_VECTOR
