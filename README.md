# Operating-Systems-Assignment 1

##Introduction
This is an example of the producer-consumer problem. The producer's role is to create an item and place it in a buffer. The consumer's role is to delete items in the buffer. In this case the buffer is actually a table which is capable of holding only two items at once. If the table is filled the producer will not run since it cannot produce anymore items. If the table is empty the consumer will not run since there are no items to consume. The two programs share the memory which is held in the table.

##Execution
In order for this program to run please use the following commands:
'g++ -pthread -lrt -o main main.cpp ./main

To compile with both files (producer.cpp and consumer.cpp), type the following commands:

g++ producer.cpp -pthread -lrt -o producer g++ consumer.cpp -pthread -lrt -o consumer

./producer & ./consumer
'
