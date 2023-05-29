//
// Created by 16415 on 2023/5/22.
//

#include "../include/menu.h"

void Menu::displayMainMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "亲爱的管理员您好，请输入对应功能前的编号来操作本银行账户管理系统" << std::endl
              << "1: 添加新用户信息" << std::endl
              << "2: 查询用户信息" << std::endl
              << "3: 输出用户信息" << std::endl
              << "4: 修改用户信息" << std::endl
              << "5: 删除用户信息" << std::endl
              << "6: 对用户信息进行排序" << std::endl
              << "0: 退出系统并保存数据" << std::endl;
    std::cout << ">";
}

void Menu::displayFetchMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入对应功能前的编号来查询信息" << std::endl
              << "1: 根据姓名进行精确查询" << std::endl
              << "2: 根据ID进行精确查询" << std::endl
              << "3: 根据家庭住址进行模糊查询" << std::endl
              << "0: 返回上级菜单" << std::endl;
    std::cout << ">";
}

void Menu::displayChangeMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入要修改账户信息的账户的ID，或输入0返回上级菜单" << std::endl;
    std::cout << ">";
}

void Menu::displayDeleteMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "请输入要删除的账户信息的账户的ID，或输入0返回上级菜单" << std::endl;
    std::cout << ">";
}
