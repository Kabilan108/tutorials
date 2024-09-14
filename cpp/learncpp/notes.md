
---
### One Definition Rule (ODR) in C++:

•Part 1: Within a file
  - Each function, variable, type, or template in a given scope: only one definition
  - Definitions in different scopes don't violate this rule
  - violation causes compiler redefinition error

• Part 2: Within a program
  - Each function or variable in a given scope: only one definition
  - Applies across multiple files
  - Excludes functions and variables not visible to the linker
  - violation causes linker redefinition error

• Part 3: Exceptions
  - Types, templates, inline functions, and inline variables
  - Allowed to have duplicate definitions in different files
  - Each definition must be identical
  - violation causes undefined behavior
---

