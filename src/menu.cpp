//
// Created by 16415 on 2023/5/22.
//

#include "../include/menu.h"

void Menu::displayMainMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "�װ��Ĺ���Ա���ã��������Ӧ����ǰ�ı���������������˻�����ϵͳ" << std::endl
              << "1: ������û���Ϣ" << std::endl
              << "2: ��ѯ�û���Ϣ" << std::endl
              << "3: ����û���Ϣ" << std::endl
              << "4: �޸��û���Ϣ" << std::endl
              << "5: ɾ���û���Ϣ" << std::endl
              << "6: ���û���Ϣ��������" << std::endl
              << "0: �˳�ϵͳ����������" << std::endl;
    std::cout << ">";
}

void Menu::displayFetchMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "�������Ӧ����ǰ�ı������ѯ��Ϣ" << std::endl
              << "1: �����������о�ȷ��ѯ" << std::endl
              << "2: ����ID���о�ȷ��ѯ" << std::endl
              << "3: ���ݼ�ͥסַ����ģ����ѯ" << std::endl
              << "0: �����ϼ��˵�" << std::endl;
    std::cout << ">";
}

void Menu::displayChangeMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "������Ҫ�޸��˻���Ϣ���˻���ID��������0�����ϼ��˵�" << std::endl;
    std::cout << ">";
}

void Menu::displayDeleteMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "������Ҫɾ�����˻���Ϣ���˻���ID��������0�����ϼ��˵�" << std::endl;
    std::cout << ">";
}
