#include <cstdio>
// #include <unistd.h>
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <bits/stdc++.h>
using namespace std;

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
              cout << entry.szExeFile << endl;
              CloseHandle(hProcess);
            }
          }
        }
      }
    }
  }
  CloseHandle(snapshot);
}

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
          cout << entry.szExeFile << endl;
          CloseHandle(hProcess);
        }
      }
    }
  }

  CloseHandle(snapshot);
}

// driver function
int main()
{
  fstream file;
  bool Flag = false;
  std::vector<std::string> blocklist, allowlist;
  string process, filename;
  filename = "rules.txt";
  file.open(filename.c_str());
  file >> process;
  string check = process;
  while (file >> process)
  {
    if (process == "}")
    {
      Flag = true;
      continue;
    }
    if (process == "{" || process == ",")
      continue;
    if (Flag == true)
    {
      blocklist.push_back(process);
    }
    else
      allowlist.push_back(process);
  }
  cout << check << endl;
  for (auto i : blocklist)
    cout << i << " ";
  cout << endl;
  for (auto i : allowlist)
    cout << i << " ";
  cout << endl;
  while (true)
  {
    if (check == "allow")
    {
      ProcessHandler2(allowlist);
    }
    else
    {
      ProcessHandler1(blocklist);
    }
  }
  file.close();
  return 0;
}