#include <iostream>

#include "port.h"
#include "vintage_port.h"

int main() {

	std::cout << "~~~~~Port~~~~~" << std::endl;
	std::cout << "Port object" << std::endl;

	Port    port;

	std::cout << port << std::endl;
	port.Show();

	Port    copy = port;
	copy += 15;

	std::cout  << std::endl << "Changed copy of the object" << std::endl;
	std::cout << copy << std::endl;

	std::cout << std::endl << "~~~~~Vintage port~~~~~" << std::endl;

	VintagePort   vintage_port;

	std::cout << "Vintage port object" << std::endl;

	std::cout << vintage_port << std::endl;
	vintage_port.Show();

	VintagePort     vp_copy(vintage_port);
	vp_copy += 120;

	std::cout << std::endl << "Changed copy of the object" << std::endl;
	std::cout << vp_copy << std::endl;

	return 0;
}