Test-KSyntaxHightlight
----------------------

It's a simple gui app with stupid plugins for syntax highlighting.
The first one is based on KSyntaxHighlight, the second - on Qt's example.

## Build

You must have Qt5 and KF5.

```
cmake -S . -B build
cmake --build build
```

## Usage

1. Open app;
2. Type some C++ code;
3. Choose from top menu "Highlighting-\>Open..."
4. Choose the one of built .so libraries;
5. ?????
6. PROFIT!
