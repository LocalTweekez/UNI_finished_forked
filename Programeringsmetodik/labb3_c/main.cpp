#include <iostream>
#include "p_queue.cpp"
#include <string>



struct order
{
    std::string name;
    int price;
};

struct compareOrderPrice{
    bool operator()(const order& lhs, const order& rhs){
        return lhs.price < rhs.price;
    }
};

int randPrice() {
    return std::rand() % 16 + 15;
}


template<class T>
void tradeDeals(p_queue<T,compareOrderPrice>& buy_orders, p_queue<T,compareOrderPrice>& sell_orders) {
    while (!buy_orders.empty()) {
        if (buy_orders.begin()->price < sell_orders.begin()->price) {
            buy_orders.pop();
        }
        else {
            std::cout << buy_orders.begin()->name << " bought for (" << buy_orders.begin()->price <<
                      "), sold by " << sell_orders.begin()->name << " for the price of (" << sell_orders.begin()->price
                      << ")\n";

            buy_orders.pop();
            sell_orders.pop();
        }
    }
}

int main() {

    p_queue<order,compareOrderPrice> buyords;
    p_queue<order,compareOrderPrice> sellorders;

    std::string jva = "Joakim Von Anka",
            ep = "Erik Pendel",
            jw = "Jarl Wallenburg";


    buyords.push({ jva, randPrice() });
    buyords.push({ jva, randPrice() });
    buyords.push({ jva, randPrice() });
    sellorders.push({ jva, randPrice() });
    sellorders.push({ jva, randPrice() });
    sellorders.push({ jva, randPrice() });
    sellorders.push({ jva, randPrice() });

    buyords.push({ ep, randPrice() });
    buyords.push({ ep, randPrice() });
    buyords.push({ ep, randPrice() });
    buyords.push({ ep, randPrice() });
    sellorders.push({ ep, randPrice() });
    sellorders.push({ ep, randPrice() });
    sellorders.push({ ep, randPrice() });

    buyords.push({ jw, randPrice() });
    buyords.push({ jw, randPrice() });
    buyords.push({ jw, randPrice() });
    sellorders.push({ jw, randPrice() });
    sellorders.push({ jw, randPrice() });
    sellorders.push({ jw, randPrice() });
    sellorders.push({ jw, randPrice() });


    buyords.print();
    std::cout << "---------------" << std::endl;
    sellorders.print();
    std::cout << "---------------" << std::endl;

    tradeDeals(buyords, sellorders);

    return 0;
}

