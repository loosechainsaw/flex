project(tests)

add_executable(tests source/main.cpp
        include/catch/catch.hpp
        source/all_of.cpp
        source/any_of.cpp
        source/clear.cpp
        source/copy.cpp
        source/copy_if.cpp
        source/count.cpp
        source/count_if.cpp
        source/empty.cpp
        source/fill.cpp
        source/find.cpp
        source/find_if.cpp
        source/front.cpp
        source/iota.cpp
        source/none_of.cpp
        source/push_back.cpp
        source/push_front.cpp
        source/rename.cpp
        source/replace_front.cpp
        source/second.cpp
        source/size.cpp
        source/tail.cpp
        source/third.cpp
        source/transform.cpp
        source/transform_front.cpp
        )
target_link_libraries(tests PRIVATE flex::flex)
target_include_directories(tests PRIVATE include )