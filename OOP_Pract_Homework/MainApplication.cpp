/* TESTING GROUND */

#include <iostream>
#include "Store.h"
#include "Client.h"
#include "Device.h"
#include "Test.h"

int main()
{
	Store store;
	Client client("Uncle Bob", "deltasix", 500.0f);
	Product product("This product is undefined", 50.0f, 30.0f);
	Test one;

	/* WORK IN PROGRESS:
	store.addProduct(&product);
	client.addToCart(&product);
	client.printClientInfo();
	client.printCartProducts();
	...
	*/
	
	/* IF NEEDED:
	system("pause");
	*/

	return 0;
}