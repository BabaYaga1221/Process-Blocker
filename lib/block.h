#include <cstdio>
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <bits/stdc++.h>

// function ProcessHandler1 is a function which runs when the first arugument of text file is block.
void ProcessHandler1(std::vector<std::string> a)
{

  PROCESSENTRY32 entry;
  entry.dwSize = sizeof(PROCESSENTRY32);

  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  for (int i = 0; i < a.size(); i++)
  {
    if (Process32First(snapshot, &entry) == TRUE)
    {
      while (Process32Next(snapshot, &entry) == TRUE)
      {

        if (strcmp(entry.szExeFile, a[i].c_str()) == 0)
        {
          HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
          TerminateProcess(hProcess, 1);
          std::cout << entry.szExeFile << std::endl;
          CloseHandle(hProcess);
        }
      }
    }
  }

  CloseHandle(snapshot);
}