#include "naett.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
    naettReq* req =
        naettRequest("http://www.dn.se", naettMethod("GET"), naettHeader("content-type", "application/json"));
    naettRes* res = naettMake(req);
    while (!naettComplete(res)) {
        usleep(100 * 1000);
    }

    int bodyLength = 0;
    const char* body = naettGetBody(res, &bodyLength);
    printf("Got %d bytes of type '%s':\n", bodyLength, naettGetHeader(res, "Content-Type"));
    printf("%.100s\n...\n", body);
}