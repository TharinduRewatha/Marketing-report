/*Write a program to manages sales in a store.
Each time an item is sold we need to record the item value and quantity.
At the end of the day we need to generate a sales report like shown below,
Use functions for abstraction
(Note that total sales should be displayed with , )


Daily Sales Report
------------------
55.00 X 6
794.50 X 20
200.00 X 6
976.95 X 2
...

Total sales = 1,974,490.50

*/
#include <iostream>
#include <iomanip>

using namespace std;

float saleValues[1000];
unsigned short qty[1000];
unsigned short storeAt = 0;

void getSalesInput();
void genarateSalesReport();
float calcSalesTotal();

int main(){
    
    
    getSalesInput();
    genarateSalesReport();

    return 0;
}

void getSalesInput(){
    cout << "== Sales Management System ==" << endl;
    cout << "Enter sales details. Enter 0 as sales value to exit." << endl;
    
    while(true){
        
        cout << endl << "Enter sale value : ";
        cin >> saleValues[storeAt];
        
        if(saleValues[storeAt] == 0) break;
        
        cout << "Enter qty : ";
        cin >> qty[storeAt];
        
        storeAt++;
        
    }
    
}

void genarateSalesReport(){
    
    cout << endl << "-- Daily Sales Report --" << endl;
    
    for(int i = 0 ; i < storeAt; i++){
        cout << "[" << i + 1 << "] " << saleValues[i] << " X " << qty[i] << endl;
    }
    
    cout.imbue(locale(""));
    cout << "Total Sales (LKR) " << fixed << setprecision(2) << setfill('0') << calcSalesTotal() << endl;
    
}

float calcSalesTotal(){
    
    float total = 0;
    
    for(int i = 0; i < storeAt; i++){
        total += saleValues[i] * qty[i]; 
    }
    
    return total;
    
}

