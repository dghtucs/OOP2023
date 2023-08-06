cxx = g++
flags = -std=c++11
obj = main.o Cow.o Farm.obj
target = main

$(target):$(obj)
	$(cxx) $(flags) -o $(target) $(obj)

main.o:main.cpp
	$(cxx) $(flags) -c main.cpp

Cow.o:Cow.cpp
	$(cxx) $(flags) -c Cow.cpp

Farm.o:Farm.cpp
	$(cxx) $(flags) -c Farm.cpp

.PHONY:clean

clean:
	del *.o


