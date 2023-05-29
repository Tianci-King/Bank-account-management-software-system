//
// Created by 16415 on 2023/5/22.
//

#ifndef PROJECT_ABS_ACCOUNTLIST_H
#define PROJECT_ABS_ACCOUNTLIST_H
#include "list.h"
#include "account.h"

class AccountList : public List<Account> {
public:

    ListNode<Account> *fetchNode(const std::string&, const std::string&);

    void delNode(const std::string&, const std::string&);

    void changeNode(std::string, const std::string&);

    void sortNode();

    void fetchNode();

private:
    void sort(bool (*cmp)(const ListNode<Account>&, const ListNode<Account>&));

    void swap(ListNode<Account>*, ListNode<Account>*);


};

#endif //PROJECT_ABS_ACCOUNTLIST_H
