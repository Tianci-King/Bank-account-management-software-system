//
// Created by 16415 on 2023/5/22.
//

#ifndef PROJECT_ABS_ACCOUNT_H
#define PROJECT_ABS_ACCOUNT_H

#include <string>
#include <iostream>
#include <regex>
#include <ctime>
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;



class Account {
public:
    Account();

    virtual ~Account();

    Account(const Account& accountDataCopy);

    const string &getID() const;

    void setID(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const double &getBlance() const;

    void setBlance(const double &blance);

    const string getIdentityNumber() const;

    void setIdentityNumber(const string &identityNumber);

    const string getworkPlace() const;

    void setworkPlace(const string &workPlace);

    const string getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    const string getAddress() const;

    void setAddress(const string &address);

    const string &getEMail() const;

    void setEMail(const std::string &eMail);

    tm* getOpenDate() const;

    void setOpenDate(tm* openDate_);

    tm* getCloseDate() const;

    void setCloseDate(tm* closeDate_);

    friend std::istream &operator>>(std::istream &in, Account &right);

    friend std::ostream &operator<<(std::ostream &out, const Account &right);

private:
    string ID;
    string name;
    double balance;
    string identityNumber;
    string workPlace;
    string phoneNumber;
    string address;
    string eMail;
    std::tm* openDate;
    std::tm* closeDate;
};

#endif //PROJECT_ABS_ACCOUNT_H
