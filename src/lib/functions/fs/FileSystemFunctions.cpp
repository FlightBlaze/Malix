#include "FileSystemFunctions.h"

MALIX_NATIVE_FUNCTION(fs_absolutePath) {
    function->checkArguments(values, 2);
    return Value(fs::absolute(TO_FS_PATH(0), TO_FS_PATH(1)).string());
}

MALIX_NATIVE_FUNCTION(fs_canonicalPath) {
    function->checkArguments(values, 2);
    return Value(fs::canonical(TO_FS_PATH(0), TO_FS_PATH(1)).string());
}

MALIX_NATIVE_FUNCTION(fs_copy) {
    function->checkArguments(values, 2);
    fs::copy(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_copyFile) {
    function->checkArguments(values, 2);
    return Value(fs::copy_file(TO_FS_PATH(0), TO_FS_PATH(1)));
}

MALIX_NATIVE_FUNCTION(fs_copySymlink) {
    function->checkArguments(values, 2);
    fs::copy_symlink(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_createDirectory) {
    function->checkArguments(values, 1);
    return Value(fs::create_directory(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_createDirectories) {
    function->checkArguments(values, 1);
    return Value(fs::create_directories(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_createHardLink) {
    function->checkArguments(values, 2);
    fs::create_hard_link(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_createSymlink) {
    function->checkArguments(values, 2);
    fs::create_symlink(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_createDirectorySymlink) {
    function->checkArguments(values, 2);
    fs::create_directory_symlink(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_currentPath) {
    function->checkArguments(values, 0);
    return Value(fs::current_path().string());
}

MALIX_NATIVE_FUNCTION(fs_exists) {
    function->checkArguments(values, 1);
    return Value(fs::exists(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_equivalent) {
    function->checkArguments(values, 2);
    return Value(fs::equivalent(TO_FS_PATH(0), TO_FS_PATH(1)));
}

MALIX_NATIVE_FUNCTION(fs_fileSize) {
    function->checkArguments(values, 1);
    return Value((double) fs::file_size(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_hardLinkCount) {
    function->checkArguments(values, 1);
    return Value((double) fs::hard_link_count(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_lastWriteTime) {
    function->checkArguments(values, 1);
    auto ftime = fs::last_write_time(TO_FS_PATH(0));
    std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
    return Value((double) cftime);
}

MALIX_NATIVE_FUNCTION(fs_readSymlink) {
    function->checkArguments(values, 1);
    return Value(fs::read_symlink(TO_FS_PATH(0)).string());
}

MALIX_NATIVE_FUNCTION(fs_remove) {
    function->checkArguments(values, 1);
    return Value(fs::remove(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_removeAll) {
    function->checkArguments(values, 1);
    return Value((double) fs::remove_all(TO_FS_PATH(0)));
}

MALIX_NATIVE_FUNCTION(fs_rename) {
    function->checkArguments(values, 2);
    fs::rename(TO_FS_PATH(0), TO_FS_PATH(1));
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_resizeFile) {
    function->checkArguments(values, 2);
    fs::resize_file(TO_FS_PATH(0), (uintmax_t) values[1].getNumberValue());
    return Value();
}

MALIX_NATIVE_FUNCTION(fs_spaceFree) {
    function->checkArguments(values, 1);
    return Value((double) fs::space(TO_FS_PATH(0)).free);
}

MALIX_NATIVE_FUNCTION(fs_spaceCapacity) {
    function->checkArguments(values, 1);
    return Value((double) fs::space(TO_FS_PATH(0)).capacity);
}

MALIX_NATIVE_FUNCTION(fs_spaceAvailable) {
    function->checkArguments(values, 1);
    return Value((double) fs::space(TO_FS_PATH(0)).available);
}

MALIX_NATIVE_FUNCTION(fs_tempDirectoryPath) {
    function->checkArguments(values, 0);
    return Value(fs::temp_directory_path().string());
}

MALIX_NATIVE_FUNCTION(fs_fileName) {
    function->checkArguments(values, 1);
    return Value(TO_FS_PATH(0).filename().string());
}

MALIX_NATIVE_FUNCTION(fs_fileExtension) {
    function->checkArguments(values, 1);
    return Value(TO_FS_PATH(0).extension().string());
}

MALIX_NATIVE_FUNCTION(fs_fileStem) {
    function->checkArguments(values, 1);
    return Value(TO_FS_PATH(0).stem().string());
}

MALIX_NATIVE_FUNCTION(fs_getContent) {
    function->checkArguments(values, 1);
    std::ifstream ifs(TO_FS_PATH(0));
    return Value(std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())));
}

MALIX_NATIVE_FUNCTION(fs_setContent) {
    function->checkArguments(values, 2);
    std::istringstream iss(values[1].getStringValue());
    std::ofstream oss(TO_FS_PATH(0));
    std::vector<std::string> result;

    for (std::string token; std::getline(iss, token, '\n'); )
        result.push_back(std::move(token));

    for (const std::string &line : result)
        oss << line << '\n';

    oss.close();
    return Value();
}