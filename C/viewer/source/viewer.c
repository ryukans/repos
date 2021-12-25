#include "../header/viewer.h"

int main(int argc, char const *argv[])
{
    ipc_t qdes;

    qdes.key = ftok(".", 'Q');
    qdes.id = msgget(qdes.key, 0664);

    recieve(qdes.id);

    return VIEWER_EXIT_SUCCESS;
}

