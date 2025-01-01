<h1 align="center">
  Common core 42 - ft_printf()
</h1>

<p align="center">
<img src="https://github.com/tmatheusdiniz/42-ft_printf/releases/download/images/ft_printf.webp" width="1000" hidth="400">
</P>
<p align="center">
    <b><i>This project is part of first milestone of the 42 cursus</i></b>
</p>

<h3 align="center">
    <a href="#-index">Index</a>
    <span> · </span>
    <a href="#FFD700-about">About</a>
    <span> · </span>
    <a href="#%EF%B8%8F-resources">Resources</a>
<h3/>

## 🖨️ ft_printf
<br>
<div align="center">
    <p><i>This project has already been graded</i></p>
    <img src="https://github.com/tmatheusdiniz/42-libft/releases/download/Note/score.png")>
</div>

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
## Resources
> Here are the resources I used to carry out this project:

