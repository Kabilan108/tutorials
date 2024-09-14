
// before compilation, source files are preprocessed
// the preprocessor removes comments, ends files in a newline and processes `#include` directives
//
// result of preprocessing: translation unit -> compiled
//
// preprocessor replaces #include directive with contents of the included file.
//
//
// the `#define` directive can be used to create macros
// macros are ruless that define how input text is converted to output text
// object like & function like -> dont use function like
// object like:


// #define MY_NUMBER some_text
// avoid using these; legacy feature from C


// #define MY_DIRECTIVE // these can be usefulfor conditional compilation

---

#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}

// ifndef is if not defined
//
//
// C++ syntax:
// #ifdef PRINT_BOB -> #if defined(PRINT_BOB)
// #ifndef PRINT_BOB -> #if !defined(PRINT_BOB)

---

// use `#if 0` to stop some code from being compiled; `#if 1` guarantees compilation
//
