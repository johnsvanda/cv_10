//
// Created by svandaj on 24.11.2021.
//

#ifndef CV_10_ZASOBNIK_H
#define CV_10_ZASOBNIK_H


#include <string>

struct Element {
    std::string top;
};

typedef Element * UkElement;

Element pop();
void push(Element elToPush);



#endif //CV_10_ZASOBNIK_H
