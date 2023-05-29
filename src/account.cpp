//
// Created by 16415 on 2023/5/22.
//

#include "../include/account.h"
#include "../include/function.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;

string ID_MAX = "1000";

Account::Account(const Account &accountDataCopy) {
    setID(accountDataCopy.getID());
    setName(accountDataCopy.getName());
    setBlance(accountDataCopy.getBlance());
    setIdentityNumber(accountDataCopy.getIdentityNumber());
    setworkPlace(accountDataCopy.getworkPlace());
    setPhoneNumber(accountDataCopy.getPhoneNumber());
    setAddress(accountDataCopy.getAddress());
    setEMail(accountDataCopy.getEMail());
    setOpenDate(accountDataCopy.getOpenDate());
    setCloseDate(accountDataCopy.getCloseDate());
}

const string &Account::getID() const {
    return ID;
}

void Account::setID(const string &id) {
    Account::ID = id;
}

const string &Account::getName() const {
    return name;
}

void Account::setName(const string &name) {
    Account::name = name;
}

const double &Account::getBlance() const {
    return balance;
}

void Account::setBlance(const double &blance) {
    Account::balance = blance;
}

const string Account::getIdentityNumber() const {
    return identityNumber;
}

void Account::setIdentityNumber(const string &identityNumber) {
    Account::identityNumber = identityNumber;
}

const string Account::getworkPlace() const {
    return workPlace;
}

void Account::setworkPlace(const string &workPlace) {
    Account::workPlace = workPlace;
}

const string Account::getPhoneNumber() const {
    return phoneNumber;
}

void Account::setPhoneNumber(const string &phoneNumber) {
    Account::phoneNumber = phoneNumber;
}

const string Account::getAddress() const {
    return address;
}

void Account::setAddress(const string &address) {
    Account::address = address;
}

const string &Account::getEMail() const {
    return eMail;
}

void Account::setEMail(const string &eMail) {
    Account::eMail = eMail;
}

tm *Account::getOpenDate() const {
    return openDate;
}

void Account::setOpenDate(tm *openDate_) {
    openDate = openDate_;
}

tm *Account::getCloseDate() const {
    return closeDate;
}

void Account::setCloseDate(tm* closeDate_) {
    closeDate = closeDate_;
}

Account::Account() = default;

Account::~Account() = default;

std::istream &operator>>(std::istream &in, Account &right) {
    //自动生成不重复ID
    if(typeid(in) == typeid(cin)) {
        cout << ">正在创建您的账户中...请输入“1”配置您账户的详细信息" << endl;
    }
    in >> right.ID;
    if (std::stoi(right.getID()) >= std::stoi(ID_MAX)) {
        ID_MAX = std::to_string((std::stoi(right.getID()) + 1));
    }
    if (right.getID().size() < 4) {
        right.ID = ID_MAX;
    }
    if(typeid(in) == typeid(cin)) {
        cout << "请输入您的姓名：";
    }
    in >> right.name;
    //输入身份证号码
    idcin:
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "的身份证号码：";
    }
    in >> right.identityNumber;
    //金额初始化为0
    if(typeid(in) == typeid(cin)) {
        cout << "您的身份证号码为: " << right.identityNumber << endl;
        cout << "确认无误请输入“-1”，若要修改身份证号码请输入“-2”重新输入身份证号码" << endl << ">";
    }
    double temp ;
    in >> temp;
    if (temp == -2) {
        goto idcin;
    } else  {
        if (temp < 0) temp = 0;
        right.setBlance(temp);
    }

    //输入工作地点
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "工作地点：";
    }
    in >> right.workPlace;
    //输入电话号码
    string phoneNum;
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "的电话号码：";
    }
    while (in >> phoneNum) {
        if (regex_match(phoneNum, std::regex("[1-9][0-9]{10}"))) {
            right.setPhoneNumber(phoneNum);
            break;
        } else {
            cout << "输入的电话号码格式非法，应该为11位非0开头的纯数字，请重新输入：";
        }
    }
    //输入住址
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "的住址：";
    }
    in >> right.address;
    //输入邮箱
    string eMail;
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "的电子邮箱（输入0代表为留空）：";
    }
    while (in >> eMail) {
        if (regex_match(eMail, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
            right.setEMail(eMail);
            break;
        } else if (eMail == "0") {
            right.setEMail("");
            break;
        } else {
            cout << "输入的邮箱地址格式非法，正确的样例为：123456@zjut.edu.cn，请重新输入：";
        }
    }
    //输入开户
    if(typeid(in) == typeid(cin)) {
        cout << "请输入" << right.name << "的开户时间：";
    }

    tm *openTime_ = (struct tm *)malloc(sizeof(struct tm));
    if(typeid(in) == typeid(cin)) {
        cout << "请输入开户时间年份（例如2023）" << endl << ">";
    }
    in >> openTime_->tm_year;
    if(typeid(in) == typeid(cin)) {
        cout << "请输入开户时间年月份（例如6）" << endl << ">";
    }
    in >> openTime_->tm_mon;
    if(typeid(in) == typeid(cin)) {
        cout << "请输入开户时间具体日期（例如17）" << endl << ">";
    }
    in >> openTime_->tm_mday;
    openTime_->tm_hour = 9;
    openTime_->tm_min = 0;
    openTime_->tm_sec = 0;
    right.setOpenDate(openTime_);

    return in;
}

std::ostream &operator<<(std::ostream &out, const Account &right) {
    if(typeid(out) == typeid(cout)) {
        out << "ID:" << right.getID() << '\n'
            << "姓名:" << right.getName() << '\n'
            << "金额:" << right.getBlance() << '\n'
            << "身份证号码:" << right.getIdentityNumber() << '\n'
            << "工作地点:" << right.getworkPlace() << '\n'
            << "电话号码:" << right.getPhoneNumber() << '\n'
            << "家庭地址:" << right.getAddress() << '\n'
            << "电子邮箱:" << right.getEMail() << '\n'
            << "开户时间:" ;
            showTime(right.getOpenDate());
    }else{
        out << right.getID() << " "
            << right.getName() << " "
            << right.getIdentityNumber() << " "
            << right.getBlance() << " "
            << right.workPlace << " "
            << right.getPhoneNumber() << " "
            << right.getAddress() << " "
            << right.getEMail() << " "
            << right.getOpenDate()->tm_year << " "
            << right.getOpenDate()->tm_mon << " "
            << right.getOpenDate()->tm_mday ;
    }
    return out;
}



