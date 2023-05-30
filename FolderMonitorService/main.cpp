#include <iostream>
#include <format>

#include "FMS.h"

int main() {
    SERVICE_TABLE_ENTRY ServiceTable[] =
    {
        {FMS_SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)ServiceMain},
        {NULL, NULL}
    };

    if (StartServiceCtrlDispatcher(ServiceTable) == FALSE)
        return GetLastError();

    return 0;
}