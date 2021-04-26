
#include "log.h"

#include "../common/debugger.h"

// Log2 BitDump DumpAsC 没有用到
// Log Dump Dump4 用到了


void LogWrapper(const char* file, int line, const char* function, const std::string& str) {
	// WLOG(0, file, function, line) << str;

	WLINFO(file, line, function) << str;
}


int main() {
	SetLogCallBack(LogWrapper);


    // myprintf("niamde: %s\n", "wsm??");

    Log("niamde: %s\n", "wsm??");
    Log("niamde: %s\n", "wsm??");
    Log("niamde: %s\n", "wsm??");

    // Log2("niamde: %s\n", "wsm??");


}




