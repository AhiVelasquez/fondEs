#include "Telefonata.hpp"

// costruttori
Telefonata::Telefonata(): inizio(), fine(), numero(0) {} //cosi richiama il costruttore senza parametri di Orario.h
Telefonata::Telefonata(const Orario& i, const Orario& f, int n): inizio(i), fine(f), numero(n) {}

// getter e setter
const Orario& Telefonata::getInizio() const { return inizio; }
const Orario& Telefonata::getFine() const { return fine; }
int Telefonata::getNum() const { return numero; }
void Telefonata::setInizio(const Orario& newI) { assert(newI <= fine); inizio = newI; }
void Telefonata::setInizio() { std::cin >> inizio; assert(inizio <= fine);}
void Telefonata::setFine(const Orario& newF) { assert(newF >= inizio); fine = newF; }
void Telefonata::setFine() { std::cin >> fine; assert(fine >= inizio); }
void Telefonata::setNum(const unsigned& newNum) { numero = newNum; }
void Telefonata::setNum() { std::cin >> numero; assert(numero >= 0);}

// metodi della classe
unsigned Telefonata::durata() const {
   return fine.inSec() - inizio.inSec();
}

// overload degli operatori
bool Telefonata::operator== (const Telefonata& key) const {
   return (inizio == key.inizio && fine == key.fine && numero == key.numero);
}
bool Telefonata::operator>= (const Telefonata& key) const {
   return (inizio >= key.inizio && fine >= key.fine && numero >= key.numero);
}
