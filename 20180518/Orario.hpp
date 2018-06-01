#ifndef ORARIO_HPP // impedisce che la classe sia inclusa più volte
#define ORARIO_HPP

// Includo quello che mi serve per la classe
// NOTA che cmq questi vengono visti anche nel main
#include <cassert>
#include <iostream>

class Orario {
   friend std::ostream& operator<< (std::ostream&, const Orario&);
   friend std::istream& operator>> (std::istream&, Orario&);
   friend unsigned operator- (const Orario&, const Orario&);

public:
   // costruttori
	Orario(): o(0), m(0), s(0) {}
	Orario(unsigned x, unsigned y, unsigned z) {setOrario(x, y, z);}

   // metodi della classe
	unsigned inSec() const;

   // operatori
	bool operator== (const Orario&) const;
	bool operator>= (const Orario&) const;
	bool operator<= (const Orario& o) const;
	Orario& operator++();
	Orario operator++(int);

private:
   unsigned o, m, s;
   void setOrario (unsigned x, unsigned y, unsigned z);
};

#endif
