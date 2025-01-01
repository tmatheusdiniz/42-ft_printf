<h1 align="center">
  Common core 42 - ft_printf()
</h1>

<p align="center">
<img src="https://github.com/tmatheusdiniz/42-ft_printf/releases/download/images/ft_printf.webp" width="1000" hidth="200">
</P>
<p align="center">
    <b><i>This project is part of first milestone of the 42 cursus</i></b>
</p>

<h3 align="center">
    <a href="#-score">Score</a>
    <span> · </span>
    <a href="#-about">About</a>
    <span> · </span>
    <a href="#-usage">Usage</a>
    <span> · </span>
    <a href="#-resources">Resources</a>
    <span> · </span>
    <a href="#-testing">Testing</a>
</h3>

## 🖨️ ft_printf
<br>
<div align="center">
    <p><i>This project has already been graded</i></p>
    <img src="https://github.com/tmatheusdiniz/42-libft/releases/download/Note/score.png")>
</div>

## 🚨 Disclaimer
At 42, projects are made based on a few rules, such as: 

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 
 <b>Therefore, I didn't have the best possible efficiency in this project and, due to the rules, I ended the project having too many functions, and I didn't have time to analyze and improve the efficiency of my code, to have fewer functions.</b>

## 📖 About
> The aim of this project is to recreate the printf function from the standard <stdio.h> library of the C language.
> 
> I decided to make the project complete (with the bonus part).
### 🧐 How can you use ft_printf()

supported types: (%) c, s, i | d, x | X, p.  
supported flags : #0-+(space).

For more information on the use of flags, see: [Oracle Docs](https://docs.oracle.com/cd/E19253-01/817-6223/chp-fmt-1.2/index.html)

## ⚙️ Usage
> To be able to use ft_printf, you'll need to install the gcc compiler, if you don't already have it.</i>

<i>This project has a make file, so run “make” after cloning the project, and this will generate a library called libftprint in the root directory.</i>

<i>So now you need a .c file that contains a main() function that uses ft_printf. Example: </i>
```c
#include "ft_printf.h"
int main(void)
{
      ft_printf("my name is %s\n", "your_name");
      return (0);
}
```
## 🛠️ Resources
> Here are the resources I used to carry out this project:

[C language Docs](https://www.gnu.org/software/c-intro-and-ref/manual/c-intro-and-ref.html)

[Oracle Docs](https://docs.oracle.com/cd/E19253-01/817-6223/chp-fmt-1.2/index.html)

## 🧪 Testing
> I used many repositories for testing. In addition, I've also used a few main makes on my own.
> 
> If you want to do these tests, contact me at the e-mail address I have in my git.

#### References to other repositories i used to test
* [printfTester](https://github.com/Tripouille/printfTester)
* [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
* [ft_printf_test](https://github.com/cacharle/ft_printf_test)

## 📞 Contact me

If you are interested in contacting me with any questions, you can do so via slack <b>mreinald</b> or via the e-mail address i have set up on my github.
