//
// Created by 16415 on 2023/5/30.
//
#include "../include/function.h"

using std::cin;
using std::cout;
using std::endl;

tm* nowTime() {
    time_t curtime;
    struct tm* info;
    time(&curtime);
    info = gmtime(&curtime);
    return info;
}

void showTime(tm *time_) {
    cout<<time_->tm_year<<"."<<time_->tm_mon<<"."<<time_->tm_mday<<" "<<" "<<((time_->tm_hour)%24)<<":";
    if (time_->tm_min < 10) {
        cout<<"0"<<time_->tm_min<<":";
    }else {
        cout<<time_->tm_min<<":";
    }
    if (time_->tm_sec < 10) {
        cout<<"0"<<time_->tm_sec;
    }else {
        cout<<time_->tm_sec;
    }
    cout<<endl;
}