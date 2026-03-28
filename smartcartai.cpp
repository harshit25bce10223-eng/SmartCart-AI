#include <iostream>
#include <string>

using namespace std;


string item_name[] = {"Milk", "Water", "Butter", "Fruits", "Racket"};
int price_list[] = {30, 100, 60, 50, 2000};
int option_num[] = {1, 2, 3, 4, 5};
int total_items_available = 5;

void additem(string user_bucket[], int &check_cart_size, int cart_price[], int &price_cart_size);
void item_remove(string user_bucket[], int &check_cart_size,int cart_price [], int &price_cart_size);
void update_item(string user_bucket[], int &check_cart_size,int cart_price [], int &price_cart_size);
void user_list(string user_bucket [], int &check_cart_size,int cart_price [], int &price_cart_size);
void total_bill(string user_bucket [], int &check_cart_size,int cart_price [], int &price_cart_size);


void recommend_item(string last_item) {
    cout << "--- Recommended Item ---" << endl;

    if (last_item == "Milk") {
        cout << "You can also buy Butter" << endl;
    }
    else if (last_item == "Fruits") {
        cout << "You can also buy Water" << endl;
    }
    else if (last_item == "Racket") {
        cout << "You can also buy Water bottle " << endl;
    }
    else {
        cout << "Check out other items too!" << endl;
    }
}

void total_bill (string user_bucket [], int &check_cart_size,int cart_price [], int &price_cart_size) {
    int c = check_cart_size;
    cout<<" --- Your Total bill --- "<<endl;
    double total = 0;
    for(int i = 0; i<check_cart_size; i++) {
        cout<< i + 1 << " " <<user_bucket[i] << " - Rs." <<cart_price [i]<<endl;
        int j = cart_price[i];
        total += j;
    }
    cout<<" Total amount = " <<total<<endl;
    double gst = total * 0.18;
    cout<<" Total tax = " <<gst<<endl;
    double total_amount = total + gst;
    cout<<" Total amount (including gst) = " <<total_amount<<endl;
    cout<<" ------ Thanks for Visiting SmartCart AI ------"<<endl;
}

void update_item (string user_bucket[], int &check_cart_size,int cart_price [], int &price_cart_size) {
    int item;
    int n = total_items_available; 
    int item_replace;
    do {
        cout << "  ---- Your Current Bucket ----  " << endl;
        for (int i = 0; i<check_cart_size; i++) {
        cout<< i+1 << ". " << user_bucket[i] << " - Rs." << cart_price[i] <<endl;
    }
        cout<<" --- Please select the item you want to replace --- ";
        cin>>item;

        if (item == 0) break;

        if (item > 0 && item <= check_cart_size) {
            for (int i = 0; i<n ; i++) {
                cout<< option_num[i] << ". " << item_name[i] << " - Rs. "<<price_list[i] <<endl;
            }
            cout<<" Please select '0' to go back to menu "<<endl;
            cout<<"Please select the item to replace with : ";
            cin>>item_replace;

            if (item_replace == 0) break;

            if (item_replace > 0 && item_replace <= n) {
                user_bucket [item-1] = item_name [item_replace - 1];
                cart_price [item-1] = price_list [item_replace - 1];
                cout<<" --- Item updated successfully --- "<<endl;
            }
            else {
                cout<<" --- Please choose the correct option --- "<<endl;
            }
        }
        else {
            cout<<" --- Please choose the correct option --- "<<endl;
        }
}
    while (true);

}

void item_remove (string user_bucket[], int &check_cart_size,int cart_price [], int &price_cart_size) { 
    
    int items_deleted_count = 0;
    int option;
    
do {
    if (check_cart_size == 0) {
        cout<<"Cart is now empty. Returning to menu..."<<endl;
        break;
    }

    cout << "  ---- Your Current Bucket ----  " << endl;
    for (int i = 0; i<check_cart_size; i++) {
        cout<< i+1 << ". " << user_bucket[i] << " - Rs." << cart_price[i] <<endl;
    }
        cout<<" Please select '0' to go back to menu "<<endl;
        cout<<" Please select the option of item you want to delete : "<<endl;
        cin>>option;

        if (option == 0) {
            if (items_deleted_count > 0) {
                cout<<items_deleted_count << " Items removed"<<endl;
            }
            break;
        }        

        if (option > 0 && option <= check_cart_size) {
            int index_to_delete = option - 1;
            for (int z = index_to_delete; z<check_cart_size-1; z++) {
                user_bucket [z] = user_bucket[z+1];
                cart_price[z] = cart_price[z + 1];
            } 
            cout << " -- Item removed successfully! -- " << endl;
            price_cart_size--;
            check_cart_size--; 
            items_deleted_count++;
        }
        else {
            cout<<" --- Invalid option --- "<<endl;
        }
}
 while (true);
}

 
void additem(string user_bucket[], int &check_cart_size, int cart_price[], int &price_cart_size) {
    int option;
 do {
        cout << " --- Available Items ---" << endl;
        for (int i = 0; i<total_items_available ; i++) {
            cout<< option_num[i] << ". " << item_name[i] << " - Rs. "<<price_list[i] <<endl;
        }
            cout<<"Option Choosed : ";
            cin>>option;

            if (option == 0) break;

            if(option >= 1 && option <= total_items_available) {
                cout << " --- Item added successfully --- "<<endl;
                user_bucket [check_cart_size] = item_name [option - 1];
                cart_price [price_cart_size] = price_list[option - 1];
                recommend_item(item_name[option - 1]);
                check_cart_size++;
                price_cart_size++;
            }
            else {
                cout << " --- Invalid input, Please select again --- "<<endl;
            }
        } 
        while(true);
} 


 
void user_list (string user_bucket [], int &check_cart_size, int cart_price [], int &price_cart_size) {                                        
        string list_oper [] = {"Add Item","Remove Item", "Update Item","Checkout to pay", "Exit"};
        int num;
    do {
       for(int i =0; i<5; i++) {
            cout<< i+1 << ". " << list_oper[i] <<endl;
       }
        cout<<"Enter the option to choose = ";
        cin>>num;

        if(num == 1) {
            additem (user_bucket,check_cart_size, cart_price, price_cart_size);
        }
        else if (num == 2) {
            if (check_cart_size != 0) {
                item_remove(user_bucket,check_cart_size, cart_price, price_cart_size);
        }
            else {
                cout<<"   --- Your cart is empty ---   "<<endl;
            }
            }
        else if (num == 3) {
            if (check_cart_size != 0) {
                update_item (user_bucket,check_cart_size, cart_price, price_cart_size);
            }
            else {
                cout<<"   --- Your cart is empty ---   "<<endl;
            }
        }
        else if (num == 4){
            if (check_cart_size != 0){
                total_bill (user_bucket,check_cart_size, cart_price, price_cart_size);
                cout<<"     ----- Thank you for choosing us -----     "<<endl;
                break;
        }
        else {
            cout<<" --- Cart is empty --- "<<endl;
        }
        }
        else if (num==5) {
            cout<<"     ----- Thank you for choosing us -----     "<<endl;
        }
        else {
            cout<<" --- Please select the correct option --- "<<endl;
        }
} 
    while(num != 5);

}


int main () {                    
    cout<<" ----------- Welcome to SmartCart AI ----------"<<endl;
    string user_bucket[100];
    int cart_price[100];
    int check_cart_size = 0;
    int price_cart_size = 0;

    user_list(user_bucket, check_cart_size, cart_price, price_cart_size);

    return 0;
}