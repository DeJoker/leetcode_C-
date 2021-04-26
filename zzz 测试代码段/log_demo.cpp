
#include "log.h"

#include "../common/debugger.h"

// Log2 BitDump DumpAsC 没有用到
// Log Dump Dump4 用到了


void LogWrapper(int level, const char* file, int line, const char* function, const std::string& str) {
	// WLOG(0, file, function, line) << str;

    switch(level) {
        case 0:
            WLDEBUG(file, line, function) << str;
            break;
        case 2:
            WLERROR(file, line, function) << str;
            break;
        default:
	        WLINFO(file, line, function) << str;
    }
}


int main() {
	SetLogCallBack(LogWrapper);


    // myprintf("niamde: %s\n", "wsm??");

    Log("niamde: %s\n", "wsm??");
    Log("niamde: %s\n", "wsm??");
    Log("niamde: %s\n", "wsm??");

    // Log2("niamde: %s\n", "wsm??");


}




