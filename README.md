<font size="20">The repository is archived</font> 

[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/CommPay?color=silver&style=flat-square)](https://github.com/Nakama3942/CommPay/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/CommPay/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/CommPay/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/CommPay/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/CommPay/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

# CommPay

## Overview
CommPay (full "Communal Payment") is a program that, based on its name, will calculate the amount to be paid for utility bills. This program takes into account all the coefficients that are calculated by utilities. If necessary, you can always change both the tariff (if it has changed) and the coefficient itself (if it differs in your region). [_So far, only tariffs are implemented as coefficients, but I will update this function soon._]

## Building
I will note the main thing: the program, its library and the necessary files are installed in the directory of user programs at the address /usr/locale (the author, by the way, it was divided into unnecessary subdirectories that were empty), and if a person installs this program as written independently (which, in principle, is the case), then first you need to open permanent access to this directory, for which you need to write the command:

> user@user:~/Downloads/CommPay$ chown user:user /usr/locale

Since initially this directory belongs to the root user, you need to write this command under the root. There is one step left: the directory where the libraries are installed must be set to LD_LIBRARY_PATH. I advise you to check. To do this, enter the command:

> user@user:~/Downloads/CommPay$ echo $LD_LIBRARY_PATH

If the /usr/locale/lib directory is not there, then add it with the command:

> user@user:~/Downloads/CommPay$ LD_LIBRARY_PATH=/usr/locale/lib

Now, after installation, the program will not swear at the lack of libraries. Now you can attend the installation. For this, a makefile has been added to the project, in which everything is already ready. It is enough to write the commands in the following order:

> user@user:~/Downloads/CommPay$ make

> user@user:~/Downloads/CommPay$ make install

> user@user:~/Downloads/CommPay$ make clean

With the first command, you build the program, install it with the second, and with the third one you clear your disk from intermediate files that are needed only at the time of the build.

## Deleting
After installing the program, you can delete the sources as well, however, all the files that are used for the program's operation are registered in the makefile, so it is not recommended to delete it. Therefore, you can save this file somewhere and when you need to uninstall this program, simply return to the directory of this file and write the command:

> user@user:~/Downloads/CommPay$ make uninstall

After that, you can also use this file. If you have a repository for storing makefiles of different programs, then it will be enough just to find the one you need: if your makefiles are renamed, then just run the make command in the terminal for the required file; and if not, then the file itself says which program it belongs to and you need to run it from the directory where it is located.
***
## Afterword
This program is written on the basis of my old (_and, by the way, the very first_) project. It was written in the C language, it had only four functions, it was written in one file, the function of changing currencies did not work (_as it turned out during the program rewriting, the format of writing to the file was simply not specified there, so the writing did not occur_). Then I abandoned this project until better times, but recently I took up it again: I rewrote it in C++, split it into a bunch of classes, which were spread across different libraries, and all the errors were fixed. In general, I applied all my new knowledge and technologies in this project and I want to develop it further along with increasing my experience and knowledge.

## Authors
<table>
    <tr>
        <td align="center"><a href="https://github.com/Nakama3942"><img src="https://avatars.githubusercontent.com/u/73797846?s=400&u=a9b7688ac521d739825d7003a5bd599aab74cb76&v=4" width="100px;" alt=""/><br /><sub><b>Kalynovsky Valentin</b></sub></a></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
    </tr>
</table>
