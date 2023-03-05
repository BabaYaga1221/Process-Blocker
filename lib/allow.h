#include <cstdio>
// #include <unistd.h>
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <bits/stdc++.h>

// Check that the current process is a foreground process or not.
bool IsForegroundProcess(DWORD pid)
{
  HWND hwnd = GetForegroundWindow();
  if (hwnd == NULL)
    return false;

  DWORD foregroundPid;
  if (GetWindowThreadProcessId(hwnd, &foregroundPid) == 0)
    return false;

  return (foregroundPid == pid);
}

// ProcessHandler2 is function to handle the process when your first argument in text file is allow.
void ProcessHandler2(std::vector<std::string> a)
{
  PROCESSENTRY32 entry;
  entry.dwSize = sizeof(PROCESSENTRY32);

  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  for (int i = 0; i < a.size(); i++)
  {

    if (Process32First(snapshot, &entry) == TRUE)
    {
      // int c=0;
      while (Process32Next(snapshot, &entry) == TRUE)
      {
        if (strcmp(entry.szExeFile, a[i].c_str()) != 0)
        {
          bool check = false;
          for (int j = 0; j < a.size(); j++)
          {
            if (strcmp(entry.szExeFile, a[j].c_str()) == 0)
            {
              check = true;
              break;
            }
          }
          if (check == false)
          {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
            if (IsForegroundProcess(entry.th32ProcessID) == true)
            {
              TerminateProcess(hProcess, 1);
              std::cout << entry.szExeFile << std::endl;
              CloseHandle(hProcess);
            }
          }
        }
      }
    }
  }
  CloseHandle(snapshot);
}