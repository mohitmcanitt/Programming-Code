/*

We have a C Program file with an extension of .c i.e. hello.c file.
Step 1 is preprocessing of header files, all the statements starting with # (hash symbol) and comments are replaced/removed during the pre-processing with the help of a pre-processor. It generates an intermediate file with .i file extension i.e. a hello.i file.
Step 2 is a compilation of hello.i file. Compiler software translates the hello.i file to hello.s with assembly level instructions (low-level code).
Step 3, assembly-level code instructions are converted into machine-understandable code (binary/hexadecimal form) by the assembler. The file generated is known as the object file with an extension of .obj/.o i.e. hello.obj/hello.o file.
Step 4, Linker is used to link the library files with the object file to define the unknown statements. It generates an executable file with .exe/.out extension i.e. a hello.exe/hello.out file.
Next, we can run the hello.exe/hello.out executable file to get the desired output on our output window, i.e., Hello World!.


Conclusion
Compilation process in C is also known as the process of converting Human Understandable Code (C Program) into a Machine Understandable Code (Binary Code))
Compilation process in C involves four steps: pre-processing, compiling, assembling, and linking.
The preprocessor tool helps in comments removal, macros expansion, file inclusion, and conditional compilation. These commands are executed in the first step of the compilation process. Compiler software helps boost the program's performance and translates the intermediate file to an assembly file.
Assembler helps convert the assembly file into an object file containing machine-level code.
Linker is used for linking the library file with the object file. It is the final step in compilation to generate an executable file.



*/
