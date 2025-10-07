#编译目录下的源文件
aux_source_directory(. CLIENT_LIST)

#生成可执行文件
add_executable(ChatClient ${CLIENT_LIST})

#链接库
target_link_libraries(ChatClient pthread)