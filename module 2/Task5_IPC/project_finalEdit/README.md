IPC project 

using 
    -pipes
    -shared memory 
    -Boost library (logger)
    -Gtest


-The project succfully worked and the requester can read the content of a speacfied file or list the files in a diroctory

-the project had 5 stages
    -pipes implmentation
    -shared memory implemntation
    -file handling
    -Logging by Boost
    -gtest 


//release 2

the user can now run the request and send to it the path of the listed file or the path of the text file to be read from 

ex1

--
./request -r "/home/nahass/Desktop/test/test.txt"
Received arguments: -r /home/nahass/Desktop/test/test.txt
Value 0 and Path /home/nahass/Desktop/test/test.txt sent to the pipe.
hi from test


./fh
Received value: 0 and Path: /home/nahass/Desktop/test/test.txt
shared mem address: 0x7f30ce3b3000 [0..1023]
backing file:       /dev/shm/my_shared_memory_file



ex2

nahass@nahass:~/Desktop/Valeo Tasks/module 2/Task5_IPC/project/build/request$ ./request -l "/home/nahass/Desktop/test"
Received arguments: -l /home/nahass/Desktop/test
Value 1 and Path /home/nahass/Desktop/test sent to the pipe.
test.txt


./fh
Received value: 1 and Path: /home/nahass/Desktop/test
shared mem address: 0x7f15b9985000 [0..1023]
backing file:       /dev/shm/my_shared_memory_file


//new edit
now the file handler can run as doemon
put file_handler.service in etc/systemd/system

then run these commands

sudo systemctl enable filehandler.service   //enable the service
sudo systemctl start filehandler.service    //start it
sudo systemctl status filehandler.service   //check the status of the doemon if it      succfully run or not 

