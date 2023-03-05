# Process Blocker
Process Blocker is a command-line tool developed in C++ that allows users to block unwanted processes on their computer. With this tool, users can prevent certain applications from running, thus improving the performance of their system and preventing security threats.

# Features
Process Blocker offers the following features:

 - Block any process by its executable name
 - Unblock previously blocked processes 
 - View a list of currently blocked processes
 - Set up a list of processes to automatically block on startup

# Installation
Process Blocker can be installed by following these steps:

1. Download the latest version of Process Blocker from the project's GitHub repository.
2. Extract the contents of the downloaded ZIP file to a directory of your choice.
3. Open a command prompt or terminal window and navigate to the directory where Process Blocker was extracted.
4. Edit **Process.txt** file to either block or allow the process. 
5. Compile the file ad run the process-blocker executable file to start the program.

# Usage
Process Blocker can be used by running the __process-blocker__ executable file from a command prompt or terminal window. The following commands are available:

- **Compilation** - Compile the C++ file named as *processBlocker.cpp*
- __Process.txt__ - Edit this file in the manner like.
    - **allow/block** - first argument is either allow or block.
    - **allowlist** - edit the next line of text as like this *{ process1.exe , process2.exe }*. Add the file name as extension in the list.
    - **blocklist** - edit the next line of txt file like this *{ process1.exe , process2.exe }*. Add the file name as extension in the list.
- __Execute__ - Run the complied file and block the process which you want.

# Example
To block a process named notepad.exe, run the following command:

for the txt file - **Process.txt**
```
allow
{ brave.exe , explorer.exe , Code.exe , WindowsTerminal.exe }
{ notepad.exe , wordpad.exe , Taskmgr.exe }
```
#### OR
```
block
{ brave.exe , explorer.exe , Code.exe , WindowsTerminal.exe }
{ notepad.exe , wordpad.exe , Taskmgr.exe }
```

Open the windows terminal in the same folder and type -
```
$ cpp processBlocker.cpp -o processBlocker
$ ./processBlocker.exe
```

# Contributions
Contributions to Process Blocker are welcome! 