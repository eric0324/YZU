# Happy coding on UNIX

a short introduction

Garrett Yeh - March 22, 2015

---

All of our homework must be done on this work station. (TAs will test your code on this machine) !

The ip address of our server is 140.138.145.82 (ssh port: 22).

id/pw: The TA 徐皓 just sent id and password to each of you last week. If you miss it, please contact with TA 徐皓. He will help you and send new password to your mailbox (@mail.yzu) again.

##Connection tools:

If you are using win32, the PuTTY is the best choice to get connection with our course server.

Get it only from this website: http://ftp.yzu.edu.tw/putty/download.html (use English version **ONLY**)

for Mac use, I believe the Terminal.app which was shipped with Mac OS X will be good enough.

Of course, you may use another well-known terminal software, for example: “iTerm2” to manage it. 

##Coding references:

Please read man page carefully before you engage with any new function.
BSD: http://www.freebsd.org/cgi/man.cgi <— first choice, we are using FreeBSD on the course server

Linux: http://linux.die.net/man/

Here is some instruction of using man page:
http://linux.vbird.org/linux_basic/0160startlinux.php#manual

##Coding tool (text editor)

The VIM is the text editor that we presented on the course.
Here, I recommend each student take a look to this web page for tips of using vim:
http://blog.vgod.tw/2009/12/08/vim-cheat-sheet-for-programmers/

##Using Git and GitHub:

Slides of our supplemental courses:
https://www.peterdavehello.org/slides/2015_YZU_CSE_1032_Git_Essential/

Our GitHub organization:
https://github.com/YZU-CSE-CS305-Intro-to-OS

Another reference:
http://www.slideshare.net/lkiral/git-34157836?related=2 (tutorial)
http://www.slideshare.net/littlebtc/git-5528339 (tutorial)
http://blog.miniasp.com/post/2013/11/04/Learning-Git-Part-2-Master-Git-in-30-days.aspx (tips)

##Complete your report with markdown!

In this course, please use markdown to complete your reports and commit it with your homework.

**Markdown** is a **markup language** with plain text formatting syntax designed so that it can be converted to HTML and many other formats using a tool by the same name.

Markdown in GitHub:
https://help.github.com/articles/markdown-basics/ (tutorial)
https://help.github.com/articles/github-flavored-markdown/ <— GitHub Flavored Markdown!


Complete documents of Markdown syntax: http://daringfireball.net/projects/markdown/syntax
(Chinese version: http://markdown.tw)
A powerful on-line editor: https://stackedit.io <— Check it first!

##There are some commands for you!

ls
> list files in this directory

cp A B
> copy a file A to B

mv A B
> rename file A to B

rm A
> remove file A

vim A
> use vim to edit file A

g++ A.cpp -o B.o
> compile A.cpp to an exec file named B.o
note:  .o is not required, please don't upload it.


Here is a reference for linking the libraries (the tutorial)
http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html

A common workflow of preparation of your homework
(In the following text, we assume your student ID is s1234567 and # is the NUMBER of homework in one digit, Please replace it with your student ID and follow the steps exactly!)

 1. Clone your private repository of hw# to your home directory on
    server or another suitable location from our organisation on [GitHub](https://github.com/YZU-CSE-CS305-Intro-to-OS)

 2. After you start to deal with your homework, add a file report_s1234567_OSHw#.md as your report and code_s1234567_OSHw#.c as your program. Then, commit it!!

 3. Complete your program and write your report with Markdown! Please commit your homework when you have progress.

 4. Make sure you have complete the assignment and prepare a clear demo in your report. **Do it ON YOUR OWN and ON TIME.**


Okay, if you guys have further question... find me/TAs in the class, mail to me/TAs or meet me in my office hours.
