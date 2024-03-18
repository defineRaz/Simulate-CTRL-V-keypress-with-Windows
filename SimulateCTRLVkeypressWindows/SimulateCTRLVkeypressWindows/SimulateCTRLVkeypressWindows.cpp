// SimulateCTRLVkeypressWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.
#define WINVER 0x0500
#include <windows.h>

#include <iostream>

int main()
{

    // Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    int counter = 0;

    while (counter != 3)
    {
        // Press the "Ctrl" key
        ip.ki.wVk = VK_CONTROL;
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Press the "V" key
        ip.ki.wVk = 'V';
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the "V" key
        ip.ki.wVk = 'V';
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

        // Release the "Ctrl" key
        ip.ki.wVk = VK_CONTROL;
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        counter++;
        Sleep(1000); // pause for 1 second

    }

    // We won't actually ever reach this point
    return 0;

}

