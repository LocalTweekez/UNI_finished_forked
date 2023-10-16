//
// Created by tahak on 8/17/2023.
//

#ifndef LABB5_C_MYFUNC_H
#define LABB5_C_MYFUNC_H


class MyFunc {
public:
    MyFunc(double mean);
    double mean;
    double operator()(double xi);
};


#endif //LABB5_C_MYFUNC_H
