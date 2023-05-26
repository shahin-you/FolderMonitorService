#include "FMS.h"

TCHAR FMS_SERVICE_NAME[] = TEXT("FolderMonitorService");

DWORD WINAPI ServiceCtrlHandler(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext) {
    switch (dwControl) {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        break;
    }
    return NO_ERROR;
}

DWORD WINAPI ServiceMain(DWORD dwNumServicesArgs, LPSTR* lpServiceArgVectors) {
    // Register the service control handler

    return NO_ERROR;
}