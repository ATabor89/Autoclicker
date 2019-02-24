#include <Windows.h>

#include <thread>
#include <chrono>
#include <iostream>

void LeftClick()
{
	INPUT Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
	std::cout << "Press F6 to toggle autoclicker || Press F7 to exit\n\n";

	bool click = false;
	std::chrono::milliseconds clickInterval = std::chrono::milliseconds(50);

	while (true)
	{
		if (GetAsyncKeyState(VK_F6) & 1)
			click = !click;

		if (GetAsyncKeyState(VK_F7) & 1)
			return 0;

		if (click)
		{
			LeftClick();
			std::this_thread::sleep_for(clickInterval);
		}
		else
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //throttle the loop when not clicking
	}

	return 0;
}

//int main()
//{
//
//	bool click = false;
//	std::chrono::milliseconds clickInterval = std::chrono::milliseconds(100);
//
//	while (true)
//	{
//		if (GetAsyncKeyState(VK_F6))
//			click = !click;
//
//		if (GetAsyncKeyState(VK_F7))
//			return 0;
//
//		if (click)
//		{
//			while (true)
//			{
//				if (GetAsyncKeyState(VK_F6))
//				{
//					click = !click;
//					break;
//				}
//
//				if (GetAsyncKeyState(VK_F7))
//					return 0;
//
//				LeftClick();
//				std::this_thread::sleep_for(clickInterval);
//			}
//		}
//		else
//			std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	}
//
//	return 0;
//}