// this program will print the C++ language standard being used by the compiler
// from learncpp.com

#include <iostream>

const int numStandards = 7;
// the C++26 stdCode is a placeholder since it is not finalized
const long stdCode[numStandards] = { 
  199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L
};
const char* stdName[numStandards] = { 
  "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" 
};

long getCPPStandard() {
  #if defined (_MSVC_LANG)
    // visual studio
    return _MSVC_LANG;
  #elif defined (_MSC_VER)
    // older visual studio
    return -1;
  #else 
    // __cplusplus is the intended way to query the language standard code
    return __cplusplus;
  #endif
}

int main() {
  long standard = getCPPStandard();

  if (standard == -1) {
    std::cout << "Error: can't determine language standard. \n";
    return 0;
  }

  for (int i = 0; i < numStandards; ++i) {
    if (standard == stdCode[i]) {
      std::cout << "compiler version: " << stdName[i] << "(" << standard << "L)\n";
      break;
    }

    if (standard < stdCode[i]) {
      std::cout << "compiler version: " << stdName[i] << " prerelease (" << standard
        << "L)\n";
      break;
    }
  }

  return 0;
}
