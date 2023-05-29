//
// Created by 16415 on 2023/5/22.
//

#include "../include/file.h"

File::File(const std::string path, const std::string fileType) {
    File::path = path;
    File::fileType = fileType;
}

void File::init(AccountList &accountList) {
    std::ifstream in;
    in.open(path + fileType, std::ios::in);
    if(!in.is_open()) {
        std::ofstream out;
        out.open(path + fileType, std::ios::out | std::ios::app);
        out.close();
        in.open(path + fileType, std::ios::in);
    }
    while(!in.eof()) {
        accountList.addNode(in);
    }
    in.close();
}

void File::add(Account &account) {
    std::ofstream out;
    out.open(path + fileType, std::ios::app);
    if(!out.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    out << std::endl << account;
    out.close();
}

void File::change(AccountList &accountList) {
    std::ofstream out;
    out.open(path + ".temp", std::ios::app);
    if(!out.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    auto ptr = accountList.getHead();
    if(ptr) {
        out << ptr->getData();
        ptr = ptr->getNext();
    }
    while(ptr) {
        out << std::endl << ptr->getData();
        ptr = ptr->getNext();
    }
    out.close();
    remove((path + fileType).c_str());
    rename((path + ".temp").c_str(), (path + fileType).c_str());
}
