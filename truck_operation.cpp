#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

 
class truck 
 { 
string name;
  
int quantity;
  
int weight;
  
static int tot_weight;		// Static member variable for total weight
  static int tot_quantity;		// Static member variable for total quantity

public: 
truck ():quantity (0), weight (0) 
	{ 
cout << "Enter the product name: " << endl;
	
cin >> name;
	
cout << "Enter the quantity of the product: " << endl;
	
cin >> quantity;
	
cout << "Enter the weight of the product: " << endl;
	
cin >> weight;
  
} 
 
bool add_product () 
 { 
const int max_quantity_limit = 500;	
	if (tot_weight < 500 && (tot_weight + (quantity * weight) <= 500)
		&& (tot_quantity + quantity <= max_quantity_limit))
	  
	  {
		
tot_weight += quantity * weight;
		
tot_quantity += quantity;
		
cout << "The product details added successfully" << endl;
		
return true;
	  
}
	
cout <<
	  "The product details not added due to overweight or quantity limit exceeded"
	  << endl;
	
return false;
  
}
	
 
bool remove_product () 
 { 
if (tot_quantity > 0)
		
{
tot_weight -= quantity * weight;
		  
tot_quantity -= quantity;
		  
cout << "The product details removed successfully" << endl;
		  
return true;
		  
}
		  
cout <<
		  "The product details not removed due to no products in the truck" <<
		  endl;
		  
return false;
		  
}
		  
 
void display () 
 { 
cout << name << " ";
		  
cout << quantity << " ";
		  
cout << weight << " ";
		  
cout << quantity * weight << endl;
		  
} 
 
static int getTotWeight () 
 { 
return tot_weight;
		  
}
		  
 
static int getTotQuantity () 
 { 
return tot_quantity;
		  
}
		  
 
static bool isPrime (int n) 
		  { 
if (n <= 1) 
		  return false; 
for (int i = 2; i <= sqrt (n); i++) 
		  { 
if (n % i == 0) 
 return false; 
}
		  
return true; 
}
		  
};

		  
 
// Initialize static members
int truck::tot_weight = 0; 
int truck::tot_quantity = 0; 
 
int main () 
 { 
vector < truck > products; 
int option; 
int test_case; 
 
cout << "Enter the number of test cases: "; 
cin >> test_case; 
 
while (test_case--)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Display products" << endl;
        cout << "4. Check if the total quantity is prime or not" << endl;
        cout << "5. Check if there are at least 3 products with a total weight equal to 500" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            truck product;
            if (product.add_product())
            {
                products.push_back(product);
            }
            break;
        }
        case 2:
            if (products.size() > 0)
            {
                cout << "Removing a product:" << endl;
                products.back().remove_product();
                products.pop_back();
            }
            else
            {
                cout << "No products to remove." << endl;
            }
            break;
        case 3:
            cout << "Displaying products:" << endl;
            for (int i = 0; i < products.size(); i++)
            {
                products[i].display();
            }
            break;
        case 4:
            if (truck::isPrime(truck::getTotQuantity()))
            {
                cout << "The final quantity is a prime number." << endl;
            }
            else
            {
                cout << "The final quantity is not a prime number." << endl;
            }
            break;
        case 5:
            if (products.size() >= 3 && truck::getTotWeight() == 500)
            {
                cout << "There are at least 3 products with a total weight equal to 500." << endl;
            }
            else
            {
                cout << "There are not enough products or the total weight is not equal to 500." << endl;
            }
            break;
        default:
            cout << "Invalid option. Please enter a valid choice." << endl;
            break;
        }
    }

    return 0;
}

		   
