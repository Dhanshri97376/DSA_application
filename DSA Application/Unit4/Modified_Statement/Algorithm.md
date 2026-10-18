## Algorithm – Automated File Classification and Organization System Using C++

**Algorithm:**

1. **Start** the program and initialize the required variables and filesystem operations.

2. Ask the user to enter the directory path containing the files to be organized.

3. Check whether the specified directory exists and is valid. If the directory is invalid, display an error message and terminate the program.

4. Read the files available in the specified directory using C++ filesystem operations.

5. Select each file individually and check whether it is a regular file. Ignore directories and other non-regular entries.

6. Extract the file extension and convert it to lowercase to ensure consistent classification regardless of letter case.

7. Identify the category of the file based on its extension, such as Documents, Images, Videos, Audio, Code, or Others.

8. Create the appropriate destination folder inside the selected directory if it does not already exist.

9. Construct the destination path by combining the category folder with the original filename.

10. Check whether a file with the same name already exists in the destination folder. If a duplicate exists, skip the file to prevent overwriting existing data.

11. If no duplicate exists, move the file into its corresponding destination folder using filesystem operations.

12. Display the filename and destination category after a successful file movement. If an operation fails, handle the error appropriately.

13. Repeat the classification and organization process for all remaining regular files in the selected directory.

14. Maintain counters for successfully organized files and skipped files to prepare the final summary.

15. Display the organization summary, including the number of files organized and the number of files skipped.

16. Display a completion message indicating that the file organization process has finished.

17. **Stop** the program.
