# -DATA-COMPRESSION-TOOL
*COMPANY*: CODTECH IT SOLUTIONS PVT.LTD
**NAME*: DILIP KUMAR MURMU
*INTERN ID*: CT04DF2445
*DOMAIN*: C LANGUAGE
*DURATION*: 4 WEEKS
*MENTOR*: NEELA SANTOSH KUMAR
#Task 4 Description – Run-Length Encoding Compression Tool in C

This C program is designed to perform simple data compression using the Run-Length Encoding (RLE) algorithm. It is divided into two major components: one that captures and writes user input to a file, and another that compresses that file's contents into a separate file using RLE logic. The program adopts a modular approach, making the functions organized and easy to manage.

The first function, generateFile(), handles file creation and input capture. It takes the name of a file as input, opens it in write mode, and prompts the user to enter a line of text. This input can include spaces and special characters. After the user enters the text, the function removes any trailing newline character and writes the cleaned content to the file. If the file cannot be opened, an error message is displayed. Once the data is successfully saved, the file is closed properly to ensure no data loss.

The second function, runLengthCompress(), performs the core logic of the compression. It opens the source file (which contains the user's input) in read mode and a target file (to store the compressed output) in write mode. If either file cannot be accessed, the function returns with an error message. The compression algorithm reads the file character by character while tracking consecutive repetitions of the same character. When a different character is encountered, the function writes the previous character along with its repetition count to the output file. This pattern continues until the end of the file, and the final character sequence is also written to ensure completeness. This function includes proper checks for edge cases such as an empty file and handles them gracefully with informative messages.

The main() function orchestrates the entire process. It sets up the input and output file names and ensures that the input buffer is cleared before taking user input to avoid unintended behavior. It then calls the file creation function to accept and store the user's content, followed by the compression function to apply RLE on the stored data.

Overall, this program effectively demonstrates how repeated patterns in a text can be compressed using a straightforward algorithm. The implementation highlights important concepts such as file handling, character-level processing, conditional logic, and memory-efficient text manipulation. The use of Run-Length Encoding ensures that sequences of repeating characters are represented more compactly, reducing the file size in cases of redundancy. This task serves as a solid introduction to data compression and the practical use of algorithms for optimizing storage and transmission.
#OUTPUTN

