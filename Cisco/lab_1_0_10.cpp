#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder{
private:
    string  item_Name;
    double  item_Price;
    int     item_Orders;

public:
    ShopItemOrder () : item_Name(""), item_Price(0), item_Orders(0){};

    ShopItemOrder(string in, double pri, int num): item_Name(in), item_Price(pri), item_Orders(num) {
    }
    void set_itemName(string name) {
        item_Name = name;
    }
    void set_itemPrice(double price) {
        item_Price = price;
    }
    void set_itemOrder(int orders) {
        item_Orders = orders;
    }
    string get_itemName(){
        return item_Name;
    }
    double get_itemPrice(){
        return item_Price;
    }
    int get_itemOrder(){
        return item_Orders;
    }
};

struct tmp_order {
    string  cont;
    string  itemNam;
    double  itemPric{};
    int     itemOrde{};
};

// void    imput_data (tmp_order *order) {
//     cout << "Articulo: ";
//     cin >> order->itemNam;
//     cout << endl;
//     cout << "Precio: ";
//     cin >> order->itemPric;
//     cout << endl;
//     cout << "Unidades: ";
//     cin >> order->itemOrde;
//     cout << endl;
//     do {
//         cout << "Hay mas productos (Y/N): ";
//         cin >> order->cont;
//     }while (order->cont != "Y" && order->cont !="N");
//     cout << endl;
// }

void    imput_data (ShopItemOrder *Order) {
    string  item_tmp;
    double  price_tmp;
    int     order_tmp;
    cout << "Articulo: ";
    cin >> item_tmp;
    Order->set_itemName(item_tmp);
    cout << "Precio: ";
    cin >> price_tmp;
    Order->set_itemPrice(price_tmp);
    cout << "Cantidad: ";
    cin >> order_tmp;
    Order->set_itemOrder(order_tmp);
}

ShopItemOrder* new_array (ShopItemOrder *Order, int items) {
    auto* NewArray = new ShopItemOrder[items + 1];
    int cnt = 0;
    while (cnt < items){
        NewArray[cnt] = Order[cnt];
        cnt ++;
    }
    NewArray[cnt] = ShopItemOrder();
    delete[] Order;
    return NewArray;
}

int main (){
    int     num_Order = 0;
    string  cont = "Y";
    tmp_order item_Temporal;
    item_Temporal.cont = "Y";
    ShopItemOrder *Order = new ShopItemOrder[num_Order + 1];
    while (item_Temporal.cont == "Y") {
        imput_data(&Order[num_Order]);
//        Order[num_Order] = ShopItemOrder(item_Temporal.itemNam,item_Temporal.itemPric,item_Temporal.itemOrde);
        cout << "Datos introducidos: " << Order[num_Order].get_itemName() << "\t" << Order[num_Order].get_itemPrice() << "\t" <<
                Order[num_Order].get_itemOrder() << endl;
        Order = new_array(Order, num_Order + 1);
    }
    return 0;
}
