OBJECTS= Main.o String.o Array.o

prog: $(OBJECTS)
	g++ $(OBJECTS) -o prog

#make看到[.o]文件，自动把[.c]文件加到依赖关系中，并且g++ －c ..也会被推导出来
#main.o: Main.h SeqList.h LinkList.h SeqStack.h LinkStack.h \
#	SeqQueue.h LinkQueue.h
#string.o: Main.h
$(OBJECTS): Main.h
Main.o: SeqList.h LinkList.h SeqStack.h LinkStack.h \
	SeqQueue.h LinkQueue.h

clean:
	rm $(OBJECTS) prog