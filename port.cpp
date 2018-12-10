#include "port.h"

#include <cstring>

Port::Port(const char* br, const char* st, int b) {

	if (!br)
		br = "none";
	if (!st)
		st = "none";

	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);

	std::strncpy(style, st, style_size);
	style[style_size - 1] = '\0';

	bottles = b;
}

Port::Port(const Port& p) {

	*this = p;
}

Port&   Port::operator=(const Port& p) {

	if (this != &p) {

		delete [] brand;
		brand = new char[std::strlen(p.brand) + 1];
		std::strcpy(brand, p.brand);

		std::strncpy(style, p.style, style_size);
		style[style_size - 1] = '\0';

		bottles = p.bottles;
	}

	return *this;
}

Port&   Port::operator+=(int b) {

	bottles += b;

	return *this;
}

Port&   Port::operator-=(int b) {

	if (b >= bottles)
		bottles = 0;
	else
		bottles -= b;

	return *this;
}

void    Port::Show() const {

	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<< (std::ostream& os, const Port& p) {

	os << p.brand << ", " << p.style << ", " << p.bottles;

	return os;
}
