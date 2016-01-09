OBJECTS= main.o

DataStructure: $(OBJECTS)
	g++ main.o -o DataStructure

#make看到[.o]文件，自动把[.c]文件加到依赖关系中
main.o: main.cpp main.h LinkList.h SeqList.h

clean:
	rm $(OBJECTS) DataStructure