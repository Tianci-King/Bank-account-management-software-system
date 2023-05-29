//
// Created by 16415 on 2023/5/22.
//

#ifndef PROJECT_ABS_FILE_H
#define PROJECT_ABS_FILE_H

#include <fstream>
#include "accountList.h"

class File {
public:
    File(const string, const string);

    void init(AccountList&);

    void add(Account&);

    void change(AccountList&);
private:
    std::string path;
    std::string fileType;
};
#endif //PROJECT_ABS_FILE_H
