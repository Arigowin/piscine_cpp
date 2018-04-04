#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook
{
public:
  Contact contact[8];

  PhoneBook(void);
  ~PhoneBook(void);

  void add(void);
  void search(void);

private:
  void _shortDisplayContacts(void);
  void _formatString(std::string str);
};

#endif //PHONEBOOK_CLASS_HPP
