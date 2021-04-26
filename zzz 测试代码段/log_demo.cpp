
#include "log.h"

#include "../common/debugger.h"

// Log2 BitDump DumpAsC 没有用到
// Log Dump Dump4 用到了


void LogWrapper(const string& str) {
	LOG_DEBUG << str;
}


int main() {
	SetLogCallBack(LogWrapper);


    myprintf("niamde: %s\n", "wsm??");

    Log("niamde: %s\n", "wsm??");

    // Log2("niamde: %s\n", "wsm??");


}




