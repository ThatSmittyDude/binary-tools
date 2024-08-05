# binaries
This repo has utilities to dump binary, hex and octal files from executable files
--------------------------------------------------------------------

COMPILE:

 Simply use gcc or tcc to compile these codes
 
  I recomend gcc, to install `sudo apt install gcc`
    
  Heres how to compile:
      
      gcc hexdump.c -o hexdump
      
      gcc bindump.c -o bindump
      
      gcc octaldump.c -o octaldump
      
--------------------------------------------------------------------

INSTALL:
  
  `sudo cp bindump hexdump octaldump /bin`
  
--------------------------------------------------------------------

USER GUIDE:

  To run a hexdump:
      `hexdump <targetFile> <outputfile>`
  
  To run a bindump:
      `bindump <targetFile> <outputFile>`
  
  To run an octaldump:
      `octalDump <targetFile> <outputFile>`

  ------------------------------------------------------------------
  
  These should be fairly simple to compile and use froma command line
  
  I hope you like them!

  And of course, help and feedback is always welcome!
