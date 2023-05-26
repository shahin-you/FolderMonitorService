#pragma once
#include <windows.h>

extern TCHAR FMS_SERVICE_NAME[];

DWORD WINAPI ServiceMain(DWORD dwNumServicesArgs, LPSTR* lpServiceArgVectors);
DWORD WINAPI ServiceCtrlHandler(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext);