#include "../common/debugger.h"
#include <cstdlib>
#include <unistd.h>

int ismkSuc()
{
    char tmpfile[L_tmpnam] = "/tmp/cyclone.XXXXXX";
    auto fd = mkstemp(tmpfile);
    if(fd > 0) close(fd);
    cout << string(tmpfile) <<endl;
}

int main() {
    ismkSuc();
    return 0;
}
