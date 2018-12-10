#include "vintage_port.h"

#include <cstring>

VintagePort::VintagePort(): Port("none", "vintage"), nickname(strdup("none")), year(0) {}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y):
	Port(br, "vintage", b),
	nickname(strdup(nn)),
	year(y) {}

VintagePort::VintagePort(const VintagePort& vp) {

	*this = vp;
}

VintagePort&    VintagePort::operator=(const VintagePort& vp) {

	if (this != &vp) {

		Port::operator=(vp);

		delete [] nickname;
		nickname = strdup(vp.nickname);
		year = vp.year;
	}

	return *this;
}

void VintagePort::Show() const {

	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
	Port::Show();
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {

	os << vp.nickname << ", " << vp.year << ", ";
	os << static_cast<const Port&>(vp);

	return os;
}
