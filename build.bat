@echo --------------------------------Build------------------------------------
del ReflexAST.exe
win_bison --report=all --report-file=bisonreport -d -o parser.cpp parser.y 
win_flex -otokens.cpp tokens.l 
g++ -static-libgcc -static-libstdc++ -oReflexAST parser.cpp tokens.cpp main.cpp ^
icmemory.cpp 
@echo --------------------------------Done-------------------------------------

 
