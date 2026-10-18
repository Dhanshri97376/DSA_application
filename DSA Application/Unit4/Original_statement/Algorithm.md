## Algorithm – Smart File Organizer (Original)

**Algorithm:**

1. **Start** the program.

2. Initialize the required variables and libraries for file and directory handling.

3. Ask the user to specify the directory path containing the files that need to be organized.

4. Check whether the specified directory exists and is accessible. If the directory is invalid, display an error message and ask the user to provide a valid path.

5. Read and retrieve the list of files available in the selected directory.

6. Examine each file individually and identify its name, extension, and file type.

7. Classify the files into different categories based on their extensions, such as documents, images, videos, audio files, and other files.

8. Create separate folders for each category in the selected directory. If the folders already exist, use the existing folders instead of creating duplicates.

9. Select each file and determine the appropriate destination folder according to its category.

10. Move the file into its corresponding folder while ensuring that files are not moved into an incorrect category.

11. Check whether a file with the same name already exists in the destination folder. Handle duplicate filenames appropriately to avoid accidental overwriting.

12. Continue processing the remaining files until all eligible files in the selected directory have been examined and organized.

13. Display the organized folder structure and the number of files processed in each category.

14. Display a success message after completing the file organization process. If any file cannot be moved, display an appropriate error message.

15. Allow the user to verify the newly organized directory and access files from their respective folders.

16. **Stop** the program.
