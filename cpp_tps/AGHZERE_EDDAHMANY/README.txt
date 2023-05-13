Command to execute : cmake -G"Unix Makefiles" ===> then execute : make
To see the output of listing.cpp, you should execute : g++ -I./include -fno-elide-constructors ./src/matrix.cpp ./src/listing.cpp -o listing
About the listing : We notice that the output shows only some creations of matrix by move constructor, which means that is it used also the copy constructor, and also uses just one time the move assignment operator. That is because of -fno-elide-constructors property.
