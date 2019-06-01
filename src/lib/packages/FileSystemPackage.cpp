#include "FileSystemPackage.h"

std::string FileSystemPackage::getName() {
    return "fs";
}

std::vector<Function *> FileSystemPackage::getFunctions() {
    return {
            MALIX_NATIVE_FUNCTION_POINTER("absolutePath", fs_absolutePath),
            MALIX_NATIVE_FUNCTION_POINTER("canonicalPath", fs_canonicalPath),
            MALIX_NATIVE_FUNCTION_POINTER("copy", fs_copy),
            MALIX_NATIVE_FUNCTION_POINTER("copyFile", fs_copyFile),
            MALIX_NATIVE_FUNCTION_POINTER("copySymlink", fs_copySymlink),
            MALIX_NATIVE_FUNCTION_POINTER("createDirectory", fs_createDirectory),
            MALIX_NATIVE_FUNCTION_POINTER("createDirectories", fs_createDirectories),
            MALIX_NATIVE_FUNCTION_POINTER("createHardLink", fs_createHardLink),
            MALIX_NATIVE_FUNCTION_POINTER("createSymlink", fs_createSymlink),
            MALIX_NATIVE_FUNCTION_POINTER("createDirectorySymlink", fs_createDirectorySymlink),
            MALIX_NATIVE_FUNCTION_POINTER("currentPath", fs_currentPath),
            MALIX_NATIVE_FUNCTION_POINTER("exists", fs_exists),
            MALIX_NATIVE_FUNCTION_POINTER("equivalent", fs_equivalent),
            MALIX_NATIVE_FUNCTION_POINTER("hardLinkCount", fs_hardLinkCount),
            MALIX_NATIVE_FUNCTION_POINTER("lastWriteTime", fs_lastWriteTime),
            MALIX_NATIVE_FUNCTION_POINTER("readSymlink", fs_readSymlink),
            MALIX_NATIVE_FUNCTION_POINTER("remove", fs_remove),
            MALIX_NATIVE_FUNCTION_POINTER("removeAll", fs_removeAll),
            MALIX_NATIVE_FUNCTION_POINTER("rename", fs_rename),
            MALIX_NATIVE_FUNCTION_POINTER("resizeFile", fs_resizeFile),
            MALIX_NATIVE_FUNCTION_POINTER("spaceFree", fs_spaceFree),
            MALIX_NATIVE_FUNCTION_POINTER("spaceCapacity", fs_spaceCapacity),
            MALIX_NATIVE_FUNCTION_POINTER("spaceAvailable", fs_spaceAvailable),
            MALIX_NATIVE_FUNCTION_POINTER("tempDirectoryPath", fs_tempDirectoryPath),
            MALIX_NATIVE_FUNCTION_POINTER("fileSize", fs_fileSize),
            MALIX_NATIVE_FUNCTION_POINTER("fileName", fs_fileName),
            MALIX_NATIVE_FUNCTION_POINTER("fileExtension", fs_fileExtension),
            MALIX_NATIVE_FUNCTION_POINTER("fileStem", fs_fileStem),
            MALIX_NATIVE_FUNCTION_POINTER("getContent", fs_getContent),
            MALIX_NATIVE_FUNCTION_POINTER("setContent", fs_setContent),
    };
}

std::map<std::string, Value *> FileSystemPackage::getConstants() {
    return {};
}
