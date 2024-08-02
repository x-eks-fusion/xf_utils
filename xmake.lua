add_rules("mode.debug")

add_requires("pthread")

function add_xf_utils(base_path) 
    add_cflags("-std=gnu99 -O0")
    add_files(string.format("%s/src/**.c", base_path))
    add_files(string.format("%s/port/*.c", base_path))
    add_includedirs(string.format("%s/src", base_path))
    add_includedirs(string.format("%s/port", base_path))
    add_packages("pthread")
end


target("xf_utils")
    set_kind("binary")
    add_cflags("-Wall")
    add_files("examples/*.c")
    add_includedirs("examples")
    add_xf_utils(".")
