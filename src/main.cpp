#include "../include/file.h"
#include "../include/menu.h"
#include "../include/admin.h"

int main() {
    Menu menu;
    AccountList list;

    Account account_now;
    bool loginFlag = false;

    int userType = 1;
    bool flagMain = true;
    bool flagMain_ = true;
    File file("../data/data", ".txt");
    file.init(list);
    //out<<list.fetchNode("����" , "name")->getData();
    menu1:
    cout << "----------------------------------------" << endl;
    cout << "��ӭʹ�������˻�����ϵͳ" << endl;
    cout << "��ѡ���¼���" << endl;
    cout << "1: ���й���Ա" << endl;
    cout << "2: �����û�" << endl;
    cout << "0: �˳�ϵͳ" << endl;
    cout << ">";
    while(flagMain_ and cin >> userType and userType) {
        int typeNum;
        std::string ID_now , password_now;
        switch (userType) {
            case 1: {
                Admin admin("../data/admin", ".txt");
                if (!admin.login()) {
                    flagMain_ = false;
                    break;
                }
                menu:
                menu.displayMainMenu();
                while(flagMain and cin >> typeNum) {
                    if (typeNum == 0) {
                        goto end;//����0��ȫ�˳�����
                    }
                    switch (typeNum) {
                        case 1: {
                            cout << "----------------------------------------" << endl;
                            auto temp = list.addNode(cin);
                            file.add(temp);
                            cout << "----------------------------------------" << std::endl;
                            cout << "�����˺��Ѿ������ɹ���" << endl;
                            cout << temp;
                            menu.displayMainMenu();
                            break;
                        }
                        case 2: {
                            if (!list.getSize()) {
                                cout << "----------------------------------------" << endl;
                                cout << "��ǰϵͳ�����˻����������˻��������ϵͳ" << endl;
                                break;
                            }
                            menu.displayFetchMenu();
                            int typeNum_;
                            bool flag = true;
                            while (flag && cin >> typeNum_ ) {
                                switch (typeNum_) {
                                    case 1: {
                                        cout << "----------------------------------------" << endl;
                                        cout << "���������ѯ�û���������";
                                        string name;
                                        cin >> name;
                                        auto user = list.fetchNode(name, "name");
                                        if (user) {
                                            cout << *user;
                                        } else {
                                            cout << "���û�������" << endl;
                                        }
                                        flag = false;
                                        break;
                                    }
                                    case 2: {
                                        cout << "----------------------------------------" << endl;
                                        cout << "���������ѯ�û���ID��";
                                        string ID_;
                                        cin >> ID_;
                                        auto user = list.fetchNode(ID_, "ID");
                                        if (user) {
                                            cout << user;
                                        } else {
                                            cout << "���û�������" << endl;
                                        }
                                        flag = false;
                                        break;
                                    }
                                    case 3: {
                                        cout << "----------------------------------------" << endl;
                                        //list.fetchNode();
                                        flag = false;
                                        break;
                                    }
                                    case 0: {
                                        goto menu;
                                    }
                                    default: {
                                        std::cout << "������������������\n>";
                                        break;
                                    }
                                }

                            }
                            menu.displayMainMenu();
                            break;
                        }
                        case 3: {
                            cout << "----------------------------------------" << endl;
                            list.display();
                            menu.displayMainMenu();
                            break;
                        }
                        case 4: {
                            menu.displayChangeMenu();
                            string temp;
                            cin >> temp;
                            if (temp == "0") {
                                goto menu;
                            }else {
                                list.changeNode(temp , "ID");
                                file.change(list);
                            }
                            menu.displayMainMenu();
                            break;
                        }
                        case 5: {
                            menu.displayDeleteMenu();
                            string temp;
                            cin >> temp;
                            if (temp == "0") {
                                goto menu;
                            } else {
                                list.delNode(temp , "ID");
                                file.change(list);
                            }
                            menu.displayMainMenu();
                            break;
                        }
                        case 6: {
                            cout << "----------------------------------------" << endl;
                            list.sortNode();
                            file.change(list);
                            menu.displayMainMenu();
                            break;
                        }
                        default: {
                            cout << "������������������\n>";
                        }
                    }

                }
                break;
            }
            case 2: {
                menu2:
                int choice;
                loginFlag = false;
                if (!list.getSize()) {
                    cout << "----------------------------------------" << endl;
                    cout << "��ǰϵͳ�����˻����������˻��������ϵͳ" << endl;
                    cout << "���ڴ����˻���..." << endl;

                    //�����˺�
                    auto temp = list.addNode(cin);
                    file.add(temp);
                    cout << "----------------------------------------" << std::endl;
                    cout << "�����˺��Ѿ������ɹ���" << endl;
                    cout << temp;
                }

                cout << "----------------------------------------" << endl;
                cout << "�������Ӧ����ǰ�ı�������ж�Ӧ�Ĳ���" << endl;
                cout << "1: ��¼�����˺�" << endl;
                cout << "2: ע���µ��˺�" << endl;
                cout << "3: ������һ���˵�" <<endl;
                cout << ">";
                while(cin >> choice){
                    switch (choice) {
                        case 1: {
                            login:
                            cout << "----------------------------------------" << endl;
                            cout << "���ڵ�½��..." << endl;

                            {
                                cout << "�����������˺�(ID):" << std::endl;
                                cout << ">";
                                cin >> ID_now;
                                cout << "��������������(���֤����):" << std::endl;
                                cout << ">";
                                cin >> password_now;

                                //��¼���
                                if (list.fetchNode(ID_now , "ID") != nullptr) {
                                    Account account_ = list.fetchNode(ID_now , "ID")->getData();
                                    if (account_.getIdentityNumber() == password_now) {
                                        loginFlag = true;
                                        account_now = account_;
                                        goto loginsucceed;
                                    } else {
                                        cout << "�Բ��������������������������˳���¼" << endl;
                                        cout << "�������Ӧ����ǰ�ı��" << endl;
                                        cout << "1: ���������˺�����" << endl;
                                        cout << "2: �½��˺�" << endl;
                                        cout << "3: ������һ���˵�" << endl;
                                        cout << ">";
                                        int choice2;
                                        while(cin >> choice2) {
                                            switch (choice2) {
                                                case 1:
                                                    goto login;//���ص�¼�˵�
                                                case 2:
                                                    goto sign;//����ע��˵�
                                                case 3:
                                                    goto menu2;
                                                default:
                                                    cout << "������������������\n>";
                                            }
                                        }

                                    }
                                } else {
                                    cout << "�Բ����˺Ų�����" << endl;
                                    cout << "�������Ӧ����ǰ�ı��" << endl;
                                    cout << "1: ���������˺�����" << endl;
                                    cout << "2: �½��˺�" << endl;
                                    cout << "3: ������һ���˵�" << endl;
                                    cout << ">" ;
                                    int choice3;
                                    while(cin >> choice3) {
                                        switch (choice3) {
                                            case 1:
                                                goto login;
                                            case 2:
                                                goto sign;
                                            case 3:
                                                goto menu2;
                                            default:
                                                cout << "������������������\n>";
                                        }
                                    }
                                }
                            }
                        }
                        case 2: {
                            sign:
                            cout << "----------------------------------------" << endl;
                            cout << "���ڴ����˻���..." << endl;

                            //�����˺�
                            auto temp = list.addNode(cin);
                            account_now = temp;
                            file.add(account_now);
                            file.init(list);
                            cout << "----------------------------------------" << endl;
                            cout << "�����˺��Ѿ������ɹ���" << endl;
                            cout << account_now ;
                            cout << "�������Ӧ����ǰ�ı��" << endl;
                            cout << "1: һ����¼�����˺�" << endl;
                            cout << "2: ������һ���˵�" << endl;
                            cout << ">";
                            int choice4;
                            while(cin >> choice4) {
                                switch (choice4) {
                                    case 1: {
                                        //һ����¼
                                        loginFlag = true;
                                        goto loginsucceed; //��ת��½�ɹ�
                                    }
                                    case 2:
                                        goto menu2;
                                    default:
                                        cout << "������������������\n>";
                                }
                            }
                        }
                        case 3:
                            goto menu1;//������һ���˵�����һ�����˵�
                        default: {
                            cout << "������������������\n>";
                        }
                    }
                    file.change(list);
                }

                loginsucceed:
                //��¼�ɹ�
                if (loginFlag) {
                    cout << "----------------------------------------" << endl;
                    cout << "��ϲ������¼�ɹ���" << endl;
                    cout << "�������Ӧ����ǰ�ı��" << endl;
                    cout << "1: �˺Ŵ��" << endl;
                    cout << "2: �˺�ȡ��" << endl;
                    cout << "3: �˺�ת��" << endl;
                    cout << "4: ��ѯ�˻���Ϣ" << endl;
                    cout << "5: �˺�����" << endl;
                    cout << "6: ��ȫ�˳��˻�" << endl;
                    cout << ">";
                    int choice5;
                    while(cin >> choice5) {
                        switch (choice5) {
                            case 1: {
                                cout << "----------------------------------------" << endl;
                                cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() << endl;
                                cout << "��������Ҫ����Ľ��" << endl;
                                cout <<">";
                                double balance_;
                                while(cin >> balance_) {
                                    if (balance_ <= 0) {
                                        cout << "��������������������" << endl;
                                        cout << ">";
                                    } else {
                                        cout << "����ɹ�!" << endl;
                                        double balanceTemp = account_now.getBlance();
                                        account_now.setBlance(balanceTemp + balance_);
                                        list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp + balance_);
                                        cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() <<endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 2: {
                                cout << "----------------------------------------" << endl;
                                cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() << endl;
                                cout << "��������Ҫȡ���Ľ��" << endl;
                                cout <<">";
                                double balance_;
                                while(cin >> balance_) {
                                    if (balance_ <= 0 or balance_ > account_now.getBlance()) {
                                        cout << "��������������������" << endl;
                                        cout << ">";
                                    } else {
                                        cout << "ȡ���ɹ�!" << endl;
                                        double balanceTemp = account_now.getBlance();
                                        account_now.setBlance(balanceTemp - balance_);
                                        list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp - balance_);
                                        cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() <<endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 3: {
                                cout << "----------------------------------------" << endl;
                                cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() << endl;
                                cout << "��������Ҫת���Ľ����տ���˺ţ�ID��" << endl;
                                cout << "��������˺�ID����һ���ո��������: 100 1001��" << endl;
                                cout <<">";
                                double balance_;
                                string ID_;
                                while(cin >> balance_ >> ID_) {
                                    if (list.fetchNode(ID_ , "ID") != nullptr and ID_ != account_now.getID()) {
                                        Account account_ = list.fetchNode(ID_, "ID")->getData();

                                        if (balance_ <= 0 or balance_ > account_now.getBlance()) {
                                            cout << "��������������������" << endl;
                                            cout << ">";
                                        } else {
                                            cout << "ת���ɹ�!" << endl;
                                            double balanceTemp = account_now.getBlance();
                                            account_now.setBlance(balanceTemp - balance_);
                                            list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp - balance_);
                                            double  balanceTempGiven = account_.getBlance();
                                            account_.setBlance(balanceTempGiven + balance_);
                                            list.fetchNode(ID_ , "ID")->getData().setBlance(balanceTempGiven + balance_);
                                            cout << "����ǰ���˻����Ϊ: " << account_now.getBlance() <<endl;
                                            break;
                                        }
                                    } else {
                                        if (ID_ == account_now.getID()) {
                                            cout << "�տ�˻����������Լ�������������" << endl;
                                        }
                                        else
                                            cout << "�տ�˺���������������" << endl;
                                        cout << ">";
                                    }
                                }
                                break;
                            }
                            case 4: {
                                cout << "----------------------------------------" << endl;
                                cout << "���ڲ�ѯ�����˺���Ϣ...�����˺���Ϣ����: " << endl;
                                cout << account_now;
                                break;
                            }
                            case 5: {
                                cout << "----------------------------------------" << endl;
                                cout << "�����˻��Ѿ�ע������л����ʹ��" << endl;
                                list.delNode(account_now.getID() , "ID");
                                goto menu1;
                            }
                            case 6: {
                                cout << "----------------------------------------" << endl;
                                cout << "�����˻��Ѿ���ȫ�˳�����л����ʹ��" << endl;
                                loginFlag = false;
                                goto menu1;
                            }
                        }
                        file.change(list);
                        cout << "----------------------------------------" << endl;
                        cout << "������������Ҫ���������������Ӧ����ǰ�ı��" << endl;
                        cout << "1: �˺Ŵ��" << endl;
                        cout << "2: �˺�ȡ��" << endl;
                        cout << "3: �˺�ת��" << endl;
                        cout << "4: ��ѯ�˻���Ϣ" << endl;
                        cout << "5: �˺�����" << endl;
                        cout << "6: ��ȫ�˳��˻�" << endl;
                        cout << ">";
                    }
                }

                break;
            }
            default: {
                std::cout << "������������������\n>";
            }
        }
    }
    end:
    //�����޸���������ļ���Ϣ
    file.change(list);

    system("pause");
    return 0;
}
