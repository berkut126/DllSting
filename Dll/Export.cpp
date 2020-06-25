#include "pch.h"

extern "C" {
	__declspec(dllexport) HRESULT MyCFunc(std::wostream& out, LPCWSTR myString, int a) {
		out << myString << "\n" << a << std::endl;
		return 0;
	}
}
