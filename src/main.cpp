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
    //out<<list.fetchNode("刘邦" , "name")->getData();
    menu1:
    cout << "----------------------------------------" << endl;
    cout << "欢迎使用银行账户管理系统" << endl;
    cout << "请选择登录身份" << endl;
    cout << "1: 银行管理员" << endl;
    cout << "2: 银行用户" << endl;
    cout << "0: 退出系统" << endl;
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
                        goto end;//输入0安全退出程序
                    }
                    switch (typeNum) {
                        case 1: {
                            cout << "----------------------------------------" << endl;
                            auto temp = list.addNode(cin);
                            file.add(temp);
                            cout << "----------------------------------------" << std::endl;
                            cout << "您的账号已经创建成功！" << endl;
                            cout << temp;
                            menu.displayMainMenu();
                            break;
                        }
                        case 2: {
                            if (!list.getSize()) {
                                cout << "----------------------------------------" << endl;
                                cout << "当前系统暂无账户，请新增账户后操作本系统" << endl;
                                break;
                            }
                            menu.displayFetchMenu();
                            int typeNum_;
                            bool flag = true;
                            while (flag && cin >> typeNum_ ) {
                                switch (typeNum_) {
                                    case 1: {
                                        cout << "----------------------------------------" << endl;
                                        cout << "请输入想查询用户的姓名：";
                                        string name;
                                        cin >> name;
                                        auto user = list.fetchNode(name, "name");
                                        if (user) {
                                            cout << *user;
                                        } else {
                                            cout << "该用户不存在" << endl;
                                        }
                                        flag = false;
                                        break;
                                    }
                                    case 2: {
                                        cout << "----------------------------------------" << endl;
                                        cout << "请输入想查询用户的ID：";
                                        string ID_;
                                        cin >> ID_;
                                        auto user = list.fetchNode(ID_, "ID");
                                        if (user) {
                                            cout << user;
                                        } else {
                                            cout << "该用户不存在" << endl;
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
                                        std::cout << "输入有误，请重新输入\n>";
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
                            cout << "输入有误，请重新输入\n>";
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
                    cout << "当前系统暂无账户，请新增账户后操作本系统" << endl;
                    cout << "正在创建账户中..." << endl;

                    //创建账号
                    auto temp = list.addNode(cin);
                    file.add(temp);
                    cout << "----------------------------------------" << std::endl;
                    cout << "您的账号已经创建成功！" << endl;
                    cout << temp;
                }

                cout << "----------------------------------------" << endl;
                cout << "请输入对应功能前的编号来进行对应的操作" << endl;
                cout << "1: 登录已有账号" << endl;
                cout << "2: 注册新的账号" << endl;
                cout << "3: 返回上一级菜单" <<endl;
                cout << ">";
                while(cin >> choice){
                    switch (choice) {
                        case 1: {
                            login:
                            cout << "----------------------------------------" << endl;
                            cout << "正在登陆中..." << endl;

                            {
                                cout << "请输入您的账号(ID):" << std::endl;
                                cout << ">";
                                cin >> ID_now;
                                cout << "请输入您的密码(身份证号码):" << std::endl;
                                cout << ">";
                                cin >> password_now;

                                //登录检测
                                if (list.fetchNode(ID_now , "ID") != nullptr) {
                                    Account account_ = list.fetchNode(ID_now , "ID")->getData();
                                    if (account_.getIdentityNumber() == password_now) {
                                        loginFlag = true;
                                        account_now = account_;
                                        goto loginsucceed;
                                    } else {
                                        cout << "对不起，密码错误，请输入重新输入或退出登录" << endl;
                                        cout << "请输入对应功能前的编号" << endl;
                                        cout << "1: 重新输入账号密码" << endl;
                                        cout << "2: 新建账号" << endl;
                                        cout << "3: 返回上一级菜单" << endl;
                                        cout << ">";
                                        int choice2;
                                        while(cin >> choice2) {
                                            switch (choice2) {
                                                case 1:
                                                    goto login;//返回登录菜单
                                                case 2:
                                                    goto sign;//返回注册菜单
                                                case 3:
                                                    goto menu2;
                                                default:
                                                    cout << "输入有误，请重新输入\n>";
                                            }
                                        }

                                    }
                                } else {
                                    cout << "对不起，账号不存在" << endl;
                                    cout << "请输入对应功能前的编号" << endl;
                                    cout << "1: 重新输入账号密码" << endl;
                                    cout << "2: 新建账号" << endl;
                                    cout << "3: 返回上一级菜单" << endl;
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
                                                cout << "输入有误，请重新输入\n>";
                                        }
                                    }
                                }
                            }
                        }
                        case 2: {
                            sign:
                            cout << "----------------------------------------" << endl;
                            cout << "正在创建账户中..." << endl;

                            //创建账号
                            auto temp = list.addNode(cin);
                            account_now = temp;
                            file.add(account_now);
                            file.init(list);
                            cout << "----------------------------------------" << endl;
                            cout << "您的账号已经创建成功！" << endl;
                            cout << account_now ;
                            cout << "请输入对应功能前的编号" << endl;
                            cout << "1: 一键登录您的账号" << endl;
                            cout << "2: 返回上一级菜单" << endl;
                            cout << ">";
                            int choice4;
                            while(cin >> choice4) {
                                switch (choice4) {
                                    case 1: {
                                        //一键登录
                                        loginFlag = true;
                                        goto loginsucceed; //跳转登陆成功
                                    }
                                    case 2:
                                        goto menu2;
                                    default:
                                        cout << "输入有误，请重新输入\n>";
                                }
                            }
                        }
                        case 3:
                            goto menu1;//返回上一级菜单，第一级主菜单
                        default: {
                            cout << "输入有误，请重新输入\n>";
                        }
                    }
                    file.change(list);
                }

                loginsucceed:
                //登录成功
                if (loginFlag) {
                    cout << "----------------------------------------" << endl;
                    cout << "恭喜您，登录成功！" << endl;
                    cout << "请输入对应功能前的编号" << endl;
                    cout << "1: 账号存款" << endl;
                    cout << "2: 账号取款" << endl;
                    cout << "3: 账号转账" << endl;
                    cout << "4: 查询账户信息" << endl;
                    cout << "5: 账号销户" << endl;
                    cout << "6: 安全退出账户" << endl;
                    cout << ">";
                    int choice5;
                    while(cin >> choice5) {
                        switch (choice5) {
                            case 1: {
                                cout << "----------------------------------------" << endl;
                                cout << "您当前的账户余额为: " << account_now.getBlance() << endl;
                                cout << "请输入您要存入的金额" << endl;
                                cout <<">";
                                double balance_;
                                while(cin >> balance_) {
                                    if (balance_ <= 0) {
                                        cout << "输入金额有误，请重新输入" << endl;
                                        cout << ">";
                                    } else {
                                        cout << "存入成功!" << endl;
                                        double balanceTemp = account_now.getBlance();
                                        account_now.setBlance(balanceTemp + balance_);
                                        list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp + balance_);
                                        cout << "您当前的账户余额为: " << account_now.getBlance() <<endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 2: {
                                cout << "----------------------------------------" << endl;
                                cout << "您当前的账户余额为: " << account_now.getBlance() << endl;
                                cout << "请输入您要取出的金额" << endl;
                                cout <<">";
                                double balance_;
                                while(cin >> balance_) {
                                    if (balance_ <= 0 or balance_ > account_now.getBlance()) {
                                        cout << "输入金额有误，请重新输入" << endl;
                                        cout << ">";
                                    } else {
                                        cout << "取出成功!" << endl;
                                        double balanceTemp = account_now.getBlance();
                                        account_now.setBlance(balanceTemp - balance_);
                                        list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp - balance_);
                                        cout << "您当前的账户余额为: " << account_now.getBlance() <<endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 3: {
                                cout << "----------------------------------------" << endl;
                                cout << "您当前的账户余额为: " << account_now.getBlance() << endl;
                                cout << "请输入您要转出的金额和收款方的账号（ID）" << endl;
                                cout << "（金额与账号ID间用一个空格隔开，例: 100 1001）" << endl;
                                cout <<">";
                                double balance_;
                                string ID_;
                                while(cin >> balance_ >> ID_) {
                                    if (list.fetchNode(ID_ , "ID") != nullptr and ID_ != account_now.getID()) {
                                        Account account_ = list.fetchNode(ID_, "ID")->getData();

                                        if (balance_ <= 0 or balance_ > account_now.getBlance()) {
                                            cout << "输入金额有误，请重新输入" << endl;
                                            cout << ">";
                                        } else {
                                            cout << "转出成功!" << endl;
                                            double balanceTemp = account_now.getBlance();
                                            account_now.setBlance(balanceTemp - balance_);
                                            list.fetchNode(account_now.getID() , "ID")->getData().setBlance(balanceTemp - balance_);
                                            double  balanceTempGiven = account_.getBlance();
                                            account_.setBlance(balanceTempGiven + balance_);
                                            list.fetchNode(ID_ , "ID")->getData().setBlance(balanceTempGiven + balance_);
                                            cout << "您当前的账户余额为: " << account_now.getBlance() <<endl;
                                            break;
                                        }
                                    } else {
                                        if (ID_ == account_now.getID()) {
                                            cout << "收款方账户不能是您自己，请重新输入" << endl;
                                        }
                                        else
                                            cout << "收款方账号有误，请重新输入" << endl;
                                        cout << ">";
                                    }
                                }
                                break;
                            }
                            case 4: {
                                cout << "----------------------------------------" << endl;
                                cout << "正在查询您的账号信息...您的账号信息如下: " << endl;
                                cout << account_now;
                                break;
                            }
                            case 5: {
                                cout << "----------------------------------------" << endl;
                                cout << "您的账户已经注销，感谢您的使用" << endl;
                                list.delNode(account_now.getID() , "ID");
                                goto menu1;
                            }
                            case 6: {
                                cout << "----------------------------------------" << endl;
                                cout << "您的账户已经安全退出，感谢您的使用" << endl;
                                loginFlag = false;
                                goto menu1;
                            }
                        }
                        file.change(list);
                        cout << "----------------------------------------" << endl;
                        cout << "请问您还有需要帮助的吗？请输入对应功能前的编号" << endl;
                        cout << "1: 账号存款" << endl;
                        cout << "2: 账号取款" << endl;
                        cout << "3: 账号转账" << endl;
                        cout << "4: 查询账户信息" << endl;
                        cout << "5: 账号销户" << endl;
                        cout << "6: 安全退出账户" << endl;
                        cout << ">";
                    }
                }

                break;
            }
            default: {
                std::cout << "输入有误，请重新输入\n>";
            }
        }
    }
    end:
    //保存修改完的链表文件信息
    file.change(list);

    system("pause");
    return 0;
}
