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
	{0x04, "����м�"},
	{0x05, "X1 ��갴ť"},
	{0x06, "X2 ��갴ť"},
	{0x08, "BACKSPACE ��"},
	{0x09, "Tab ��"},
	{0x0C, "CLEAR ��"},
	{0x10, "SHIFT ��"},
	{0x11, "CTRL ��"},
	{0x12, "Alt ��"},
	{0x13, "PAUSE ��"},
	{0x14, "CAPS LOCK ��"},
	{0x20, "�ո��"},
	{0x21, "PAGE UP ��"},
	{0x22, "PAGE DOWN ��"},
	{0x23, "END ��"},
	{0x24, "HOME ��"},
	{0x25, "LEFT ARROW ��"},
	{0x26, "UP ARROW ��"},
	{0x27, "RIGHT ARROW ��"},
	{0x28, "DOWN ARROW ��"},
	{0x29, "SELECT ��"},
	{0x2A, "PRINT ��"},
	{0x2B, "EXECUTE ��"},
	{0x2C, "PRINT SCREEN ��"},
	{0x2D, "INS ��"},
	{0x2E, "DEL ��"},
	{0x2F, "HELP ��"},
	{0x30, "0 ��"},
	{0x31, "1 ��"},
	{0x32, "2 ��"},
	{0x33, "3 ��"},
	{0x34, "4 ��"},
	{0x35, "5 ��"},
	{0x36, "6 ��"},
	{0x37, "7 ��"},
	{0x38, "8 ��"},
	{0x39, "9 ��"},
	{0x41, "A ��"},
	{0x42, "B ��"},
	{0x43, "C ��"},
	{0x44, "D ��"},
	{0x45, "E ��"},
	{0x46, "F ��"},
	{0x47, "G ��"},
	{0x48, "H ��"},
	{0x49, "I ��"},
	{0x4A, "J ��"},
	{0x4B, "K ��"},
	{0x4C, "L ��"},
	{0x4D, "M ��"},
	{0x4E, "N ��"},
	{0x4F, "O ��"},
	{0x50, "P ��"},
	{0x51, "Q ��"},
	{0x52, "R ��"},
	{0x53, "S ��"},
	{0x54, "T ��"},
	{0x55, "U ��"},
	{0x56, "V ��"},
	{0x57, "W ��"},
	{0x58, "X ��"},
	{0x59, "Y ��"},
	{0x5A, "Z ��"},
	{0x5B, "�� Windows ��"},
	{0x5C, "�� Windows ��"},
	{0x60, "���ּ��� 0 ��"},
	{0x61, "���ּ��� 1 ��"},
	{0x62, "���ּ��� 2 ��"},
	{0x63, "���ּ��� 3 ��"},
	{0x64, "���ּ��� 4 ��"},
	{0x65, "���ּ��� 5 ��"},
	{0x66, "���ּ��� 6 ��"},
	{0x67, "���ּ��� 7 ��"},
	{0x68, "���ּ��� 8 ��"},
	{0x69, "���ּ��� 9 ��"},
	{0x6A, "�˺ż�"},
	{0x6B, "�Ӻż�"},
	{0x6C, "�ָ�����"},
	{0x6D, "���ż�"},
	{0x6E, "����"},
	{0x6F, "���ż�"},
	{0x70, "F1 ��"},
	{0x71, "F2 ��"},
	{0x72, "F3 ��"},
	{0x73, "F4 ��"},
	{0x74, "F5 ��"},
	{0x75, "F6 ��"},
	{0x76, "F7 ��"},
	{0x77, "F8 ��"},
	{0x78, "F9 ��"},
	{0x79, "F10 ��"},
	{0x7A, "F11 ��"},
	{0x7B, "F12 ��"},
	{0x90, "NUM LOCK ��"},
	{0x91, "SCROLL LOCK ��"},
	{0xA0, "�� SHIFT ��"},
	{0xA1, "�� SHIFT ��"},
	{0xA2, "�� Ctrl ��"},
	{0xA3, "�� Ctrl ��"},
	{0xA4, "�� ALT ��"},
	{0xA5, "�� ALT ��"},
};
const std::string CONFIG_FILE = "./config/config.cfg"; // ָ�������ļ���·��������
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
	cout << "��ס" << ((readStoredValue(CONFIG_FILE) == 0) ? "�����" : virtualKeyMap[readStoredValue(CONFIG_FILE)]) << ", ������ת����" << endl;
	mciSendString(L"open ./config/bgm.mp3 alias athley", NULL, 0, NULL);
	mciSendString(L"play athley ", NULL, 0, NULL);
	entrance();
	return 0;
}





