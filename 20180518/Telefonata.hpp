/*
Si implementi una classe telefonata che contenga come
dati:
   - l'orario in cui la telefonata è iniziata
   - l'orario in cui è terminata
   - il numero che è stato composto

La classe deve contenere almeno i seguenti metodi:
   - costruttore senza parametri;
   - costruttore che riceve i due orari e il numero;
   - funzioni get e set;
   - operatore==;
   - operatore>=;
   - operatore<<;
   - operatore>>;
*/

#ifndef TELEFONATA_HPP // impedisce che la classe sia inclusa più volte
#define TELEFONATA_HPP

// Includo quello che mi serve per la classe
// NOTA che cmq questi vengono visti anche nel main
#include "Orario.hpp"

class Telefonata {
   friend std::ostream& operator<< (const std::ostream&, const Telefonata&);
   friend std::istream& operator>> (const std::istream&, const Telefonata&);

public:
   // costruttori
   Telefonata();
   Telefonata(const Orario&, const Orario&, int);

   // getter e setter
   const Orario& getInizio() const;
   const Orario& getFine() const;
   int getNum() const; // restituire per valore!
   void setInizio(const Orario&);
   void setInizio();
   void setFine(const Orario&);
   void setFine();
   void setNum(const unsigned&);
   void setNum();

   // metodi della classe
   unsigned durata() const;

   // overload degli operatori
   bool operator== (const Telefonata&) const;
   bool operator>= (const Telefonata&) const;

private:
   Orario inizio, fine;
   unsigned numero;
};

#endif
