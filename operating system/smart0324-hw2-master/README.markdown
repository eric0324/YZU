#Hw2 : Shell it!

a homework of making your own shell

due date: 5/8 23:59 am (Late homework is **NOT** accepted)
All of our homework would be verified on our server. (TAs will test your code on our machine) 

---

##The goal of this homework:
In this homework, we ask you to create your own shell to mimic current one with limited functionality. We assume that you are familiar with C programming and basic operations of a UNIX shell. Then, you may focus on learning how to fork, exec a program and control data passing between programs.

##Requirements:
Your shell must deal with commands by yourself. It means you need to divide the command into tokens and fork a child process to execute command with arguments. Hint: you may need to use fork(…) and execvp(…) to help you to accomplish this goal.
For example, a user may use complex commands like “ls -al”, you need to interpret it correctly and fork a child process to execute “ls” with argument “-al”, just like things that done by your original shell. (50pts) 
* make sure you include a indicator to allow user input their command.
For example: print a symbol “[hostname] >” and echo user’s inputs.
![DEMO](./shell_test.jpg)

* (10 pts) provide “exit” command to return to original shell and prevent user use “Ctrl+D” to exit shell accidentally.

* (10 pts) allow TAs input a shell script file to test your program directly by “<” operate.
For example: use ./a.out < script_file.sh to input several commands in the same time.

* (10 pts) make sure commands “cd, cd.., cd XXX” work correctly in your own shell.
NOTE: The environment of its mother process (your original shell) will still untouched.

* (20 pts) provide “|, >, <” operator inside your shell.
For example: use "ls- al | more" to pipe output of *ls* to *more* (a pager program)

* (Bonus 10+10pts) Provide functions that add command history (allow user to navigate used commands by Arrow keys) and tab-completion to user.

**Checkout the demo program edenShell.out for more details.!
Also, here is an example script_file.sh, you may use following command to execute it.
./edenShell.out < script_file.sh

##Please write a report:
You need to mention at least three things: 
1. What is your creation? (in detail) *How to make compile and use your work?* 
   (Also, prepare a checklist for each requirement)

2. How it works, demo it BOTH in text(commands) and screen snapshot (check the example on the right side), *the snapshot MUST work on your own account.*

3. Convince me you are the best! Write down the reasons or your difficulty in doing thiw homework.

##Howto:
(In the following text, we assume your student ID is s1234567, please replace it with your correct student ID and follow the steps **exactly**!)

1. Clone your private repository of hw1 to your home directory on server or another suitable location from our organisation on [GitHub](https://github.com/YZU-CSE-CS305-Intro-to-OS)

2. After you start to deal with your homework, add a file **report_s1234567.md** as your report and **code_s1234567.c or cpp** as your program. Then, commit it. (Do not commit multiple copies of your work.)

3. Complete your program and write your report with Markdown.
*. Please commit your homework when you have progress.

4. Make sure you have complete the assignment and prepare a clear demo in your report. **Do it ON YOUR OWN and ON TIME.**

NOTE: You would get 0 point, if you don’t follow rules, especially on the filename and format of your work.
