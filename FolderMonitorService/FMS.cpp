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
    SERVICE_STATUS_HANDLE hServiceStatus = RegisterServiceCtrlHandler(FMS_SERVICE_NAME, (LPHANDLER_FUNCTION)ServiceCtrlHandler);
    if (hServiceStatus == NULL)
        return GetLastError();

    //set process status
    SERVICE_STATUS serviceStatus;
    serviceStatus.dwServiceType = SERVICE_USER_OWN_PROCESS;
    serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_STOP | 
                                       SERVICE_ACCEPT_USER_LOGOFF | SERVICE_ACCEPT_TIMECHANGE;
    serviceStatus.dwWin32ExitCode = NO_ERROR;
    serviceStatus.dwServiceSpecificExitCode = NO_ERROR;
    serviceStatus.dwCurrentState = SERVICE_START_PENDING;
    serviceStatus.dwCheckPoint = 0;

    SetServiceStatus(hServiceStatus, &serviceStatus);

    return NO_ERROR;
}