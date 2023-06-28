/*
9.  Write a function that given two vector<double>s price and weight computes a value (an “index”) that
    is the sum of all price[i]*weight[i]. Make sure to have weight.size()==price.size()
10. Write a function maxv() that returns the largest element of a vector
    argument.
11. Write a function that finds the smallest and the largest element of a vector
    argument and also computes the mean and the median. Do not use global variables.
    Either return a struct containing the results or pass them back 
    through reference arguments. Which of the two ways of returning several 
    result values do you prefer and why?
*/


#include "../../std_lib_facilities.h"

struct product
{
    vector<double> price;
    vector<double> weight;
    vector<string> name;
    product(vector<double> p, vector<double> w, vector<string> n) :price(p),weight(w), name(n) {}
};

void sumOfTwoVec(const vector<double>& price, const vector<double>& weight);
void sumOfProduct(const product prod);
void maxPriceV(const product prod);
void minPriceV(const product prod);
void meanofProd(const product prod);
void medianofProd(const product prod);
void printProd(const product prod, string label, double val);

int main(){

    vector<double> price = {10.29,20.2,20.9,30.2,50.3};
    vector<double> weight = {3,2,5,3,5};
    vector<string> name = {"shirt", "hat", "swimsuit", "shooes", "jeans"};
    sumOfTwoVec(price, weight);

    if(price.size() != weight.size()){
        cout<<"Error, not same size";
    }
    product shopProd(price, weight, name);
    sumOfProduct(shopProd);
    maxPriceV(shopProd);
    minPriceV(shopProd);
    meanofProd(shopProd);
    medianofProd(shopProd);
}


void minPriceV(const product prod){
    double minVal = 0;
    string label = "Smallest";
    for (size_t i = 0; i < prod.price.size(); i++){
        for (size_t k = 0; k < prod.price.size(); k++)
        {
            if(prod.price[i]<prod.price[k]){
                minVal = prod.price[i];
            }
        }
    }
    printProd(prod, label, minVal);
}

void printProd(const product prod, string label, double val){
    for (size_t i = 0; i < prod.price.size(); i++)
    {
        if (val == prod.price[i])
        {
            cout<<label<<" price is "<<prod.name[i]<<" with a price of "<<prod.price[i]<<'\n';
        }
    }
}

void maxPriceV(const product prod){
    double maxVal = 0;
    string label = "Largest";
    for (size_t i = 0; i < prod.price.size(); i++){
        for (size_t k = 0; k < prod.price.size(); k++)
        {
            if(prod.price[i]>prod.price[k]){
                maxVal = prod.price[i];
            }
        }
    }
    printProd(prod, label, maxVal);
}

void sumOfProduct(const product prod){
    double sum = 0;
    for(size_t i = 0; i < prod.price.size(); i++){
        sum += prod.price[i]*prod.weight[i];
    }
    cout<<"The sum is "<<sum<<'\n';
}

void meanofProd(const product prod){
    double mean = 0;
    double sum = 0;
    for(size_t i = 0; i < prod.price.size(); i++){
        sum += prod.price[i];
    }
    mean = sum/prod.price.size();
    cout<<"The mean is "<<mean<<'\n';
}


void sumOfTwoVec(const vector<double>& price, const vector<double>& weight){
    if(price.size() != weight.size()) 
        cout<<"Error, not same size\n";
    double sum = 0;
    for(size_t i = 0; i < price.size(); i++){
        sum += price[i]*weight[i];

    }
    cout<<"The sum is = "<<sum<<'\n';
}