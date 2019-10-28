# caesar_cipher
It is "toy"-project for learning Caesars cipher.

#run  
Program use stdout for main output and stderr for error output.  
Use command promt like this:  
$ caesar_cipher.exe [key] [offset] [input_filename] optional >log.txt 2>&1 // redirect stdout and stderr in file log.txt  

#notes
- key:
	- [-e] // encrypt file
	- [-d] // decrypt file
- offset:
	- integer number in [1, 25] //  you may redefined it in src code of program (need recompile)
- input_filename:
	- any file like [name].txt // file must be in the same directory where program is called
