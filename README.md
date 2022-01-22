# Spencer's Minimal GLIBC printf Mockup
This small reimplementation only has a few format specificiers.
As the project moved forward I wanted to work on others, and fealt like I had learned enought about "va\_arg".
## Format Specificers
```
 u: unsigned decimal integer
 c: unsigned char
 s: char* or string 
```
## Installation
All of the functionality is inside one self contained header file.
The "my\_printf\.c" has a small example of how to use the format specifiers.
The basic binary can be built in the source directory with gcc.
Just compile the "\.c" file with the aforementioned gcc compiler and it should be good to go.
## Misc\.
Finally, there are two tests, using a very minimal testing framework.
These were created to learn how to write unit test with the c language.
