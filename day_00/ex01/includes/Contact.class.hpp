#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <ctime>

class Contact
{
public:
  Contact();
  ~Contact(void);

  void addInst(void);
  static int getNbInst(void);
  void display(void);

  std::string getFirstName(void) const;
  std::string getLastName(void) const;
  std::string getNickname(void) const;
  std::string getLogin(void) const;
  std::string getPostalAddress(void) const;
  std::string getEmailAddress(void) const;
  std::string getPhoneNumber(void) const;
  struct std::tm getBirthdayDate(void) const;
  std::string getFavoriteMeal(void) const;
  std::string getUnderwearColor(void) const;
  std::string getDarkestSecret(void) const;

  void setFirstName(void);
  void setLastName(void);
  void setNickname(void);
  void setLogin(void);
  void setPostalAddress(void);
  void setEmailAddress(void);
  void setPhoneNumber(void);
  void setBirthdayDate(void);
  void setFavoriteMeal(void);
  void setUnderwearColor(void);
  void setDarkestSecret(void);

private:
  static int _nbInst;

  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _login;
  std::string _postalAddress;
  std::string _emailAddress;
  std::string _phoneNumber;
  struct std::tm _birthdayDate;
  std::string _favoriteMeal;
  std::string _underwearColor;
  std::string _darkestSecret;
};

#endif //CONTACT_CLASS_HPP
