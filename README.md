All programs have already been compiled.
Simply open the monitor program and select file> open project
then navigate to the desired project folder and choose the .amp file
***Notes for new projects***
When creating a new project there are two changes that need to be made
1.
In the source files window, add the compiler flag -std=c99 for compatability
![image](https://github.com/jaspack/ECE346-Labs-in-C/assets/141270994/04b75b06-b4b1-4c8a-bc7c-8434bcfd2083)

2.
After attempting to compile the project a makefile will be made. Edit the file with notepad to
move any header files to the correct line. Additionally, an existing makefile can be copy and paste into
another project directory if the projects use the same files.
![image](https://github.com/jaspack/ECE346-Labs-in-C/assets/141270994/48a4927d-8e8c-4877-8151-60ca5be2f8d0)
