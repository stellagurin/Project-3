OBJS = PriorityQueueDr.o PriorityQueue.o
COMPILE = g++ -g -c -std=gnu++0x -o $@

.PHONY: run

PriorityQueue:	    $(OBJS)
					g++ -o $@ $(OBJS)

PriorityQueueDr.o:	PriorityQueueDr.cpp
					$(COMPILE) PriorityQueueDr.cpp

PriorityQueue.o:	PriorityQueue.h PriorityQueue.cpp
				    $(COMPILE) PriorityQueue.cpp

run:	$ PriorityQueue
		./$ PriorityQueue

clean:
		$(RM) $(OBJS)

cleanall:	clean
			$(RM) PriorityQueue
