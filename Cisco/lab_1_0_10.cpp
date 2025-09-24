#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder{
private:
    string item_Name;

public:
    ShopItemOrder(string in): item_Name(in) {
        cout << "El constructor ha asignado in:" << in << " a la variable item_Name: " << item_Name << endl;
    }
    void get_ItemName() {
        cout << "El nombre del Item es: " << item_Name << endl;
    }

};

int main (){
    ShopItemOrder item1("Camiseta");
    item1.get_ItemName();
    return 0;
}
