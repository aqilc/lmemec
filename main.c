
#include "consts.h"
#include "utils/click.h"
#include "utils/misc.h"

int main() {
  
  //clickl(300, 300);

  printcoords(getres());
  printf("\n");
  printcoords(pointtocoords(getmouse()));

  
  HWND WindowHandle = FindWindow(NULL, PROCESS_NAME);
  if (WindowHandle == NULL) {
    printf("\nemail Could not find window.\nError: %ld\n", GetLastError());
    return 1;
  }

  printf("WindowHandle: %d", WindowHandle->unused);
  DWORD PID;
  GetWindowThreadProcessId(WindowHandle, &PID);
  PVOID hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, PID);
  if (hProcess == NULL) {
    printf("Error: Could not open process\n");
    return 1;
  }
  printf("Process handle: %p", hProcess);
}
