//
// Created by 46172 on 2022/5/29.
//

#ifndef FILESYSTEM_FS_H
#define FILESYSTEM_FS_H
#include <cstdio>
#include <vector>
using namespace std;
const unsigned int PRESERVE_BLOCK_NUMBER = 127; //为inode等保留的块数
const unsigned int DATA_BLOCK_LENGTH = 64 ;  // 数据块内容大小
const unsigned int DATA_BLOCK_NUMBER = 512 ;  // 数据块数目
const unsigned int MAX_INODE_NUMBER = 1000;
const int INDEX_LIST_LENGTH = DATA_BLOCK_LENGTH/sizeof(int);     // 成组链中每组个数
const int INDEX_LIST_NUMBER = sizeof(int);		//  成组链组数
const int MAX_FILE_LENGTH = 10;      // 允许的最大文件长度，即占数据块的最大数目
const int MAX_User_NUMBER = 8;           // 最大用户数
const char* root_path = "../src/bak";
extern FILE* fp ;
typedef char Block[DATA_BLOCK_LENGTH];
extern char InodeBit[MAX_INODE_NUMBER/8];
extern char BlockBit[DATA_BLOCK_NUMBER/8];
struct Inode;
extern Inode rootInode;
extern Inode CurDirInode;
extern vector<Inode> CurDirSubInode;
extern vector<Inode> openList;
extern string username;

struct Inode {

};

struct SuperBlock {

};

struct UserBlock {
    unsigned int uid;
    char username[14];
    char password[14];
};

/*
 * 目录项
 */
struct Dentry {
    string name;
    unsigned int id;
};

/*
 * 目录Block单条数据
 */
struct DirectorInfo {
    char name[12];
    unsigned int id;
};

void __writeSuper(SuperBlock* superBlock);
void __writeInode(unsigned int id, Inode* inode);
void __writeBlock(unsigned int id, void* data, size_t size, size_t len);

void __readSuper(SuperBlock* superBlock);
void __readInode(unsigned int id, Inode* inode);
void __readBlock(unsigned int id, Block* block);

/*
 * return 0时无剩余inode
 */
unsigned int __getFreeInodeId();

bool __freeInode(unsigned int id);
/*
 * return UINT32_MAX 时无空闲块
 */
unsigned int __getFreeBlock();

bool __freeBlock(unsigned int id);

int __cd(string name);

bool __login(string username, string password);

void __logout();

int __mkdir(string name);

vector<string> __ls();

int __touch(string name);

int __open(string name);

int __write(string name, string data);

int __read(string name);

int __close(string name);

int __delete(string name);

int __rmdir(string name);

int __rm(string name);

int __format(string name);

int __ln(string src, string dst);//软连接

int __cp(string src, string dst);

int __chpw(string username, string password);

int __chmod(string name, string args);

int __createUser(string username, string password);

int __mv(string src, string dst);

#endif //FILESYSTEM_FS_H
