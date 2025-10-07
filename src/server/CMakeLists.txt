#包含目录下所有·cpp文件
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)
aux_source_directory(./dataoperate DATAOPERATE_LIST)
aux_source_directory(./redis REDIS_LIST)
#指定生成可执行文件
add_executable(ChatServer ${SRC_LIST} ${DB_LIST} ${DATAOPERATE_LIST} ${REDIS_LIST})
#添加链接库
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient hiredis pthread )