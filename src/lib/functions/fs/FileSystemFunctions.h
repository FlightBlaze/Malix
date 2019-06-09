#ifndef MALIX_FILESYSTEMFUNCTIONS_H
#define MALIX_FILESYSTEMFUNCTIONS_H

#include <boost/filesystem.hpp>
#include "../NativeFunction.h"

#define TO_FS_PATH(idx) \
    boost::filesystem::path(values[idx].getStringValue())

MALIX_NATIVE_FUNCTION(fs_absolutePath);
MALIX_NATIVE_FUNCTION(fs_canonicalPath);
MALIX_NATIVE_FUNCTION(fs_normalizePath);
MALIX_NATIVE_FUNCTION(fs_copy);
MALIX_NATIVE_FUNCTION(fs_copyFile);
MALIX_NATIVE_FUNCTION(fs_copySymlink);
MALIX_NATIVE_FUNCTION(fs_createDirectory);
MALIX_NATIVE_FUNCTION(fs_createDirectories);
MALIX_NATIVE_FUNCTION(fs_createHardLink);
MALIX_NATIVE_FUNCTION(fs_createSymlink);
MALIX_NATIVE_FUNCTION(fs_createDirectorySymlink);
MALIX_NATIVE_FUNCTION(fs_currentPath);
MALIX_NATIVE_FUNCTION(fs_exists);
MALIX_NATIVE_FUNCTION(fs_equivalent);
MALIX_NATIVE_FUNCTION(fs_fileSize);
MALIX_NATIVE_FUNCTION(fs_hardLinkCount);
MALIX_NATIVE_FUNCTION(fs_lastWriteTime);
MALIX_NATIVE_FUNCTION(fs_readSymlink);
MALIX_NATIVE_FUNCTION(fs_remove);
MALIX_NATIVE_FUNCTION(fs_removeAll);
MALIX_NATIVE_FUNCTION(fs_rename);
MALIX_NATIVE_FUNCTION(fs_resizeFile);
MALIX_NATIVE_FUNCTION(fs_spaceFree);
MALIX_NATIVE_FUNCTION(fs_spaceCapacity);
MALIX_NATIVE_FUNCTION(fs_spaceAvailable);
MALIX_NATIVE_FUNCTION(fs_tempDirectoryPath);
MALIX_NATIVE_FUNCTION(fs_fileName);
MALIX_NATIVE_FUNCTION(fs_fileExtension);
MALIX_NATIVE_FUNCTION(fs_fileStem);
MALIX_NATIVE_FUNCTION(fs_fileParent);

MALIX_NATIVE_FUNCTION(fs_getContent);
MALIX_NATIVE_FUNCTION(fs_setContent);

#endif //MALIX_FILESYSTEMFUNCTIONS_H
