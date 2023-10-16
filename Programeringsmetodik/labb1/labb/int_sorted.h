#ifndef INT_SORTED
#define INT_SORTED

#include <cstdlib>
#include "int_buffer.h"
class int_sorted {
private:
	int_buffer buf;

public:
	int_sorted(const int* source, size_t size);
	size_t size() const;
	void insert(int value);
	const int* begin() const;
	const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;
	int_buffer getBuf();
	bool checkIfSorted();
	int_sorted sort(const int* begin, const int* end);
	void print();
	
};

#endif