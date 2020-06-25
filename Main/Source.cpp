#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <iostream>

typedef HRESULT(__cdecl* LPFNDLLFUNC1)(std::wostream& out, LPCWSTR myString, int a);

int main() {

	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
	HRESULT hrReturnVal;

	hDLL = LoadLibrary("D:\\Projects\\C++\\DllSting\\Debug\\Dll");

	LPCWSTR myString = L"nisansaio";
	int a = 7;

	if (NULL != hDLL)
	{
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "MyCFunc");
		if (NULL != lpfnDllFunc1)
		{
			// call the function
			hrReturnVal = lpfnDllFunc1(std::wcout, myString, a);
		}
		else
		{
			// report the error
			hrReturnVal = ERROR_DELAY_LOAD_FAILED;
		}
		FreeLibrary(hDLL);
	}
	else
	{
		hrReturnVal = ERROR_DELAY_LOAD_FAILED;
	}
	return 0;
}