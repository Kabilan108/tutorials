// only declarations and definitions can be in a namespace; no executable namespaces
// you can define functions in namespaces



void foo();  // okay: function forward declaration
int x;       // compiles but discouraged: non-const global variable definition without initializer
int y { 5 }; // compiles but discouraged: non-const global variable definition with initializer
// x = 5;       // compile error: executable statements are not allowed in namespaces



// :: is a scope resolution operator -> identifies namespace that contains symbol

// `using directive` -> dumps names from namespace into scope

