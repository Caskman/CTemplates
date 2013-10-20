C Template Data Structures

This script produces the files to define and manipulate a specified data type by using one of the following data structures:
	Doubly linked list

Still have more to add

===============================================================================

Example

Running the following:

	./template -l String

yields three files: stringlist.c, stringlist.h, and stringlist_imp.h

These files allow to you use the StringList, StringNode, and String type.  The modifications needed are in stringlist_imp.h where the typedef for String needs to be adjusted for your specific application, i.e., char*. 




