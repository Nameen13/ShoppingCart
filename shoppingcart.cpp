#include<iostream>
#include "product.h"
#include<vector>

using namespace std;

vector<Product> allProducts = {
    Product(1,"apple",20),
    Product(2,"banana",12),
    Product(3,"mango",50),
    Product(4,"guava",90),
    Product(5,"strawberry",60),
    Product(6,"watermelon",55),
};

bool checkout(cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in cash :";
    
    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change :"<<paid-total<<endl;
        cout<<"Thankyou for Shopping";
        return true;
    }
    else{
        cout<<"Not enough Cash";
        return false;
    }
}

Product * ChooseProduct(){
    string productList;
    cout<<"List of all product: "<<endl;

    for(auto product : allProducts){
        productList.append(product.getDisplayName());
    }
    cout<< productList <<endl;

    cout<<"------------"<<endl;
    string choice;
    cin>>choice;

    for(int i = 0; i<allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<" Product Not Found! "<<endl;
    return NULL;

}

int main(){
    
    char action;
    cart cart;

    while(true){

        cout<<"Select an action - {a}dd item, {v}iew item, {c}heckout" <<endl;
        cin>>action;

        if(action == 'a'){

            Product *product = ChooseProduct();
            if(product!=NULL){
                cout<<"Added to cart "<< product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }

            
        }
        else if(action=='v'){

            cout<<"------------"<<endl;
            cout<< cart.viewCart();
            cout<<"------------"<<endl;


        }
        else{
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }

    }


    return 0;
}