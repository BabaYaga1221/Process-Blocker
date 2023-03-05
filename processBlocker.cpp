#include <cstdio>
// #include <unistd.h>
#include <iostream>
#include "lib/allow.h"
#include "lib/block.h"
#include <bits/stdc++.h>
using namespace std;

// driver function
int main()
{
  fstream file;
  bool Flag = false;
  std::vector<std::string> blocklist, allowlist;
  string process, filename;
  filename = "Process.txt";
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