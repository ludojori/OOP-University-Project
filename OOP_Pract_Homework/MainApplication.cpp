/* (!)THIS IS CURRENTLY A TESTING GROUND(!) 

Note:
Main interface coming soon!

*/

#include <iostream>
#include "Store.h"

int main()
{
	Product product1("Product1", 53, 2),
		product2("Product2", 12, 4),
		product3("Product3", 98.5, 3);
	Device device1("ASUS", "TUF504", "Asus", "Device1", 804.3, 8.3),
		device2("ACER", "ASPIRE", "Acer", "Device2", 632.2, 5.3),
		device3("HP", "HPSeriesModel", "HP", "Device3", 542.6, 3.2);
	Book book1,
		book2,
		book3;
	Food food1,
		food2,
		food3;
	Accessory accessory1,
		accessory2,
		accessory3;

	Client client("Boris Slav", "password", 3000);
	client.addToCart(&product1).addToCart(&product2).addToCart(&device1).addToCart(&product3);
	client.printCart();
	client.payProducts();
	
	Store store;
	store.addProduct(&device1).addProduct(&device2).addProduct(&device3).addProduct(&product1);
	store.printByCategory(Product::Category::DEVICE);

	/* IF NEEDED:
	system("pause");
	*/

	return 0;
}