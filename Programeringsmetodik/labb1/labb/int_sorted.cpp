#include "int_sorted.h"
#include "iostream"



int_sorted::int_sorted(const int* source, size_t t_size): 
	buf(int_buffer(source, t_size)) {

	if(size() >1 )
		sort(begin(), end());


};
size_t int_sorted::size() const {

	return buf.size();
};

void int_sorted::insert(int value) {
	int_sorted temp(&value, 1);
	*this = merge(temp);
};

int_buffer int_sorted::getBuf()
{
	return buf;
}

bool int_sorted::checkIfSorted(){
	int* next = buf.begin();
	int a = *buf.begin();
	while (++next != buf.end()) {
		int b = *next;
		if (a > b) {
			std::cout << "is not sorted" << std::endl;
			return false;
		}
		a = b;
	}
	std::cout << "sorted!" << std::endl;
	return true;
}


void int_sorted::print(){
	buf.print();
}



int_sorted int_sorted::sort(const int* begin, const int* end){
	if (begin == end) return int_sorted(nullptr, 0);

	if (begin == end - 1) return int_sorted(begin, 1);
	
	ptrdiff_t half = (end - begin) / 2;

	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));
}





const int* int_sorted::begin() const {
	return buf.begin();
};

const int* int_sorted::end() const {
	return buf.end();
};



int_sorted int_sorted::merge(const int_sorted& merge_with) const {
	size_t cSize = this->size() + merge_with.size();
	size_t index = 0;
	int_buffer c = int_buffer(cSize);
	auto A = this->begin();
	auto B = merge_with.begin();


	while (A != this->end() && B != merge_with.end()) {
		int a = *A;
		int b = *B;
		if (a < b) {
			c[index] = a;
			A++;
		}
		else {
			c[index] = b;
			B++;
		}
		index++;
	}
	while (A != this->end()) {
		int a = *A;
		c[index] = a;
		index++;
		A++;
	}
	while (B != merge_with.end()) {
		int b = *B;
		c[index] = b;
		index++;
		B++;
	}
	int_sorted C(nullptr, 0);
	C.buf = c;
	return C;
};

