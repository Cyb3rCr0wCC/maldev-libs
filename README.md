### Introduction
This repository contians helper libraries and tools that i used during my malware development journey.

### Components
-   **encryption/enc.h** - this contain basic xor functionality for c programming language to bypass static detection engines.
-   **scripts/tring-to-array.sh** - this is the bash scrip to create char array from given string again to bypass some static analysis and detection.
-   **scripts/string-stack.py** - This can be used to store string in stack to able to create position independent shellcode.
-   **crypter.exe/crypter.bin** - Executable program for encryption and decryption.
-   **scripts/opcode.sh** - Extracts opcodes from shellcode, that can be injectabel to memory.
-   **addresshunter.h**   - Library container functions that hels us to load dlls at the runtime for position independent shellcode development
-   **samples/**          - Sample malwares that uses these libraries.
