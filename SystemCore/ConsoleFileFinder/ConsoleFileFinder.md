Copyright © 2024 Bental Tagor

Design:
=======
The following readme page highlights the design of the Console File Reader Command for reading files 
at a specific directory and displaying the file's content in the console window(s).

Usage:
------
file-finder --help \
file-finder <path> <filePattern> \
file-finder <path> --filePatters:=<pattern1, pattern2, ... patternN> \
file-finder --path:=<path> --filePatters:=<pattern1, pattern2, ... patternN> 

FileFinderCommand: 
------------------
Input: path (String), fileNamePatterns (Array<String>)

1. Parsing command parameters and invoking logic based on the Command Library.
   ConsoleFileFinderCommand::Run() is the main entry for running the command logic.
   (Please refer the Command library section below for more information on the command framework.)

2. Finding a list of files at specific directory by using the FileFinder component class.
   >void IFileFinder::FindFiles(const std::wstring& dir, const std::vector<std::wstring>& patterns, std::list<std::wstring>& files); 

3. Displaying the content of the files in main console (Solution A) 
   or multiple consoles (Solution B).

Solution A: 
-----------
1. For each file path, a file console class is created for displaying the content of a file.
   IFileConsole::Display() is the interface for displaying content of a file.

2. The FileConsole class creates an instance of a TabularData::File() class for reading it's content.
   Internally, the FileConsole::Display() API is using a record iterator for iterating over the lines of the file,
   and displaying its content to main console.

Solution B:
-----------
In this solution we will display the content of files in multiple consoles (1-5), which will fit into main screen.
In order to display the content of a file new consoles are needed to be created.
The Console Windows library is responsible for creating new console window and refreshing it's content.
The design of this solution is to create a new process for each console, and use a named pipe in order to write data from the main process and to read data from each created console process by using a dedicated named pipe.
A named pipe is a named, one-way or duplex pipe for communication between the pipe server and one or more pipe clients.
All instances of a named pipe share the same pipe name, but each instance has its own buffers and handles, and provides a separate conduit for client/server communication.
The use of instances enables multiple pipe clients to use the same named pipe simultaneously.

Implementation:
===============
The following executable/libraries are supporting the solution:

Console File Finder:
--------------------
The ConsoleFileFinder command executable reads an input directory path and file name patterns and displays the file's content in console windows (1-5 instances).

Code: SystemCore/ConsoleFileFinder

Console Helper:
---------------
The Console Helper executable reads the data from the corresponding named pipe and refresh the content of the console.

Code: SystemCore/ConsoleHelper

Command Library:
----------------
The Command library implements the framework and interfaces for implementing command-line tools.
The command library defines a manifest scheme for defining input parameters of a command-line and provides the basic parsing functionality of those parameters.
The library is a placeholder for new and updated command features to be defined and implemented.

Code: SystemCore/Command

Data Structures Library:
------------------------
The Data Structures library defines and implements customized data structures.

The Data Structures library defines and implements customized data structures. The library provides simple, creative, and efficient implementation and interfaces.
The library includes data structures such as an array, bit array, cache, linked-list, doubly linked list, expression tree, graph, hash-map, map, matrix, multi-level, doubly linked list, priority queue, stack, tree,  
BPlus Tree, trie, etc.

Code: SystemCore/DataStructures

Console Windows:
----------------
The Console Windows library implements the functionality of creating multiple console windows for output.
The design of this solution is to create a new process for each console, and use a named pipe in order to write data from the main process and to read data from each created process by using a dedicated named pipe.
A named pipe is a named, one-way or duplex pipe for communication between the pipe server and one or more pipe clients.
All instances of a named pipe share the same pipe name, but each instance has its own buffers and handles,
and provides a separate conduit for client/server communication.
The use of instances enables multiple pipe clients to use the same named pipe simultaneously.

Code: SystemCore/ConsoleWindows

Following are the important classes which participates in the design of console window.

(A) Console Window:
-------------------
The Console Window class creates a dedicated named pipe and a process for the console-helper.exe executable.
The name of the named pipe is: \\.\pipe\<ConsoleWindowName>
The Console Window creates a dedicated process for running console-helper.exe for reading data from the named pipe and writing it to the console window. The parameters of the console-helper.exe
are: consoleTitle(string), and namedPipe(string).
This allows the helper process to open the named pipe for reading, read runtime data into a buffer, and write it to the output stream.

Interface:
----------
namespace console_windows {

    /**
     * The IConsoleWindow interface defines a Console Window.
     */
    class IConsoleWindow {
    public:
        IConsoleWindow() = default;
        virtual ~IConsoleWindow() = default;

        /**
         * Gets console stream.
         */
        virtual std::wostream& GetConsoleStream() = 0;
    };

    /**
     * Defines the Shared Ptr of Console Window.
     */
    using IConsoleWindowSharedPtr = std::shared_ptr<IConsoleWindow>;

} // namespace console_windows

(B) Console Process:
--------------------
The Console Process class is responsible to create a child process by using the ::CreateProcessW() API.
In practice, the Console Window class uses the Console Process class for running console-helper.exe process for reading the written data of the main process from the named pipe and refreshing the console
output.

Interface:
----------
namespace console_windows {

    /**
     * The IConsoleProcess interface defines a Console Process.
     */
    class IConsoleProcess {
    public:
        IConsoleProcess() = default;
        virtual ~IConsoleProcess() = default;

        /**
         * Terminates the running process.
         */
        virtual void Terminate(int exitCode) = 0;
    };

    /**
     * Defines the Shared Ptr of Console Process.
     */
    using IConsoleProcessSharedPtr = std::shared_ptr<IConsoleProcess>;

} // namespace console_windows

(C) Console Pipe:
-----------------
The Console Pipe class implements a named pipe, which is using a communication channel between "main" process and "console" process for sharing data.

The server ("main" process) is creating the pipe by using the following API:

    /**
     * Creates a Console Pipe.
     */
    static IConsolePipeSharedPtr Create(
        const std::wstring& name,
        Mode mode,
        size_t readCapacity,
        size_t writeCapacity);

The client (child process) is opening the pipe for reading by using the following API:

    /**
     * Opens a Console Pipe.
     */
    static IConsolePipeSharedPtr Open(
        const std::wstring& name,
        Mode mode);

Interface:
----------
namespace console_windows {

    /**
     * The IConsolePipe interface defines a Console Pipe.
     */
    class IConsolePipe {
    public:
        /**
         * Defines the states of pipe.
         */
        enum class State
        {
            Client,
            ServerConnected,
            ServerDisconnected
        };

        /**
         * Defines the mode of accessing console pipe.
         */
        enum class Mode
        {
            Read,
            Write,
            Both
        };

        /**
         * Defines the buffer for reading/writing from/to console pipe.
         */
        using Buffer = std::vector<std::wstring::value_type>;

        IConsolePipe() = default;
        virtual ~IConsolePipe() = default;

        /**
         * The copy/move constructors.
         */
        IConsolePipe(const IConsolePipe &) = delete;
        IConsolePipe(IConsolePipe &&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsolePipe &operator=(const IConsolePipe &) = delete;
        IConsolePipe &operator=(IConsolePipe &&) = delete;

        /**
         * Gets name of pipe.
         */
         virtual const std::wstring& GetName() const = 0;

        /**
         * Reads data from pipe and returns the number of bytes written to buffer.
         */
        virtual size_t Read(Buffer& buffer) = 0;

        /**
         * Writes data to pipe and returns number of bytes written.
         */
        virtual size_t Write(const Buffer& buffer) = 0;
    };

    /**
     * Defines the Shared Ptr of Console Pipe.
     */
    using IConsolePipeSharedPtr = std::shared_ptr<IConsolePipe>;

} // namespace console_windows

Tabular Data:
-------------
In statistics, tabular data refers to data that is organized in table with rows and columns.
Within the table, the rows represent observations, and the columns represent attributes for those observations. The opposite of Tabular Data to be visual data, which would be some type of plot or chart that helps to visualize the values of a data set.
The Tabular Data library defines the interfaces for writing and reading Files and Tabular Files.
Those data structures can be used when processing logs or other data structures which require
those internal data structures.

Code: SystemCore/TabularData

Client Server:
--------------
The Client Server library implements a retry handler for invoking logic based on a retry policy.

Base Library:
------------- 
The Base library implements basic logic for any project in C++ and provides complimentary functionality.
This library includes basic classes such as EqualBuilder for calculating equality of objects, CompareToBuilder for
comparing objects, Comparators, String utilities, Iterators, and etc.    

Code: DevEnvironment\Base
