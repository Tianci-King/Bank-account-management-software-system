//
// Created by 16415 on 2023/5/22.
//

#include "../include/accountList.h"

ListNode<Account> *AccountList::fetchNode(const string & fetchText, const string & fetchType) {
    ListNode<Account> *ptr = head;
    if(fetchType == "ID") {
        while(ptr) {
            if(ptr->getData().getID() == fetchText) {
                return ptr;
            }
            ptr = ptr->getNext();
        }
    }
    else if (fetchType == "name") {
        // �����������
        int num = 0;
        ListNode<Account> *ptr_[getSize()];
        while(ptr) {
            if(ptr->getData().getName() == fetchText) {
                ptr_[num] = ptr;
                if(num == 1) {
                    cout << "��ѯ������û����������Ӧ�û�ǰ�ı�Ž���ѡ��" << endl;
                    cout << "NO.1" << endl << *ptr_[0];
                    cout << "NO.2" << endl << *ptr;
                } else if(num) {
                   cout << "NO." << (num + 1) << endl << *ptr;
                }
                num ++;
            }
            ptr = ptr->getNext();
        }
        if(num > 1) {
            int val;
            cout << ">";
            cin >> val;
            if(val <= num) {
                return ptr_[val - 1];
            } else {
                return ptr_[num - 1];
            }
        } else if(num == 1) {
            return ptr_[0];
        }
    }
    return nullptr;
}

void AccountList::delNode(const string &delText, const string &delType) {
    ListNode<Account> *ptr = fetchNode(delText, delType);
    if(!ptr) {
        cout << "�����ڸ��˻�" << std::endl;
        return;
    }
    ListNode<Account> *ptr_ = ptr->getPrior();
    if(ptr_ && ptr->getNext()) {
        ptr_->setNext(ptr->getNext());
        ptr->getNext()->setPrior(ptr_);
    } else if(ptr_) {
        //ɾβ�ڵ�
        ptr_->setNext(nullptr);
        tail = ptr_;
    } else if(ptr->getNext()) {
        //ɾͷ�ڵ�
        ptr->getNext()->setPrior(nullptr);
        head = ptr->getNext();
    } else {
        //ɾ����Ψһ�ڵ�
        tail = nullptr;
        head = nullptr;
    }
    -- size;
    delete ptr;
    ptr = nullptr;
}

void AccountList::changeNode(string context, const string &type) {
    auto account_ = type == "name" ? fetchNode(context, "name") : fetchNode(context, "ID");
    if(account_) {
    cout << "������Ҫ�޸ĵ���Ϣ�ı��" << endl;
    cout << "1: ����" << endl
         << "2: ���֤����" << endl
         << "3: �����ص�" << endl
         << "4: �绰����" << endl
         << "5: ��ͥ��ַ" << endl
         << "6: ��������" << endl
         << "0: �˳�" << endl;
    cout << ">";
    int typeNum;
    bool flag = true;
    string temp;
    while(flag && cin >> typeNum && typeNum ) {
        switch (typeNum) {
            case 1: {
                cout << "�������µ�����:";
                cin >> temp;
                account_->getData().setName(temp);
                context = temp;
                display();
                flag = false;
                break;
            }
            case 2: {
                cout << "�������µ����֤����:";
                cin >> temp;
                account_->getData().setIdentityNumber(temp);
                display();
                flag = false;
                break;
            }
            case 4: {
                std::cout << "�������µĵ绰����:";
                while (cin >> temp) {
                    if (regex_match(temp, std::regex("[0-9]{11}"))) {
                        account_->getData().setPhoneNumber(temp);
                        break;
                    } else {
                        cout << "����ĵ绰�����ʽ�Ƿ���Ӧ��Ϊ11λ��0��ͷ�Ĵ����֣����������룺";
                    }
                }
                display();
                flag = false;
                break;
            }
            case 5: {
                cout << "�������µĵ�ַ:";
                cin >> temp;
                account_->getData().setAddress(temp);
                display();
                flag = false;
                break;
            }

            case 6: {
                std::cout << "�������µ�����:";
                while (cin >> temp) {
                    if (regex_match(temp, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
                        account_->getData().setEMail(temp);
                        break;
                    } else if (temp == "0") {
                        account_->getData().setEMail("");
                        break;
                    } else {
                        cout << "����������ַ��ʽ�Ƿ�����ȷ������Ϊ��123456@zjut.edu.cn�����������룺";
                    }
                }
                display();
                flag = false;
                break;
            }

            default: {
                cout << "������������������\n>";
                break;
            }
        }
    }
    } else {
    // ��ѯ���ݳ�������
    cout << "δ���ҵ����û�" << endl;
    }
}

void AccountList::swap(ListNode<Account> *left, ListNode<Account> *right) {
    // ���������ڵ��ǰ�����
    head = left == head ? right: head;
    tail = right == tail ? left: tail;

    if(left->getNext() == right) {
        // �����Ľڵ�����
        ListNode<Account> *prior = left->getPrior();
        ListNode<Account> *next = right->getNext();

        left->setNext(next);
        if(next) {
            next->setPrior(left);
        }
        left->setPrior(right);

        right->setPrior(prior);
        if(prior) {
            prior->setNext(right);
        }
        right->setNext(left);
    } else {
        // �����Ľڵ㲻����
        if(left->getPrior()) {
            left->getPrior()->setNext(right);
        }
        ListNode<Account> *prior = right->getPrior();
        prior->setNext(left);
        right->setPrior(left->getPrior());
        left->setPrior(prior);
        prior = nullptr;

        left->getNext()->setPrior(right);
        ListNode<Account> *next = right->getNext();
        if(next) {
            next->setPrior(left);
        }
        right->setNext(left->getNext());
        left->setNext(next);
        next = nullptr;
    }
}

void AccountList::sortNode() {
    cout << "������Ҫ�������Ϣ�ı��" << endl;
    cout << "1: ����" << endl
         << "2: ���֤����" << endl
         << "3: �����ص�" << endl
         << "4: �绰����" << endl
         << "5: ��������" << endl
         << "6: ���" << endl
         << "0: �˳�" << endl;
    cout <<">";
    int type;
    cin >> type;
    switch (type) {
        case 1: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                return left.getData().getName() < right.getData().getName();
            });
            display();
            break;
        }
        case 2: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                return left.getData().getIdentityNumber() < right.getData().getIdentityNumber();
            });
            display();
            break;
        }
        case 3: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                return left.getData().getworkPlace() < right.getData().getworkPlace();
            });
            display();
            break;
        }
        case 4: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                return left.getData().getIdentityNumber() < right.getData().getIdentityNumber();
            });
            display();
            break;
        }
        case 5: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                if(left.getData().getOpenDate()->tm_year < right.getData().getOpenDate()->tm_year) {
                    return true;
                }else if (left.getData().getOpenDate()->tm_year == right.getData().getOpenDate()->tm_year and left.getData().getOpenDate()->tm_mon < right.getData().getOpenDate()->tm_mon) {
                    return true;
                }else if (left.getData().getOpenDate()->tm_year == right.getData().getOpenDate()->tm_year and left.getData().getOpenDate()->tm_mon == right.getData().getOpenDate()->tm_mon and left.getData().getOpenDate()->tm_mday < right.getData().getOpenDate()->tm_mday) {
                    return true;
                }else
                    return false;
            });
            display();
            break;
        }
        case 6: {
            sort([](const ListNode<Account> &left , const ListNode<Account> &right) ->bool {
                return left.getData().getBlance() < right.getData().getBlance();
            });
            display();
            break;
        }
        case 0: {
            cout << "----------------------------------------" << endl;
            cout << "�˳��ɹ���" << endl;
        }
        default: {
            cout << "������������������\n>";
        }
    }
}

void AccountList::sort(bool (*cmp)(const ListNode<Account> &, const ListNode<Account> &)) {
    // ����ʵ�֣��ֽ׶����ò�������
    ListNode<Account> *ptr = head;
    ListNode<Account> *ptr_ = nullptr;
    ListNode<Account> *ptr_tmp = nullptr;
    for(int i = 0; i < getSize() - 1; i ++) {
        ptr_ = ptr->getNext();
        ptr_tmp = ptr;
        for(int j = i + 1; j < getSize(); j ++) {
            if(cmp(*ptr_, *ptr_tmp)) {
                ptr_tmp = ptr_;
            }
            ptr_ = ptr_->getNext();
        }
        if(ptr != ptr_tmp) {
            swap(ptr, ptr_tmp);
            ptr = ptr_tmp;
        }
        ptr = ptr->getNext();
    }
}

void AccountList::fetchNode() {
    // ͨ����ַʵ��ģ����ѯ
    string  temp;
    ListNode<Account> *ptr = head;
    bool flag = true;

    cout << "������Ҫ���Ŀ���˻��Ĺؼ���" << endl;
    cin >> temp;
    while(ptr) {
        string address = ptr->getData().getName();
        for (int i = 0; i < address.size(); ++i) {
            for (int j = 0; j < temp.size(); ++j) {
                if (address[i] == temp[j] and address[i] != ' ' and temp[j] != ' ') {
                    cout << *ptr;
                    flag = false;
                    return;
                }
            }
        }
        ptr = ptr->getNext();
    }

        cout << "δ�ܲ�ѯ������Ҫ����û�" << endl;

}
