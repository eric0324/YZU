#Hw1 : Make a call directly

a short homework of using system call

due date: 3/29 23:59 am (Late homework is **NOT** accepted)

---

All of our homework would be verified on our server. (TAs will test your code on our machine) 
The ip address of our server is 140.138.145.82 (ssh port: 22). Before you get started, please read the document “Happy coding on UNIX.pdf” first. And, **implement your homework in C/C++** language. (My suggestion: C Lang.)

##The goal of this homework:
In this homework, we want to help you to understand the usage of GitHub and system call (To know the way to make/invoke a system call). Therefore, You need to build your own program with system calls.


##Rules:

• **Each program must invoke the system call using syscall directly (i.e., no C convenience functions).**
• Each program must produce some demonstrable and comprehensible result (e.g., provide console outputs, make changes to the file system, etc.).
• You may use additional system calls to help do your work, but each program should center around one particular system call’s functionality.
• You may resort to “normal” C or C++ (data structures, libraries, etc.) to process the results of your system call.
• Implement whatever command-line parameters you like, to make your programs more flexible or powerful.

##References:
Except to read this article and sample code, you should search another resources on the www.
Check follow links to study more on system call:
http://asm.sourceforge.net/intro/hello.html >> a hello world in assembly.
http://www.freebsd.org/cgi/man.cgi?query=syscall&sektion=2 >> man page for syscall() 
http://www.freebsd.org/doc/en/books/developers-handbook/x86-system-calls.html
**Check the file hw_1_sample.cpp, too. (Please DO NOT duplicate my result in your homework)**
...and make your own version to show your creativity.

##Please write a report: (in Chinese or English, use Markdown to write it)
Of course, you should prepare a document of your work in Chinese or English(foreign student) .

You need to mention a least three things: 
1. What is your creation? (in detail) *How to make compile and use your work?*
2. How it works, demo it BOTH in text(commands) and screen snapshot (check the example on the right side), *the snapshot MUST work on your own account.*
3. Convince me you are the best! Write down the reasons.


##Howto:
(In the following text, we assume your student ID is s1234567, please replace it with your correct student ID and follow the steps **exactly**!)

1. Clone your private repository of hw1 to your home directory on server or another suitable
location from our organisation on [GitHub](https://github.com/YZU-CSE-CS305-Intro-to-OS)
2. After you start to deal with your homework, add a file **report_s1234567.md** as your report and **code_s1234567.c** as your program. Then, commit it
3. Complete your program and write your report with Markdown (If you are not familiar with it, check “Happy coding on UNIX”)

*. Please commit your homework when you have progress.!
4. Make sure you have complete the assignment and prepare a clear demo in your report. **Do it ON YOUR OWN and ON TIME.**

NOTE: You would get 0 point, if you don’t follow rules, especially on the filename and format of your work.
