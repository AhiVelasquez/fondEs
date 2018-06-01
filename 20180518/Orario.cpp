#include "Orario.hpp"
// Metodi della classe che non ho impelementato in Orario.h

void Orario::setOrario(unsigned x, unsigned y, unsigned z) {
	assert(x<=23 && y<=59 && z<=59);
	o = x; m = y; s = z;
}

std::ostream& operator<< (std::ostream& o, const Orario& O) {
	o << O.o << ":" << O.m << ":" << O.s;
	return o;
}

std::istream& operator>> (std::istream& i, Orario& O) {
	i >> O.o >> O.m >> O.s;
   // assert(O.o<=23 && O.m<=59 && O.s<=59);
   assert(O.o>=0 && O.m>=0 && O.s>=0); // c'è bisogno perchè sono unsigned (?) e in qualche modo, qualcuno, gestisce l'eccezione
	return i;
}

bool Orario::operator== (const Orario& O) const {
	return (o == O.o && m == O.m && s == O.s);
}

bool Orario::operator<= (const Orario& o) const {
	return inSec() <= o.inSec();
}

bool Orario::operator>= (const Orario& o) const {
	return inSec() >= o.inSec();
}

Orario& Orario::operator++ () {
	if(o==23) o = 0;
	else o++;

	return *this;
}

Orario Orario::operator++ (int) {
	Orario T(*this);
	if (o==23) o = 0; else o++; return T;
}

unsigned operator- (const Orario& o1, const Orario& o2) {
	assert(o1 >= o2);
	unsigned A = o1.o * 3600 + o1.m * 60 + o1.s;
	unsigned B = o2.o * 3600 + o2.m * 60 + o2.s;
	return A-B;
}

unsigned Orario::inSec() const {
   if(o == 0 && m == 0 && s == 0) return 0;
	return o * 3600 + m * 60 + s;
}
