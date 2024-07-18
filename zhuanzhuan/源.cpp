#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include<map>
#include<thread>
#include<string>
#pragma comment(lib,"winmm.lib")
using namespace std;
std::map<int, std::string> virtualKeyMap = {
	{0x04, "Êó±êÖÐ¼ü"},
	{0x05, "X1 Êó±ê°´Å¥"},
	{0x06, "X2 Êó±ê°´Å¥"},
	{0x08, "BACKSPACE ¼ü"},
	{0x09, "Tab ¼ü"},
	{0x0C, "CLEAR ¼ü"},
	{0x10, "SHIFT ¼ü"},
	{0x11, "CTRL ¼ü"},
	{0x12, "Alt ¼ü"},
	{0x13, "PAUSE ¼ü"},
	{0x14, "CAPS LOCK ¼ü"},
	{0x20, "¿Õ¸ñ¼ü"},
	{0x21, "PAGE UP ¼ü"},
	{0x22, "PAGE DOWN ¼ü"},
	{0x23, "END ¼ü"},
	{0x24, "HOME ¼ü"},
	{0x25, "LEFT ARROW ¼ü"},
	{0x26, "UP ARROW ¼ü"},
	{0x27, "RIGHT ARROW ¼ü"},
	{0x28, "DOWN ARROW ¼ü"},
	{0x29, "SELECT ¼ü"},
	{0x2A, "PRINT ¼ü"},
	{0x2B, "EXECUTE ¼ü"},
	{0x2C, "PRINT SCREEN ¼ü"},
	{0x2D, "INS ¼ü"},
	{0x2E, "DEL ¼ü"},
	{0x2F, "HELP ¼ü"},
	{0x30, "0 ¼ü"},
	{0x31, "1 ¼ü"},
	{0x32, "2 ¼ü"},
	{0x33, "3 ¼ü"},
	{0x34, "4 ¼ü"},
	{0x35, "5 ¼ü"},
	{0x36, "6 ¼ü"},
	{0x37, "7 ¼ü"},
	{0x38, "8 ¼ü"},
	{0x39, "9 ¼ü"},
	{0x41, "A ¼ü"},
	{0x42, "B ¼ü"},
	{0x43, "C ¼ü"},
	{0x44, "D ¼ü"},
	{0x45, "E ¼ü"},
	{0x46, "F ¼ü"},
	{0x47, "G ¼ü"},
	{0x48, "H ¼ü"},
	{0x49, "I ¼ü"},
	{0x4A, "J ¼ü"},
	{0x4B, "K ¼ü"},
	{0x4C, "L ¼ü"},
	{0x4D, "M ¼ü"},
	{0x4E, "N ¼ü"},
	{0x4F, "O ¼ü"},
	{0x50, "P ¼ü"},
	{0x51, "Q ¼ü"},
	{0x52, "R ¼ü"},
	{0x53, "S ¼ü"},
	{0x54, "T ¼ü"},
	{0x55, "U ¼ü"},
	{0x56, "V ¼ü"},
	{0x57, "W ¼ü"},
	{0x58, "X ¼ü"},
	{0x59, "Y ¼ü"},
	{0x5A, "Z ¼ü"},
	{0x5B, "×ó Windows ¼ü"},
	{0x5C, "ÓÒ Windows ¼ü"},
	{0x60, "Êý×Ö¼üÅÌ 0 ¼ü"},
	{0x61, "Êý×Ö¼üÅÌ 1 ¼ü"},
	{0x62, "Êý×Ö¼üÅÌ 2 ¼ü"},
	{0x63, "Êý×Ö¼üÅÌ 3 ¼ü"},
	{0x64, "Êý×Ö¼üÅÌ 4 ¼ü"},
	{0x65, "Êý×Ö¼üÅÌ 5 ¼ü"},
	{0x66, "Êý×Ö¼üÅÌ 6 ¼ü"},
	{0x67, "Êý×Ö¼üÅÌ 7 ¼ü"},
	{0x68, "Êý×Ö¼üÅÌ 8 ¼ü"},
	{0x69, "Êý×Ö¼üÅÌ 9 ¼ü"},
	{0x6A, "³ËºÅ¼ü"},
	{0x6B, "¼ÓºÅ¼ü"},
	{0x6C, "·Ö¸ô·û¼ü"},
	{0x6D, "¼õºÅ¼ü"},
	{0x6E, "¾äµã¼ü"},
	{0x6F, "³ýºÅ¼ü"},
	{0x70, "F1 ¼ü"},
	{0x71, "F2 ¼ü"},
	{0x72, "F3 ¼ü"},
	{0x73, "F4 ¼ü"},
	{0x74, "F5 ¼ü"},
	{0x75, "F6 ¼ü"},
	{0x76, "F7 ¼ü"},
	{0x77, "F8 ¼ü"},
	{0x78, "F9 ¼ü"},
	{0x79, "F10 ¼ü"},
	{0x7A, "F11 ¼ü"},
	{0x7B, "F12 ¼ü"},
	{0x90, "NUM LOCK ¼ü"},
	{0x91, "SCROLL LOCK ¼ü"},
	{0xA0, "×ó SHIFT ¼ü"},
	{0xA1, "ÓÒ SHIFT ¼ü"},
	{0xA2, "×ó Ctrl ¼ü"},
	{0xA3, "ÓÒ Ctrl ¼ü"},
	{0xA4, "×ó ALT ¼ü"},
	{0xA5, "ÓÒ ALT ¼ü"},
};
const std::string CONFIG_FILE = "./config/config.cfg"; // Ö¸¶¨ÅäÖÃÎÄ¼þµÄÂ·¾¶»òÃû³Æ
const std::string Velocity = "./config/velocity.cfg";
atomic<bool> stop(false);
int readStoredValue(string FILE) {
	int value = 0;
	std::ifstream configFile(FILE);
	if (configFile.is_open()) {
		configFile >> value;
		configFile.close();
	}
	return value;
}
void entrance()
{
	while (true)
	{
		while (GetKeyState(readStoredValue(CONFIG_FILE) == 0 ? VK_XBUTTON1 : readStoredValue(CONFIG_FILE)) < 0) {
			mouse_event(MOUSEEVENTF_MOVE, readStoredValue(Velocity) == 0 ? 800 : readStoredValue(Velocity), 0, 0, 0);
			Sleep(1);
		}
	}
}
int main() {
	cout << "°´×¡" << ((readStoredValue(CONFIG_FILE) == 0) ? "Êó±ê²à¼ü" : virtualKeyMap[readStoredValue(CONFIG_FILE)]) << ", ÁúÍõ¿ª×ª¿©£¡" << endl;
	mciSendString(L"open ./config/bgm.mp3 alias athley", NULL, 0, NULL);
	mciSendString(L"play athley ", NULL, 0, NULL);
	entrance();
	return 0;
}





