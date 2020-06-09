#include <iostream>
#include <Windows.h>

int main()
{
    int key;
    while (true) {
        for (int i = 0; i < 26; i++) { // 26번 반복
            key = 65 + i; // 먼저 대문자 처리
            if (GetAsyncKeyState(key) & 0x0001) { // 키가 눌러졌다면...
                if (GetKeyState(VK_SHIFT) < 0 || GetKeyState(VK_CAPITAL) == 1) { // 쉬프트 키가 눌려져 있거나 CapsLock이 켜져있다면...
                    std::cout << (char)key; // 대문자용, 그대로 출력
                }
                else { // 그 외의 경우라면...
                    std::cout << (char)(key + 32); // 소문자용, key값에 32를 더해줌으로써 소문자 키가 있는 곳으로 점프한 후 ----> 출력
                }
            }
        }
    }
}
