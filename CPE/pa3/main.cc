#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>
#include <string>

//This function finds directory with the given name(2nd argument) from the given path(1st argument)
//For example below finds "world" directory from the root directory
//find_directory(&root, "world");
Entry* find_directory(Directory* root, const std::string& path)
{
    //Implement your code here.
    //Leverage find member function.
    Directory* current = nullptr; // 널로 초기화
    std::istringstream iss(path);
    std::string token;

    if (path == "") return nullptr;

    std::getline(iss, token, '/');
    if (token == "root") current = root; // 처음에 루트면 현재 경로는 루트
    
    while (std::getline(iss, token, '/'))
    {
        Entry* found = current->find(token);

        if (!found) // 경로 중 dir없을떄
            return nullptr;
        else if (dynamic_cast<Directory*>(found) == nullptr) // 경로 중 dir이 아닐때
            return dynamic_cast<File*>(found); // File로 업캐스팅
    
        current = static_cast<Directory*>(found); // 현재 경로 저장
    }

    return current; // Directory로 업캐스팅
    
    //...
}

void noDirectory() { std::cout << "no such directory\n" << std::endl; }

void exec_cmd(Directory* root,std::string cmd)
{
  //*****Do NOT MODIFY START*****
  std::istringstream iss1(cmd),iss2(cmd);
  std::string token;
  std::getline(iss2,token,' ');
  std::getline(iss1,token,' ');
  //*****DO NOT MODIFY END*****

  //Implement your code here
    std::string path;
    std::getline(iss1, path, ' '); // 경로 저장

    size_t lastSlash = path.find_last_of('/');
    std::string parentPath = (lastSlash != std::string::npos) ? path.substr(0, lastSlash) : "";
    std::string targetName = (lastSlash != std::string::npos) ? path.substr(lastSlash + 1) : path;
    // 타겟의 dir 가져오기
    Directory* targetDir = dynamic_cast<Directory*>(find_directory(root, path));
    // 타겟의 바로 전 dir 가져오기
    Directory* parentDir = dynamic_cast<Directory*>(find_directory(root, parentPath));
    // 타겟의 file 가져오기
    File* targetFile = dynamic_cast<File*>(find_directory(root, path));

    if (token == "mkdir") // dir 만들기
    {
        if (!parentDir)
            noDirectory();
        else if (!parentDir->add(new Directory(targetName)))
            std::cout << "directory already exists\n" << std::endl;
    }
    else if (token == "touch") // file 만들기
    {
        if (!parentDir)
            noDirectory();
        else if (!parentDir->add(new File(targetName)))
            std::cout << "file already exists\n" << std::endl;
    }
    else if (token == "echo") // file 안에 content까지 넣어서 만들기
    {
        std::string content;
        std::getline(iss1, content);
        if (!parentDir)
            noDirectory();
        else if (!parentDir->add(new File(targetName, content))) // content 업데이트
            std::cout << targetFile->content(content) << std::endl;
    }
    else if (token == "ls") // dir, file 리스트 출력
    {
        if (targetDir)
            std::cout << targetDir->content() << std::endl;
        else
            noDirectory();
    }
    else if (token == "tree") // dir 트리 출력
    {
        if (targetDir)
            std::cout << *targetDir << std::endl;
        else
            noDirectory();
    }
    else if (token == "cat") // file 내용 출력
    {
        if (!parentDir)
            noDirectory();
        else if (!targetFile)
            std::cout << "no such file\n" << std::endl;
        else
            std::cout << targetFile->content() << std::endl << std::endl;
    }
    else if (token == "mv") // dir or file 옮기기
    {
        std::string destination;
        std::getline(iss1, destination); // 옮길 위치 가져오기
        Directory* destDir = dynamic_cast<Directory*>(find_directory(root, destination));

        Entry* source = nullptr;
        if (parentDir)
            source = parentDir->find(targetName);
        
        if (destDir && (dynamic_cast<Directory*>(source) || dynamic_cast<File*>(source)))
        {
            destDir->add(source);
            parentDir->remove(targetName);
            delete source;
        }
        else
            std::cout << "no such file or directory\n" << std::endl;
    }
    else if (token == "cp") // dir or file 복사
    {
        std::string destination;
        std::getline(iss1, destination); // 옮길 위치 가져오기
        Directory* destDir = dynamic_cast<Directory*>(find_directory(root, destination));

        Entry* source = nullptr;
        if (parentDir)
            source = parentDir->find(targetName);
        
        if (destDir && (dynamic_cast<Directory*>(source) || dynamic_cast<File*>(source)))
            destDir->add(source);
        else
            std::cout << "no such file or directory\n" << std::endl;
    }
    else if (token == "rmdir") // dir 제거
    {
        if (path == "root") return; // 이런 테스트케이스는 없음

        if (targetDir)
            delete parentDir->remove(targetName);
        else
            noDirectory();
    }
    else if (token == "rm") //
    {
        if (targetFile)
            delete parentDir->remove(targetName);
        else
            std::cout << "no such file\n" << std::endl;
    }
    else
    {
        // 없는 명령어(그냥 만들어 봄)
        std::cout << "Error: Unknown command '" << token << "'.\n" << std::endl;
    }
    //...
}


int main()
{
  //*****Do NOT MODIFY START*****
    Directory root("root");
    root.add(new Directory("hello"));
    std::cout << root << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while(1){
      std::getline(std::cin,inputBuffer);
      if(inputBuffer.compare("exit")==0) break;
      exec_cmd(&root,inputBuffer);
    }
  //*****DO NOT MODIFY END*****

}
