#include "Terminal/Input.h"
#include "Core/Windows.h"
#include "Core/Text.h"
#include "Core/Widget.h"
#include "Core/Box.h"
#include "Core/Container.h"
#include "Core/VerticalLayout.h"
#include "Core/HorizontalLayout.h"
#include "Core/Button.h"
#include <iostream>
#include <sys/ioctl.h> 
#include <unistd.h>   
#include <cerrno>
#include <dirent.h>
#include <string>

using namespace std;

struct winsize w;


void loadDirectory(string path, string file[], int &fileCount, bool isDir[])
{
    DIR *myDir;
    struct dirent *enter;

    myDir = opendir(path.c_str());
    if(myDir == NULL)
    {
        perror("No file found");
    }

    while((enter = readdir(myDir)) != NULL)
    {
        if(enter->d_name[0] == '.') continue;
        if(enter->d_type == DT_DIR) isDir[fileCount] = 1;
        file[fileCount] = enter->d_name;
        fileCount++;
        if (fileCount >= 50) break;
    }
    closedir(myDir);
}

void buildUI(string file[],bool isDir[] ,int *fileCount, Container& layout, Button* myButtons, string* path, bool *needRebuild)
{

    for(int i = 0; i < *fileCount; i++)
    {
        myButtons[i] = Button(0,0,3,25, file[i], isDir[i],[file, i, isDir, fileCount, path, needRebuild](){
            if(isDir[i])
            { 
                *path = *path + '/' + file[i];
                *fileCount = 0;
                loadDirectory(*path, file, *fileCount, isDir);
                for(int i = 0; i < 50; i++)
                {
                    isDir[i] = false;
                }
                *needRebuild = 1;
            }
        });
        layout.addWidget(&myButtons[i]);
    }

}

string checkFile(int focusedIndex, string file[], bool isDir[])
{
    if(isDir[focusedIndex] == true)
    {
        return "[DIR] " + file[focusedIndex];
    }else
    {
        return "[FILE] " + file[focusedIndex];
    }
}

int main(int argc, char* argv[])
{
    if (argc <= 1){
        cout << "Please provided directory to start from." << endl;
        return 0;
    }
    string path = argv[1];
    char c = '\0';
    string instructionString = "j/k move | Enter open | b back | q quit";

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    Window myWindow(w.ws_row, w.ws_col);
    VerticalLayout myVerticalLayout(0, 2, w.ws_row, 30, 50);
    Text title(0, 0, 1, path.length(), path, GREEN);
    Text instructions(w.ws_col-instructionString.length(), w.ws_row-1, 1, instructionString.length(), instructionString, 0);

    Button* myButtons;
    myButtons = new Button[50];

    string  fileArray[50];
    int fileCount = 0;
    bool isDir[50] = {false}, needsRebuild = 0;
    loadDirectory(path, fileArray, fileCount, isDir);
    buildUI(fileArray, isDir, &fileCount, myVerticalLayout, myButtons, &path,&needsRebuild);

    string statusBarString = checkFile(myVerticalLayout.getFocusedIndex(), fileArray, isDir);

    Text statusBar(0, w.ws_row-1, 1, statusBarString.length(), statusBarString, CYAN);


    enableRawMode();

    while (1) 
    {
        c = '\0';
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
        if (c == 'q') break;

        myWindow.clear(); 
        instructions.render(myWindow);
        title.render(myWindow);
        statusBar.render(myWindow);
        myVerticalLayout.render(myWindow);
        myWindow.flush(); 
        if(needsRebuild)
        {
            title.setSentence(path);
            myVerticalLayout.reset();
            delete[] myButtons;
            myButtons = new Button[50]; 
            buildUI(fileArray, isDir, &fileCount, myVerticalLayout, myButtons, &path, &needsRebuild);
            needsRebuild = false;
        }
        if(c == 98)
        {
            path = path.substr(0, path.rfind('/'));
            fileCount = 0;
            for(int i = 0; i < 50; i++)
            {
                isDir[i] = false;
            }
            loadDirectory(path, fileArray, fileCount, isDir);
            needsRebuild = 1;
            

        }else
        {
            myVerticalLayout.handleInput(c);
        }
        statusBarString = checkFile(myVerticalLayout.getFocusedIndex(), fileArray, isDir);
        statusBar.setSentence(statusBarString);
        
        
    }


    delete[] myButtons;
    disableRawMode();
}
