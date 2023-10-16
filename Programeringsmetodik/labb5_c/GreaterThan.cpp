#include "GreaterThan.h"

bool GreaterThan::operator()(const laptop& obj) {
    return(obj.getMemory() > value);
}