
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>

using namespace std;

string getCategory(string ext)
{
    for (int i = 0; i < (int)ext.length(); i++)
        ext[i] = tolower((unsigned char)ext[i]);

    if (ext == ".pdf" || ext == ".doc" ||
        ext == ".docx" || ext == ".txt" ||
        ext == ".ppt" || ext == ".pptx")
        return "Documents";

    if (ext == ".jpg" || ext == ".jpeg" ||
        ext == ".png" || ext == ".gif")
        return "Images";

    if (ext == ".mp3" || ext == ".wav")
        return "Audio";

    if (ext == ".mp4" || ext == ".avi" ||
        ext == ".mkv")
        return "Videos";

    if (ext == ".cpp" || ext == ".c" ||
        ext == ".py" || ext == ".java")
        return "Code";

    return "Others";
}

string getExtension(string filename)
{
    size_t pos = filename.find_last_of('.');
    if (pos == string::npos)
        return "";
    return filename.substr(pos);
}

int main()
{
    string folder;

    cout << "====================================\n";
    cout << "       SMART FILE ORGANIZER\n";
    cout << "====================================\n";
    cout << "Enter folder path: ";
    getline(cin, folder);

    // Remove quotation marks if included in pasted path
    if (folder.length() >= 2 &&
        folder[0] == '"' &&
        folder[folder.length() - 1] == '"')
        folder = folder.substr(1, folder.length() - 2);

    DWORD attr = GetFileAttributesA(folder.c_str());

    if (attr == INVALID_FILE_ATTRIBUTES ||
        !(attr & FILE_ATTRIBUTE_DIRECTORY))
    {
        cout << "Error: Folder does not exist.\n";
        cout << "Please enter a valid folder path.\n";
        return 1;
    }

    if (folder[folder.length() - 1] != '\\')
        folder += "\\";

    string searchPath = folder + "*.*";
    WIN32_FIND_DATAA data;
    HANDLE handle = FindFirstFileA(
        searchPath.c_str(), &data);

    if (handle == INVALID_HANDLE_VALUE)
    {
        cout << "Unable to read folder.\n";
        return 1;
    }

    int organized = 0;
    int skipped = 0;

    do
    {
        string filename = data.cFileName;

        if (filename == "." || filename == ".." ||
            (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            continue;

        string category = getCategory(getExtension(filename));
        string targetFolder = folder + category;

        // Create category folder if it does not exist
        CreateDirectoryA(targetFolder.c_str(), NULL);

        string source = folder + filename;
        string destination = targetFolder + "\\" + filename;

        // Never overwrite an existing file
        if (GetFileAttributesA(destination.c_str()) !=
            INVALID_FILE_ATTRIBUTES)
        {
            cout << "Skipped: " << filename
                 << " (duplicate)\n";
            skipped++;
            continue;
        }

        if (MoveFileA(source.c_str(), destination.c_str()))
        {
            cout << "Moved: " << filename
                 << " -> " << category << "\n";
            organized++;
        }
        else
        {
            cout << "Could not move: " << filename << "\n";
            skipped++;
        }

    } while (FindNextFileA(handle, &data));

    FindClose(handle);

    cout << "\n========== SUMMARY ==========\n";
    cout << "Files organized: " << organized << "\n";
    cout << "Files skipped: " << skipped << "\n";
    cout << "Organization completed.\n";

    system("pause");
    return 0;
}

