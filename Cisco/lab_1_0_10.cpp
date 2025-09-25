#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder{
private:
    string  item_Name;
    double  item_Price;
    int     item_Orders;

public:
    //Constuctor por defecto para crear el último valor del array
    ShopItemOrder () : item_Name(""), item_Price(0), item_Orders(0){};
    //Sobrecarga del constructor para introducir datos (Se puede borrar, no se usa de momento)
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

// Cargamos los datos en el objeto que corresponde
string  imput_data (ShopItemOrder *Order) {
    string  item_tmp;
    string  cont = "Y";
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
    do {
        cout << "Hay más artículos (Y/N): ";
        cin >> cont;
    } while (cont !="Y" && cont !="N");
    return cont;
}
//Eliminamos y creamos un nuevo array a medida que vamos intoduciendo items de manera dinámica.
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
    double  total_Fact = 0.0;
    string  cont = "Y";
    ShopItemOrder *Order = new ShopItemOrder[num_Order + 1];
    while (cont == "Y"){
        cont = imput_data(&Order[num_Order]);
        Order = new_array(Order, num_Order + 1);
        num_Order++;
    }
    // Impresion de la factura
    cout << "\tFactura Camisería Martín: " << endl << "-----------------------------------------" << endl;
    cout << "Articulo:\t\t\tPrecio:\t\tTotal:" << endl;
    for (int cnt = 0; cnt < num_Order; cnt++){
        cout << Order[cnt].get_itemOrder() << " x " << Order[cnt].get_itemName() << "  ---->  " << Order[cnt].get_itemPrice() << "  ---->  " <<
            Order[cnt].get_itemPrice()*Order[cnt].get_itemOrder() << endl;
        total_Fact += Order[cnt].get_itemPrice()*Order[cnt].get_itemOrder();
    }
    cout << "Total de la Factura: \t\t\t" << total_Fact << endl;
    return 0;
}
