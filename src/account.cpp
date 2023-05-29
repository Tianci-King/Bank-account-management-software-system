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
    //�Զ����ɲ��ظ�ID
    if(typeid(in) == typeid(cin)) {
        cout << ">���ڴ��������˻���...�����롰1���������˻�����ϸ��Ϣ" << endl;
    }
    in >> right.ID;
    if (std::stoi(right.getID()) >= std::stoi(ID_MAX)) {
        ID_MAX = std::to_string((std::stoi(right.getID()) + 1));
    }
    if (right.getID().size() < 4) {
        right.ID = ID_MAX;
    }
    if(typeid(in) == typeid(cin)) {
        cout << "����������������";
    }
    in >> right.name;
    //�������֤����
    idcin:
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "�����֤���룺";
    }
    in >> right.identityNumber;
    //����ʼ��Ϊ0
    if(typeid(in) == typeid(cin)) {
        cout << "�������֤����Ϊ: " << right.identityNumber << endl;
        cout << "ȷ�����������롰-1������Ҫ�޸����֤���������롰-2�������������֤����" << endl << ">";
    }
    double temp ;
    in >> temp;
    if (temp == -2) {
        goto idcin;
    } else  {
        if (temp < 0) temp = 0;
        right.setBlance(temp);
    }

    //���빤���ص�
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "�����ص㣺";
    }
    in >> right.workPlace;
    //����绰����
    string phoneNum;
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "�ĵ绰���룺";
    }
    while (in >> phoneNum) {
        if (regex_match(phoneNum, std::regex("[1-9][0-9]{10}"))) {
            right.setPhoneNumber(phoneNum);
            break;
        } else {
            cout << "����ĵ绰�����ʽ�Ƿ���Ӧ��Ϊ11λ��0��ͷ�Ĵ����֣����������룺";
        }
    }
    //����סַ
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "��סַ��";
    }
    in >> right.address;
    //��������
    string eMail;
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "�ĵ������䣨����0����Ϊ���գ���";
    }
    while (in >> eMail) {
        if (regex_match(eMail, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
            right.setEMail(eMail);
            break;
        } else if (eMail == "0") {
            right.setEMail("");
            break;
        } else {
            cout << "����������ַ��ʽ�Ƿ�����ȷ������Ϊ��123456@zjut.edu.cn�����������룺";
        }
    }
    //���뿪��
    if(typeid(in) == typeid(cin)) {
        cout << "������" << right.name << "�Ŀ���ʱ�䣺";
    }

    tm *openTime_ = (struct tm *)malloc(sizeof(struct tm));
    if(typeid(in) == typeid(cin)) {
        cout << "�����뿪��ʱ����ݣ�����2023��" << endl << ">";
    }
    in >> openTime_->tm_year;
    if(typeid(in) == typeid(cin)) {
        cout << "�����뿪��ʱ�����·ݣ�����6��" << endl << ">";
    }
    in >> openTime_->tm_mon;
    if(typeid(in) == typeid(cin)) {
        cout << "�����뿪��ʱ��������ڣ�����17��" << endl << ">";
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
            << "����:" << right.getName() << '\n'
            << "���:" << right.getBlance() << '\n'
            << "���֤����:" << right.getIdentityNumber() << '\n'
            << "�����ص�:" << right.getworkPlace() << '\n'
            << "�绰����:" << right.getPhoneNumber() << '\n'
            << "��ͥ��ַ:" << right.getAddress() << '\n'
            << "��������:" << right.getEMail() << '\n'
            << "����ʱ��:" ;
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



